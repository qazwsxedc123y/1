#define  _CRT_SECURE_NO_WARNINGS
extern int row;//行数
extern int col;//列数
extern int mine_num;//类的个数
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

void Initboard(char** board, char set);

void Displaymine(char** board);//要避免与宏的名字重

void Setmine(char** board);

void Findmine(char** board, char** show);

void digui(char** board, char** show, int x, int y, int* count);