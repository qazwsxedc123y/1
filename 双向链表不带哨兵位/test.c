#define  _CRT_SECURE_NO_WARNINGS

#include"DLList.h"

int main()
{
	DL* DLList = NULL;
	DLPushFront(&DLList, 6);
	DLPushFront(&DLList, 5);
	DLPushBack(&DLList, 7);
	DLPushBack(&DLList, 8);
	DLprint(DLList);

	DLPopFront(&DLList);
	DLprint(DLList);

	DLPopBack(&DLList);
	DLprint(DLList);

	DLPushBack(&DLList, 10);
	DLPushBack(&DLList, 11);
	DLprint(DLList);

	DL* pos= DListFind(DLList, 10);
	DLEarse(&DLList, pos);
	DLprint(DLList);

	pos = DListFind(DLList, 7);
	DLInsertBack(&DLList, pos, 12);//����λ�ú��
	DLprint(DLList);

	DLInsertFront(&DLList, pos, 13);//����λ��ǰ��
	DLprint(DLList);

	pos = DListFind(DLList, 6);
	Modify(&DLList,pos,20);
	DLprint(DLList);

	//�ͷ�����
	DListDestory(&DLList);
	return 0;
}