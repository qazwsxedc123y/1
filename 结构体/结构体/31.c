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


//������ݵ���һ�ַ���
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


//�������  ���ӡ

//struct s
//{
//	char a;
//	int c;
//	double d;
//};
/*void f(int c)
{
	c = 5;
}*///ʵ�����β���&��ͬһ��ַ�ſ����޸�
//void init(struct s* p)//�ṹ��ָ�����
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
//}//���Ϊ�˰�ȫ ֻ��ӡ ���޸�  ���Լ�һ��const
//int main()
//{
//	struct s a;
//	init(&a);
//	print(a);
//	print2(&a);
//	//print2�ȽϺã���Ϊ2ֻռ4/8���ֽ��Ǹ���ַ
//	//���ṹ����ڴ�ᵼ�������½�
//	
//	//int a = 0.;
//	//f(&a);
//	//a.a = 'w';
//	//a.c = 5;
//	//a.d = 3.14;
//	return 0;
//}


//����ṹ��Ĵ�С

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


//���ʹ��  offsetof
//��Ҫ����ͷ�ļ�  stddef.h
//���ò鿴���������ڵ�ƫ����
//��һ��Ϊ�����������Ǳ�������
//�ڶ����ǳ�Ա��

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

