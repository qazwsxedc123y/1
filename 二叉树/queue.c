#define  _CRT_SECURE_NO_WARNINGS
#include"BTree.h"

//typedef struct QListNode
//{
//	struct QLNode* next;
//	QDataType data;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* phead;
//	QNode* ptail;
//	int size;
//}Queue;
void QueueInit(Queue* ps)
{
	ps->size = 0;
	ps->phead = NULL;
	ps->ptail = NULL;
}
// 队尾入队列 
void QueuePush(Queue* ps, QDataType data)
{
	assert(ps);
	QNode* newcode = (QNode*)malloc(sizeof(QNode));
	if (newcode == NULL)
	{
		perror("malloc error");
		return;
	}
	newcode->next = NULL;
	newcode->data = data;
	if (ps->ptail == NULL)//空--第一次
	{
		assert(ps->phead==NULL);
		ps->phead=ps->ptail=newcode;
	}
	else
	{
		ps->ptail->next = newcode;
		ps->ptail = newcode;
	}
	ps->size++;
}

void QueuePop(Queue* ps)
{
	assert(ps);//没有的话删不了
	assert(!QueueEmpty(ps));	
	if (ps->size==1)
	{
		free(ps->phead);
		ps->phead = ps->ptail = NULL;
	}
	else
	{
		QNode* tmp = ps->phead->next;
		QNode* cur = ps->phead;
		free(cur);
		ps->phead = tmp;
	}
	ps->size--;
}

QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->phead->data;
}

QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->ptail->data;
}

int QueueSize(Queue* ps)
{
	assert(ps);
	return ps->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* ps)
{
	assert(ps);
	return ps->size == 0;
}

void QueueDestroy(Queue* ps)
{
	assert(ps);
	QNode* cur = ps->phead;
	while (!QueueEmpty(ps))
	{
		QNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ps->phead=ps->ptail = NULL;
	ps->size = 0;
}