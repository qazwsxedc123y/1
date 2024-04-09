#define  _CRT_SECURE_NO_WARNINGS
#include"SLlist.h"

void StackInit(ST* ps)
{
	assert(ps);
	//ps->_top = 0;//栈顶指向尾后一个位置
	ps->_top = -1;//栈顶指向尾

	ps->_capacity = 0;
	ps->a = NULL;
}

void StackPush(ST* ps, SLDatatype data)
{
	if (ps->_top+1 == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		SLDatatype* tmp=(SLDatatype*)realloc(ps->a, sizeof(SLDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc error");
			return ;
		}
		ps->_capacity = newcapacity;
		ps->a = tmp;
	}
	ps->_top++;
	ps->a[ps->_top] = data;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	//assert(!*ps);
	ps->_top--;
}

SLDatatype StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->_top];
}

int StackSize(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_top + 1;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(ST* ps)
{
	assert(ps);
	//if (ps->_top == -1)//为空
	//{
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}
	return ps->_top==-1;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_top = -1;
	free(ps->a);
	ps->a = NULL;
}