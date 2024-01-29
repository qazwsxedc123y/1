#define  _CRT_SECURE_NO_WARNINGS


#include"game.h"

void menu()
{
	printf("********************\n");
	printf("****  1 . play  ****\n");
	printf("****  0 . exit  ****\n");
	printf("********************\n");
}
void game()
{
	
	char show[ROWS][COLS];
	//展示的棋盘，存放排雷的信息
	char mine[ROWS][COLS];
	//存放雷的信息

	//初始化棋盘 11*11
	Initboard(show,ROWS,COLS,'*');
	
	Initboard(mine,ROWS,COLS,'0');
	//0 不是雷   1是雷
	 
	//打印棋盘信息
	//Displaymine(show,ROW,COL);//9*9
	//Displaymine(mine,ROW,COL);

	//布置雷
	Setmine(mine, ROW, COL);
	Displaymine(show, ROW, COL);
	Displaymine(mine, ROW, COL);

	//扫雷
	Findmine(mine,show, ROW, COL);//传进去两个数组
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("---------扫雷---------\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			break;
		}
	} while (input);
	return 0;
}