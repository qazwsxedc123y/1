#define  _CRT_SECURE_NO_WARNINGS


#include"game.h"

void menu()
{
	printf("********************\n");
	printf("****  1 . play  ****\n");
	printf("****  0 . exit  ****\n");
	printf("********************\n");
}
void difficulty()
{
	int input = 0;
	do {
		printf("请选择扫雷的难度\n");
		printf("********************\n");
		printf("***    1. essy   ***\n");
		printf("***    2. mid    ***\n");
		printf("***    3. hard   ***\n");
		printf("********************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
#define ROW 9
#define COL 9
#define counts 10
			break;
		case 2:
#define ROW 16
#define COL 16
#define counts 30
			break;
		case 3:
#define ROW30
#define COL 16
#define counts 99
			break;
		default:  
			printf("输入错误，请重新输入难度选择\n");
			break;
		}
	} while (input!=1&&input!=2&&input!=3);
}
void game()
{
	difficulty();
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