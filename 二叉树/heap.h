#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<errno.h>
#include<time.h>
#include<stdbool.h>


//二叉树
typedef int BTDataType;
typedef struct BTNode
{
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

//队列
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

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);

// 二叉树销毁   是返回0，不是返回1
void BinaryTreeDestory(BTNode* root);



//初始化
void QueueInit(Queue* ps);
// 队尾入队列 
void QueuePush(Queue* ps, QDataType data);
// 队头出队列 
void QueuePop(Queue* ps);
// 获取队列头部元素 
QDataType QueueFront(Queue* ps);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* ps);
// 销毁队列 
void QueueDestroy(Queue* ps);