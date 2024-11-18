#define  _CRT_SECURE_NO_WARNINGS
#include"main.h"

int main()
{
	int x = 5, y = 6;
	printf("%d", Add(x, y));
	return 0;
}


//#include<iostream>
//#include<string.h>
//#include<iomanip>
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//#define MAXSIZE 1000    //图书表可能达到的最大长度
//using namespace std;
//typedef struct
//{//图书信息定义
//    char no[20];    //图书ISBN
//    char name[50];   //图书名字
//    float price;   //图书价格
//}Book;
//typedef struct
//{//图书表的顺序存储结构类型为SqList
//    Book* elem;                   //存储空间的基地址
//    int length;                   //图书表中当前图书个数
//}SqList;
//int InitList_Sq(SqList& L)
//{//构造一个空的顺序表L
//    L.elem = new Book[MAXSIZE];     //为顺序表分配一个大小为MAXSIZE的数组空间
//    if (!L.elem)exit(OVERFLOW);    //存储分配失败退出
//    L.length = 0;                   //空表长度为0
//    return OK;
//}
//int Input_Sq(SqList& L)
//{//顺序表的输入
///**************begin************/
//    for (int i = 0; i < MAXSIZE; i++)
//    {
//        cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
//        if ((L.elem[i].no, "0") == 0 && (L.elem[i].name, "0") == 0 && (L.elem[i].price, '0') == 0)
//            return OK;
//        else
//            L.length++;
//    }
//    return OK;
//
//
//    /**************end************/
//}
//int Output_Sq(SqList L)
//{//顺序表的输出
///**************begin************/
//    cout << L.length << endl;
//    for (int i = 0; i < L.length; i++) {
//        // if(L.elem[i].no == '0'&&L.elem[i].name=='0'&&L.elem[i].price=='0')
//        //     break;
//        cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2) << L.elem[i].price << endl;
//    }
//    return OK;
//
//
//    /**************end************/
//}
//int main()
//{
//    SqList L;                   //定义一个SqList类型的变量L
//    InitList_Sq(L);             //初始化一个空的顺序表L
//    Input_Sq(L);                //输入数据
//    Output_Sq(L);               //输出数据
//    return 0;
//}
//
////#include <stdio.h>  
////#include <stdlib.h>  
////#define MAX 100  
////#define true 1 // 1 是 true, 0 是 false  
////#define s "hello Linux"  
////#define Linux 1  
////
////int main() {
////    if (true) {
////        printf("%s\n", s); // 输出 s 宏定义的字符串  
////    }
////
////#if true  
////    printf("hello Linux\n");
////#else  
////    printf("hello Windows\n");
////#endif  
////
////#ifdef Linux  
////    printf("Debug mode is enabled.\n");
////#endif // 这个指令标记了 #ifdef 的结束  
////
////    printf("%d\n", MAX);
////    printf("Program is running...\n");
////
////    return 0;
////}