#define  _CRT_SECURE_NO_WARNINGS

#include"DLlist.h"

int main()
{
	//初始化链表
	DL* DLList = DLListInit();
	//因为带哨兵位，不需要修改头节点，修改的是头节点指向的结构体的内容
	//传值就行，传的是DLList这个指针存的地址
	SLPushBack(DLList,8);
	SLPushFront(DLList, 5);
	SLPushFront(DLList, 6);
	SLPushBack(DLList,7);
	SLprint(DLList);//6->5->8->7

	SLPopFrpnt(DLList);
	SLPopBack(DLList);
	SLPushBack(DLList, 7);
	SLprint(DLList);//5->8->7
	DL* pos=SLFind(DLList,8);
	SLInsertBack(DLList,pos,9);//后插    5->8->9->7
	SLprint(DLList);
	pos = SLFind(DLList, 8);
	SLInsertFront(DLList, pos, 10);  //前插  5->10->8->9->7
	SLprint(DLList);
	SLErase(DLList,pos);//删除  5->10->9->7
	SLprint(DLList);
	DListDestory(DLList);
	return 0;
}