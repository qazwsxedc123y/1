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