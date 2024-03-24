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
//初始化
void QueueInit(Queue* ps);
// 队尾入队列 
void QueuePush(Queue* ps, QDataType data);
// 队头出队列 
void QueuePop(Queue* ps);
// 获取队列头部元素 
QDataType QueueFront(Queue* ps);
// 获取队列队尾元素 
QDataType QueueBack(Queue* ps);
// 获取队列中有效元素个数 
int QueueSize(Queue* ps);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* ps);
// 销毁队列 
void QueueDestroy(Queue* ps);