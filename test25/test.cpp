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


//class Solution {
//    int dp[100010] = { 0 };// dp[i] 表示以dp[i]为结尾长度为i的子序列
//    int pos = 0;
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 该数组最长严格上升子序列的长度
//     * @param a int整型vector 给定的数组
//     * @return int整型
//     */
//    int LIS(vector<int>& a) {
//        // write code here
//        int n = a.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (pos == 0 || a[i] > dp[pos])
//            {
//                dp[++pos] = a[i];
//            }
//            else
//            {
//                // 二分查找插入的合适位置
//                int l = 1, r = pos;
//                while (l < r)
//                {
//                    int mid = (l + r) / 2;
//                    if (dp[mid] >= a[i]) r = mid;
//                    else l = mid + 1;
//                }
//                dp[l] = a[i];
//            }
//        }
//        return pos;
//    }
//};



//const int N = 1010;
//int dp[N][N] = { 0 };
//int n, m;
//string s1, s2;
//int main() {
//    cin >> n >> m >> s1 >> s2;
//    s1 = ' ' + s1;
//    s2 = ' ' + s2;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
//            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//        }
//    }
//
//    cout << dp[n][m] << endl;
//}
//// 64 位输出请用 printf("%lld")




//#include <iostream>

//int sum = 0;
//const int N = 20, M = N * 9;
//int n;
//string s;
//bool fun()
//{
//    bool dp[M];
//    memset(dp, false, sizeof(dp)); // 初始化为 false
//    dp[0] = true;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = sum; j >= (s[i] - '0'); j--)
//        {
//            dp[j] = dp[j] || dp[j - (s[i] - '0')];
//        }
//    }
//    return dp[sum];
//}
//int main() {
//
//    cin >> s;
//    n = s.size();
//    for (int i = 0; i < n; i++) sum += s[i] - '0';
//
//    if (sum % 2 != 0) cout << "No" << endl;
//
//    else
//    {
//        sum /= 2;
//        if (fun()) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")



//int main() {
//    int n;
//    while (cin >> n)
//    {
//        int ret = 1;
//        while (ret - 1 <= n) ret *= 2;
//        cout << ret / 2 - 1 << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")




//const int N = 1010;
//int dp[N][N]; // dp[i][j]表示 s1 串[0, i]区间与 s2 串[0, j]区间最小的编码距离
//string s1, s2;
//int main() {
//    cin >> s1 >> s2;
//    s1 = ' ' + s1;
//    s2 = ' ' + s2;
//    int n1 = s1.size(), n2 = s2.size();
//    // 初始化a
//    for (int i = 0; i < n1; i++) dp[i][0] = i;
//    for (int j = 0; j < n2; j++) dp[0][j] = j;
//
//    for (int i = 1; i <= n1; i++)
//    {
//        for (int j = 1; j <= n2; j++)
//        {
//            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
//
//            else
//            {
//                dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
//            }
//        }
//    }
//
//    cout << dp[n1][n2] << endl;
//}
//// 64 位输出请用 printf("%lld")



//struct ListNode {
// 	int val;
//	struct ListNode *next;
// 	ListNode(int x) : val(x), next(nullptr) {}
//};
// 
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//    const int N = 1e5 + 1;
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // write code here
//        // 先保存在vector，然后再存入链表
//        int k = lists.size();
//        ListNode* cur1 = lists[0];
//        ListNode* head = nullptr;
//        for (int i = 1; i < k; i++)
//        {
//            ListNode* cur2 = lists[i];
//            // 将cur1与cur2进行排序
//            // 先确定头
//            head = cur1->val > cur2->val ? cur2 : cur1;
//            ListNode* tail = head;
//            while (cur1 || cur2)
//            {
//                int v1 = (cur1 == nullptr ? N : cur1->val);
//                int v2 = (cur2 == nullptr ? N : cur2->val);
//                if (v1 < v2)
//                {
//                    tail->next = cur1;
//                    tail = tail->next;
//                    cur1 = cur1->next;
//                }
//                else
//                {
//                    tail->next = cur2;
//                    tail = tail->next;
//                    cur2 = cur2->next;
//                }
//                cout << "1" << endl;
//            }
//            // 排完
//            cur1 = head;
//        }
//        return head;
//    }
//};
//
//int main()
//{
//    Solution s;
//    ListNode* head1, * head2;
//    ListNode* cur1 = new ListNode(1);
//    ListNode* cur2 = new ListNode(2);
//    ListNode* cur3 = new ListNode(3);
//    cur1->next = cur2;
//    cur2->next = cur3;
//
//    ListNode* cur4 = new ListNode(4);
//    ListNode* cur5 = new ListNode(5);
//    cur4->next = cur5;
//
//    head1 = cur1;
//    head2 = cur4;
//    vector<ListNode*> v;
//    v.push_back(head1);
//    v.push_back(head2);
//    s.mergeKLists(v);
//    return 0;
//}


//// dfs + 记忆化搜索
//const int N = 105;
//int p[N][N], n, m;
//int memo[N][N] = { -1 };
//int ret = 0;
//
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//
//int dfs(int i, int j)
//{
//    if (memo[i][j] != -1) return memo[i][j];
//    int ans = 1;
//    for (int k = 0; k < 4; k++)
//    {
//        int x = i + dx[k], y = j + dy[k];
//        if (x >= 0 && y >= 0 && x < n && y < m && p[x][y] > p[i][j])
//        {
//            ans = max(ans, dfs(x, y) + 1);
//        }
//    }
//    memo[i][j] = ans;
//    //cout << "1" << endl;
//    return ans;
//}
//int main() {
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> p[i][j];
//
//    //
//    memset(memo, -1, sizeof(memo));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            ret = max(ret, dfs(i, j));
//        }
//    }
//
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")



//int cnt[26];
//int main() {
//    memset(cnt, 0, sizeof(cnt));
//    int ret = 0;
//    char ans;
//    string s;
//    while (getline(cin, s))
//    {
//        // cout << s << endl;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (s[i] == ' ') continue;
//            int pos = s[i] - 'a';
//            cnt[pos]++;
//            if (cnt[pos] > ret)
//            {
//                ret = cnt[pos];
//                ans = s[i];
//            }
//        }
//    }
//    cout << ans << endl;
//}
//// 64 位输出请用 printf("%lld")


//int main()
//{
//	int a = 32;
//	int x = pow(a, 0.5);
//	cout << x << endl;
//	return 0;
//}


//const int N = 1010;
//int n, t[N];
//int main() {
//    // 剩余学生身高 倒 V
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> t[i];
//
//    // 使得 k 尽可能大
//    // 动态规划
//    int f[n + 1], g[n + 1]; // f[i] 表示前 i 个学生，最高的身高升序个数
//    // g[i] 表示后 i 个学生，最高的身高升序个数
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 1; j < i; j++)
//        {
//            if (t[i] > t[j]) f[i] = max(f[i], f[j] + 1);
//        }
//        cout << f[i] << " ";
//    }
//    cout << endl;
//    for (int i = n; i >= 2; i--)
//    {
//        for (int j = n; j > i; j--)
//        {
//            if (t[i] > t[j]) f[i] = max(g[i], g[j] + 1);
//        }
//        cout << g[i] << " ";;
//    }
//    cout << endl;
//    int ret = 0;
//
//    for (int i = 1; i <= n; i++)
//    {
//        ret = max(ret, f[i] + g[i] - 1);
//    }
//    cout << n - ret << endl;
//}
//// 64 位输出请用 printf("%lld")



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numProject int整型
     * @param groups int整型vector<vector<>>
     * @return int整型vector
     */
    vector<int> findOrder(int numProject, vector<vector<int> >& groups) {
        // write code here

        vector<vector<int>> edges(numProject); // 邻接表存储边
        vector<int> in(numProject); // 标记每一个点的入度
        queue<int> q;
        // 拓扑排序
        vector<int> ret;
        // 先建图
        for (int i = 0; i < numProject; i++)
        {
            int a = groups[i][0], b = groups[i][1];
            edges[a].push_back(b);
            in[b]++;
        }
        for (int i = 0; i < numProject; i++) {

            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        while (q.size())
        {
            int a = q.front();
            q.pop();
            ret.push_back(a);
            for (auto b : edges[a])
            {
                if (--in[b] == 0)
                    q.push(b);
            }
        }

        if (ret.size() == numProject)
        {
            for (int i = 0; i < numProject; i++)
            {
                cout << ret[i] << " ";
            }
            return ret;
        }
        else
        {
            vector<int> ret;
            return ret;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v;
    v.push_back({ 2,1 });
    s.findOrder(3, v);
    return 0;
}