#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
using namespace std;


//class Solution {
//    int dp[100010] = { 0 };// dp[i] ��ʾ��dp[i]Ϊ��β����Ϊi��������
//    int pos = 0;
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ��������ϸ����������еĳ���
//     * @param a int����vector ����������
//     * @return int����
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
//                // ���ֲ��Ҳ���ĺ���λ��
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
//// 64 λ������� printf("%lld")




//#include <iostream>

//int sum = 0;
//const int N = 20, M = N * 9;
//int n;
//string s;
//bool fun()
//{
//    bool dp[M];
//    memset(dp, false, sizeof(dp)); // ��ʼ��Ϊ false
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
//// 64 λ������� printf("%lld")



//int main() {
//    int n;
//    while (cin >> n)
//    {
//        int ret = 1;
//        while (ret - 1 <= n) ret *= 2;
//        cout << ret / 2 - 1 << endl;
//    }
//}
//// 64 λ������� printf("%lld")




//const int N = 1010;
//int dp[N][N]; // dp[i][j]��ʾ s1 ��[0, i]������ s2 ��[0, j]������С�ı������
//string s1, s2;
//int main() {
//    cin >> s1 >> s2;
//    s1 = ' ' + s1;
//    s2 = ' ' + s2;
//    int n1 = s1.size(), n2 = s2.size();
//    // ��ʼ��a
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
//// 64 λ������� printf("%lld")



//struct ListNode {
// 	int val;
//	struct ListNode *next;
// 	ListNode(int x) : val(x), next(nullptr) {}
//};
// 
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param lists ListNode��vector
//     * @return ListNode��
//     */
//    const int N = 1e5 + 1;
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // write code here
//        // �ȱ�����vector��Ȼ���ٴ�������
//        int k = lists.size();
//        ListNode* cur1 = lists[0];
//        ListNode* head = nullptr;
//        for (int i = 1; i < k; i++)
//        {
//            ListNode* cur2 = lists[i];
//            // ��cur1��cur2��������
//            // ��ȷ��ͷ
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
//            // ����
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


//// dfs + ���仯����
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
//// 64 λ������� printf("%lld")



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
//// 64 λ������� printf("%lld")


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
//    // ʣ��ѧ����� �� V
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> t[i];
//
//    // ʹ�� k �����ܴ�
//    // ��̬�滮
//    int f[n + 1], g[n + 1]; // f[i] ��ʾǰ i ��ѧ������ߵ�����������
//    // g[i] ��ʾ�� i ��ѧ������ߵ�����������
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
//// 64 λ������� printf("%lld")



//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param numProject int����
//     * @param groups int����vector<vector<>>
//     * @return int����vector
//     */
//    vector<int> findOrder(int numProject, vector<vector<int> >& groups) {
//        // write code here
//
//        vector<vector<int>> edges(numProject); // �ڽӱ�洢��
//        vector<int> in(numProject); // ���ÿһ��������
//        queue<int> q;
//        // ��������
//        vector<int> ret;
//        // �Ƚ�ͼ
//        for (int i = 0; i < numProject; i++)
//        {
//            int a = groups[i][0], b = groups[i][1];
//            edges[a].push_back(b);
//            in[b]++;
//        }
//        for (int i = 0; i < numProject; i++) {
//
//            if (in[i] == 0)
//            {
//                q.push(i);
//            }
//        }
//        while (q.size())
//        {
//            int a = q.front();
//            q.pop();
//            ret.push_back(a);
//            for (auto b : edges[a])
//            {
//                if (--in[b] == 0)
//                    q.push(b);
//            }
//        }
//
//        if (ret.size() == numProject)
//        {
//            for (int i = 0; i < numProject; i++)
//            {
//                cout << ret[i] << " ";
//            }
//            return ret;
//        }
//        else
//        {
//            vector<int> ret;
//            return ret;
//        }
//    }
//};

//int main()
//{
//    Solution s;
//    vector<vector<int>> v;
//    v.push_back({ 2,1 });
//    s.findOrder(3, v);
//    return 0;
//}


//#include <unordered_map>
//#include <utility>
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param A int����vector<vector<>>
//     * @param f int����vector<vector<>>
//     * @return int����vector<vector<>>
//     */
//
//    vector<vector<int> > flipChess(vector<vector<int>>& A, vector<vector<int> >& f) {
//        // write code here
//        // �����ת����Ϊż������ô�Ͳ���Ҫ��ת
//        int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
//        int n = A.size();
//        bool vis[4][4];
//        memset(vis, false, sizeof(vis));
//        for (int i = 0; i < f.size(); i++)
//        {
//            int a = f[i][0] - 1;
//            int b = f[i][1] - 1;
//            // cout << a << " " << b;
//            for (int k = 0; k < 4; k++)
//            {
//                int x = a + dx[k];
//                int y = b + dy[4];
//                //cout << x << " " << y << endl;
//                if (x >= 0 && y >= 0 && x < 4 && y < 4)
//                {
//                    if (vis[x][y] == false) vis[x][y] = true;
//                    else vis[x][y] = false;
//                    //cout << x << " " << y << endl;
//                }
//            }
//        }
//
//        for (int i = 0; i < 4; i++)
//        {
//            for (int j = 0; j < 4; j++)
//            {
//                if (vis[i][j])
//                {
//                    cout << i << " " << j << endl;
//                    if (A[i][j] == 0) A[i][j] = 1;
//                    else A[i][j] = 0;
//                }
//            }
//        }
//        return A;
//    }
//};



// const int N = 1e5 + 10;
//int n, a[N];
//int func(int pos) // ��posΪ��㣬��ʼ���ɺڰ�
//{
//    long long ret = 0;
//    long long dp[N]; // dp[i] ��ʾ��iΪ����������������֣���õı�ʳֵ
//    for (int i = 0; i < 3; i++) {
//        dp[i] = a[i + 1];
//        if (n > i + 2) ret = max(ret, dp[i]);
//    }
//    dp[3] = dp[0] + a[4];
//    if (n > 5) ret = max(ret, dp[3]);
//
//    dp[4] = a[5];
//    long long t = max(dp[0], dp[1]);
//    dp[4] += t;
//    if (n > 6) ret = max(ret, dp[4]);
//
//    for (int i = 5; i < n - 2; i++)
//    {
//        dp[i] = a[i + 1];
//        long long t = max(dp[i - 3], max(dp[i - 4], dp[i - 5]));
//        dp[i] += t;
//        ret = max(ret, dp[i]);
//    }
//    return ret;
//}
//int main() {
//    // �е����ƴ�ҽ���
//    // ��̬�滮
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    long long ret = func(0);
//
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")
//
//int main()
//{
//    Solution s;
//    vector<vector<int>> v;
//    // [[0,0,1,1],[1,0,1,0],[0,1,1,0],[0,0,1,0]],[[2,2],[3,3],[4,4]]
//    v.push_back({ 0,0,1,1 });
//    v.push_back({ 1,0,1,0 });
//    v.push_back({ 0,1,1,0 });
//    v.push_back({ 0,0,1,0 });
//    vector<vector<int>> f;
//    f.push_back({ 2,2 });
//    f.push_back({ 3,3 });
//    f.push_back({ 4,4 });
//
//    s.flipChess(v, f);
//    return 0;
//}



//
//const int N = 1e5 + 10;
//int n;
//long long a[N];
//
//long long func() {
//    if (n < 3) return 0;
//
//    vector<long long> dp(n + 5, 0);
//    long long ret = 0;
//
//    // ��ʼ�����п��ܵ����
//    for (int i = 0; i <= n - 3; i++) {
//        dp[i] = a[i + 1];  // ��iΪ��㣬���a[i+1]�ı�ʳ��
//    }
//    // ����ǰ�����������
//    if (n >= 3) ret = max(ret, dp[0]);
//    if (n >= 4) ret = max(ret, dp[1]);
//    if (n >= 5) ret = max(ret, dp[2]);
//    if (n >= 6) ret = max(ret, dp[3]);
//
//    // ��̬�滮ת��
//    for (int i = 3; i <= n - 3; i++) {
//        // ���Դ�i-3, i-4, i-5��λ��ת�ƹ���
//        long long prev_max = 0;
//        if (i - 3 >= 0) prev_max = max(prev_max, dp[i - 3]);
//        if (i - 4 >= 0) prev_max = max(prev_max, dp[i - 4]);
//        if (i - 5 >= 0) prev_max = max(prev_max, dp[i - 5]);
//
//        dp[i] += prev_max;
//        ret = max(ret, dp[i]);
//    }
//
//    return ret;
//}
//
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    long long ret = func();
//    cout << ret << endl;
//
//    return 0;
//}





//int n, l, r;
//string s;
//int main() {
//    cin >> n >> l >> r >> s;
//    int cnt[26];
//    memset(cnt, 0, sizeof(cnt));
//    // i,j
//    int ans = 0, ret = 0;
//    int j = 0, i = 0;
//    for (; j < n; j++)
//    {
//        int pos = s[j] - 'a';
//        if (cnt[pos] == 0) ans++;
//        cnt[pos]++;
//
//
//        while (ans > r)
//        {
//            int e = s[i++] - 'a';
//            cnt[e]--;
//            if (cnt[e] == 0) ans--;
//        }
//
//        if (ans >= l)
//        {
//            int tl = i;
//            int ta = ans;
//            int tempCnt[26];
//            memcpy(tempCnt, cnt, sizeof(cnt));
//
//            while (ta >= l)
//            {
//                ret++;
//                int tempPos = s[tl] - 'a';
//                tempCnt[tempPos]--;
//                if (tempCnt[tempPos] == 0)
//                {
//                    ta--;
//                }
//                tl++;
//            }
//        }
//    }
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")




//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ���ٻ�����
//     * @param arr int����vector the array
//     * @param aim int���� the target
//     * @return int����
//     */
//    int minMoney(vector<int>& arr, int aim) {
//        // write code here
//        int dp[aim + 1]; // dp[i] ��ʾҪ���� i Ԫ�������ٻ���
//        for (int i = 1; i <= aim; i++) dp[i] = aim + 1;
//        dp[0] = 0;
//        for (int i = 0; i <= aim; i++)
//        {
//            for (int j = 0; j < arr.size(); j++)
//            {
//                if (i >= arr[j]) dp[i] = min(dp[i], dp[i - arr[j]] + 1);
//            }
//        }
//        return dp[aim] > aim ? -1 : dp[aim];
//    }
//};




//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int N = 2e5 + 10;
//int n, l, r;
//int main() {
//    n = 5, l = 2, r = 3;
//    int a[5] = { 3,1,6,2,5 };
//
//    sort(a, a + n);
//
//    // ����
//    long long ret = 0;
//    for (int i = 0; i < n; i++)
//    {
//        // Ѱ�������� �� ������
//        // a[i] �������� �� ������
//        // ��Ѱ����
//        int left = i + 1, right = n - 1;
//        int begin = 0, end = 0;
//        int ans = a[i] + l;
//        while (left < right)
//        {
//            int mid = (right - left) / 2 + left;
//            if (a[mid] < ans) left = mid + 1;
//            else right = mid - 1;
//        }
//        begin = left;
//        // Ѱ��������
//        ans = a[i] + r;
//        while (left < right)
//        {
//            int mid = (right - left) / 2 + left;
//            if (a[mid] < ans) left = mid + 1;
//            else right = mid - 1;
//        }
//        end = left;
//
//        ret += (end - begin + 1);
//    }
//
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")


//#include <iostream>
//using namespace std;
//const int N = 1e9 + 7;
//int n;
//long long ret1 = 0, ret2 = 0;
//void hanoi1(int n, char from, char to, char aux)
//{
//    ret1 += 1;
//    ret1 %= N;
//    if (n == 1)
//        return;
//    hanoi1(n - 1, from, to, aux);
//
//    hanoi1(n - 1, to, aux, from);
//
//    hanoi1(n - 1, aux, to, from);
//}
//
//void hanoi2(int n, char from, char to, char aux)
//{
//    ret2 += 1;
//    ret2 %= N;
//    if (n == 1)
//    {
//        ret2 += 1;
//        return;
//    }
//
//
//    hanoi1(n - 1, from, to, aux);
//
//    hanoi1(n - 1, to, aux, from);
//
//    hanoi1(n - 1, to, from, aux);
//
//    hanoi1(n - 1, from, to, aux);
//
//    hanoi1(n - 1, to, aux, from);
//}
//int main() {
//    cin >> n;
//    hanoi1(n, 'A', 'B', 'C');
//
//    hanoi2(n, 'A', 'C', 'B');
//
//    cout << ret1 << " " << ret2 << endl;
//}
//// 64 λ������� printf("%lld")



#include <iostream>
using namespace std;

const int MOD = 1000000007; // ͨ��ʹ��10^9+7��Ϊģ��

int main() {
    int n;
    cin >> n;
    int x = 1, y = 2;
    for (int i = 2; i <= n; i++)
    {
        int xx = x, yy = y;
        x = (2 * yy + 1) % MOD;
        y = ((2 * yy) % MOD + 2 + xx) % MOD;
    }

    cout << x << " " << y << endl;
}
// 64 λ������� printf("%lld")