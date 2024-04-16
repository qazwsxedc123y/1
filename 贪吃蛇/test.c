#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"


void test()
{
	//创建贪吃蛇
	Snack snack = { 0 };
	GameStart(&snack);
	//运行游戏
    //GameRun();
    //结束游戏 - 善后工作
    //GameEend();
}
int main()
{
	setlocale(LC_ALL, "");

	test();
	return 0;
}