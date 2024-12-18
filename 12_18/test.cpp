#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
long long a, b, n, ret = 0;

int main()
{
    cin >> a >> b >> n;
    long long i = 1;// 用于判断是周几
    long long sm = a * 5 + b * 2;
    int ret = n / sm * 7;
    n %= sm;
    while (n > 0)
    {
        if (i % 7 == 0 || i % 7 == 6)// 周六 周日
        {
            n -= b;
        }
        else
        {
            n -= a;
        }
        i++;
        ret++;
    }
    cout << ret;
    return 0;
}