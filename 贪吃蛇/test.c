#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"


void test()
{
	char ch;
	do {
		//创建贪吃蛇
		Snack snack = { 0 };
		GameStart(&snack);
		//运行游戏
		GameRun(&snack);
		//结束游戏 - 善后工作
		GameEnd(&snack);
		SetPos(20, 15);
		printf("再来一局吗?(Y/N):");
		ch = getchar();
		while (getchar() != '\n');
	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 28);

}
int main()
{
	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "");

	test();
	return 0;
}