#define  _CRT_SECURE_NO_WARNINGS
#include"ProcessBar.h"

#include"ProcessBar.h"

typedef void (*callback_t)(int);

void download(callback_t cb)
{
    int total = 1000;
    int curr = 0;
    while (curr <= total)
    {
        int rate = curr * 100 / total;
        cb(rate);
        curr += 10;
        usleep(5000);
    }
    printf("\n");
    Init();
    return;
}

int main()
{
    printf("第一次下载：\n");
    download(processbar);
    printf("第二次下载：\n");
    download(processbar);
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