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


//存放内容的另一种方法
//struct s
//{
//	char a;
//	int c;
//	double d;
//};
//int main()
//{
//	struct s a;
//	a.a = 'w';
//	a.c = 5;
//	a.d = 3.14;
//	return 0;
//}


//函数存放  与打印

//struct s
//{
//	char a;
//	int c;
//	double d;
//};
/*void f(int c)
{
	c = 5;
}*///实参与形参俩&是同一地址才可以修改
//void init(struct s* p)//结构体指针接收
//{
//	p->a = 'w';
//	p->c = 100;
//	p->d = 3.14;
//}
//void print(struct s a)
//{
//	printf("%c %d %lf\n", a.a, a.c, a.d);
//}
//void print2(const struct s* p)
//{
//	printf("%c %d %lf\n", p->a, p->c, p->d);
//}//如果为了安全 只打印 不修改  可以加一个const
//int main()
//{
//	struct s a;
//	init(&a);
//	print(a);
//	print2(&a);
//	//print2比较好，因为2只占4/8个字节是个地址
//	//但结构体过于大会导致性能下降
//	
//	//int a = 0.;
//	//f(&a);
//	//a.a = 'w';
//	//a.c = 5;
//	//a.d = 3.14;
//	return 0;
//}


//计算结构体的大小

//struct s
//{
//	char a;
//	int c;
//	double d;
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
	//printf("%d ", s1);
	//return 0;
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


//宏的使用  offsetof
//需要引用头文件  stddef.h
//作用查看该类型所在的偏移量
//第一个为类型名（不是变量名）
//第二个是成员名

//#include<stddef.h>
//struct s
//{
//	char a;
//	int c;
//	double d;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct s, a));
//	printf("%d\n", offsetof(struct s, c));
//	printf("%d\n", offsetof(struct s, d));
//	return 0;
//}

