#define  _CRT_SECURE_NO_WARNINGS

#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col,char ret)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{
			board[i][j] = ret;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("  ");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i );
	}
	printf("\n");
	for (i=1;i<=row;i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	while (count)
	{		
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}	
}
int  get_mine_count(char mine[ROWS][COLS],  int x, int y)
{
	    return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win< row * col - Easy_count)
	{
		printf("�������Ų��׵�����:>\n");
		scanf("%d%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�Ϸ�
			//1 ����  2 ����
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{//������Χ������
				int count=get_mine_count(mine,x, y);
				show[x][y] = count + '0';
				//ת��Ϊ�ַ�0�����Ǽ�'0' ����0
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("��������Ƿ������������\n");
		}
	}
	if (win == row * col - Easy_count)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}