#define  _CRT_SECURE_NO_WARNINGS

#include"DLlist.h"

int main()
{
	//��ʼ������
	DL* DLList = DLListInit();
	//��Ϊ���ڱ�λ������Ҫ�޸�ͷ�ڵ㣬�޸ĵ���ͷ�ڵ�ָ��Ľṹ�������
	//��ֵ���У�������DLList���ָ���ĵ�ַ
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
	SLInsertBack(DLList,pos,9);//���    5->8->9->7
	SLprint(DLList);
	pos = SLFind(DLList, 8);
	SLInsertFront(DLList, pos, 10);  //ǰ��  5->10->8->9->7
	SLprint(DLList);
	SLErase(DLList,pos);//ɾ��  5->10->9->7
	SLprint(DLList);
	DListDestory(DLList);
	return 0;
}