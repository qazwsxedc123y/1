#define  _CRT_SECURE_NO_WARNINGS

#include"SLListNode.h"

int main()
{
	//初始化链表
	DL* DLList =DLListInit();
	//因为带哨兵位，不需要修改头节点，修改的是头节点指向的结构体的内容
	//传值就行，传的是DLList这个指针存的地址
//	SLPushBack(DLList,8);
	SLPushFront(&DLList,5);
	SLPushFront(&DLList,6);
//	SLPushBack(&DLList,7);
	SLprint(DLList);
	return 0;
}