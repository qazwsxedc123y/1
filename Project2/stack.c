//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//#include"stack.h"
////先进后出
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->_top = ps->_capacity = 0;//顶为top-1
//	ps->_a = NULL;
//}
//void Capacity_Add(Stack* ps)
//{
//	//增
//	assert(ps);
//	printf("增\n");
//	int new_capacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
//	int *tmp=realloc(ps->_a, sizeof(int) * new_capacity);
//	if (tmp != NULL)
//	{
//		ps->_a = tmp;
//	}
//	ps->_capacity = new_capacity;
//}
//void StackPush(Stack* ps, STDataType data)//入
//{
//	assert(ps);
//	if (ps->_capacity == ps->_top)
//	{
//		//进行增容
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
//// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
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