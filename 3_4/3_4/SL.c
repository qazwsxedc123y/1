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