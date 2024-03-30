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

//С�Ѹ�Ϊ��� ֻ��Ҫ��adjust����<��Ϊ>

void HeapInit(Hp* php);
void HeapDestroy(Hp* php);
void Heappush(Hp* php,HpDataType x);
void Heapprint(Hp* php);
int HeapSize(Hp* php);

//Ϊ�շ���0   �ǿշ��ط���
int HeapEmpty(Hp* php);

HpDataType HeapTop(Hp* php);

void HeapPop(Hp* php);

void adjustment_down(Hp* php, int n, int parent);
void adjustment_prev(Hp* php,  int child);
void swap(HpDataType* p1, HpDataType* p2);


void HeapSort(Hp* php, int n);
//�Ž���  ����С��
//�������  ��β����  ���һ��������С��  Ȼ��size--
//�ظ����  �ͻ�õ��ڶ�С��
