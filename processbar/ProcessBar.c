#define  _CRT_SECURE_NO_WARNINGS
#include"ProcessBar.h"
#include<string.h>
#include <windows.h> 

#define body '#'
#define NUM 102

void processbar()
{
	char bar[NUM];
	memset(bar, '\0', sizeof(bar));
	int cnt = 0;
	while (cnt <= 100)
	{
		printf("[%s][%d%%]\r", bar, cnt);
		bar[cnt++] = body;
		Sleep(10);
	}
	printf("\n");
}

// v1

//#include"ProcessBar.h"
//4  #include<string.h>
//5  #include<unistd.h>
//6
//7 const char* lable = "|/-\\";
//8
//9  void processbar()
//10  {
//	11     char bar[NUM];
//	12     memset(bar, '\0', sizeof(bar));
//	13     int cnt = 0;
//	14     while (cnt <= 100)
//		15     {
//		16         printf("[%-100s][%d%%][%c]\r", bar, cnt, lable[cnt % 4]);
//		17         fflush(stdout);
//		18         bar[cnt++] = body;
//		19         if (cnt < 100) bar[cnt] = '>';
//		20         usleep(100000);
//		21     }
//	22     printf("\n");
//	23 }
//24

