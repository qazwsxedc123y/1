#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"

void cursor_hide()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标 
	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态 
}

void SetPos(int x,int y)
{
	//获得标准输出设备的句柄
	HANDLE hOutput = NULL;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置,到pos
	COORD pos = { x,y };
	SetConsoleCursorPosition(hOutput, pos);
}

void Welcome_game()
{
	SetPos(35, 12);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(36, 18);
	system("pause");
	system("cls");
}

void CreatMap()
{
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
	system("pause");
}

void GameStart(pSnack ps)
{
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	//1光标隐藏
	cursor_hide();

	//2.打印环境界面
	//第一个界面，欢迎
	// 第二个界面，介绍怎么操作游戏
	Welcome_game();
	CreatMap();
		//3.功能介绍
}