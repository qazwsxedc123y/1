#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef int SLDataType;

typedef struct SLList
{
    SLDataType x;
    struct SLList* next;
} SL;

void SLPushback(SL** ppage, SLDataType x);

void SLPrint(SL* ppage);