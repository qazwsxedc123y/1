#define  _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define counts 10
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

void Displaymine(char board[ROWS][COLS], int row, int col);//要避免与宏的名字重

void Setmine(char board[ROWS][COLS], int row, int col);

void Findmine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);

void digui(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);