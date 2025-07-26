#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
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


//const int N = 1e7 + 5;
//int n, m;
//long long arr[10][10];
//long long func(int x, int y)
//{
//    // 先计算行
//    // 后计算列
//    long long ret = 0;
//    for (int i = 0; i < m; i++)
//    {
//        ret += arr[x][i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        ret += arr[i][y];
//    }
//    return ret - arr[x][y];
//}
//int main() {
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> arr[i][j];
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cout << func(i, j);
//        }
//        cout << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")



//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param param string字符串
//     * @return string字符串
//     */
//    string compressString(string param) {
//        // write code here
//        string ret;
//        int i = 0;
//        while (i < param.size())
//        {
//            char ch = param[i];
//            int ans = 0;
//            while (i < param.size() && ch == param[i])
//            {
//                ans++;
//                i++;
//            }
//            if (ans == 1)
//            {
//                ret += ch;
//            }
//            else
//            {
//                ret += ch;
//                // 加上后面数字
//                string tmp;
//                int t = ans;
//                while (t)
//                {
//                    int x = t % 10;
//                    tmp.push_back('0' + x);
//                    t /= 10;
//                }
//                reverse(tmp.begin(), tmp.end());
//                ret += tmp;
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    s.compressString("aabcccccaaa");
//	return 0;
//}



#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
// 堆的top K问题
// 再加上一个哈希表
const int N = 2e5 + 10;
long long arra[N]; // 酸
long long arrb[N]; // 甜
unordered_map<long long, vector<long long>> hash1;
priority_queue<long long> q;
long long n, k;
int main() {
    cin >> n >> k;
    // 先输入酸
    // 后甜
    for (long long i = 0; i < n; i++) cin >> arra[i];

    for (long long i = 0; i < n; i++) cin >> arrb[i];

    for (long long i = 0; i < n; i++)
    {
        q.push(arrb[i]);
        hash1[arrb[i]].push_back(arra[i]);
    }


    for (auto& [a, b] : hash1)
    {
        sort(b.begin(), b.end());
    }

    long long ans1 = 0; // 存酸度
    long long ans2 = 0; // 存甜度

    for (long long i = 0; i < k; i++)
    {
        long long t = q.top();
        q.pop();
        ans2 += t;
        // 取最小的酸度
        auto a = hash1[t];
        for (long long j = 0; j < a.size(); j++)
        {
            if (a[j] != -1)
            {
                ans1 += a[j];
                a[j] = -1;

                break;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
}
// 64 位输出请用 printf("%lld")





















