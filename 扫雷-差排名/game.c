#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //��ɫ����
	//ע��SetConsoleTextAttribute��һ��API��Ӧ�ó����̽ӿڣ�
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
	color(7); //��ɫ����Ϊ��ɫ
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

void help_flag(char** board, int x, int y,int* n)
{
	color(9);//����ɫ
	if ((*n) == 0)
	{
		printf("���ź������Ѿ�û����ʾ������\n");
	}
	(*n)--;
	if (board[x][y] == '1')
	{
		printf("��ϲ���Ƕ��ˣ��������Ϊ��\n");
		printf("�㻹ʣ��%d����ʾ����\n",*n);
	}
	else
	{
		printf("���ź��������겻Ϊ�ף��㻹ʣ��%d����ʾ����\n", *n);
	}
	color(7);
}

void set_flag(char** show, char** board, int* p, int* p1, int* p2)
{
	color(6);
	//��Ʊ���ǵĵط���Ϊ��@��
	int x;
	int y;
	//if (*p == mine_num)
	printf("%d \n", *p);
	if (*p == mine_num)
	{
		printf("�Ѿ��ﵽ������ֵ\n");
		return;//�ﵽ�������
	}
	while (1)
	{
		printf("��������Ҫ��ǵ�����\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (show[x][y] == '*')//û�б��Ų������Ҳû�б���ǹ�
			{
				*p1 = x;
				*p2 = y;
				show[x][y] = '@';
				(*p)++;
				break;
			}
			else if (show[x][y] != '@' && show[x][y] != '*')
			{
				printf("��Ǹ����������ɨ����������ף��������������n");
				continue;
			}
			else
			{
				printf("��Ǹ���������Ѿ�����ǹ�,�������������\n");
				continue;
			}
		}
		else {
			printf("����Ƿ�������������µ�����\n");
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
		printf("Ŀǰû�б�ǣ��޷�����ȡ�����\n");
		return;
	}
	while (1)
	{
		printf("��������Ҫȡ����ǵ�����\n");
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
				printf("�����겻Ϊ������꣬�����������µ�����,\n��������ȷ�ı������\n");
				continue;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
			continue;
		}
	}
	color(7);
}

void nume3()
{
	color(6);
	printf("--------�Ƿ���Ҫ���---------\n");
	printf("********   1.  ���    ******\n");
	printf("******** 2.ȡ�������Ϣ******\n");
	printf("********   else. ext   ******\n");
	printf("****** �������֤��ǻ��� ****\n");
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
				printf("�Ƿ���Ҫ��ʾ�������Ƿ�Ϊ�ף�Y/N\n");
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
			printf("�Ƿ�Ҫ���б�ǣ�Y/N\n");
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				system("cls");
				goto again;
			}
		}
		//system("cls");
		Displaymine(show);
		printf("--------ɨ��---------\n");
		printf("������Ҫ���ҵ�����:\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)//�������
		{
			if (board[x][y] == '0')//��һ�β���
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
					printf("�������Ѿ����ҹ��ˣ����ڴ����������꣺\n");
					color(7);
				}
			}
			else
			{
				system("cls");
				color(6);
				printf("���ź����㱻��ը����\n");
				color(7);
				Displaymine(board);
				break;
			}
		}
		else
		{
			color(6);
			printf("��������겻���������������µ����꣺\n");
			color(7);
		}
		if (count == row * col - mine_num)
		{
			system("cls");
			color(6);
			printf("��ϲ�㣬��ʤ��\n");
			color(7);
			Displaymine(board);
		}
	}
}