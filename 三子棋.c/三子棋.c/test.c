#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"

void meun()
{
	printf("************************\n");
	printf("****1. play 0. exit*****\n");
	printf("************************\n");
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |    


void game()
{
	char ret = 0;
	//���������̵���Ϣ
	char board[ROW][COL] = { 0 };
	//���̵ĳ�ʼ��
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
        //��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else if(ret == 'Q')
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));//��ʱ�������srand
	do
	{
		meun();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������,���ٴ�����:<\n");
			break;
		}
	} while (input);

}
int main()
{
	test();
	return 0;
}