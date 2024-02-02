#define  _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>


//了解

//位段的类型只能是整形类型  int  short int
//位段的成员名后面有一个冒号与数字

//如下
//位段--2进制位
//位段的空间上是按照需要以4个字节(int)或者1个字节(char )的方式来开辟的。
//不够再放的话就浪费，再开辟
//因为最大是4个字节所以后面的数字不能大于32
 
//struct s
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//int main()
//{
//	struct s a;
//	printf("%zd\n", sizeof(a));//8 个字节
//	return 0;
//}