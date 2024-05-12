#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
	//注：SetConsoleTextAttribute是一个API（应用程序编程接口）
}
void Initboard(char** board, char set)
{
	int i = 0;
	for (i = 0; i < row + 2; i++)
	{
		int j = 0;
		for (j = 0; j < col + 2; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displaymine(char** board)
{
	color(7); //颜色设置为白色
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

void help_flag(char** board, int x, int y,int* n)
{
	color(9);//深蓝色
	if ((*n) == 0)
	{
		printf("很遗憾，你已经没有提示机会了\n");
	}
	(*n)--;
	if (board[x][y] == '1')
	{
		printf("恭喜你标记对了，该坐标就为雷\n");
		printf("你还剩余%d次提示机会\n",*n);
	}
	else
	{
		printf("很遗憾，该坐标不为雷，你还剩余%d次提示机会\n", *n);
	}
	color(7);
}

void set_flag(char** show, char** board, int* p, int* p1, int* p2)
{
	color(6);
	//设计被标记的地方设为’@‘
	int x;
	int y;
	//if (*p == mine_num)
	printf("%d \n", *p);
	if (*p == mine_num)
	{
		printf("已经达到标记最大值\n");
		return;//达到最大标记量
	}
	while (1)
	{
		printf("请输入需要标记的坐标\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (show[x][y] == '*')//没有被排查过而且也没有被标记过
			{
				*p1 = x;
				*p2 = y;
				show[x][y] = '@';
				(*p)++;
				break;
			}
			else if (show[x][y] != '@' && show[x][y] != '*')
			{
				printf("抱歉，该坐标已扫查过，不是雷，请从新输入坐标n");
				continue;
			}
			else
			{
				printf("抱歉，该坐标已经被标记过,请从新输入坐标\n");
				continue;
			}
		}
		else {
			printf("坐标非法，请从新输入新的坐标\n");
			continue;
		}
	}
	color(7);
}


void cancle_flag(char** show, int* p)
{
	color(6);
	int x = 0;
	int y = 0;
	if ((*p) == 0)
	{
		printf("目前没有标记，无法进行取消标记\n");
		return;
	}
	while (1)
	{
		printf("请输入需要取消标记的坐标\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (show[x][y] == '@')
			{
				show[x][y] = '*';
				(*p)--;
				break;
			}
			else if (show[x][y] != '@')
			{
				printf("该坐标不为标记坐标，请重新输入新的坐标,\n请输入正确的标记坐标\n");
				continue;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			continue;
		}
	}
	color(7);
}

void nume3()
{
	color(6);
	printf("--------是否需要标记---------\n");
	printf("********   1.  标记    ******\n");
	printf("******** 2.取消标记信息******\n");
	printf("********   else. ext   ******\n");
	printf("****** 共五次验证标记机会 ****\n");
	printf("******************************\n");
	color(7);
}

void Findmine(char** board, char** show)
{
	int x = 0;
	int y = 0;
	int count = 0;

	int help_count = 5;
	int count_check = 0;
	int* p = &count_check;
	int choice = 0;
	while (count < row * col - mine_num)
	{
	again:
		nume3();
		scanf("%d", &choice);
		if (choice != 1 || choice != 2)
		{
			if (choice == 1)
			{
				int x = 0;
				int y = 0;
				set_flag(show, board, p, &x, &y);
				//system("cls");
				Displaymine(show);
				getchar();
				char ch;
				printf("是否需要提示该坐标是否为雷？Y/N\n");
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
				{
					help_flag(board, x, y, &help_count);
				}
			}
			else if (choice == 2)
			{
				system("cls");
				Displaymine(show);
				cancle_flag(show, p);
				//system("cls");
				Displaymine(show);
			}
			getchar();
			char ch;
			printf("是否还要进行标记？Y/N\n");
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				system("cls");
				goto again;
			}
		}
		//system("cls");
		Displaymine(show);
		printf("--------扫雷---------\n");
		printf("请输入要查找的坐标:\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)//坐标合理
		{
			if (board[x][y] == '0')//第一次查找
			{
				if (show[x][y] == '*' || show[x][y] == '@')
				{
					if (show[x][y] == '@')
					{
						(*p)--;
					}
					digui(board, show, x, y, &count);
					system("cls");
					Displaymine(show);
				}
				else
				{
					color(6);
					printf("该坐标已经查找过了，请在次输入新坐标：\n");
					color(7);
				}
			}
			else
			{
				system("cls");
				color(6);
				printf("很遗憾，你被雷炸死了\n");
				color(7);
				Displaymine(board);
				break;
			}
		}
		else
		{
			color(6);
			printf("输入的坐标不合理，请重新输入新的坐标：\n");
			color(7);
		}
		if (count == row * col - mine_num)
		{
			system("cls");
			color(6);
			printf("恭喜你，获胜了\n");
			color(7);
			Displaymine(board);
		}
	}
}