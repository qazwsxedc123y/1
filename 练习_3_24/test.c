#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include <stdlib.h> 

// ����������
union Test {
    int num;
    char bytes;
};

// �жϵ�ǰ�������ֽ�˳����
int check() 
{
    union Test test;
    test.num = 1;
    return test.bytes == 1;  // ���bytesΪ1����ΪС�ˣ�����Ϊ���
}

int main() {
    if (check()) 
    {
        printf("��ǰ����ΪС��\n");
    }
    else 
    {
        printf("��ǰ����Ϊ���\n");
    }
    return 0;
}


//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);
//    return 0;
//}

//union Un
//{
//	short s[7];
//	int n;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}

//#define A 2
//#define B 3
//
//#define MAX_SIZE A+B
//
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);


//int main()
//{
//	char buffer[25] = { '7','5','a','b'};
//	int i = 0;
//	i = atoi(buffer);
//	printf("%d", i);
//	return 0;
//}
 

//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//���ϱ����Ķ��� 
//	union Un un = { 0 };
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un un = { 0 };
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//	printf("%p\n", &un);
//}
//enum Color
//{
//    GREEN = 1,
//    RED,
//    BLUE,
//    GREEN_RED = 10,
//    GREEN_BLUE,
//    sss,
//}c;
//int main()
//{
//    printf("%zd", sizeof(c));
//}


//struct S3
//{
//    double d;
//    char c;
//    int i;
//};
//struct S4
//{
//    char c1;
//    struct S3 s3;
//    double d;
//};
//int main()
//{
//    printf("%zd", sizeof(struct S4));
//    return 0;
//}
////��ϰ2 
//struct S2
//{
//    char c1;
//    char c2;
//    int i;
//};
//printf("%d\n", sizeof(struct S2));
////��ϰ3 
//
//printf("%d\n", sizeof(struct S3));
////��ϰ4-�ṹ��Ƕ������ 

//printf("%d\n", sizeof(struct S4));

//void print(struct st ps)
//{
//    printf("%d %c", ps.a, ps.b);
//}
//int main()
//{
//    struct st s = { 10,'b' };//��ʼ��
//    print(s);
//    return 0;
//}