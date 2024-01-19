#define  _CRT_SECURE_NO_WARNINGS
//结构体里面的成员可以是指针，标量，数组甚至是其他结构体
#include<stdio.h>


//typedef的写法

//typedef struct stu
//{
//	char name[7];
//	short age;
//	char tele[12];
//}Stu;
//void print1(Stu p2)
//{
//	printf("%s\n", p2.name);
//	printf("%d\n", p2.age);
//	printf("%s\n", p2.tele);
//}
//void print2(Stu* p2)
//{
//	printf("%s\n", p2->name);
//	printf("%d\n", p2->age);
//	printf("%s\n", p2->tele);
//}
//int main()
//{
//	Stu p1={ "张三",17,"12345678978" };
//	print1(p1);
//	print2(&p1);
//	return 0;
//}

//普通写法

//struct stu
//{
//	char name[7];
//	short age;
//	char tele[12];
//};
//
//void print1(struct stu pa)//实参传给形参的时候，形参是实参的一份临时拷贝
//{
//	printf("%s\n", pa.name);
//	printf("%d\n", pa.age);
//	printf("%s\n", pa.tele);
//}
//void print2(struct stu* p)
//{
//	printf("%s\n", p->name);
//	printf("%d\n", p->age);
//	printf("%s\n", p->tele);
//}
//int main()
//{
//	struct stu s = { "张三",5,"12345678911" };
//	print1(s);
//	print2(&s);
//	return 0;
//}


// 在结构体里面嵌套结构体

struct stu  //类型  不占用空间
{
	char name[20];//结构体成员
	char tele[12];
	char sex[5];
};

struct s
{
	char name[20];
	struct stu stu;
}p1;  //定义结构体类型的同时定义变量p1

int main()
{
	struct s p2 = { "张三",{"李四","12345678923","男"} };  //定义结构体变量p2
	printf("%s\n", p2.name);
	printf("%p\n", &p2.stu.name);
	printf("%s\n", p2.stu.tele);
	printf("%s\n", p2.stu.sex);
}

//typedef 的使用

//typedef struct stu  //类型  不占用空间  typedef是将类型名重新起个名字
//{
//	char name[20];
//	short age[5];
//	char tele[12];
//	char sex[5];
//}stu;
//
//int main()
//{
//	struct stu s1;//创建一个结构体变量 
//	stu s2;
//	return 0;
//}


// struct 结构体关键字  stu  结构体标签  struct stu  结构体类型

//struct stu  //类型  不占用空间
//{
//	char name[20];//结构体成员
//	short age[5];
//	char tele[12];
//	char sex[5];
//};
//
//int main()
//{
//	struct stu s;  //创建一个结构体变量 
//	return 0;
//}