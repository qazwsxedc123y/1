#define  _CRT_SECURE_NO_WARNINGS


#include"game.h"
int row = 0;//行
int col = 0;//列
int mine_num = 0;//雷的个数
void menu1()
{
	printf("********************\n");
	printf("****  1 . play  ****\n");
	printf("****  0 . exit  ****\n");
	printf("********************\n");
}
void menu2()
{
	printf("***********************\n");
	printf("***   1. esay       ***\n");
	printf("***   2. medium     ***\n");
	printf("***   3. difficulty ***\n");
	printf("***********************\n");
}
void game()
{
	int input = 0;
	do
	{
		menu2();
		scanf("%d", &input);
	
		switch (input)
		{
		case 1:
			row = 9, col = 9, mine_num = 10;
			break;
		case 2:
			row = 16, col = 16, mine_num = 255;
			break;
		case 3:
			row = 30, col = 16, mine_num = 99;
			
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input != 1 && input != 2 && input != 3);
	//创建棋盘
	char** mine = (char**)malloc(sizeof(char*) * (row + 2));
	char** show = (char**)malloc(sizeof(char*) * (row + 2));
	int i = 0;
	for (i = 0; i < col + 2; i++)
	{
		//存放雷的信息
		mine[i] = (char*)malloc(sizeof(char) * (col + 2));
		//展示的棋盘，存放排雷的信息
		show[i] = (char*)malloc(sizeof(char) * (col + 2));
	}

	//初始化棋盘 11*11
	Initboard(show, '*');

	Initboard(mine, '0');
	//0 不是雷   1是雷

	//打印棋盘信息
	Displaymine(show);//9*9
	//Displaymine(mine,ROW,COL);

	//布置雷
	Setmine(mine);
	Displaymine(show);
	//Displaymine(mine);
	//Displaymine(mine, ROW, COL);

	//扫雷
	Findmine(mine, show);//传进去两个数组
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu1();
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
		default:
			break;
		}
	} while (input);
	return 0;
}