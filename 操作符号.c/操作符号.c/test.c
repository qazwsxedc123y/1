#define  _CRT_SECURE_NO_WARNINGS
#include"头.h"
//
//int main()
//{
//	int c = 1;
//	printf("%d", c + --c);
//	return 0;
//
//}



//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	//代码有问题  *的优先级高于+  只能保证*的计算在+的前面  不能保证第三个*比第一个+先进行运算
//	int q = a * b + c * d + a * b;
//	printf("%d", q);
//	return 0;
//}




//隐式类型转换
 
// 什么时候进行整型提升
//1. 为了获得这个精度，表达式中的字符和短整型操作数在使用之前要转换为普通整型
//2. 通用CPU(generapurpose CPU)是难以置接实现两个8比特字节直接相加运算
// 所以，表达式中各种长度可能小于int长的整型值，都必须先转换为unsigned int或int，然后才能送入CPU去执行运算
// 
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));
//	printf("%u\n", sizeof(+c));
//	printf("%u\n", sizeof(!c));
//	return 0;
//}

//整形类型提升  
//转换为  int  型的
//即选取最高位 进行前补
//int main()
//{
//	char a = 3;  //00000011  进行整形提升
////	变为00000000000000000000000000000011
//	char b = 127;//01111111
////      00000000000000000000000001111111
//	char c = a + b;
////进行相加
//// 	   00000000000000000000000000000011
//// 	   00000000000000000000000001111111
////     00000000000000000000000010000010  
//// 	   结果放c后为10000010（char类型）
//// 	   打印的为%d  即为整形故c还要整形提升
////     11111111111111111111111110000010  补码
//// 	   11111111111111111111111110000001  反码
//// 	   10000000000000000000000001111110  原码
////     整形为-126
//	printf("%c\n", a);
//	printf("%c\n", b);
//	printf("%d\n", c);//打印的为%d  即为整形故c还要整形提升
//	return 0;
//}



//结构体的操作符
//struct sr
//{
//	char name[20];
//	int age;
//	char id[20];
//};
//int main()
//{
//	struct sr  s1={"张三",18,"12112121" };
//	struct sr* ps = &s1;
//
//	//效果相同
//	//结构体指针->成员名
//	printf("%s\n", ps->name);
//	printf("%s\n",(*ps).name);
//
//
////	printf("%s\n", s1.name);
////	printf("%d\n", s1.age);
////	printf("%s\n", s1.id);
//	return 0;
//}






//int get_max(int x, int y)
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//操作符为（）  操作数有三个  get_max  a  b
//	int max = get_max(a, b);
//	printf("%d\n", max);
//	return 0;
//}


//下标引用操作符
//int main()
//{
//	int arr[10] = { 0 };
////  1 +2  +为操作符，操作数有俩个为 1  2
////  []为操作符  操作数为arr  与 4   有俩个
//  	arr[4] = 9;
//	printf("%d", arr[4]);
//	return 0;
//}
//


//逗号操作符  
//int main()
//{
//	int a = 1;
//	int b = 2;
////  ,号表达式从左向右依次运算（全都运算）结果为最后一个表达式的结果
//	int c = (a > b, a = a + 10, a, b = a + 1);
//	printf("%d", c);
//	return 0;
//}

//三目操作符
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = (a < b ? b : a);
//	printf("%d", max);
//	return 0;
//}


//逻辑与  逻辑或   
//结束标识为可以判断出i的值
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4; 
//		
//	//i = a++ && ++b && d++;
//	//因为a为先使用再加加，故为假那么后面全都不进行算数 ，已经可以判断出i的值为0 
//	// 则i为假 即为0  但a完成了自加变为了  1 
//	
//	i = a++ || ++b || d++;	
//	//仅进行a++就可以判断出i的值，故后面的运算可以不算
//	printf("%d\n", i);//i=1
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	 return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c= a++;
//	printf("%d\n", c);
//	printf("%d\n", a);
//	if(a && b)
//	printf("%d\n", a);
//	return 0;
//}





//在这个修改后的代码中，我使用%lu格式说明符来打印sizeof操作符的结果。在main函数中，
// sizeof(arr)会打印出数组arr的实际大小，为40，sizeof(ch)会打印出数组ch的实际大小，
// 为10。在test1和test2函数中，sizeof(arr)和sizeof(ch)会打印出指针的大小，取决于系统是32位还是64位。


//void testl(int arr[])//用指针接受后打印的指针大小
//{
//	printf("%d\n",sizeof(arr));
//}
//void test2(char ch[]) 
//{
//	printf("%d\n",sizeof(ch));
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(ch));
//	testl(arr);
//	test2(ch);
//	return 0;
//}




//强制类型转换  
//int main()
//{
//	int a = (int)3.14;
//	return 0;
//}



//++a;与a++的区别
//int main()
//{
//	int a = 10;
//	printf("%d\n", ++a);  //先加加再使用
//	printf("%d\n", a++);  //先使用再加加
//	return 0;
//}




//按位取反  ~ 的使用
//int main()
//{
//	int a = 11;
//	a = a | (1 << 2);
////	000000000000000000001011  a
////	000000000000000000000100
////	 
////	111111111111111111110001   补
////	111111111111111111110000  反
////	000000000000000000001111 15的原
////	1011 利用 ~变为 1111  15
//	printf("%d\n", a);
////把000000000000000000001111  变为000000000000000000001011
////  111111111111111111111011  按位与
////  000000000000000000000100  由按位取反
//	a = a & (~(1 << 2));
//	printf("%d\n", a);
//	return 0;
//}



//按位取反  ~
//int main()
//{
//	int a = 0;
	//按（2进制）取反
	//000000000000000000000000  原反补码相同
	//取反
	//111111111111111111111111 补码
	// 补变反码  -1
	//111111111111111111111110 反码
	//首不变 其余取反
	//100000000000000000000001 原码  -1
//	printf("%d", ~a);
//	return 0;
//}



//sizeof的用法二
//int main()
//{
//    short s = 0;
//    int a = 10;
//    printf("%d\n", sizeof(s = a + 5));//sizeof（里面如果是运算，则不参与运算）
//    printf("%d\n", s);
//    return 0;
//}
//输出为   2  0




//sizeof的使用的补充 1
//int main()
//{
//    int a = 10;
//    char b = 'r';
//    char* p = &b;
//    int arr[10] = { 0 };
////  sizeof 计算的变量所占空间的大小  单位为字节  
//    //后为前对应的类型，效果执行相同
//    //第一行的（）可省去   第二行不可省 
//    //变量名中的（）可省   类型的不可省
//    printf("%d\n", sizeof(a));
//    printf("%d\n", sizeof(int));
//
//
//    printf("%d\n", sizeof(b));
//    printf("%d\n", sizeof(char));
//
//
//    printf("%d\n", sizeof(p));
//    printf("%d\n", sizeof(char*));
//
//
//    printf("%d\n", sizeof(arr));
//    printf("%d\n", sizeof(int [10]));
//
//    return 0;
//}




//int main()
//{
//    int a = 20;
//    int* b = &a;//取地址操作符&  解引用操作符*
//    *b = 10;
//    printf("%d",*b);
//    return 0;
//}



//单目操作符   ！取反
//int main()
//{
//    int a = -5;
//    int b = !a;
//    printf("%d", b);
//    return 0;
//}




//算一个数(补码)二进制有几个1    方法二  按位操作符(按位与，全一则一）
//int main()
//{
//    int num = 0;
//    int count = 0;
//    int i = 0;
//    scanf("%d", &num);
//    for(i=0;i<32;i++)
//    {
//        if (num ^ 1 == 1)
//        {         
//            count++;
//        }
//        num = num >> 1;
//    }
//    printf("%d", count);
//    return 0;
//}



//算一个数的补码有几个1（负数计算的不是补码）只能计算正数    方法一
//int main()
//{
//    int num = 0;
//    int count = 0;
//    scanf("%d", &num);
//    while (num)
//    {
//        if (num > 0)
//        {
//            if (num % 2 == 1)
//                count++;
//            num = num / 2;
//        }
//        else
//        {
//            num = -num;
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}
