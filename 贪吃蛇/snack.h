#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include <locale.h>
#include<time.h>

#define Wall L'□'
#define Body L'●'
#define Food L'★'

#define POS_X 24
#define POS_Y 5

//检查某个按键是否被按了
#define KEY_PRESS(VK) ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )

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
	OK,//正常
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

//游戏开始
void GameStart(pSnack ps);

//欢迎界面
void Welcome_game();

//绘制地图
void CreatMap();

//打印提示操作信息
void PrintHelpInfo();

//创建蛇
void CreateSnack(pSnack ps);

//创建食物
void CreateFood(pSnack ps);

//游戏暂停
void Pause();

//游戏正常运行
void GameRun(pSnack ps);

//贪吃蛇的移动
void SnackMove(pSnack ps);


//正常的游戏结束
void GameEend(pSnack ps);