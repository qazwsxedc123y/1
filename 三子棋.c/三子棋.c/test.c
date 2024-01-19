#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"

void meun()
{
	printf("************************\n");
	printf("****1. play 0. exit*****\n");
	printf("************************\n");
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |    


void game()
{
	char ret = 0;
	//数组存放棋盘的信息
	char board[ROW][COL] = { 0 };
	//棋盘的初始化
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
        //电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else if(ret == 'Q')
	{
		printf("平局\n");
	}
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));//用时间戳定义srand
	do
	{
		meun();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请再次输入:<\n");
			break;
		}
	} while (input);

}
int main()
{
	test();
	return 0;
}