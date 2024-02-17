#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//ȫ�ֱ���
extern int row;//����
extern int col;//����
extern int mine_num;//��ĸ���

//������һ��Rank�ṹ��
typedef struct Rank
{
	char name[20];//�û���
	int time;//ʱ��(������Ϸ�ĳɼ�)
}Rank;

//��ʼ������
void InitBoard(char** board, char set);
//��ӡ����
void DisplayBoard(char** board);
//������
void SetMine(char** mine);
//�����
void SignMine(char** show);
//�ݹ�չ��һƬ
void board(char** mine, char** show, int x, int y);
//��ȡ�׵ĸ���
int get_mine_count(char** mine, int x, int y);
//�Ų���
int FindMine(char** mine, char** show);//��mine���Ų�ŵ�show��
//��ȡ��������
void Update_Rank(Rank info);