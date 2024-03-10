#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>

typedef int SLDataType;

typedef struct SLList
{
    SLDataType x;
    struct SLList* next;
}SL;

void SLPushback(SL** pphead, SLDataType x);

void SLPushFront(SL** pphead, SLDataType x);

void SLPopBack(SL** pphead);

void SLPopFront(SL** pphead);

SL* SLFind(SL* pphead, SLDataType x);

void SLInsert(SL** pphead,SL* pos, SLDataType x);

void SLInsertBack(SL** pphead, SL* pos, SLDataType x);

void SLErase(SL** pphead, SL* pos);

void SLModify(SL** pphead, SL* pos, SLDataType x);

void SLPrint(SL* pphead);

void SLList_free(SL** pphead);