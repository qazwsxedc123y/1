#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<errno.h>

typedef int HpDataType;
typedef struct heap
{
	HpDataType* a;
	int _size;
	int _capacity;
}Hp;

//小堆改为大堆 只需要在adjust部分<改为>

void HeapInit(Hp* php);
void HeapDestroy(Hp* php);
void Heappush(Hp* php,HpDataType x);
void Heapprint(Hp* php);
int HeapSize(Hp* php);

//为空返回0   非空返回非零
int HeapEmpty(Hp* php);

HpDataType HeapTop(Hp* php);

void HeapPop(Hp* php);

void adjustment_down(Hp* php, int n, int parent);
void adjustment_prev(Hp* php,  int child);
void swap(HpDataType* p1, HpDataType* p2);


void HeapSort(Hp* php, int n);
//排降序  建立小堆
//调整完后  首尾交换  最后一个就是最小的  然后size--
//重复如此  就会得到第二小的
