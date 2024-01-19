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
    //1. 排好棋盘
    //2. 初始化
    //3. 雷的信息
    char mine[ROWS][COLS] = { 0 };//存放雷的信息
    char show[ROWS][COLS] = { 0 };//排查出来的雷的信息
    //初始化
    InitBoard(mine, ROWS, COLS,'0');
    InitBoard(show, ROWS, COLS,'*');
    //打印棋盘
    //DisplayBoard(mine, ROW, COL);
    printf("\n");
    DisplayBoard(show, ROW, COL);
    printf("\n");
    //布雷
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    //扫雷
    FindMine(mine,show, ROW, COL);
}
void test()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do {
        menu();
        printf("请选择:< ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}
