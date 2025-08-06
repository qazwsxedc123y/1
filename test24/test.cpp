#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;




// 8.5

//string s;
//int n;
//int func()
//{
//    for (int len = 2; len <= n; len++)
//    {
//        for (int i = 0; i < n - len + 1; i++)
//        {
//            bool flag = true;
//            int l = i, r = i + len - 1;
//
//            // 判断该区间是否为回文串
//            while (l < r)
//            {
//                if (s[l] != s[r])
//                {
//                    flag = false;
//                    break;
//                }
//                l++, r--;
//            }
//            if (flag == true) return len;
//        }
//    }
//    return -1;
//}
//int main() {
//    cin >> s;
//    // 长度不长，可以考虑采用全部长度遍历
//    // 2 到 n
//    n = s.size();
//
//    int ret = func();
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")
//
//
//
//const int N = 1e6 + 100;
//int n, arr[N];
//long long func(int pos)
//{
//    // 采用动态规划
//    long long f[N] = { 0 }; // 表示第i位置不选时，值最大的选择
//    long long g[N] = { 0 }; // 表示第i位置选时，值最大的选择
//    // 对于第i位置
//    // 选择g[i] = max(f[i-1] + arr[i],arr[i] + g[i-2])
//    // 不选f[i] = max(g[i-1], f[i-1]);
//    // 初始化
//    g[pos] = arr[pos];
//
//    for (int i = pos + 1; i <= n; i++)
//    {
//        g[i] = max(f[i - 1] + arr[i], arr[i] + g[i - 2]);
//        f[i] = max(g[i - 1], f[i - 1]);
//    }
//    return max(g[n], f[n]);
//}
//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> arr[i];
//
//    // 打家劫舍
//    cout << max(func(1), func(2)) << endl;
//}
//// 64 位输出请用 printf("%lld")
//
//
//
//const int N = 1e6 + 100;
//int n, p, a[N] = { 0 };
//int main() {
//    cin >> n >> p;
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    // 可以采用滑动窗口
//    sort(a, a + n);
//    // [K-p, K+p]
//
//    int ret = 0;
//    for (int l = 0, r = 0; r < n; r++)
//    {
//        while (a[r] - a[l] > 2 * p)
//        {
//            l++;
//        }
//        ret = max(r - l + 1, ret);
//    }
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 计算成功举办活动需要多少名主持人
//     * @param n int整型 有n个活动
//     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
//     * @return int整型
//     */
//    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
//        // write code here
//        sort(startEnd.begin(), startEnd.end());
//        priority_queue<int, vector<int>, greater<int>> heap;
//
//        heap.push(startEnd[0][1]);
//
//        for (int i = 1; i < n; i++)
//        {
//            int a = startEnd[i][0];
//            if (a >= heap.top())
//            {
//                heap.pop();
//                heap.push(startEnd[i][1]);
//            }
//            else
//            {
//                heap.push(startEnd[i][1]);
//            }
//        }
//
//        return heap.size();
//    }
//};