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

	//��ֵ
	newcode->val = x;
	newcode->prev = NULL;
	newcode->next = *pphead;
	//����ͷ�ڵ�
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

void DLPopFront(DL** pphead)
{
	assert(pphead);
	assert(*pphead);
	DL* tail = *pphead;
	*pphead = (*pphead)->next;
	//�ͷŵ�һ���ڵ�
	free(tail);
	//����
	(*pphead)->prev = NULL;
	return;
}

void DLPopBack(DL** pphead)
{
	assert(pphead);
	assert(*pphead);
	DL* tail = *pphead;
	//���һ�Ҫ�ҵ������ڶ����ڵ㣬
	//�ı����next  NULL

	//�����ֻ��һ���ڵ�
	if (tail->next == NULL)
	{
		free(pphead);
//		*pphead = NULL;
		return;
	}
	while (tail->next->next)//�ҵ��������ڵ�
	{
		tail = tail->next;
	}
	DL* back = tail->next;//�ҵ����һ���ڵ�
	free(back);
	tail->next = NULL;//�޸ĵ����ڶ����ڵ�
	return;
}

DL* DListFind(DL* plist, SLdatatype x)
{
	assert(plist);
	DL* tail = plist;
	while (tail)
	{
		if (tail->val == x)//�ж�
		{
			return tail;
		}
		//����
		tail = tail->next;
	}
	printf("����Ϣ�ڸ������ڲ�����\n");
	return NULL;
}

void DLEarse(DL** pphead, DL* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	DL* tail = *pphead;
	//���ǻ���Ҫ�ҵ���һ���ڵ�  �޸�prev   ��Ϊ��һ�ڵ�
	//��һ�ڵ�   �޸�next   ��Ϊ��һ�ڵ�
	while (tail != pos)//�ҵ���ӦҪɾ���Ľڵ�
	{
		tail = tail->next;
	}
	if (tail->next==NULL)//β�ڵ�
	{
		DLPopBack(pphead);
		return;
	}
	else if (tail->prev == NULL)//ͷ�ڵ�
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
	while (tail != pos)//�ҵ���Ӧ�ڵ�
	{
		tail = tail->next;
	}
	if (tail->next == NULL)//β�ڵ�
	{
		DLPushBack(pphead,x);
		return;
	}
	else if (tail->prev == NULL)//ͷ�ڵ�
	{
		DLPushFront(pphead,x);
		return;
	}
	//��malloc
	//�޸ĸýڵ��next  ָ������ӵĽڵ�
	//�޸ı����ڵ����һ���ڵ�   �޸�prev  ��Ϊָ������ӵĽڵ�
	DL* newcode = (DL*)malloc(sizeof(DL));
	if (newcode == NULL)
	{
		perror("malloc error\n");
	}
	newcode->val = x;
	newcode->next = tail->next;
	newcode->prev = tail;

	DL* Back = tail->next;//ԭ��������һ���ڵ�

	tail->next = newcode;//�޸�ԭ���ڵ��nextָ������ӵ�
	Back->prev = newcode;//�޸�ԭ���ڵ���һ���ڵ��prev
	return;
}

void DLInsertFront(DL** pphead, DL* pos, SLdatatype x)//ǰ��
{
	assert(pphead);
	assert(pos);
	DL* tail = *pphead;
	while (tail != pos)//�ҵ���Ӧ�ڵ�
	{
		tail = tail->next;
	}
	if (tail->next == NULL)//β�ڵ�
	{
		DLPushBack(pphead, x);
		return;
	}
	else if (tail->prev == NULL)//ͷ�ڵ�
	{
		DLPushFront(pphead, x);
		return;
	}
	//��malloc
	//�޸ĸýڵ��next  ָ������ӵĽڵ�
	//�޸ı����ڵ����һ���ڵ�   �޸�prev  ��Ϊָ������ӵĽڵ�
	DL* newcode = (DL*)malloc(sizeof(DL));
	if (newcode == NULL)
	{
		perror("malloc error\n");
	}
	newcode->val = x;
	newcode->next = tail;
	newcode->prev = tail->prev;

	DL* Front = tail->prev;//ԭ��������һ���ڵ�

	tail->prev = newcode;//�޸�ԭ���ڵ��prevָ������ӵ�
	Front->next = newcode;//�޸�ԭ���ڵ���һ���ڵ��next
	return;
}

void Modify(DL** pphead, DL* pos, SLdatatype x)
{
	assert(pphead);
	assert(pos);
	DL* tail = *pphead;
	while (tail != pos)//�ҵ���Ӧ�ڵ�
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
		//�ȱ���ýڵ�ָ��ĵ�ַ
		tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
	return;
}