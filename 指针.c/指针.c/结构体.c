#define  _CRT_SECURE_NO_WARNINGS
//�ṹ������ĳ�Ա������ָ�룬���������������������ṹ��
#include<stdio.h>


//typedef��д��

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
//	Stu p1={ "����",17,"12345678978" };
//	print1(p1);
//	print2(&p1);
//	return 0;
//}

//��ͨд��

//struct stu
//{
//	char name[7];
//	short age;
//	char tele[12];
//};
//
//void print1(struct stu pa)//ʵ�δ����βε�ʱ���β���ʵ�ε�һ����ʱ����
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
//	struct stu s = { "����",5,"12345678911" };
//	print1(s);
//	print2(&s);
//	return 0;
//}


// �ڽṹ������Ƕ�׽ṹ��

struct stu  //����  ��ռ�ÿռ�
{
	char name[20];//�ṹ���Ա
	char tele[12];
	char sex[5];
};

struct s
{
	char name[20];
	struct stu stu;
}p1;  //����ṹ�����͵�ͬʱ�������p1

int main()
{
	struct s p2 = { "����",{"����","12345678923","��"} };  //����ṹ�����p2
	printf("%s\n", p2.name);
	printf("%p\n", &p2.stu.name);
	printf("%s\n", p2.stu.tele);
	printf("%s\n", p2.stu.sex);
}

//typedef ��ʹ��

//typedef struct stu  //����  ��ռ�ÿռ�  typedef�ǽ������������������
//{
//	char name[20];
//	short age[5];
//	char tele[12];
//	char sex[5];
//}stu;
//
//int main()
//{
//	struct stu s1;//����һ���ṹ����� 
//	stu s2;
//	return 0;
//}


// struct �ṹ��ؼ���  stu  �ṹ���ǩ  struct stu  �ṹ������

//struct stu  //����  ��ռ�ÿռ�
//{
//	char name[20];//�ṹ���Ա
//	short age[5];
//	char tele[12];
//	char sex[5];
//};
//
//int main()
//{
//	struct stu s;  //����һ���ṹ����� 
//	return 0;
//}