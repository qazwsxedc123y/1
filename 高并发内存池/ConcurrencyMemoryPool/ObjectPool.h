#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using std::cout;
using std::endl;


#ifdef _WIN32
#include<windows.h>
#else
// 
#endif

// 直接去堆上按页申请空间
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux下brk mmap等
#endif

	if (ptr == nullptr)
		throw std::bad_alloc();

	return ptr;
}

// 这里的 _freeList 就相当于ThreadCache 的桶（自由链表）
// _memory 相当于从 CentralCache 批量获取的内存

template<class T>
class ObjectPool
{
public:
	T* New()
	{
		T* obj = nullptr;

		// 如果已经有还回来的内存块，那么就不需要向 _memory中申请了
		if (_freeList)
		{
			// 头删
			void* _next = *(void**)_freeList;
			obj = (T*)_freeList;
			_freeList = _next;
		}
		else
		{
			// 剩余内存不够一个对象大小时，则重新开大块空间
			if (_remainBytes < sizeof(T))
			{
				_remainBytes = 128 * 1024;
				// _memory = (char*)malloc(_remainBytes);
				// 修改为按页分配
				_memory = (char*)SystemAlloc(_remainBytes >> 13);
				if (_memory == nullptr)
				{
					throw std::bad_alloc();
				}
			}

			obj = (T*)_memory;
			size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
			_memory += objSize;
			_remainBytes -= objSize;
		}
		
		// 定位new，显示调用T的构造函数初始化
		// 避免T为自定义类型或着类似vector之类的
		new(obj)T;

		return obj;
	}
	void Delete(T* obj)
	{
		// 显示调用析构函数清理对象
		obj->~T();

		// 进行头插进 _freeList内
		*(void**)obj = _freeList;
		_freeList = obj;

	}
private:
	char* _memory = nullptr; // 指向大块内存的地址
	size_t _remainBytes = 0; // 大块内存在切分的过程中剩余的字节数

	void* _freeList = nullptr; // 指向还回来过程中链接的自由链表的头指针
};


struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};

void TestObjectPool()
{
	// 申请释放的轮次
	const size_t Rounds = 5;

	// 每轮申请释放多少次
	const size_t N = 100000;

	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	ObjectPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	cout << "new cost time:" << end1 - begin1 << endl;
	cout << "object pool cost time:" << end2 - begin2 << endl;
}