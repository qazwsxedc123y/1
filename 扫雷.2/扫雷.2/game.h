#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//全局变量
extern int row;//行数
extern int col;//列数
extern int mine_num;//类的个数

//定义了一个Rank结构体
typedef struct Rank
{
	char name[20];//用户名
	int time;//时间(代表游戏的成绩)
}Rank;

//初始化棋盘
void InitBoard(char** board, char set);
//打印棋盘
void DisplayBoard(char** board);
//布置雷
void SetMine(char** mine);
//标记雷
void SignMine(char** show);
//递归展开一片
void board(char** mine, char** show, int x, int y);
//获取雷的个数
int get_mine_count(char** mine, int x, int y);
//排查雷
int FindMine(char** mine, char** show);//从mine中排查放到show中
//获取排名函数
void Update_Rank(Rank info);