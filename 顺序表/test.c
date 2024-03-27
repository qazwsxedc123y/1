#define  _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

int main()
{
	SeqList sl;
	SeqListInit(&sl);
	
	SeqListInsert(&sl, 0, 2);
	SeqListInsert(&sl, 0, 3);
	SeqListInsert(&sl, 0, 4);
	SeqListInsert(&sl, 0, 5);
	SeqListPushBack(&sl, 1);
	SeqListPushFront(&sl, 6);
	int ret=SeqListFind(&sl, 5);
	if (ret == -1)
	{
		printf("没有找到,该信息不存在\n");
	}
	else
	{
		printf("该下角标为：%d\n", ret);
	}
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListDestroy(&sl);
	return 0;
}