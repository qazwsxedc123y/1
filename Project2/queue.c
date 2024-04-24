#define  _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//先进先出
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* new_QNode=(QNode*)malloc(sizeof(QNode));
	if (new_QNode == NULL)
	{
		perror("QueuePush malloc fail");
		return;
	}
	new_QNode->_data = data;
	new_QNode->_next = NULL;
	if (q->_front==NULL)//第一次
	{
		q->_front = new_QNode;
		q->_rear = new_QNode;
	}
	else//有头了
	{
		q->_rear->_next = new_QNode;
		q->_rear = new_QNode;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	//换头，与去头
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* second = q->_front->_next;
		QNode* first = q->_front;
		free(first);
		q->_front = second;
	}
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}
int QueueSize(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return 0;
	}
	QNode* cur = q->_front;
	int count = 1;
	while (cur != q->_rear)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (!QueueEmpty(q))
	{
		QNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	q->_front = q->_rear = NULL;
}
void test(Queue* q)
{
	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	printf("大小为：%d\n", QueueSize(q));
	printf("队尾为：");
	printf("%d\n", QueueBack(q));
	while (!QueueEmpty(q))
	{
		printf("%d ", QueueFront(q));
		QueuePop(q);
	}
	QueueDestroy(q);
}

int main()
{
	Queue Qu;
	test(&Qu);
	return 0;
}