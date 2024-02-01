#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//正常的结构体设置

//struct sa//sa 为结构体名字，随便设置
//{
//	char ar[2];
//	int age;
//};//分号一定不要少
//int main()
//{
//	struct sa s1;
//	return 0;
//}

//全局与局部的区别

//struct sa//sa 为结构体名字，随便设置
//{
//	char ar[2];
//	int age;
//}s2;//s2是全局的定义结构体的变量
//int main()
//{
//	struct sa s1;//s1是局部的结构体变量
//	return 0;
//}


//匿名的结构体

//尽量不要用  只能用一次
//struct
//{
//	int a;
//	char c;
//}a;
//
//struct
//{
//	int a;
//	char c;
//}*pa;
//int main()
//{
//	pa = &a;//两者不是同一类型的
//	return 0;
//}


//结构体的自引用

//struct n
//{
//	int a;
//	struct n* next;//4/8字节
//	//struct n next;错误
//	//因为sizeof（struct n）无法计算
//};
//int main()
//{
//
//	return 0;
//}



//typedef  的使用


//typedef struct node//一般不要省去node
//{
//	int a;
//	//是将struct node简化为e
//}e;
//但是对于这种
//typedef struct
//{
//	int a;
//	struct e* next;//错误  就会产生是先有重命名e还是先有next
//	//要写成struct e  不是写一个e
//}e;//先有鸡还是先有蛋
//int main()
//{
//	return 0;
//}


//结构体的打印

//struct s
//{
//	char a;
//	char b;
//	int c;
//};
//struct s2
//{
//	char a;
//	char b;
//	struct s t;
//	int c;
//};
//int main()
//{
//	struct s c= { 'a','c',10 };
//	printf("%c %c %d\n", c.a, c.b, c.c);//打印
//
//	struct s2 a = { 'a','c',{'a','c',10},10 };
//	printf("%d", a.t.a);//打印的是a
//
//
//	return 0;
//}


//计算结构体的大小

//struct s
//{
//	char a;
//	char b;
//	int c;
//};
//struct s2
//{
//	char a;
//	char b;
//	struct s t;
//	int c;
//};
//struct s3
//{
//	char a;
//	double d;
//};
//int main()
//{
//	struct s c = { 'a','c',10 };
//	int s1 = sizeof(c);
//	struct s2 s;
//	struct s3 m;
//	int s2 = sizeof(s);
//	int s3 = sizeof(m);
//	printf("%d %d %d", s1,s2,s3);
//	return 0;
//}
//  提供解释 



//默认对齐数的修改

//#pragma pack(4)//设置默认对齐数为4  大小为12
////#pragma pack()//取消默认对齐数
////默认对齐数为1的话下面大小就是9
//struct s
//{
//	char a;
//	double d;
//};
//int main()
//{
//
//	return 0;
//}


int main()
{

	return 0;
}