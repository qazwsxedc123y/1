#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//
//void menu()
//{
//	printf("****************\n");
//	printf("*** 1. play  ***\n");
//	printf("*** 0. exit  ***\n");
//	printf("****************\n");
//
//}
//void game()
//{
//	int r = rand() % 100 + 1;
//	int guess,n=5;
//	while (1)
//	{
//		printf("����������\n");
//		scanf("%d", &guess);
//		if (r == guess)
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//		else if (guess > r)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("��С��\n");
//		}
//		n--;
//		if (n == 0)
//		{
//			printf("���ź���ʧ����\n");
//			break;
//		}
//		printf("��ʣ��%d��\n", n);
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do{
//		menu();
//		printf("�����룬�Ƿ��棺>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("��Ϸ�������˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ����������ѡ��\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}