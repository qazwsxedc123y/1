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
//#define MAXSIZE 1000    //ͼ�����ܴﵽ����󳤶�
//using namespace std;
//typedef struct
//{//ͼ����Ϣ����
//    char no[20];    //ͼ��ISBN
//    char name[50];   //ͼ������
//    float price;   //ͼ��۸�
//}Book;
//typedef struct
//{//ͼ����˳��洢�ṹ����ΪSqList
//    Book* elem;                   //�洢�ռ�Ļ���ַ
//    int length;                   //ͼ����е�ǰͼ�����
//}SqList;
//int InitList_Sq(SqList& L)
//{//����һ���յ�˳���L
//    L.elem = new Book[MAXSIZE];     //Ϊ˳������һ����СΪMAXSIZE������ռ�
//    if (!L.elem)exit(OVERFLOW);    //�洢����ʧ���˳�
//    L.length = 0;                   //�ձ���Ϊ0
//    return OK;
//}
//int Input_Sq(SqList& L)
//{//˳��������
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
//{//˳�������
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
//    SqList L;                   //����һ��SqList���͵ı���L
//    InitList_Sq(L);             //��ʼ��һ���յ�˳���L
//    Input_Sq(L);                //��������
//    Output_Sq(L);               //�������
//    return 0;
//}
//
////#include <stdio.h>  
////#include <stdlib.h>  
////#define MAX 100  
////#define true 1 // 1 �� true, 0 �� false  
////#define s "hello Linux"  
////#define Linux 1  
////
////int main() {
////    if (true) {
////        printf("%s\n", s); // ��� s �궨����ַ���  
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
////#endif // ���ָ������ #ifdef �Ľ���  
////
////    printf("%d\n", MAX);
////    printf("Program is running...\n");
////
////    return 0;
////}