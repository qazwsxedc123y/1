#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"

void Initboard(char** board ,char set)
{
	int i = 0;
	for (i = 0; i < row+2; i++)
	{
		int j = 0;
		for (j = 0; j < col+2; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displaymine(char** board)
{
	int i = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%-3d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 1;
		printf("%-3d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%-3c ", board[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char** board)
{
	int count = mine_num;
	//生成十个雷
	int x = 0;//行
	int y = 0;//列
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

int Countmine(char** board, int x, int y)
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

void digui(char** board, char** show, int x, int y, int* count)
{
	if (x >= 1 && x <= col && y >= 1 && y <= row)
	{
		int ret = Countmine(board, x, y);
		(*count)++;
		if (ret > 0)
		{
			show[x][y] = ret + '0';
			return;
		}
		else //四周没雷，进入递归展开
		{
			show[x][y] = ' ';//四周没雷的改为 空格  ' '
			int i = 0;
		//	向四周共8个位置递归
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{

					//只对 '*' 进行展开，防止死循环
					if (show[i][j] == '*')
					{
						digui(board, show, i, j, count);
					}

				}
			}
		}
	}
}

//void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
//{
//
//	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //限制在棋盘内展开，防止越界
//	{
//		int count = Countmine(mine, x, y);//获取雷数
//
//		if (count == 0) //四周没雷，进入递归展开
//		{
//			show[x][y] = ' ';//四周没雷的改为 空格  ' '
//
//
//			int i = 0;
//		//	向四周共8个位置递归
//			for (i = x - 1; i <= x + 1; i++)
//			{
//				int j = 0;
//				for (j = y - 1; j <= y + 1; j++)
//				{
//
//					//只对 '*' 进行展开，防止死循环
//					if (show[i][j] == '*')
//					{
//						expand(mine, show, i, j, win);
//					}
//
//				}
//			}
//		}
//		else   //四周有雷显示雷数
//		{
//			show[x][y] = count + '0';
//		}
//
//		//记录展开的数量
//		(*win)++;
//	}
//}

void Findmine(char** board, char** show)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < row * col - mine_num)
	{
		printf("请输入要查找的坐标:\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)//坐标合理
		{
			if (board[x][y] == '0')//第一次查找
			{ 
				if (show[x][y] == '*')
				{

				//	expand(board, show, x, y, &count);
					digui(board, show, x, y, &count);
					printf("%d\n", count);
					Displaymine(show);
				}
				else
				{
					printf("该坐标已经查找过了，请在次输入新坐标：\n");
				}
				//if (show[x][y] == '*')//第一次查找
				//{
				//	int ret = Countmine(board, x, y);//查看附近有几个雷
				//	show[x][y] = ret + '0';
				//	//再次打印棋盘
				//	Displaymine(show, ROW, COL);
				//	count++;
				//}
				//else
				//{
				//	printf("该坐标已经查找过了，请在次输入新坐标：\n");
				//}
			}
			else
			{
				printf("很遗憾，你被雷炸死了\n");
				Displaymine(board);
				break;
			}
		}
		else
		{
			printf("输入的坐标不合理，请重新输入新的坐标：\n");
		}
		if (count == row * col - mine_num)
		{
			printf("恭喜你，获胜了\n");
			Displaymine(board);
		}
	}
}