#include <iostream>
#include <thread>
#include <windows.h>  // ���� Windows API ͷ�ļ���ʹ�� Sleep ����

using namespace std;
// Ŀǰ�����ǵ�ԭ���̣߳�pthread�⣬ԭ���߳̿�
void threadrun()
{
    while (true)
    {
        cout << "I am a new thread for C++" << endl;
        Sleep(1000);  // ÿ�� 1000 ���루�� 1 �룩��ӡһ��
    }
}

int main()
{
    // ����һ�����߳�
    thread t1(threadrun);

    // �����̵߳ȴ�һ��ʱ����˳�
    Sleep(5000);  // ���߳�˯�� 5000 ���루�� 5 �룩

    // ���߳��˳�ǰ��ȷ�����߳�Ҳ�ܼ���ִ��һ��ʱ��
    t1.join();

    return 0;
}
