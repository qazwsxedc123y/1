#define  _CRT_SECURE_NO_WARNINGS


#include"game.h"

void menu()
{
	printf("********************\n");
	printf("****  1 . play  ****\n");
	printf("****  0 . exit  ****\n");
	printf("********************\n");
}
void difficulty()
{
	int input = 0;
	do {
		printf("��ѡ��ɨ�׵��Ѷ�\n");
		printf("********************\n");
		printf("***    1. essy   ***\n");
		printf("***    2. mid    ***\n");
		printf("***    3. hard   ***\n");
		printf("********************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
#define ROW 9
#define COL 9
#define counts 10
			break;
		case 2:
#define ROW 16
#define COL 16
#define counts 30
			break;
		case 3:
#define ROW30
#define COL 16
#define counts 99
			break;
		default:  
			printf("������������������Ѷ�ѡ��\n");
			break;
		}
	} while (input!=1&&input!=2&&input!=3);
}
void game()
{
	difficulty();
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