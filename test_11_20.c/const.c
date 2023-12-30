#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//standard library  标准库  对应system
#include<windows.h>//程序需要的重要头文件
#include<math.h>
#include<time.h>
#include<assert.h>

//关键字const用来定义常量，如果一个变量被const修饰，那么它的值就不能再被改变
//int main()
//{
//	const int n = 10;
//	int m = 100;
//	const int*  p = &n;//const放在*左边时，修饰的是*p  也就是不能通过改变p来修改*p（num）的值
//	 //int* const p  放在* 的右边修饰的是p  不能修改p所存的地址  p=&m; 就不可以了
//	// 也可以const int* const  p = &n;  俩个都不可以改
//	*p = 20;
//	printf("%d", n);
//	return 0;
//}