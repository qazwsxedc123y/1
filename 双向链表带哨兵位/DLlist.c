#define  _CRT_SECURE_NO_WARNINGS

#include"DLlist.h"

DL* BuyDLNode()
{
	DL* newcode = (DL*)malloc(sizeof(DL));
	return newcode;//返回的是这个指针存的地址
}

DL* DLListInit()
{
	DL* newcode = BuyDLNode();//存的是malloc开辟空间的地址
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

DL* SLFind(DL* pphead, SLdatatype x)
{
	assert(pphead);
	DL* tail = pphead->next;
	while (tail->val != x)
	{
		tail = tail->next;
		if (tail == pphead)
		{
			printf("该链表内不存在该数据\n");
			return NULL;
		}
	}
	return tail;
}

void SLInsertBack(DL* pphead, DL* pos, SLdatatype x)
{
	assert(pphead);
	assert(pos);
	DL* tail = pphead->next;
	while (tail != pos)//tail找到对应的节点   后插
	{
		tail = tail->next;
	}
	DL* newcode = BuyDLNode();
	newcode->val = x;
	newcode->next = tail->next;
	newcode->prev = tail;
	DL* Back = tail->next;
	Back->prev = newcode;
	tail->next = newcode;
}

void SLInsertFront(DL* pphead, DL* pos, SLdatatype x)
{
	assert(pphead);
	assert(pos);
	DL* tail = pphead->next;
	while (tail != pos)//tail找到对应的节点   前插
	{
		tail = tail->next;
	}
	DL* newcode = BuyDLNode();
	newcode->val = x;
	newcode->next = tail;
	newcode->prev = tail->prev;
	DL* Front = tail->prev;
	Front->next = newcode;
	tail->prev = newcode;
}

void SLErase(DL* pphead, DL* pos)
{
	assert(pphead);
	assert(pos);
	DL* tail = pphead->next;
	while (tail != pos)//tail找到对应的节点  要删除的节点
	{
		tail = tail->next;
	}
	DL* Front = tail->prev;
	DL* Back = tail->next;
	free(tail);
	Front->next = Back;
	Back->prev = Front;
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

void DListDestory(DL* pphead)
{
	assert(pphead);
	DL* tail = pphead->next;
	while (tail != pphead)
	{
		//先保存
		DL* tmp = tail->next;
		free(tail);
		tail = tmp;
	}
	free(pphead);
}