#define  _CRT_SECURE_NO_WARNINGS

//#include<iostream>

//using namespace std;
//int t, a[20];
//int main()
//{
//    int n;
//    cin >> n;
//    while (cin >> t) a[t]++;
//    int ans1, ans2;
//    for (int i = 1; i < 100004; i++)
//    {
//        if (a[i - 1] && !a[i] && a[i+1]) ans1 = i;
//        else if (a[i] == 2) ans2 = i;
//        if (ans1 && ans2) break;
//    }
//    cout << ans1 << " " << ans2;
//    return 0;
//}

#include <iostream>

using namespace std;
int h[10000], t, ret, dp[10001];
int check(int d)// 检测当长度为d时，是否可以完成上学
{
    for (int i = d; i < n; i++)
    {
        if (dp[i] - dp[i - d] < t) return 0;
    }
    return 1;
}
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> h[i];
        dp[i] = dp[i - 1] + h[i];
    }
    t = 2 * x;
    int l = 0, r = n;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;
        if (check(mid)) ret = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ret;
    return 0;
}