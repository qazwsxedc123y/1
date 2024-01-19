#define  _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy_count 80

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROWS][COLS], int row, int col,char ret);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_count(char mine[ROWS][COLS], int row, int col);