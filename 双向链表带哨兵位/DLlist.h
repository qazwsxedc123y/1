#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

typedef int SLdatatype;

typedef struct ListNode
{
	SLdatatype val;
	struct ListNode* next;
	struct ListNode* prev;
}DL;

DL* BuyDLNode();

DL* DLListInit();

void SLPushFront(DL* pphead, SLdatatype x);

void SLPushBack(DL* pphead, SLdatatype x);

void SLPopFrpnt(DL* pphead);

void SLPopBack(DL* pphead);

DL* SLFind(DL* pphead, SLdatatype x);

void SLInsertBack(DL* pphead, DL* pos, SLdatatype x);

void SLInsertFront(DL* pphead, DL* pos, SLdatatype x);


void SLErase(DL* pphead, DL* pos);

void SLprint(DL* pphead);

void DListDestory(DL* pphead);