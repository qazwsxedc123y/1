#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//�����Ľṹ������

//struct sa//sa Ϊ�ṹ�����֣��������
//{
//	char ar[2];
//	int age;
//};//�ֺ�һ����Ҫ��
//int main()
//{
//	struct sa s1;
//	return 0;
//}

//ȫ����ֲ�������

//struct sa//sa Ϊ�ṹ�����֣��������
//{
//	char ar[2];
//	int age;
//}s2;//s2��ȫ�ֵĶ���ṹ��ı���
//int main()
//{
//	struct sa s1;//s1�Ǿֲ��Ľṹ�����
//	return 0;
//}


//�����Ľṹ��

//������Ҫ��  ֻ����һ��
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
//	pa = &a;//���߲���ͬһ���͵�
//	return 0;
//}


//�ṹ���������

//struct n
//{
//	int a;
//	struct n* next;//4/8�ֽ�
//	//struct n next;����
//	//��Ϊsizeof��struct n���޷�����
//};
//int main()
//{
//
//	return 0;
//}



//typedef  ��ʹ��


//typedef struct node//һ�㲻Ҫʡȥnode
//{
//	int a;
//	//�ǽ�struct node��Ϊe
//}e;
//���Ƕ�������
//typedef struct
//{
//	int a;
//	struct e* next;//����  �ͻ����������������e��������next
//	//Ҫд��struct e  ����дһ��e
//}e;//���м��������е�
//int main()
//{
//	return 0;
//}


//�ṹ��Ĵ�ӡ

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
//	printf("%c %c %d\n", c.a, c.b, c.c);//��ӡ
//
//	struct s2 a = { 'a','c',{'a','c',10},10 };
//	printf("%d", a.t.a);//��ӡ����a
//
//
//	return 0;
//}


//����ṹ��Ĵ�С

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
//  �ṩ���� 



//Ĭ�϶��������޸�

//#pragma pack(4)//����Ĭ�϶�����Ϊ4  ��СΪ12
////#pragma pack()//ȡ��Ĭ�϶�����
////Ĭ�϶�����Ϊ1�Ļ������С����9
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