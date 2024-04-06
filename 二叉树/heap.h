#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<errno.h>
#include<time.h>
#include<stdbool.h>


//������
typedef int BTDataType;
typedef struct BTNode
{
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

//����
typedef BTNode* QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;


BTNode* BuyNode(BTDataType x);

void Prev_Order(BTNode* root);
void In_Order(BTNode* root);
void Post_Order(BTNode* root);
void Lever_Order(BTNode* root);

int BT_Size(BTNode* root);

int BT_Leaf_Size(BTNode* root);

int BT_Depth_Size(BTNode* root);

int BT_Size_Levre_k(BTNode* root, int k);

BTNode* BTFind_Data_k(BTNode* root,int k);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);

// ����������   �Ƿ���0�����Ƿ���1
void BinaryTreeDestory(BTNode* root);



//��ʼ��
void QueueInit(Queue* ps);
// ��β����� 
void QueuePush(Queue* ps, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* ps);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* ps);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* ps);
// ���ٶ��� 
void QueueDestroy(Queue* ps);