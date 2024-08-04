#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include <locale.h>
#include<time.h>
#include<errno.h>
#define Wall L'□'
#define Body L'●'
#define Food L'★'
void SetPos(int x, int y)
{
	//获得标准输出设备的句柄
	HANDLE hOutput = NULL;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置,到pos
	COORD pos = { x,y };
	SetConsoleCursorPosition(hOutput, pos);
}
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
	//注：SetConsoleTextAttribute是一个API（应用程序编程接口）
}
void a(int* p1, int* p2)
{
	int y = 5;
	*p1 = y;
}
int main()
{

	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	color(12);
	//上
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}
	//下
	SetPos(0, 26);
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}
	//左
	for (int i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", L'□');
	}
	//右
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", L'□');
	}
	color(7);
	return 0;
}
void SnackMove(pSnack ps)
{
	pSnackNode pNextNode = (pSnackNode)malloc(sizeof(SnackNode));
	if (pNextNode == NULL)
	{
		perror("SnackMove::malloc fail");
		return;
	}
	pNextNode->x = ps->_psnack->x + 2;
	pNextNode->y = ps->_psnack->y;

	pn->next = ps->_psnack;
	ps->_psnack = pn;
	pSnackNode cur = ps->_psnack;
	//打印出来五个了
	while (cur->next->next != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", Body);
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
}