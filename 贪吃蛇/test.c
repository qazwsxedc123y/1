#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"


void test()
{
	char ch;
	do {
		//����̰����
		Snack snack = { 0 };
		GameStart(&snack);
		//������Ϸ
		GameRun(&snack);
		//������Ϸ - �ƺ���
		GameEnd(&snack);
		SetPos(20, 15);
		printf("����һ����?(Y/N):");
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