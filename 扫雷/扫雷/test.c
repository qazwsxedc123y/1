#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
    printf("***************************\n");
    printf("******1. play 0. exit******\n");
    printf("***************************\n");
}
void game()
{ 
    //1. �ź�����
    //2. ��ʼ��
    //3. �׵���Ϣ
    char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
    char show[ROWS][COLS] = { 0 };//�Ų�������׵���Ϣ
    //��ʼ��
    InitBoard(mine, ROWS, COLS,'0');
    InitBoard(show, ROWS, COLS,'*');
    //��ӡ����
    //DisplayBoard(mine, ROW, COL);
    printf("\n");
    DisplayBoard(show, ROW, COL);
    printf("\n");
    //����
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    //ɨ��
    FindMine(mine,show, ROW, COL);
}
void test()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do {
        menu();
        printf("��ѡ��:< ");
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
            printf("�����������������\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}
