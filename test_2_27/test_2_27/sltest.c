#define  _CRT_SECURE_NO_WARNINGS

#include"sltest.h"

void SLInit(SL* ps)
{
	ps->a = (SLDatatype* )malloc(sizeof(SLDatatype) * 4);
	if (ps->a == NULL)
	{
		perror("SLInit error\n");
		return;
	}
	ps->size = 0;
	ps->capacity = max_begin;
}

void AddSLCapacity(SL* ps)
{
	SLDatatype* tmp=(SLDatatype* )realloc(ps->a, sizeof(SLDatatype) * ps->capacity * 2);
	if (tmp == NULL)
	{
		perror("AddSLCapacity error\n");
		return;
	}
	ps->a = tmp;
	ps->capacity *= 2;
}

void ChechSLCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		AddSLCapacity(ps);
	}
}

void SLPushBack(SL* ps,int x)
{
	ChechSLCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
	printf("后置添加成功\n");
}

void SLPushFront(SL* ps, int x)
{
	ChechSLCapacity(ps);
	memmove(ps->a+1, ps->a, sizeof(ps->a));
	ps->a[0] = x;
	ps->size++;
	printf("前置添加成功\n");
}

void SLPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SLprintf(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}