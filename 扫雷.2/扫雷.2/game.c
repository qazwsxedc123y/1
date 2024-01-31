#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displaymine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 1;
		printf("%2d", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = counts;
	//生成十个雷
	int x=0;//行
	int y=0;//列
	while (count)//利用坐标布置雷
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int Countmine(char board[ROWS][COLS], int x, int y)
{
	int i = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			count += board[i][j] - '0';
		}
	}
	return count;
}

void Findmine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count<row*col-counts)
	{
		printf("请输入要查找的坐标:\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= 9 && y > 0 && y <= 9)
		{//坐标合理
			if (board[x][y] == '0')//第一次查找
			{
				if(show[x][y]=='*')
				{
					int ret = Countmine(board, x, y);//查看附近有几个雷
					show[x][y] = ret + '0';
					//再次打印棋盘
					Displaymine(show, ROW, COL);
					count++;
				}
			    else
			    {
				printf("该坐标已经查找过了，请在次输入新坐标：\n");
			    }
			}
			else
			{
				printf("很遗憾，你被雷炸死了\n");
				Displaymine(board, ROW, COL);
				break;
			}
		}
		else
		{
			printf("输入的坐标不合理，请重新输入新的坐标：\n");
		}
		if (count == row * col - counts)
		{
			printf("恭喜你，获胜了\n");
			Displaymine(board, ROW, COL);
		}
	}
}
