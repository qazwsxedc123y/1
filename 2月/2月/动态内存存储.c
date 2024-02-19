#define  _CRT_SECURE_NO_WARNINGS

//操作范围为堆区!!!!
#include<string.h>
#include <stdio.h>
#include<stdlib.h>
#include<errno.h>

//malloc与free开辟空间

//int main()
//{
//	//动态类型开辟
//	//开辟成功的话就会返回一个void* 型的指针，这时候尽量要类型转化一下
//	//开辟失败的话就会返回一个NULL的指针，所以要尽量检查一下其返回值
//	//如果size为0，则为未定义的标准内容，这时候就取决与编译器
//
//	//void* malloc(size_t_Size)//函数部分（声明）
//
//	//向内存申请10个整形空间
//	int* p = (int*)malloc(10 * sizeof(int));//尽量要进行强制类型转换
//
//	//char* p2= (char*)malloc(10 * sizeof(char));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);//当动态的申请空间不再使用的时候
//	//就应该还给操作系统，其就是用到的free（）；
//	//释放空间
//
//	p = NULL;//还给后p就变成了野指针，这时候就需要将其转换一下
//	return 0;
//}

//calloc开辟空间并将开辟元素初始化为0

//int main()
//{ //                  元素个数    每个元素的字节大小
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	//释放动态开辟的空间
//	free(p);
//	p = NULL;
//	return 0;
//}


//重点
//realloc 动态内存重新开辟  调整
//变大 变小

//int main()
//{
//	int* p=(int*)malloc(20);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*(p + i) = i;
//	}
//
//	//就在此我们已经用malloc开辟了20个字节空间
//	//假设我们20个字节空间已经不够用我们需要40个字节
//	//我们就需要使用realloc来调整动态开辟的空间
//	//
//	//realloc的注意事项
//	//1. 原本的p指向的空间右足够的空间可以追加，则直接追加，返回值为p
//	//2. 如果空间不足，则realloc会重新找一个空间足够的新内存区域
//	//开辟一块满足要求的空间，并把原来的内存数据拷贝过来，释放旧的内存空间
//	//最后返回新开辟空间的地址
//	//3. 如果开辟失败则还是会返回NULL
//	//如果还用p来接收则会出问题，换个ptr接收
//
//	int* ptr=realloc(p, 40);//已经开辟的空间指针（调整的空间）  ，变后的大小
//	if (ptr != NULL)
//	{
//		p = ptr;
//		ptr = NULL;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	else
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//当然最后还是需要释放内存
//	free(p);
//	p = NULL;
//	return 0;
//}

