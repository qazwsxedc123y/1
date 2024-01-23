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
//		printf("请输入数字\n");
//		scanf("%d", &guess);
//		if (r == guess)
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//		else if (guess > r)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜小了\n");
//		}
//		n--;
//		if (n == 0)
//		{
//			printf("很遗憾，失败了\n");
//			break;
//		}
//		printf("还剩下%d次\n", n);
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do{
//		menu();
//		printf("请输入，是否玩：>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏结束，退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请从新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}