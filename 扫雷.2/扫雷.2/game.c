#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ʼ��
void InitBoard(char** board, char set)
{
	int i = 0;
	int j = 0;
	//��ʼ��
	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			board[i][j] = set;
		}
	}
}
//��ӡ����
void DisplayBoard(char** board)
{
	printf("   ");//���ǵ�y��ռ����
	for (int j = 0; j < col; j++)//��ӡx������
	{
		printf(" %d  ", j + 1);
	}
	printf("\n");
	printf("  |");
	for (int j = 0; j < col; j++)//��ӡ���̷ⶥ
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
				printf("%2d|", i);//˳����ӡy������
			}
			else
				printf(" %c |", board[i][j]);//��ӡ����
		}
		printf("\n");
		for (int j = 1; j <= col + 1; j++)//ע��colӦ��+1����Ϊj==1�����
		{
			if (j == 1)
				printf("  |");
			else
				printf("---|");
		}
		printf("\n");
	}
}
//������
void SetMine(char** mine)
{

	int count = mine_num;//�׵ĸ���
	while (count)
	{
		//����������±�
		int x = rand() % row + 1;//��Χ��1~row
		int y = rand() % col + 1;//��Χ��1~col
		if (mine[x][y] == '0')//�����ظ�������
		{
			mine[x][y] = '1';//����Ϊ��
			count--;
		}
	}
}
//�����
void SignMine(char** show)
{
	while (1)
	{
		int input = 0;
		printf("-----------------------\n");
		printf("******�����ǵ�����****\n");
		printf("*****  1.���    *******\n");
		printf("*****  0.�����  *******\n");
		printf("-----------------------\n");
		scanf("%d", &input);
		if (0 == input)
		{
			break;
			//�����Ǿ��˳�ѭ��
		}
		else
		{
			int x = 0;
			int y = 0;
			printf("�����������ǵ�����: ");
			scanf("%d %d", &x, &y);
			//����Ϸ��Լ���
			if (x >= 1 && x <= col && y >= 1 && y <= row)
			{
				show[x][y] = '@';//�������Ϊ���׵�λ��Ϊ@
				DisplayBoard(show);//��ʾ��ǵĽ��
			}
			else
			{
				printf("�Ƿ�������,�����±��\n");
			}

		}
	}
}

//��ȡ�׵ĸ���
int get_mine_count(char** mine, int x, int y)
{
	//���ַ�ת��Ϊ��ĸ���
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
//�ݹ�չ��һƬ
void board(char** mine, char** show, int x, int y)
{
	//�ж������Ƿ�Խ��
	if (x >= 1 && x <= col && y >= 1 && y <= row)
	{
		//�ж��Ƿ��Ѿ����ų�
		if (show[x][y] != '*' && show[x][y] != '@')
		{
			return;
		}
		int count = get_mine_count(mine, x, y);//��Χ�׵ĸ���
		if (count > 0)
		{
			show[x][y] = count + '0';//������ת��Ϊ�ַ�
			return;
		}
		//�ݹ���չ��ͼ
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
//�Ų���
int FindMine(char** mine, char** show)
{
	//1.�����Ų��׵�����
	//2.���������ǲ�����
	//��1������    --> ���ź�ը����
	//��0��������  --> ͳ��������Χ�м�����-->�洢�Ų��׵���Ϣ��show���飬��Ϸ����
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - mine_num)//��û�Ų���ͽ���ѭ��
	{
		SignMine(show);//�����
		printf("������Ҫ�Ų�����꣺ ");
		scanf("%d %d", &x, &y);//x�ķ�Χ��1��9��y�ķ�Χ��1��9
		//�ж�����ĺϷ���
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine);//����ô��ը�������ֳ���
				break;
			}
			else
			{
				//�����׵Ļ�ͳ��(x,y)������Χ�м�����
				board(mine, show, x, y);
				//��ʾ�Ų������Ϣ
				DisplayBoard(show);
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�������������\n");
		}
	}
	if (win == row * col - mine_num)//ȫ�����Ų�����
	{

		printf("��ϲ�㣬���׳ɹ�!\n");
		return 1;

	}
	return 0;
}