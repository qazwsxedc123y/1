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


void DLPushFront(DL** pphead, SLdatatype x);

void DLPushBack(DL** pphead, SLdatatype x);

void DLPopFront(DL** pphead);

void DLPopBack(DL** pphead);

DL* DListFind(DL* plist, SLdatatype x);

void DLEarse(DL** pphead,DL* pos);

void DLInsertBack(DL** pphead, DL* pos, SLdatatype x);

void DLInsertFront(DL** pphead, DL* pos, SLdatatype x);

void Modify(DL** pphead, DL* pos, SLdatatype x);

void DLprint(DL* pphead);

void DListDestory(DL** pphead);