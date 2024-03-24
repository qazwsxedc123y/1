#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
typedef int QDataType;
typedef struct QListNode
{
	struct QLNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
//��ʼ��
void QueueInit(Queue* ps);
// ��β����� 
void QueuePush(Queue* ps, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* ps);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* ps);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* ps);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* ps);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* ps);
// ���ٶ��� 
void QueueDestroy(Queue* ps);