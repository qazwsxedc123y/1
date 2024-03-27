#define  _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//typedef struct SeqList
//{
//	SLDateType* a;
//	int size;
//	int capacity;
//}SeqList;

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->capacity = 4;//初始为4
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * ps->capacity);
	
	ps->size = 0;
}
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	int i = 0;
	while (i<ps->size)
	{
		printf("%d ", ps->a[i]);
		i++;
	}
	printf("\n");
}
int SeqListFind(SeqList* ps, SLDateType x)//返回下角标
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void check_capacity(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDateType* temp = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		if (temp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcapacity;
	}
}
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	check_capacity(ps);
	int i = 0;
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
 	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	int end = ps->size - 1;
	int erase = pos+1;
	while (pos <= end)
	{
		ps->a[pos] = ps->a[pos + 1];
		pos++;
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, 0);
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListInsert(ps, 0, x);
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListInsert(ps, ps->size-1, x);
}