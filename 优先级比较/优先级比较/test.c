#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//+  ��   ++  ��  =   �� ,

int main()
{
	int a, b, c;
	a = 5;
	c = ++a;//a=6, c=6
	b = ++c, c++, ++a, a++;//����=�룬�ȼ���=  ����b��ֵ=++cΪ7,Ȼ����ж��ź�ļ�����ʾ����
//���Ҫʵ�ֶ��ű��ʽ��Ч��Ӧ�ã�
 //   b = (++c, c++, ++a, a++);
	b += a++ + c;
	printf("a =%d b=%d c=%d\n",a, b, c);
	return 0;
}