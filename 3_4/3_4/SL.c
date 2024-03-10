#define  _CRT_SECURE_NO_WARNINGS
#include "SL.h"


//void SLPushback(SL** pphead, SLDataType x)
//{
//	SL* newcode = (SL*)malloc(sizeof(SL));
//	if (*pphead == NULL)
//	{
//		newcode->x = x;
//		newcode->next = NULL;
//		*pphead = newcode;
//		return;
//	}
//	SL* tail = *pphead;
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	tail->next = newcode;
//	newcode->x = x;
//	newcode->next = NULL;
//}

void SLPushFront(SL** pphead, SLDataType x)
{
	assert(pphead);
	SL* newcode = (SL*)malloc(sizeof(SL));
	if (newcode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newcode->next = *pphead;
	newcode->x = x;
	*pphead = newcode;
}

void SLPushback(SL** pphead,SLDataType x)
{
	assert(pphead);
	SL* newcode = (SL*)malloc(sizeof(SL));
	if (*pphead == NULL)
	{
		*pphead = newcode;
		(*pphead)->x = x;
		(*pphead)->next = NULL;
		return;
	}
	SL* tail = *pphead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newcode;
	tail = tail->next;
	tail->x = x;
	tail->next = NULL;
}

void SLPopBack(SL** pphead)
{
	assert(pphead);
	assert(*pphead);
	SL* tail = *pphead;
	//一个也没有
	assert(*pphead);
	//一个节点
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//多个节点
	while (tail->next->next != NULL)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}

void SLPopFront(SL** pphead)
{
	assert(pphead);
	assert(*pphead);
	SL* tail = *pphead;
	*pphead = (*pphead)->next;
	free(tail);//tail是SL* tail=&SLList;


	////一个节点
	//if ((*pphead)->next == NULL)
	//{
	//	free(*pphead);
	//	*pphead = NULL;
	//	return;
	//}
	// //多个字节
	//SL* tail = *pphead;
	//*pphead = (*pphead)->next;
	//free(tail);
	////tail = NULL;  不需要，因为本来就在栈区上
}

SL* SLFind(SL* pphead, SLDataType x)
{
	assert(pphead);
	SL* tail = pphead;
	while (tail->x != x)
	{
		tail = tail->next;
	}
	return tail;
}

void SLInsert(SL** pphead, SL* pos, SLDataType x)
{
	assert(pphead);
	assert(pos);
	SL* tail = *pphead;
	SL* newcode = (SL*)malloc(sizeof(SL));
	if (newcode == NULL)
	{
		perror("SLInsert fail");
	}
	while (tail->next != pos)
	{
		tail = tail->next;
	}
	newcode->next = tail->next;
	newcode->x = x;
	tail->next = newcode;
}

void SLInsertBack(SL** pphead, SL* pos, SLDataType x)
{
	assert(pphead);
	assert(pos);
	SL* tail = *pphead;
	SL* newcode = (SL*)malloc(sizeof(SL));
	if (newcode == NULL)
	{
		perror("SLInsertBack fail");
	}
	while (tail != pos)
	{
		tail = tail->next;
	}
	newcode->next = tail->next;
	newcode->x = x;
	tail->next = newcode;
}

void SLErase(SL** pphead, SL* pos)
{
	assert(pphead);
	assert(pos);
	SL* tail = *pphead;
	if (pos == *pphead)
	{
		SLPopFront(pphead);
		return;
	}
	while (tail->next != pos)
	{
		tail = tail->next;
	}
	tail->next = pos->next;
	free(pos);
}

void SLModify(SL** pphead, SL* pos, SLDataType x)
{
	assert(pphead);
	assert(pos);
	SL* tail = *pphead;
	while (tail != pos)
	{
		tail = tail->next;
	}
	tail->x = x;
}

void SLPrint(SL* pphead)
{
	SL* tail = pphead;
	while (tail != NULL)
	{
		printf("%d->", tail->x);
		tail = tail->next;
	}
	printf("NULL\n");
}

void SLList_free(SL** pphead)
{
	//定义一个指针变量保存头结点的地址
	SL* pb = *pphead;
	while (*pphead != NULL)
	{
		//先保存p_head指向的结点的地址
		pb = *pphead;
		//p_head保存下一个结点地址
		*pphead = (*pphead)->next;
		free(pb);
		pb = NULL;
	}
}