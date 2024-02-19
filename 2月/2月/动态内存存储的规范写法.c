#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1.对NULL指针的解引用操作

//int main()
//{
//	int* p = (int*)malloc(_CRT_INT_MAX);//p为空指针
//	*(p+1) = 20;//p本就为空指针，加一后还为空指针
//	free(p);
//	p = NULL;
//	return 0;
//}

//2. 对动态开辟空间的越界访问

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		exit(1);
//		//exit(0): 正常执行程序并退出程序。exit(EXIT_SUCCESS)
//
//		//exit(1) : 非正常执行导致退出程序。exit(EXIT_FAILURE)
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i <= 10; i++)
//		{
//			*(p + i) = i;//当i是10的时候越界访问
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//3. 对非动态开辟内存使用free释放

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//free与malloc使用范围都是堆区
//	//而int a = 10;  int* p = &a;都是存在栈区，free无法释放非动态开辟空间
//	p = NULL;
//	return 0;
//}

//4. 使用free释放一块动态开辟内存的一部分

//int main()
//{
//	int* p = (int*)malloc(40);
//	p++;
//	free(p);//释放的不是原来的p而是p+1后的地址
// //会导致系统崩溃
//	p = NULL;
//	return 0;
//}

//5. 对同一块动态内存多次释放

//int main()
//{
//	int* p = (int*)malloc(40);
//	//....（省略操作动态开辟的空间的操作）
//	free(p);
//	//p=NULL;
//	free(p);
//	//会导致系统假死崩溃
//	//但是第一次释放以后直接p=NULL再次释放就没关系
//	//因为如果free一个空指针，是没有任何事情发生的
//	return 0;
//}

//6. 动态开辟内存忘记释放（内存泄漏）

//int main()
//{
//	while (1)
//	{
//		int* p = (int*)malloc(100);//一直开辟不释放
//		//就会造成电脑cpu与内存满，会造成电脑崩溃，严重黑屏
//	}
//	//忘记释放不再使?的动态开辟的空间会造成内存泄漏。
//	//切记：动态开辟的空间?定要释放，并且正确释放
//	return 0;
//}

