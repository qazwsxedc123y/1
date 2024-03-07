#define  _CRT_SECURE_NO_WARNINGS
#include "SL.h"





void SLPushback(SL** ppage,SLDataType x)
{
    SL* newcode = (SL*)malloc(sizeof(SL));
    if (*ppage == NULL)
    {
        *ppage = newcode;
        return;
    }
    SL* tail = *ppage;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newcode;
    tail = tail->next;
    tail->x = x;
}

void SLPrint(SL* ppage)
{
    SL* tail = ppage;
    while (tail->next != NULL)
    {
        printf("%d ", tail->x);
        tail = tail->next;
    }
}