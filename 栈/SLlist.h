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
//��ջ
void StackPush(ST* ps, SLDatatype data);
// ��ջ 
void StackPop(ST* ps);
// ��ȡջ��Ԫ�� 
SLDatatype StackTop(ST* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(ST* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(ST* ps);
// ����ջ 
void StackDestroy(ST* ps);