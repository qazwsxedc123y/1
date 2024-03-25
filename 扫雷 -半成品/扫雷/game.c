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
	//����ʮ����
	int x = 0;//��
	int y = 0;//��
	while (count)//�������겼����
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
		else //����û�ף�����ݹ�չ��
		{
			show[x][y] = ' ';//����û�׵ĸ�Ϊ �ո�  ' '
			int i = 0;
		//	�����ܹ�8��λ�õݹ�
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{

					//ֻ�� '*' ����չ������ֹ��ѭ��
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
//	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //������������չ������ֹԽ��
//	{
//		int count = Countmine(mine, x, y);//��ȡ����
//
//		if (count == 0) //����û�ף�����ݹ�չ��
//		{
//			show[x][y] = ' ';//����û�׵ĸ�Ϊ �ո�  ' '
//
//
//			int i = 0;
//		//	�����ܹ�8��λ�õݹ�
//			for (i = x - 1; i <= x + 1; i++)
//			{
//				int j = 0;
//				for (j = y - 1; j <= y + 1; j++)
//				{
//
//					//ֻ�� '*' ����չ������ֹ��ѭ��
//					if (show[i][j] == '*')
//					{
//						expand(mine, show, i, j, win);
//					}
//
//				}
//			}
//		}
//		else   //����������ʾ����
//		{
//			show[x][y] = count + '0';
//		}
//
//		//��¼չ��������
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
		printf("������Ҫ���ҵ�����:\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)//�������
		{
			if (board[x][y] == '0')//��һ�β���
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
					printf("�������Ѿ����ҹ��ˣ����ڴ����������꣺\n");
				}
				//if (show[x][y] == '*')//��һ�β���
				//{
				//	int ret = Countmine(board, x, y);//�鿴�����м�����
				//	show[x][y] = ret + '0';
				//	//�ٴδ�ӡ����
				//	Displaymine(show, ROW, COL);
				//	count++;
				//}
				//else
				//{
				//	printf("�������Ѿ����ҹ��ˣ����ڴ����������꣺\n");
				//}
			}
			else
			{
				printf("���ź����㱻��ը����\n");
				Displaymine(board);
				break;
			}
		}
		else
		{
			printf("��������겻���������������µ����꣺\n");
		}
		if (count == row * col - mine_num)
		{
			printf("��ϲ�㣬��ʤ��\n");
			Displaymine(board);
		}
	}
}