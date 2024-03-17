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

void SLPushBack(DL** pphead, SLdatatype x);

void SLprint(DL* pphead);