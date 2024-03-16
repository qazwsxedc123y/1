#define  _CRT_SECURE_NO_WARNINGS

#include"DLList.h"

void DLPushFront(DL** pphead, SLdatatype x)
{
	assert(pphead);
	DL* newcode = (DL*)malloc(sizeof(DL));
	DL* tail = *pphead;
	if (newcode == NULL)
	{
		perror("malloc error\n");
		return;
	}
	//if (*pphead == NULL)
	//{

	//赋值
	newcode->val = x;
	newcode->prev = NULL;
	newcode->next = *pphead;
	//更换头节点
	*pphead = newcode;
	return;
	//	}
	return;
}

void DLPushBack(DL** pphead, SLdatatype x)
{
	assert(pphead);
	DL* newcode = (DL*)malloc(sizeof(DL));
	if (newcode == NULL)
	{
		perror("malloc error\n");
		return;
	}
	if (*pphead == NULL)
	{
		*pphead = newcode;
		(*pphead)->val = x;
		(*pphead)->next = NULL;
		(*pphead)->next = NULL;
		return;
	}
	DL* tail = *pphead;
	while (tail->next)//找到最后一个节点
	{
		tail = tail->next;
	}
	tail->next = newcode;
	newcode->val = x;
	newcode->prev = tail;
	newcode->next = NULL;
	return;
}

void DLPopFront(DL** pphead)
{
	assert(pphead);
	assert(*pphead);
	DL* tail = *pphead;
	*pphead = (*pphead)->next;
	//释放第一个节点
	free(tail);
	//更换
	(*pphead)->prev = NULL;
	return;
}

void DLPopBack(DL** pphead)
{
	assert(pphead);
	assert(*pphead);
	DL* tail = *pphead;
	//而且还要找到倒数第二个节点，
	//改变其的next  NULL

	//但如果只有一个节点
	if (tail->next == NULL)
	{
		free(pphead);
//		*pphead = NULL;
		return;
	}
	while (tail->next->next)//找到最后二个节点
	{
		tail = tail->next;
	}
	DL* back = tail->next;//找到最后一个节点
	free(back);
	tail->next = NULL;//修改倒数第二个节点
	return;
}

DL* DListFind(DL* plist, SLdatatype x)
{
	assert(plist);
	DL* tail = plist;
	while (tail)
	{
		if (tail->val == x)//判断
		{
			return tail;
		}
		//迭代
		tail = tail->next;
	}
	printf("该信息在该链表内不存在\n");
	return NULL;
}

void DLEarse(DL** pphead, DL* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	DL* tail = *pphead;
	//但是还需要找到下一个节点  修改prev   改为上一节点
	//上一节点   修改next   改为下一节点
	while (tail != pos)//找到对应要删除的节点
	{
		tail = tail->next;
	}
	if (tail->next==NULL)//尾节点
	{
		DLPopBack(pphead);
		return;
	}
	else if (tail->prev == NULL)//头节点
	{
		DLPopFront(pphead);
		return;
	}
	DL* Front = tail->prev;
	DL* Back = tail->next;
	free(tail);
	Front->next = Back;
	Back->prev = Front;
	return;
}

void DLInsertBack(DL** pphead, DL* pos, SLdatatype x)
{
	assert(pphead);
	assert(pos);
	DL* tail = *pphead;
	while (tail != pos)//找到对应节点
	{
		tail = tail->next;
	}
	if (tail->next == NULL)//尾节点
	{
		DLPushBack(pphead,x);
		return;
	}
	else if (tail->prev == NULL)//头节点
	{
		DLPushFront(pphead,x);
		return;
	}
	//先malloc
	//修改该节点的next  指向新添加的节点
	//修改本来节点的下一个节点   修改prev  改为指向新添加的节点
	DL* newcode = (DL*)malloc(sizeof(DL));
	if (newcode == NULL)
	{
		perror("malloc error\n");
	}
	newcode->val = x;
	newcode->next = tail->next;
	newcode->prev = tail;

	DL* Back = tail->next;//原本链表下一个节点

	tail->next = newcode;//修改原本节点的next指向新添加的
	Back->prev = newcode;//修改原本节点下一个节点的prev
	return;
}

void DLInsertFront(DL** pphead, DL* pos, SLdatatype x)//前插
{
	assert(pphead);
	assert(pos);
	DL* tail = *pphead;
	while (tail != pos)//找到对应节点
	{
		tail = tail->next;
	}
	if (tail->next == NULL)//尾节点
	{
		DLPushBack(pphead, x);
		return;
	}
	else if (tail->prev == NULL)//头节点
	{
		DLPushFront(pphead, x);
		return;
	}
	//先malloc
	//修改该节点的next  指向新添加的节点
	//修改本来节点的下一个节点   修改prev  改为指向新添加的节点
	DL* newcode = (DL*)malloc(sizeof(DL));
	if (newcode == NULL)
	{
		perror("malloc error\n");
	}
	newcode->val = x;
	newcode->next = tail;
	newcode->prev = tail->prev;

	DL* Front = tail->prev;//原本链表下一个节点

	tail->prev = newcode;//修改原本节点的prev指向新添加的
	Front->next = newcode;//修改原本节点上一个节点的next
	return;
}

void Modify(DL** pphead, DL* pos, SLdatatype x)
{
	assert(pphead);
	assert(pos);
	DL* tail = *pphead;
	while (tail != pos)//找到对应节点
	{
		tail = tail->next;
	}
	tail->val = x;
	return;
}

void DLprint(DL* pphead)
{
	DL* tail = pphead;
	while (tail != NULL)
	{
		printf("%d->", tail->val);
		tail = tail->next;
	}
	printf("NULL\n");
}

void DListDestory(DL** pphead)
{
	DL* tmp = *pphead;
	while (*pphead != NULL)
	{
		//先保存该节点指向的地址
		tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
	return;
}