#define  _CRT_SECURE_NO_WARNINGS

#include"sltest.h"

int sselesct()
{
	int n = 0;
	printf("请输入要进行操作的信息：>");
	scanf("%d", &n);
	return n;
}

int scanf_pos()
{
	int n = 0;
	printf("请输入要进行操作的信息的下角标：>");
	scanf("%d", &n);
	return n;
}

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
	memmove(ps->a+1, ps->a, ps->size * sizeof(ps->a[0]));
	ps->a[0] = x;
	ps->size++;
	printf("前置添加成功\n");
}

void SLPopBack(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size > 0);
	SLErase(ps, ps->size-1);
}

void SLPopFront(SL* ps)
{
	assert(ps->size > 0);
	assert(ps != NULL);
	SLErase(ps, 0);
}

int FindPos(SL* ps, int pos)
{
	int n = ps->size-1;
	while (n>=0)
	{
		if (ps->a[n] == pos)
		{
			return n;
		}
		n--;
	}
		return -1;
}

void SLErase(SL* ps, int pos)
{
	assert(ps != NULL);
	assert(pos >= 0 && pos < ps->size);
	//int pos=FindPos(ps, pos);
	memmove(ps->a+pos,ps->a+pos+1,sizeof(ps->a[pos+1]));
	ps->size--;
	printf("该坐标的信息已删除\n");
}

void SLInSert(SL* ps, int pos,int x)
{
	assert(pos >= 0 && pos < ps->size);
	assert(ps != NULL);
	ChechSLCapacity(ps);
	memmove(ps->a + pos + 1, ps->a + pos, (ps->size - pos) * sizeof(ps->a[0]));
	ps->a[pos] = x;
	ps->size++;
	printf("插入成功\n");
}

void SLModify(SL* ps, int x)
{
	assert(ps != NULL);
	int ret=FindPos(ps, x);
	if (ret == -1)
	{
		printf("该信息不存在\n");
	}
	else
	{
		printf("该信息存在，请输入修改后的信息：>");
		int y = 0;
		scanf("%d", &y);
		ps->a[ret] = y;
		printf("修改成功\n");
	}
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