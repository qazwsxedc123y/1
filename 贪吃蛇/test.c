#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"


void test()
{

	//����̰����
	Snack snack = { 0 };
	GameStart(&snack);
	//������Ϸ
    GameRun(&snack);
    //������Ϸ - �ƺ���
    GameEend(&snack);
}
int main()
{
	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "");

	test();
	return 0;
}