#define  _CRT_SECURE_NO_WARNINGS


#include"game.h"

void menu()
{
	printf("********************\n");
	printf("****  1 . play  ****\n");
	printf("****  0 . exit  ****\n");
	printf("********************\n");
}
void game()
{
	
	char show[ROWS][COLS];
	//չʾ�����̣�������׵���Ϣ
	char mine[ROWS][COLS];
	//����׵���Ϣ

	//��ʼ������ 11*11
	Initboard(show,ROWS,COLS,'*');
	
	Initboard(mine,ROWS,COLS,'0');
	//0 ������   1����
	 
	//��ӡ������Ϣ
	//Displaymine(show,ROW,COL);//9*9
	//Displaymine(mine,ROW,COL);

	//������
	Setmine(mine, ROW, COL);
	Displaymine(show, ROW, COL);
	Displaymine(mine, ROW, COL);

	//ɨ��
	Findmine(mine,show, ROW, COL);//����ȥ��������
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
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
		default :
			break;
		}
	} while (input);
	return 0;
}