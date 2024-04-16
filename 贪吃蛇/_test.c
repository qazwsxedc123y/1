#define  _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<windows.h>
//#include<stdbool.h>
//void SetPos(int x,int y)
//{
//	//获得标准输出设备的句柄
//	HANDLE hOutput = NULL;
//	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//定位光标的位置,到pos
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(hOutput, pos);
//}
//int main()
//{
//	system("mode con cols=100 lines=30");
//	system("title 贪吃蛇");
//	SetPos(2,2);
//
//	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO CursorInfo;
//	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
//	CursorInfo.bVisible = false; //隐藏控制台光标 
//	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态 
//
//	system("pause");
//	return 0;
//}