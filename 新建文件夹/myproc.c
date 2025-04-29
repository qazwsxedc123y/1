#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler(int sig)
{
    printf("get a signal:%d\n", sig);
}
int main()
{
    signal(2, handler); // 捕捉2号信号
    while(1){
        printf("I am a process, I am waiting signal!\n");
        sleep(1);
    }
    return 0;
}