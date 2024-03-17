#define  _CRT_SECURE_NO_WARNINGS

#include"SLListNode.h"

DL* BuyDLNode()
{
	DL* newcode=(DL*)malloc(sizeof(DL));
	return newcode;//���ص������ָ���ĵ�ַ
}

DL* DLListInit()
{
	DL*newcode=BuyDLNode();//�����malloc���ٿռ�ĵ�ַ
	newcode ->val = -1;
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
	return;
}

void SLPushBack(DL** pphead, SLdatatype x)
{
	assert(pphead);
	DL* newcode = (DL*)malloc(sizeof(DL));
	if (newcode == NULL)
	{
		perror("malloc error\n");
		return;
	}
	DL* tail = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newcode;
		(*pphead)->val = x;
		(*pphead)->next = NULL;
		(*pphead)->next = *pphead;;
		return;
	}
	else
	{
		while (tail->next)//�ҵ����һ���ڵ�
		{
			tail = tail->next;
		}
		tail->next = newcode;
		newcode->val = x;
		newcode->prev = tail;
		newcode->next = NULL;
		return;
	}
}

void SLprint(DL* pphead)
{
	DL* tail = pphead->next;
	while (tail != pphead)
	{
		printf("%d->", tail->val);
		tail = tail->next;
	}
	printf("NULL\n");
}