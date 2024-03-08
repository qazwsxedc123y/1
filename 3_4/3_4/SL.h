#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>

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

void SLPrint(SL* pphead);