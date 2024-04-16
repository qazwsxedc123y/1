#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include <locale.h>

typedef struct SnackNode
{
	int x;
	int y;
	//指向下一个结点
	struct snack* next;
}SnackNode,*pSnackNode;

//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT,
};

//蛇的状态
enum GAME_STATUS
{
	ok,//正常
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_OK,
};

typedef struct Snack
{
	//蛇的头
	pSnackNode* _psnack;
	pSnackNode* _pfood;
	enum DIRECTION _dir;
	enum GAME_STATUS _status;
	int _food_weight;//一个食物的分数
	int _sum_score;//总成绩
	int _sleep_time;//蛇的速度，越小越快
}Snack,*pSnack;

void GameStart(pSnack ps);
void Welcome_game();
void CreatMap();