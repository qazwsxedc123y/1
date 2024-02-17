#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//初始化
void InitBoard(char** board, char set)
{
	int i = 0;
	int j = 0;
	//初始化
	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			board[i][j] = set;
		}
	}
}
//打印棋盘
void DisplayBoard(char** board)
{
	printf("   ");//考虑到y轴占两格
	for (int j = 0; j < col; j++)//打印x轴坐标
	{
		printf(" %d  ", j + 1);
	}
	printf("\n");
	printf("  |");
	for (int j = 0; j < col; j++)//打印棋盘封顶
	{
		printf("---|");
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (j == 0)
			{
				printf("%2d|", i);//顺带打印y轴坐标
			}
			else
				printf(" %c |", board[i][j]);//打印数据
		}
		printf("\n");
		for (int j = 1; j <= col + 1; j++)//注意col应该+1，因为j==1的情况
		{
			if (j == 1)
				printf("  |");
			else
				printf("---|");
		}
		printf("\n");
	}
}
//设置雷
void SetMine(char** mine)
{

	int count = mine_num;//雷的个数
	while (count)
	{
		//生产随机的下标
		int x = rand() % row + 1;//范围是1~row
		int y = rand() % col + 1;//范围是1~col
		if (mine[x][y] == '0')//避免重复设置雷
		{
			mine[x][y] = '1';//设置为雷
			count--;
		}
	}
}
//标记雷
void SignMine(char** show)
{
	while (1)
	{
		int input = 0;
		printf("-----------------------\n");
		printf("******你想标记地雷吗****\n");
		printf("*****  1.标记    *******\n");
		printf("*****  0.不标记  *******\n");
		printf("-----------------------\n");
		scanf("%d", &input);
		if (0 == input)
		{
			break;
			//不想标记就退出循环
		}
		else
		{
			int x = 0;
			int y = 0;
			printf("请输入你想标记的坐标: ");
			scanf("%d %d", &x, &y);
			//坐标合法性检验
			if (x >= 1 && x <= col && y >= 1 && y <= row)
			{
				show[x][y] = '@';//标记你认为的雷的位置为@
				DisplayBoard(show);//显示标记的结果
			}
			else
			{
				printf("非法的坐标,请重新标记\n");
			}

		}
	}
}

//获取雷的个数
int get_mine_count(char** mine, int x, int y)
{
	//将字符转化为类的个数
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
//递归展开一片
void board(char** mine, char** show, int x, int y)
{
	//判断坐标是否越界
	if (x >= 1 && x <= col && y >= 1 && y <= row)
	{
		//判断是否已经被排除
		if (show[x][y] != '*' && show[x][y] != '@')
		{
			return;
		}
		int count = get_mine_count(mine, x, y);//周围雷的个数
		if (count > 0)
		{
			show[x][y] = count + '0';//数字再转换为字符
			return;
		}
		//递归拓展地图
		else if (count == 0)
		{
			show[x][y] = '0';
			board(mine, show, x - 1, y);
			board(mine, show, x - 1, y - 1);
			board(mine, show, x, y - 1);
			board(mine, show, x + 1, y - 1);
			board(mine, show, x + 1, y);
			board(mine, show, x + 1, y + 1);
			board(mine, show, x, y + 1);
			board(mine, show, x - 1, y + 1);
		}
	}
}
//排查雷
int FindMine(char** mine, char** show)
{
	//1.输入排查雷的坐标
	//2.检查该坐标是不是雷
	//（1）是雷    --> 很遗憾炸死了
	//（0）不是雷  --> 统计坐标周围有几个雷-->存储排查雷的信息到show数组，游戏继续
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - mine_num)//还没排查完就进入循环
	{
		SignMine(show);//标记雷
		printf("请输入要排查的坐标： ");
		scanf("%d %d", &x, &y);//x的范围是1～9，y的范围是1～9
		//判断坐标的合法性
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine);//把怎么被炸死的显现出来
				break;
			}
			else
			{
				//不是雷的话统计(x,y)坐标周围有几个雷
				board(mine, show, x, y);
				//显示排查出的信息
				DisplayBoard(show);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col - mine_num)//全部都排查完了
	{

		printf("恭喜你，排雷成功!\n");
		return 1;

	}
	return 0;
}