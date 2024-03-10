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
	//һ��Ҳû��
	assert(*pphead);
	//һ���ڵ�
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//����ڵ�
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
	free(tail);//tail��SL* tail=&SLList;


	////һ���ڵ�
	//if ((*pphead)->next == NULL)
	//{
	//	free(*pphead);
	//	*pphead = NULL;
	//	return;
	//}
	// //����ֽ�
	//SL* tail = *pphead;
	//*pphead = (*pphead)->next;
	//free(tail);
	////tail = NULL;  ����Ҫ����Ϊ��������ջ����
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
	//����һ��ָ���������ͷ���ĵ�ַ
	SL* pb = *pphead;
	while (*pphead != NULL)
	{
		//�ȱ���p_headָ��Ľ��ĵ�ַ
		pb = *pphead;
		//p_head������һ������ַ
		*pphead = (*pphead)->next;
		free(pb);
		pb = NULL;
	}
}