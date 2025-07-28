#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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
//                ret += to_string(ans);
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




//using namespace std;
//// 堆的top K问题
//// 再加上一个哈希表
//const int N = 2e5 + 10;
//long long arra[N]; // 酸
//long long arrb[N]; // 甜
//unordered_map<long long, vector<long long>> hash1;
//priority_queue<long long> q;
//long long n, k;
//int main() {
//    cin >> n >> k;
//    // 先输入酸
//    // 后甜
//    for (long long i = 0; i < n; i++) cin >> arra[i];
//
//    for (long long i = 0; i < n; i++) cin >> arrb[i];
//
//    for (long long i = 0; i < n; i++)
//    {
//        q.push(arrb[i]);
//        hash1[arrb[i]].push_back(arra[i]);
//    }
//
//
//    for (auto& [a, b] : hash1)
//    {
//        sort(b.begin(), b.end());
//    }
//
//    long long ans1 = 0; // 存酸度
//    long long ans2 = 0; // 存甜度
//
//    for (long long i = 0; i < k; i++)
//    {
//        long long t = q.top();
//        q.pop();
//        ans2 += t;
//        // 取最小的酸度
//        auto a = hash1[t];
//        for (long long j = 0; j < a.size(); j++)
//        {
//            if (a[j] != -1)
//            {
//                ans1 += a[j];
//                a[j] = -1;
//
//                break;
//            }
//        }
//    }
//    cout << ans1 << " " << ans2 << endl;
//}
//// 64 位输出请用 printf("%lld")
//


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// 堆的top K问题
//const int N = 2e5 + 10;
//typedef pair<int, int> PII; // <甜度,酸度>
//int arra[N]; // 酸
//int arrb[N]; // 甜
//priority_queue<long long> q;
//int n, k;
//
//struct cmp {
//    bool operator()(const PII& a, const PII& b)
//    {
//        if (a.first != b.first)
//        {
//            return a.first < b.first; // 甜度大的优先
//        }
//        else
//        {
//            return a.second > b.second; // 甜度相同，酸度小的优先
//        }
//    }
//};
//
//int main() {
//    cin >> n >> k;
//    // 先输入酸
//    // 后甜
//    for (long long i = 0; i < n; i++) cin >> arra[i];
//
//    for (long long i = 0; i < n; i++) cin >> arrb[i];
//
//    priority_queue<PII, vector<PII>, cmp> q;
//
//    for (int i = 0; i < n; i++)
//    {
//        q.push({ arrb[i], arra[i] });
//    }
//
//    long long ans1 = 0; // 存酸度
//    long long ans2 = 0; // 存甜度
//
//    for (int i = 0; i < k; i++)
//    {
//        auto t = q.top();
//        q.pop();
//        ans1 += t.second;
//        ans2 += t.first;
//    }
//    cout << ans1 << " " << ans2 << endl;
//}
//// 64 位输出请用 printf("%lld")
//
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// 堆的top K问题
//const int N = 2e5 + 10;
//typedef pair<int, int> PII; // <甜度,酸度>
//int arra[N]; // 酸
//int arrb[N]; // 甜
//priority_queue<long long> q;
//int n, k;
//PII arr[N];
//
//struct cmp {
//    bool operator()(const PII& a, const PII& b)
//    {
//        if (a.first != b.first)
//        {
//            return a.first < b.first; // 甜度大的优先
//        }
//        else
//        {
//            return a.second > b.second; // 甜度相同，酸度小的优先
//        }
//    }
//};
//
//int main() {
//    cin >> n >> k;
//    // 先输入酸
//    // 后甜
//    for (long long i = 0; i < n; i++) cin >> arr[i].second;
//
//    for (long long i = 0; i < n; i++) cin >> arr[i].first;
//
//    sort(arr, arr + n, [&](const PII& a, const PII& b)
//        {
//            if (a.first != b.first)
//            {
//                return a.first > b.first; // 甜度大的优先
//            }
//            else
//            {
//                return a.second < b.second; // 甜度相同，酸度小的优先
//            }
//        });
//
//    long long ans1 = 0; // 存酸度
//    long long ans2 = 0; // 存甜度
//
//    for (int i = 0; i < k; i++)
//    {
//        ans1 += arr[i].second;
//        ans2 += arr[i].first;
//    }
//    cout << ans1 << " " << ans2 << endl;
//}
//// 64 位输出请用 printf("%lld")




//#include <iostream>
//#include <memory.h>
//using namespace std;
//const int N = 1024;
//
//int n, V, v[N], w[N];
//// 第一问：dp[i][j] 表示从 i 个物品挑选，总体积不超过 j ，所有选法中选出来的最大价值
//// 第二问：dp[i][j] 表示从 i 个物品挑选，总体积恰好为 j ，所有选法中选出来的最大价值
//int dp[N][N];
//
//int main() {
//    // 读入数据
//    cin >> n >> V;
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 第一问
//    // 初始化 全为0
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= V; j++)
//        {
//            // 不选 dp[i][j] = dp[i-1][j]
//            // 选   dp[i][j] = w[i] + dp[i-1][j-v[i]]
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i]) dp[i][j] = max(w[i] + dp[i - 1][j - v[i]], dp[i][j]);
//        }
//    }
//    cout << dp[n][V] << endl;
//
//    // 第二问
//    memset(dp, 0, sizeof(dp));
//
//    // 初始化
//    for (int i = 1; i <= V; i++) dp[0][i] = -1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= V; j++)
//        {
//            // 不选 dp[i][j] = dp[i-1][j];
//            // 选 dp[i][j] = w[i] + dp[i-1][j-v[i]]
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
//                dp[i][j] = max(w[i] + dp[i - 1][j - v[i]], dp[i][j]);
//        }
//    }
//
//    cout << ((dp[n][V] == -1) ? 0 : dp[n][V]) << endl;
//}


//#include <iostream>
//#include <string.h>
//using namespace std;
//const int N = 1024;
//
//int n, V, v[N], w[N];
//// 第一问：dp[i][j] 表示从 i 个物品挑选，总体积不超过 j ，所有选法中选出来的最大价值
//// 第二问：dp[i][j] 表示从 i 个物品挑选，总体积恰好为 j ，所有选法中选出来的最大价值
//int dp[N];
//
//int main() {
//    // 读入数据
//    cin >> n >> V;
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 第一问
//    // 初始化 全为0
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = V; j >= v[i]; j--)
//        {
//            dp[j] = max(w[i] + dp[j - v[i]], dp[j]);
//        }
//    }
//    cout << dp[V] << endl;
//
//    // 第二问
//    memset(dp, 0, sizeof(dp));
//
//    // 初始化
//    for (int i = 1; i <= V; i++) dp[i] = -1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = V; j >= v[i]; j--)
//        {
//            dp[j] = dp[j];
//            if (dp[j - v[i]] != -1)
//                dp[j] = max(w[i] + dp[j - v[i]], dp[j]);
//        }
//    }
//
//    cout << ((dp[V] == -1) ? 0 : dp[V]) << endl;
//}
//// 64 位输出请用 printf("%lld")


//const int N = 1e5 + 10;
//long long n, x, arr[N];
//int gcb(int a, int b)
//{
//    while (a % b != 0)
//    {
//        int c = a % b;
//        a = b;
//        b = c;
//    }
//    return b;
//}
//int main() {
//    cin >> n >> x;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] <= x) x += arr[i];
//        else
//        {
//            x += gcb(x, arr[i]);
//        }
//    }
//    cout << x << endl;
//}
//// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    int maxValue(vector<vector<int> >& grid) {
//        // write code here
//        // 使用动态规划
//        // dp[i][j] 表示到达下表为 (i-1,j-1) 时，拿到最大的价值
//        int n = grid.size(), m = grid[0].size();
//        int dp[n + 1][m + 1];
//        memset(dp, 0, sizeof(dp));
//
//        // 初始化
//        // dp[i][j] = max(dp[i-1][j] + grid[i-1][j-1], dp[i][j-1] + grid[i-1][j-1])
//
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= m; j++)
//            {
//                dp[i][j] = max(dp[i - 1][j] + grid[i - 1][j - 1], dp[i][j - 1] + grid[i - 1][j - 1]);
//            }
//        }
//
//        return dp[n][m];
//    }
//};



const int N = 110;
int t, n;
int main() {
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        bool arr[n][26];
        memset(arr, false, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++)
            {
                arr[i][s[j] - 'a'] = true;
            }
        }
        int l = 0, r = n - 1;
        bool flag = true;
        while (l <= r)
        {
            bool ans = false;
            for (int j = 0; j < 26; j++)
            {
                if (arr[l][j] == true && arr[r][j] == true)
                {
                    ans = true;
                    break;
                }
            }
            if (ans == false)
            {
                flag = false;
                break;
            }
            l++, r--;
        }
        if (flag == true) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
// 64 位输出请用 printf("%lld")