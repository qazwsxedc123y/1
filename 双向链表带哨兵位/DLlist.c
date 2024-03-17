#define  _CRT_SECURE_NO_WARNINGS

#include"DLlist.h"

DL* BuyDLNode()
{
	DL* newcode = (DL*)malloc(sizeof(DL));
	return newcode;//���ص������ָ���ĵ�ַ
}

DL* DLListInit()
{
	DL* newcode = BuyDLNode();//�����malloc���ٿռ�ĵ�ַ
	newcode->val = -1;
	newcode->next = newcode;
	newcode->prev = newcode;
	return newcode;
}

void SLPushFront(DL* pphead, SLdatatype x)
{
	assert(pphead);
	DL* newcode = BuyDLNode();
	newcode->prev = pphead;
	newcode->next = pphead->next;
	newcode->val = x;
	DL* first = pphead->next;
	pphead->next = newcode;
	first->prev = newcode;
}

void SLPushBack(DL* pphead, SLdatatype x)
{
	assert(pphead);
	DL* newcode = BuyDLNode();
	newcode->next = pphead;
	newcode->prev = pphead->prev;
	newcode->val = x;
	DL* end = pphead->prev;
	pphead->prev = newcode;
	end->next = newcode;
}

void SLPopFrpnt(DL* pphead)
{
	assert(pphead);
	DL* first = pphead->next;
	DL* second = pphead->next->next;
	free(first);
	pphead->next = second;
	second->prev = pphead;
}

void SLPopBack(DL* pphead)
{
	assert(pphead);
	DL* end = pphead->prev;
	DL* end_second = pphead->prev->prev;
	free(end);
	pphead->prev = end_second;
	end_second->next = pphead;
}

void SLprint(DL* pphead)
{
	DL* tail = pphead->next;
	printf("Sentinel->");
	while (tail != pphead)
	{
		printf("%d->", tail->val);
		tail = tail->next;
	}
	printf("NULL\n");
}