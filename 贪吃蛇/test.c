#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"


void test()
{
	//����̰����
	Snack snack = { 0 };
	GameStart(&snack);
	//������Ϸ
    //GameRun();
    //������Ϸ - �ƺ���
    //GameEend();
}
int main()
{
	setlocale(LC_ALL, "");

	test();
	return 0;
}