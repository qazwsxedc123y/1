//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//#include"stack.h"
////�Ƚ����
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->_top = ps->_capacity = 0;//��Ϊtop-1
//	ps->_a = NULL;
//}
//void Capacity_Add(Stack* ps)
//{
//	//��
//	assert(ps);
//	printf("��\n");
//	int new_capacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
//	int *tmp=realloc(ps->_a, sizeof(int) * new_capacity);
//	if (tmp != NULL)
//	{
//		ps->_a = tmp;
//	}
//	ps->_capacity = new_capacity;
//}
//void StackPush(Stack* ps, STDataType data)//��
//{
//	assert(ps);
//	if (ps->_capacity == ps->_top)
//	{
//		//��������
//		Capacity_Add(ps);
//	}
//	ps->_a[ps->_top] = data;
//	ps->_top++;
//}
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	ps->_top--;
//}
//STDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//
//	return ps->_a[ps->_top - 1];
//}
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->_top;
//}
//// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
//int StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->_top == 0;
//}
//void StackDestroy(Stack* ps)
//{
//	ps->_capacity = ps->_top = 0;
//	free(ps->_a);
//	ps->_a = NULL;
//}
//void test(Stack* ps)
//{
//	StackInit(ps);
//	StackPush(ps, 1);
//	StackPush(ps, 2);
//	StackPush(ps, 3);
//	StackPush(ps, 4);
//	while (!StackEmpty(ps))
//	{
//		printf("%d ", StackTop(ps));
//		StackPop(ps);
//	}
//	StackDestroy(ps);
//}
//int main()
//{
//	Stack st;
//	test(&st);
//	return 0;
//}