#pragma once

#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



#define POS_X 24
#define POS_Y 5

#define WALL L'��'
#define BODY L'��'
#define FOOD L'��'

//���͵�����

//�ߵķ���
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//�ߵ�״̬
//������ײǽ��ײ���Լ��������˳�
enum GAME_STATUS
{
	OK, //����
	KILL_BY_WALL, //ײǽ
	KILL_BY_SELF, //ײ���Լ�
	END_NORMAL //�����˳�
};

//����Ľڵ�����
typedef struct SnakeNode
{
	//����
	int x;
	int y;
	//ָ����һ���ڵ��ָ��
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

//typedef struct SnakeNode* pSnakeNode;


//̰����
typedef struct Snake
{
	pSnakeNode _pSnake;//ָ����ͷ��ָ��
	pSnakeNode _pFood;//ָ��ʳ��ڵ��ָ��
	enum DIRECTION _dir;//�ߵķ���
	enum GAME_STATUS _status;//��Ϸ��״̬
	int _food_weight;//һ��ʳ��ķ���
	int _score;      //�ܳɼ�
	int _sleep_time; //��Ϣʱ�䣬ʱ��Խ�̣��ٶ�Խ�죬ʱ��Խ�����ٶ�Խ��
}Snake, * pSnake;

//����������

//��λ���λ��
void SetPos(short x, short y);

//��Ϸ�ĳ�ʼ��
void GameStart(pSnake ps);

//��ӭ����Ĵ�ӡ
void WelcomeToGame();

//������ͼ
void CreateMap();

//��ʼ������
void InitSnake(pSnake ps);

//����ʳ��
void CreateFood(pSnake ps);

//��Ϸ���е��߼�
void GameRun(pSnake ps);

//�ߵ��ƶ�-��һ��
void SnakeMove(pSnake ps);

//�ж���һ�������Ƿ���ʳ��
int NextIsFood(pSnakeNode pn, pSnake ps);

//��һ��λ����ʳ��ͳԵ�ʳ��
void EatFood(pSnakeNode pn, pSnake ps);

//��һ��λ�ò���ʳ��
void NoFood(pSnakeNode pn, pSnake ps);

//������Ƿ�ײǽ
void KillByWall(pSnake ps);

//������Ƿ�ײ���Լ�
void KillBySelf(pSnake ps);

//��Ϸ�ƺ�Ĺ���
void GameEnd(pSnake ps);