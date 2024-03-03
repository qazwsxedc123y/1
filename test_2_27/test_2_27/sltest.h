#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
//#include<malloc.h>

enum select
{
	EXIT,
	PushBack,
	PushFront,
	POPBACK,
	SLPRINTF,

};

typedef int SLDatatype;
#define max_begin 4

typedef struct SeqList
{
	SLDatatype* a;
	int size;
	int capacity;
}SL;

void SLInit(SL *ps);

void SLPushBack(SL* ps,int x);

void SLPushFront(SL* ps, int x);

void SLPopBack(SL* ps);

void SLprintf(SL* ps);

void SLDestroy(SL* ps);
