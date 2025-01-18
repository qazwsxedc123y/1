#include <iostream>
#include <thread>
#include <windows.h>  // 引入 Windows API 头文件，使用 Sleep 函数

using namespace std;
// 目前，我们的原生线程，pthread库，原生线程库
void threadrun()
{
    while (true)
    {
        cout << "I am a new thread for C++" << endl;
        Sleep(1000);  // 每隔 1000 毫秒（即 1 秒）打印一次
    }
}

int main()
{
    // 创建一个新线程
    thread t1(threadrun);

    // 让主线程等待一段时间后退出
    Sleep(5000);  // 主线程睡眠 5000 毫秒（即 5 秒）

    // 主线程退出前，确保子线程也能继续执行一段时间
    t1.join();

    return 0;
}
