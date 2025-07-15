#define  _CRT_SECURE_NO_WARNINGS

#include "CentralCache.h"

CentralCache CentralCache::_sInst;  // 静态成员变量的定义


// 获取一个非空的span
// 当Central没有时，就需要向PageCache申请
Span* CentralCache::GetOneSpan(SpanList& list, size_t byte_size)
{
	// ...
	return nullptr;
}

// 从中心缓存获取一定数量的对象给thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size)
{
	size_t index = SizeClass::Index(size);
	_spanLists[index]._mtx.lock();

	Span* span = GetOneSpan(_spanLists[index], size);
	assert(span);
	assert(span->_freeList);

	// 从span中获取batchNum个对象
	// 如果不够batchNum个，有多少拿多少
	start = span->_freeList;
	end = start;
	size_t i = 0;
	size_t actualNum = 1;
	while (i < batchNum - 1 && NextObj(end) != nullptr)
	{
		end = NextObj(end);
		++i;
		++actualNum;
	}
	// 实际只可以申请到 actualNum 个内存块

	// 申请完后，要修改原本CentralCache的 span
	span->_freeList = NextObj(end);
	NextObj(end) = nullptr;

	_spanLists[index]._mtx.unlock();
	
	return actualNum;
}