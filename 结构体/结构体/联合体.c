#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//����-������-������
//union s
//{
//	char a;
//	int c;
//	double d;
//};
//int main()
//{
//	union s c;
//	printf("%d", sizeof(c));//8  ��С����������Ա�Ĵ�С
//	//�����������Ա����һ���ռ�
//	//���Բ���ͬʱʹ�ã�ֻ��ʹ������һ��
//
//	printf("%p\n", &c);//�ĸ�ֵһ��
//	printf("%p\n", &(c.a));
//	printf("%p\n", &(c.c));
//	printf("%p\n", &(c.d));
//	return 0;
//}

//�жϴ�С��
//��ͨд��

//int sys()
//{
//	int i = 1;
//	return *(char*)&i;
//}
//int main()
//{
//	int ret=sys();
//	if (ret == 1)
//	{
//		printf("���\n");
//	}
//	else
//	{
//		printf("С��\n");
//	}
//	return 0;
//}


//������д��

//int sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int ret = sys();
//	if (ret == 1)
//	{
//		printf("���\n");
//	}
//	else
//	{
//		printf("С��\n");
//	}
//	return 0;
//}


//����������Ĵ�С
//����Ķ�����Ҫ����Ԫ����
//char arr[5]; ��������1

//1.��С���������Ա�����Ĵ�С
//2.��С���ǲ��ǳ�Ա�����������������ǣ�Ҫ�˷ѿռ��Ϊ��������
//union un
//{
//	int a;//��С��4
//	char arr[5];//��С��5  ->5
//};
////��������
////4 8  ->4
////1 8  ->1   ->4
////5����4�ı���--->8
//int main()
//{
//	union un s;
//	printf("%d", sizeof(s));//8
//	return 0;
//}