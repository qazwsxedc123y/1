#define  _CRT_SECURE_NO_WARNINGS


#include"game.h"
int row = 0;//��
int col = 0;//��
int mine_num = 0;//�׵ĸ���
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input != 1 && input != 2 && input != 3);
	//��������
	char** mine = (char**)malloc(sizeof(char*) * (row + 2));
	char** show = (char**)malloc(sizeof(char*) * (row + 2));
	int i = 0;
	for (i = 0; i < col + 2; i++)
	{
		//����׵���Ϣ
		mine[i] = (char*)malloc(sizeof(char) * (col + 2));
		//չʾ�����̣�������׵���Ϣ
		show[i] = (char*)malloc(sizeof(char) * (col + 2));
	}

	//��ʼ������ 11*11
	Initboard(show, '*');

	Initboard(mine, '0');
	//0 ������   1����

	//��ӡ������Ϣ
	Displaymine(show);//9*9
	//Displaymine(mine,ROW,COL);

	//������
	Setmine(mine);
	Displaymine(show);
	//Displaymine(mine);
	//Displaymine(mine, ROW, COL);

	//ɨ��
	Findmine(mine, show);//����ȥ��������
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
			printf("---------ɨ��---------\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}