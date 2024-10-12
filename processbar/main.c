#define  _CRT_SECURE_NO_WARNINGS
#include"ProcessBar.h"

int main()
{
	//processbar();
	printf("%d", 100 / 1000);
	return 0;
}

 /*#include"ProcessBar.h"
 #include<string.h>
 #include<unistd.h>


 void processbar()
 {
	   char bar[NUM];
	    memset(bar, '\0', sizeof(bar));
	     int cnt = 0;
	     while (cnt <= 100)
		     {
		         printf("[%-100s][%d%%]\r", bar, cnt);
		         fflush(stdout);
		         bar[cnt++] = body;
		         usleep(10000);
		     }
	     printf("\n");
	 }
 }*/