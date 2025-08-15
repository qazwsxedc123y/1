#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
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


///**
// * struct TreeNode {
// *  int val;
// *  struct TreeNode *left;
// *  struct TreeNode *right;
// *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// * };
// */
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param root TreeNode类
//     * @return int整型
//     */
//    int maxSum = INT_MIN;
//    int maxGain(TreeNode* root) {
//        if (root == nullptr) return 0;
//
//        int leftGain = max(maxGain(root->left), 0);
//        int rightGain = max(maxGain(root->right), 0);
//
//        int priceNewpath = root->val + leftGain + rightGain;
//
//        maxSum = max(maxSum, priceNewpath);
//
//        return root->val + max(leftGain, rightGain);
//    }
//    int maxPathSum(TreeNode* root) {
//        maxGain(root);
//        return maxSum;
//        // write code here
//    }
//};



//const long long N = 1e4 + 10;
//long long T, arr[N];
//int main() {
//    // 有没有规律？
//    cin >> T;
//    // 2^n - 1
//    for (long long i = 1; i <= 7; i++)
//    {
//        long long j = 1;
//        long long cnt = 0;
//        while (true)
//        {
//            long long ans = pow(2, j) - 1;
//            if (ans >= i)
//            {
//                if (ans == i)
//                {
//                    arr[i] = j;
//                }
//                else
//                {
//                    cnt = j - 1;
//                    long long t = i - pow(2, cnt) + 1;
//                    arr[i] = cnt + arr[t];
//                }
//                break;
//            }
//            j++;
//        }
//    }
//    for (int i = 0; i < T; i++)
//    {
//        int t;
//        cin >> t;
//        cout << arr[t] << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")



//const int N = 15;
//int n, a[N], ret = 0;
//bool vis[N];
//void dfs(int pos)
//{
//    if (pos == n + 1)
//    {
//        ret++;
//        return;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        if (vis[i]) continue;
//        if (vis[a[i]]) return;
//        vis[i] = true;
//        dfs(pos + 1);
//        vis[i] = false;
//    }
//}
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//
//    dfs(1);
//    cout << ret << endl;
//    return 0;
//}



//const int N = 1e5 + 10;
//int n, arr[N];
//int ret = 0;
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//
//    for (int i = 0; i < n; i++)
//    {
//        if (i == n - 1)
//        {
//            ret++;
//            break;
//        }
//
//        if (arr[i] > arr[i + 1])
//        {
//            while (i + 1 < n && arr[i] >= arr[i + 1]) i++;
//            ret++;
//        }
//        else if (arr[i] < arr[i + 1])
//        {
//            while (i + 1 < n && arr[i] <= arr[i + 1]) i++;
//            ret++;
//        }
//    }
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")



//int t, h;
//void func()
//{
//    int ret = 0, a = 1;
//    while (h)
//    {
//        h -= a;
//        if (h % (a * 2) == 0)
//        {
//            a *= 2;
//        }
//        ret++;
//    }
//    cout << ret << endl;
//}
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        cin >> h;
//        func();
//    }
//    return 0;
//}



//int T;
//long long a, b;
//int main() {
//    cin >> T;
//    for (int i = 0; i < T; i++)
//    {
//        cin >> a >> b;
//        if (a == 1 || b == 1)
//        {
//            if (b == 1 && a == 1)
//            {
//                cout << "NO" << endl;
//            }
//            else
//            {
//                // 检查不为1的是不是素数
//                long long t = (a == 1 ? b : a);
//                bool flag = true;
//                for (long long j = 2; j <= pow(t, 0.5); j++)
//                {
//                    if (t % j == 0)
//                    {
//                        cout << "NO" << endl;
//                        flag = false;
//                        break;
//                    }
//                }
//                if (flag)
//                    cout << "YES" << endl;
//            }
//        }
//        else cout << "NO" << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")
//



//const int N = 2e5 + 10;
//int n, k, a[N];
//int main() {
//    cin >> n >> k;
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    sort(a, a + n);
//
//    int ret = 0, ans = 0;
//    // 滑动窗口
//    for (int l = 0, r = 0; r < n; r++)
//    {
//        ans = a[r] - a[l];
//        while (ans > k)
//        {
//            ans = a[r] - a[++l];
//        }
//        ret = max(ret, r - l + 1);
//    }
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")


//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//long long T, n, a, b;
//
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> n >> a >> b;
//        if (n <= 2) {
//            cout << min(a, b) << endl;
//            continue;
//        }
//        long long ret = 0;
//        if (a * 3 < b * 2)
//        {
//            // 双人
//            ret += n / 2 * a;
//            n %= 2;
//            if (n != 0)
//            {
//                ret += min(min(a, b), b - a);
//            }
//        }
//        else
//        {
//            ret = n / 3 * b;
//            if (n % 3 == 2) {
//                ret += min(3 * a - b, min(a, b));
//            }
//            else if (n % 3 == 1) {
//                ret = min(ret - b + 2 * a, ret + min(a, b));
//            }
//        }
//        cout << ret << endl;
//    }
//}



//typedef pair<int, int> PII;
//const int N = 2e5 + 10;
//int n;
//vector<vector<int>> v(N, vector<int>(2));
//struct cmp
//{
//    bool operator()(const PII& e1, const PII& e2)
//    {
//        return e1.first > e2.first;
//    }
//};
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];
//
//    sort(v.begin(), v.end());
//    // 区间合并
//    priority_queue<PII, vector<PII>, cmp> q;
//
//    q.push({ v[0][1], 1 });
//
//    for (int i = 1; i < n; i++)
//    {
//        int a = v[i][0];
//        if (a >= q.top().first)
//        {
//            int b = q.top().second;
//            q.pop();
//            q.push({ v[i][1], b + 1 });
//        }
//        else
//        {
//            q.push({ v[i][1], 1 });
//        }
//    }
//    int ret = 0;
//    while (!q.empty())
//    {
//        ret = max(ret, q.top().second);
//        q.pop();
//    }
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param str string字符串
//     * @return string字符串vector
//     */
//    int n;
//    vector<string> v;
//    bool vis[12] = { false };
//    string s;
//    void dfs(string& str)
//    {
//        if (s.size() == n)
//        {
//            v.push_back(s);
//            return;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            if (vis[i] == false)
//            {
//                if (i > 0 && str[i] == str[i - 1] && vis[i - 1] == false) continue;
//                s.push_back(str[i]);
//                vis[i] = true;
//                dfs(str);
//                s.pop_back();
//                vis[i] = false;
//            }
//        }
//    }
//    vector<string> Permutation(string str) {
//        // write code here
//        n = str.size();
//        sort(str.begin(), str.end());
//        dfs(str);
//        return v;
//    }
//};


//typedef pair<int, int> PII;
//
//int main() {
//    int n;
//    cin >> n;
//    if (n == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    vector<vector<int>> v(n, vector<int>(2));
//    for (int i = 0; i < n; i++)
//    {
//        cin >> v[i][0] >> v[i][1];
//    }
//
//    sort(v.begin(), v.end());
//    // 区间合并
//    priority_queue<PII, vector<PII>, greater<PII>> q; // 最小堆，比较第一个元素
//
//    q.push({ v[0][1], 1 });
//
//    for (int i = 1; i < n; i++)
//    {
//        int a = v[i][0];
//        if (a >= q.top().first)
//        {
//            int b = q.top().second;
//            q.pop();
//            q.push({ v[i][1], b + 1 });
//        }
//        else
//        {
//            q.push({ v[i][1], 1 });
//        }
//    }
//    int ret = 0;
//    while (!q.empty())
//    {
//        ret = max(ret, q.top().second);
//        q.pop();
//    }
//    cout << ret << endl;
//}
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef pair<int, int> PII;
//
//int main() {
//    int n;
//    cin >> n;
//    if (n == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    vector<vector<int>> v(n, vector<int>(2));
//    for (int i = 0; i < n; i++)
//    {
//        cin >> v[i][0] >> v[i][1];
//    }
//
//    sort(v.begin(), v.end());
//    int ret = 1, r = v[0][1];
//    for (int i = 1; i < n; i++)
//    {
//        if (v[i][0] < r)
//        {
//            r = min(r, v[i][1]);
//        }
//        else
//        {
//            ret++;
//            r = v[i][1];
//        }
//    }
//    cout << ret << endl;
//}


const int N = 1100;
bool vis[N][N];
int ret = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */

    void dfs(vector<vector<int> >& matrix, int x, int y, int len)
    {
        ret = max(ret, len);
        for (int k = 0; k < 4; k++)
        {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[0].size() && !vis[a][b] && matrix[a][b] > matrix[x][y])
            {
                vis[a][b] = true;
                dfs(matrix, a, b, len + 1);
                vis[a][b] = false;
            }
        }
    }
    int solve(vector<vector<int> >& matrix) {
        // write code here
        int n = matrix.size(), m = matrix[0].size();
        ret = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                memset(vis, false, sizeof(vis));
                vis[i][j] = true;
                dfs(matrix, i, j, 1);
            }
        }
        return ret;
    }
};