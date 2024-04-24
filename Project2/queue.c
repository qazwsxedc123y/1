#define  _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//�Ƚ��ȳ�
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
	if (q->_front==NULL)//��һ��
	{
		q->_front = new_QNode;
		q->_rear = new_QNode;
	}
	else//��ͷ��
	{
		q->_rear->_next = new_QNode;
		q->_rear = new_QNode;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	//��ͷ����ȥͷ
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
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
	printf("��СΪ��%d\n", QueueSize(q));
	printf("��βΪ��");
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