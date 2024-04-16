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
	//ָ����һ�����
	struct snack* next;
}SnackNode,*pSnackNode;

//�ߵķ���
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT,
};

//�ߵ�״̬
enum GAME_STATUS
{
	ok,//����
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_OK,
};

typedef struct Snack
{
	//�ߵ�ͷ
	pSnackNode* _psnack;
	pSnackNode* _pfood;
	enum DIRECTION _dir;
	enum GAME_STATUS _status;
	int _food_weight;//һ��ʳ��ķ���
	int _sum_score;//�ܳɼ�
	int _sleep_time;//�ߵ��ٶȣ�ԽСԽ��
}Snack,*pSnack;

void GameStart(pSnack ps);
void Welcome_game();
void CreatMap();