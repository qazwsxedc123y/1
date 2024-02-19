#define  _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>

//柔性数组的定义
//结构中的最后一个元素允许是未知大⼩的数组，这就叫做 柔性数组 成员
//如下

//struct st_type
//{
//	int i;//结构中的柔性数组成员前⾯必须⾄少⼀个其他成员
//	int a[0];//柔性数组成员   大小为未知
//	//或者
//	//int a[];
//};
//int main()
//{
//	return 0;
//}

//柔性数组大小的计算

//typedef struct st_type
//{
//	int i;//结构中的柔性数组成员前⾯必须⾄少⼀个其他成员
//	int a[];//柔性数组成员 
//}type_a;
//int main()
//{
//	printf("%zd", sizeof(type_a));
//	//sizeof返回的这种结构大小不包括柔性数组的内存
//	return 0;
//}

//使用举例（简单）

//typedef struct st_type
//{
//	int i;//结构中的柔性数组成员前面必须至少一个其他成员
//	int a[];//柔性数组成员 
//}type_a;
//int main()
//{
//	int i = 0;
//	type_a * p = (type_a*)malloc(sizeof(type_a) + 100 * sizeof(int));
//	//业务处理 
//	p->i = 100;
//	for (i = 0; i < 100; i++)
//	{
//		p->a[i] = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//优势体现


//柔性数组写法

//typedef struct st_type
//{
//	int i;//结构中的柔性数组成员前面必须至少一个其他成员
//	int a[];//柔性数组成员 
//}type_a;
//int main()
//{
//	type_a* ps = (type_a*)malloc(sizeof(type_a) + sizeof(int) * 5);
//	ps->i = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->a[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	type_a* str=realloc(ps, sizeof(type_a) + sizeof(int) * 10);
//	if (str != NULL)
//	{
//		ps = str;
//		str = NULL;
//		for (i = 5; i < 10; i++)
//		{
//			ps->a[i] = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", ps->a[i]);
//		}
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//普通写法
//typedef struct st_type
//{
//	int i;//结构中的柔性数组成员前面必须至少一个其他成员
//	int* a;//柔性数组成员 
//}type_a;
//int main()
//{
//	type_a* ps = (type_a*)malloc(sizeof(type_a));
//	ps->i = 100;
//	ps->a = (int*)malloc(sizoef(sizeof(int) * 5));
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->a[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	//....(realloc调整大小)
//
//	//释放
//	free(ps->a);
//	ps->a = NULL;
//	//俩者顺序不可错  先是释放最内侧，在释放外层
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//相比较第一种写法更好
//1.⽅便内存释放
//如果我们的代码是在一个给别人⽤的函数中，你在里面做了二次内存分配，并把整个结构体返回给⽤
//户。⽤户调⽤free可以释放结构体，但是⽤户并不知道这个结构体内的成员也需要free，所以你不能
//指望⽤户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存⼀次性分配好了，并返
//回给⽤户⼀个结构体指针，⽤户做⼀次free就可以把所有的内存也给释放掉。
//而且释放顺序不可以错

//2.这样有利于访问速度.
//连续的内存有益于提⾼访问速度，也有益于减少内存碎⽚（第二种写法存在内存碎片问题）