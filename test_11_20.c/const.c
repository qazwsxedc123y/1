#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//standard library  ��׼��  ��Ӧsystem
#include<windows.h>//������Ҫ����Ҫͷ�ļ�
#include<math.h>
#include<time.h>
#include<assert.h>

//�ؼ���const�������峣�������һ��������const���Σ���ô����ֵ�Ͳ����ٱ��ı�
//int main()
//{
//	const int n = 10;
//	int m = 100;
//	const int*  p = &n;//const����*���ʱ�����ε���*p  Ҳ���ǲ���ͨ���ı�p���޸�*p��num����ֵ
//	 //int* const p  ����* ���ұ����ε���p  �����޸�p����ĵ�ַ  p=&m; �Ͳ�������
//	// Ҳ����const int* const  p = &n;  �����������Ը�
//	*p = 20;
//	printf("%d", n);
//	return 0;
//}