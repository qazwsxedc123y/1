#define  _CRT_SECURE_NO_WARNINGS

#include"SLListNode.h"

int main()
{
	//��ʼ������
	DL* DLList =DLListInit();
	//��Ϊ���ڱ�λ������Ҫ�޸�ͷ�ڵ㣬�޸ĵ���ͷ�ڵ�ָ��Ľṹ�������
	//��ֵ���У�������DLList���ָ���ĵ�ַ
//	SLPushBack(DLList,8);
	SLPushFront(&DLList,5);
	SLPushFront(&DLList,6);
//	SLPushBack(&DLList,7);
	SLprint(DLList);
	return 0;
}