#define  _CRT_SECURE_NO_WARNINGS
extern int row;//����
extern int col;//����
extern int mine_num;//��ĸ���
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

void Initboard(char** board, char set);

void Displaymine(char** board);//Ҫ��������������

void Setmine(char** board);

void Findmine(char** board, char** show);

void digui(char** board, char** show, int x, int y, int* count);