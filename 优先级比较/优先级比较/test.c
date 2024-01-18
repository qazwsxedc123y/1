#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//+  》   ++  》  =   》 ,

int main()
{
	int a, b, c;
	a = 5;
	c = ++a;//a=6, c=6
	b = ++c, c++, ++a, a++;//对于=与，先计算=  所以b的值=++c为7,然后进行逗号后的几个表示计算
//如果要实现逗号表达式的效果应该：
 //   b = (++c, c++, ++a, a++);
	b += a++ + c;
	printf("a =%d b=%d c=%d\n",a, b, c);
	return 0;
}