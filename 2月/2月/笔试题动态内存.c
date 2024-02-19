#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//题目一


//void GetMemory(char* p)
//{
//	//str以值传递的形式给p
//	//p是GetMemory函数的形参，只能函数内部有效
//	//等GetMemory函数返回之后，动态开辟内存尚未释放
//	//并且无法找到，所以会造成内存泄漏
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);//指针变量  &str为传址
//	//参数传递默认是按值传递的，即函数接收到的是参数的拷贝，对参数的修改不会影响到原始参数。
//	// 因此，GetMemory(str)是传值调用，即将str的值（即NULL）拷贝给GetMemory函数中的参数p，
//	// 而在GetMemory函数内部对p的修改不会影响到str本身
//	strcpy(str, "hello world");//此时str还是为NULL 
//	//在此造成系统崩溃 
//	//也存在没有释放动态内存空间的问题
//	printf(str);
//}
////printf(str);格式打印没问题
////如果*str="abcdfg"
////那么打印的就是abcdfg
////跟printf("abcdfg");一样


//改正

//1

//void GetMemory(char** p)//  2
//{
//	*p = (char*)malloc(100);//  3
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);//  1
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);//  4
//	str = NULL;
//}

//2

//char* GetMemory(char* p)//  1
//{
//	p = (char*)malloc(100);
//	return p;//  2
//}
//void Test(void)
//{
//	char* str = NULL;
//	str=GetMemory(str);//  3
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);//  4
//	str = NULL;
//}



//题目二

//char* GetMemory(void)
//{
//	char p[] = "hello world";//非法访问
//	//p在栈区上会自动释放
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	//虽然str指向p的，存放着p的地址
//	//但p已经销毁，属于非法访问
//	str = GetMemory();
//	printf(str);
//}

//但如果这样就没问题

//int* test()
//{
//	int* str = malloc(40);
//	return str;
//}
//int main()
//{
//	int* p = test();
//	return 0;
//}


//题目三

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
////会正常打印hello 但是存在内存泄露的问题

//改正

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//题目四

//void Test(void)
//{
//	char* str = (char*)malloc(100);//str相当于房间号  hello相当于客人的行李
//	strcpy(str, "hello");
//	free(str);//free相当于退房
//	//退房以后str房间还存在，房间号依然没有改变
//	if (str != NULL)//  没有将str=NULL  由第一个strcpy得知str本就不是空指针
//	// 导致这里的if判断本就一定为真
//	{//再次放行李还是可以
//		//但是存在非法访问的问题
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//改正

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

