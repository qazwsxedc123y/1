#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//using namespace std;
//
//long long n = 202420242024, x, y, ret;
//const long long a[10]{ 0,20,24,40,48,60,72,80,96,100 };
//int main()
//{
//    // 2429042904288
//    x = n % 10, y = n / 10;
//    ret = 24 * 5 * y;
//    ret += a[x];
//    cout << ret;
//    return 0;
//}

#include <iostream>

using namespace std;
long long a[100005], n, ans;
int _gcd(int m, int n)
{
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], ans += (a[i] == 1 ? 1 : 0);
    // �������Ѿ���1��
    if (ans) {
        cout << n - ans;
        return 0;
    }
    int ret = 1e9;
    for (int i = 1; i < n; i++)
    {
        int t = a[i], c = 0;
        for (int j = i + 1; j <= n; j++)// �����ڵ�������
        {
            c++;
            t = _gcd(t, a[j]);
            if (t == 1)// �ɹ���Ϊ��1
            {
                ret = min(ret, c);
                break;
            }
        }
    }
    if (ret == 1e9) {
        cout << -1;
        return 0;
    }
    else cout << n + ret - 1;
    return 0;
}