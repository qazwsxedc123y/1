#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//int n;
//int main() {
//    cin >> n;
//    vector<int> v;
//    while (n)
//    {
//        int t = n % 10;
//        // 奇变1  偶变0
//        if (t % 2 == 0) //0
//        {
//            v.push_back(0);
//        }
//        else v.push_back(1);
//        n /= 10;
//    }
//    // 处理前导0
//    while (v.size() != 0 && v.back() == 0)
//    {
//        v.pop_back();
//    }
//    if (v.size() == 0) cout << "0" << endl;
//    else
//    {
//        reverse(v.begin(), v.end());
//        for (int i = 0; i < v.size(); i++) cout << v[i];
//    }
//}
//// 64 位输出请用 printf("%lld")


const int N = 1e7 + 5;
int n, m;
long long arr[10][10];
long long func(int x, int y)
{
    // 先计算行
    // 后计算列
    long long ret = 0;
    for (int i = 0; i < m; i++)
    {
        ret += arr[x][i];
    }
    for (int i = 0; i < n; i++)
    {
        ret += arr[i][y];
    }
    return ret - arr[x][y];
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << func(i, j);
        }
        cout << endl;
    }
}
// 64 位输出请用 printf("%lld")