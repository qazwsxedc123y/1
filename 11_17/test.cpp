#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<set>
#include<bitset>
#include<unordered_map>
#include<map>

using namespace std;
#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct
{//图书表的顺序存储结构类型为SqList
    Book* elem;                   //存储空间的基地址
    int length;                   //图书表中当前图书个数
}SqList;
int InitList_Sq(SqList& L)
{//构造一个空的顺序表L
    L.elem = new Book[MAXSIZE];     //为顺序表分配一个大小为MAXSIZE的数组空间
    if (!L.elem)exit(OVERFLOW);    //存储分配失败退出
    L.length = 0;                   //空表长度为0
    return OK;
}
int Input_Sq(SqList& L)
{//顺序表的输入
/**************begin************/
    for (int i = 0; i < MAXSIZE; i++)
    {
        cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
        if ((L.elem[i].no, "0") == 0 && (L.elem[i].name, "0") == 0 && (L.elem[i].price, '0') == 0)
            return OK;
        else
            L.length++;
    }
    return OK;


    /**************end************/
}
int Output_Sq(SqList L)
{//顺序表的输出
/**************begin************/
    cout << L.length << endl;
    for (int i = 0; i < L.length; i++) {
        // if(L.elem[i].no == '0'&&L.elem[i].name=='0'&&L.elem[i].price=='0')
        //     break;
        cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2) << L.elem[i].price << endl;
    }
    return OK;


    /**************end************/
}
int main()
{
    SqList L;                   //定义一个SqList类型的变量L
    InitList_Sq(L);             //初始化一个空的顺序表L
    Input_Sq(L);                //输入数据
    Output_Sq(L);               //输出数据
    return 0;
}
//struct KeyToInt1
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt1" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt2
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt2" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt3
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt3" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt4
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt4" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt5
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt5" << endl;
//		return (size_t)1;
//	}
//};
//
//
//// 假设布隆过滤器中元素类型为K，每个元素对应5个哈希函数
//template<class K, class KToInt1 = KeyToInt1, class KToInt2 = KeyToInt2,
//	class KToInt3 = KeyToInt3, class KToInt4 = KeyToInt4,
//	class KToInt5 = KeyToInt5>
//class BloomFilter
//{
//public:
//	BloomFilter(size_t size)  // 布隆过滤器中元素个数
//		: _bmp(5 * size)
//		, _size(0)
//	{}
//
//	// 插入数据
//	bool Insert(const K& key)
//	{
//		size_t hashi1 = KeyToInt1()(key);
//		size_t hashi2 = KeyToInt2()(key);
//		size_t hashi3 = KeyToInt3()(key);
//		size_t hashi4 = KeyToInt4()(key);
//		size_t hashi5 = KeyToInt5()(key);
//		if (IsInBloomFilter(hashi1)
//			&& IsInBloomFilter(hashi2)
//			&& IsInBloomFilter(hashi3)
//			&& IsInBloomFilter(hashi4)
//			&& IsInBloomFilter(hashi5))
//		{
//			return false;
//		}
//		_bmp.set(hash1);
//		_bmp.set(hash2);
//		_bmp.set(hash3);
//		_bmp.set(hash4);
//		_bmp.set(hash5);
//		return true;
//	}
//	// 检测在不在
//	// 在返回true，不在返回false
//	bool IsInBloomFilter(const K& key)
//	{
//		size_t hashi1 = KeyToInt1()(key);
//		size_t hashi2 = KeyToInt2()(key);
//		size_t hashi3 = KeyToInt3()(key);
//		size_t hashi4 = KeyToInt4()(key);
//		size_t hashi5 = KeyToInt5()(key);
//		if (_bmp.test(hashi1)
//			&& _bmp.test(hashi2)
//			&& _bmp.test(hashi3)
//			&& _bmp.test(hashi4)
//			&& _bmp.test(hashi5))
//		{
//			return true;
//		}
//		return false;
//	}
//	// 位图不支持删除
//private:
//	bitset _bmp;
//	size_t _size;   // 实际元素的个数
//};
//
//
//class bitset
//{
//public:
//	bitset(size_t bitCount)
//		: _bit((bitCount >> 5) + 1)
//		, _bitCount(bitCount)
//	{}
//	// 将which比特位置1
//	void set(size_t which)
//	{
//		int i = which / 32;
//		int j = which % 32;
//		_bit[i] |= (1 << j);
//	}
//	// 将which比特位置0
//	void reset(size_t which)
//	{
//		int i = which / 32;
//		int j = which % 32;
//		_bit[i] &= (~(1 << j));
//	}
//	// 检测位图中which是否为1
//	bool test(size_t which)
//	{
//		int i = which / 32;
//		int j = which % 32;
//		int ret = (1 << j) & _bit[i];
//		return ret;
//	}
//	size_t size()const
//	{ 
//		return _bitCount; 
//	}
//
//private:
//	vector<int> _bit;
//	size_t _bitCount;
//};