#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

typedef int SLDatatype;

typedef struct SLlist
{
	SLDatatype* a;
	int _top;
	int _capacity;
}ST;

void StackInit(ST* ps);
//入栈
void StackPush(ST* ps, SLDatatype data);
// 出栈 
void StackPop(ST* ps);
// 获取栈顶元素 
SLDatatype StackTop(ST* ps);
// 获取栈中有效元素个数 
int StackSize(ST* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(ST* ps);
// 销毁栈 
void StackDestroy(ST* ps);