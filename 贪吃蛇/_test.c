#define  _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<windows.h>
//#include<stdbool.h>
//void SetPos(int x,int y)
//{
//	//��ñ�׼����豸�ľ��
//	HANDLE hOutput = NULL;
//	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//��λ����λ��,��pos
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(hOutput, pos);
//}
//int main()
//{
//	system("mode con cols=100 lines=30");
//	system("title ̰����");
//	SetPos(2,2);
//
//	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO CursorInfo;
//	GetConsoleCursorInfo(hOutput, &CursorInfo);//��ȡ����̨�����Ϣ
//	CursorInfo.bVisible = false; //���ؿ���̨��� 
//	SetConsoleCursorInfo(hOutput, &CursorInfo);//���ÿ���̨���״̬ 
//
//	system("pause");
//	return 0;
//}