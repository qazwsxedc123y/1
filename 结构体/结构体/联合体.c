#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//联合-联合体-共用体
//union s
//{
//	char a;
//	int c;
//	double d;
//};
//int main()
//{
//	union s c;
//	printf("%d", sizeof(c));//8  大小至少是最大成员的大小
//	//共用体里面成员公用一个空间
//	//所以不能同时使用，只能使用其中一个
//
//	printf("%p\n", &c);//四个值一样
//	printf("%p\n", &(c.a));
//	printf("%p\n", &(c.c));
//	printf("%p\n", &(c.d));
//	return 0;
//}

//判断大小端
//普通写法

//int sys()
//{
//	int i = 1;
//	return *(char*)&i;
//}
//int main()
//{
//	int ret=sys();
//	if (ret == 1)
//	{
//		printf("大端\n");
//	}
//	else
//	{
//		printf("小端\n");
//	}
//	return 0;
//}


//联合体写法

//int sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int ret = sys();
//	if (ret == 1)
//	{
//		printf("大端\n");
//	}
//	else
//	{
//		printf("小端\n");
//	}
//	return 0;
//}


//计算联合体的大小
//数组的对齐数要看其元素如
//char arr[5]; 对齐数是1

//1.大小至少是其成员的最大的大小
//2.大小不是不是成员最大对齐数的整数倍是，要浪费空间变为其整数倍
//union un
//{
//	int a;//大小是4
//	char arr[5];//大小是5  ->5
//};
////对齐数：
////4 8  ->4
////1 8  ->1   ->4
////5不是4的倍数--->8
//int main()
//{
//	union un s;
//	printf("%d", sizeof(s));//8
//	return 0;
//}