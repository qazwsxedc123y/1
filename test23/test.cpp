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
//        // ���1  ż��0
//        if (t % 2 == 0) //0
//        {
//            v.push_back(0);
//        }
//        else v.push_back(1);
//        n /= 10;
//    }
//    // ����ǰ��0
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
//// 64 λ������� printf("%lld")


//const int N = 1e7 + 5;
//int n, m;
//long long arr[10][10];
//long long func(int x, int y)
//{
//    // �ȼ�����
//    // �������
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
//// 64 λ������� printf("%lld")



//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param param string�ַ���
//     * @return string�ַ���
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
//// �ѵ�top K����
//// �ټ���һ����ϣ��
//const int N = 2e5 + 10;
//long long arra[N]; // ��
//long long arrb[N]; // ��
//unordered_map<long long, vector<long long>> hash1;
//priority_queue<long long> q;
//long long n, k;
//int main() {
//    cin >> n >> k;
//    // ��������
//    // ����
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
//    long long ans1 = 0; // �����
//    long long ans2 = 0; // �����
//
//    for (long long i = 0; i < k; i++)
//    {
//        long long t = q.top();
//        q.pop();
//        ans2 += t;
//        // ȡ��С�����
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
//// 64 λ������� printf("%lld")
//


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// �ѵ�top K����
//const int N = 2e5 + 10;
//typedef pair<int, int> PII; // <���,���>
//int arra[N]; // ��
//int arrb[N]; // ��
//priority_queue<long long> q;
//int n, k;
//
//struct cmp {
//    bool operator()(const PII& a, const PII& b)
//    {
//        if (a.first != b.first)
//        {
//            return a.first < b.first; // ��ȴ������
//        }
//        else
//        {
//            return a.second > b.second; // �����ͬ�����С������
//        }
//    }
//};
//
//int main() {
//    cin >> n >> k;
//    // ��������
//    // ����
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
//    long long ans1 = 0; // �����
//    long long ans2 = 0; // �����
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
//// 64 λ������� printf("%lld")
//
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// �ѵ�top K����
//const int N = 2e5 + 10;
//typedef pair<int, int> PII; // <���,���>
//int arra[N]; // ��
//int arrb[N]; // ��
//priority_queue<long long> q;
//int n, k;
//PII arr[N];
//
//struct cmp {
//    bool operator()(const PII& a, const PII& b)
//    {
//        if (a.first != b.first)
//        {
//            return a.first < b.first; // ��ȴ������
//        }
//        else
//        {
//            return a.second > b.second; // �����ͬ�����С������
//        }
//    }
//};
//
//int main() {
//    cin >> n >> k;
//    // ��������
//    // ����
//    for (long long i = 0; i < n; i++) cin >> arr[i].second;
//
//    for (long long i = 0; i < n; i++) cin >> arr[i].first;
//
//    sort(arr, arr + n, [&](const PII& a, const PII& b)
//        {
//            if (a.first != b.first)
//            {
//                return a.first > b.first; // ��ȴ������
//            }
//            else
//            {
//                return a.second < b.second; // �����ͬ�����С������
//            }
//        });
//
//    long long ans1 = 0; // �����
//    long long ans2 = 0; // �����
//
//    for (int i = 0; i < k; i++)
//    {
//        ans1 += arr[i].second;
//        ans2 += arr[i].first;
//    }
//    cout << ans1 << " " << ans2 << endl;
//}
//// 64 λ������� printf("%lld")




//#include <iostream>
//#include <memory.h>
//using namespace std;
//const int N = 1024;
//
//int n, V, v[N], w[N];
//// ��һ�ʣ�dp[i][j] ��ʾ�� i ����Ʒ��ѡ������������� j ������ѡ����ѡ����������ֵ
//// �ڶ��ʣ�dp[i][j] ��ʾ�� i ����Ʒ��ѡ�������ǡ��Ϊ j ������ѡ����ѡ����������ֵ
//int dp[N][N];
//
//int main() {
//    // ��������
//    cin >> n >> V;
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // ��һ��
//    // ��ʼ�� ȫΪ0
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= V; j++)
//        {
//            // ��ѡ dp[i][j] = dp[i-1][j]
//            // ѡ   dp[i][j] = w[i] + dp[i-1][j-v[i]]
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i]) dp[i][j] = max(w[i] + dp[i - 1][j - v[i]], dp[i][j]);
//        }
//    }
//    cout << dp[n][V] << endl;
//
//    // �ڶ���
//    memset(dp, 0, sizeof(dp));
//
//    // ��ʼ��
//    for (int i = 1; i <= V; i++) dp[0][i] = -1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= V; j++)
//        {
//            // ��ѡ dp[i][j] = dp[i-1][j];
//            // ѡ dp[i][j] = w[i] + dp[i-1][j-v[i]]
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
//// ��һ�ʣ�dp[i][j] ��ʾ�� i ����Ʒ��ѡ������������� j ������ѡ����ѡ����������ֵ
//// �ڶ��ʣ�dp[i][j] ��ʾ�� i ����Ʒ��ѡ�������ǡ��Ϊ j ������ѡ����ѡ����������ֵ
//int dp[N];
//
//int main() {
//    // ��������
//    cin >> n >> V;
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // ��һ��
//    // ��ʼ�� ȫΪ0
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = V; j >= v[i]; j--)
//        {
//            dp[j] = max(w[i] + dp[j - v[i]], dp[j]);
//        }
//    }
//    cout << dp[V] << endl;
//
//    // �ڶ���
//    memset(dp, 0, sizeof(dp));
//
//    // ��ʼ��
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
//// 64 λ������� printf("%lld")


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
//// 64 λ������� printf("%lld")


//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param grid int����vector<vector<>>
//     * @return int����
//     */
//    int maxValue(vector<vector<int> >& grid) {
//        // write code here
//        // ʹ�ö�̬�滮
//        // dp[i][j] ��ʾ�����±�Ϊ (i-1,j-1) ʱ���õ����ļ�ֵ
//        int n = grid.size(), m = grid[0].size();
//        int dp[n + 1][m + 1];
//        memset(dp, 0, sizeof(dp));
//
//        // ��ʼ��
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



//const int N = 110;
//int t, n;
//int main() {
//    cin >> t;
//    for (int k = 0; k < t; k++)
//    {
//        cin >> n;
//        bool arr[n][26];
//        memset(arr, false, sizeof(arr));
//        for (int i = 0; i < n; i++)
//        {
//            string s;
//            cin >> s;
//            for (int j = 0; j < s.size(); j++)
//            {
//                arr[i][s[j] - 'a'] = true;
//            }
//        }
//        int l = 0, r = n - 1;
//        bool flag = true;
//        while (l <= r)
//        {
//            bool ans = false;
//            for (int j = 0; j < 26; j++)
//            {
//                if (arr[l][j] == true && arr[r][j] == true)
//                {
//                    ans = true;
//                    break;
//                }
//            }
//            if (ans == false)
//            {
//                flag = false;
//                break;
//            }
//            l++, r--;
//        }
//        if (flag == true) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}
//// 64 λ������� printf("%lld")


//int a, h, b, k;
//int main() {
//    cin >> a >> h >> b >> k;
//    // ���� �� �ȹ��������������
//    // Ȼ���๥��
//    long long ret = 0;
//    while (h > 0 && k > 0)
//    {
//        int t = min(h / b, k / a);
//        ret = ret + t * b;
//        ret = ret + t * a;
//
//        h = h - t * b;
//        k = k - t * a;
//
//    }
//    if (h > 0 && k <= 0) ret = ret + 10 * a;
//    if (k > 0 && h <= 0) ret = ret + 10 * b;
//    cout << ret << endl;
//}
// 64 λ������� printf("%lld")



//const int N = 2e5 + 10;
//long long n, arr[N], dp[N]; // dp[i]��ʾ�±�[0,i-1]֮��ĺ�
//int main() {
//    // ǰ׺�� �� ��������
//    cin >> n;
//    for (long long i = 0; i < n; i++) cin >> arr[i];
//
//    for (long long i = 1; i <= n; i++) dp[i] = dp[i - 1] + arr[i - 1];
//
//    long long ret = 0;
//    for (long long i = 1; i <= n; i++) // ��
//    {
//        for (long long j = 1; j < i; j++) // ��
//        {
//            ret = max(ret, dp[i] - dp[j]);
//        }
//    }
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")


//#include <iostream>
//#include <string>
//using namespace std;
//
//string s;
//int n;
//int func()
//{
//    // ���ж��Ƿ�ȫΪ��ͬ�ַ�
//    bool flag = false;
//    for (int i = 1; i < n; i++)
//    {
//        if (s[i] != s[0])
//        {
//            flag = true;
//            break;
//        }
//    }
//    if (flag == false) return 0;
//
//    // �жϱ����Ƿ�Ϊ����
//    flag = true;
//    int left = 0, right = n - 1;
//    while (left < right)
//    {
//        if (s[left] == s[right])
//        {
//            left++, right--;
//        }
//        else
//        {
//            flag = false;
//            break;
//        }
//    }
//    if (flag == true) return n - 1;
//    else return n;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//const int N = 1e3 + 10;
//string s;
//bool dp[N][N];
//int main() {
//    cin >> s;
//    int n = s.size();
//    int ans = 1;
//
//    // ��ʼ������Ϊ1���Ӵ�
//    for (int i = 0; i < n; i++) {
//        dp[i][i] = true;
//    }
//
//    // ��鳤��Ϊ2���Ӵ�
//    for (int i = 0; i < n - 1; i++) {
//        if (s[i] == s[i + 1]) {
//            dp[i][i + 1] = true;
//            ans = 2;
//        }
//    }
//
//    // ��鳤�ȴ���2���Ӵ�
//    for (int len = 3; len <= n; len++) {
//        for (int i = 0; i + len - 1 < n; i++) {
//            int j = i + len - 1;
//            if (s[i] == s[j] && dp[i + 1][j - 1]) {
//                dp[i][j] = true;
//                ans = max(ans, len);
//            }
//        }
//    }
//
//    cout << ans << endl;
//    return 0;
//}




//#include <iostream>
//#include <string>
//using namespace std;
//const int N = 1e3 + 10;
//string s;
//int dp[N][N];
//int main() {
//    // ��̬�滮
//    // ����dp��
//    cin >> s;
//    int n = s.size();
//    // dp[i][j] ��ʾ�Ƿ�Ϊ����(i,j)�Ƿ�Ϊ��������
//    // dp[i][j] = 
//    // ���� [i+1, j-1] �ǻ������� ����s[i] == s[j]��dp[i][j] = dp[i+1][j-1] + 2;
//    // ��֮�κ�������� false
//
//    // ��ʼ��
//    // dp[x][x] = true
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= i; j++)
//            dp[i][j] = 1;
//    }
//    int ans = 1;
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j < i; j++)
//        {
//            if (i - j == 1)
//            {
//                if (s[i - 1] == s[j - 1]) dp[i][j] = 2;
//                else dp[i][j] = 1;
//            }
//            else
//            {
//                if (s[i - 1] == s[j - 1])
//                {
//                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                }
//                else dp[i][j] = dp[i + 1][j - 1];
//            }
//            ans = max(ans, dp[i][j]);
//        }
//    }
//    cout << ans << endl;
//}
//// 64 λ������� printf("%lld")



//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        int n = s.size();
//        int dp[n][n];
//        memset(dp, 0, sizeof(dp));
//
//        // ��ʼ���������ַ��������г���Ϊ1
//        for (int i = 0; i < n; i++) {
//            dp[i][i] = 1;
//        }
//
//        // ���Ӵ����� len = 2 ��ʼ����չ
//        for (int len = 2; len <= n; len++) {
//            for (int i = 0; i + len - 1 < n; i++) {
//                int j = i + len - 1;
//                if (s[i] == s[j]) {
//                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                }
//                else {
//                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//
//        return dp[0][n - 1];
//    }
//};



//string s1, s2;
//int main() {
//    cin >> s1 >> s2;
//    int sz1 = s1.size(), sz2 = s2.size();
//
//    // ģ�⣬����
//    int ans = 0;
//    for (int i = 0; i < sz2 - sz1; i++)
//    {
//        int count = 0;
//        for (int j = 0; j < sz1; j++)
//        {
//            if (s1[j] == s2[j + i])
//                count++;
//        }
//        ans = max(ans, count);
//    }
//
//    cout << sz1 - ans << endl;
//}
//// 64 λ������� printf("%lld")



//#include <iostream>
//#include <queue>
//using namespace std;
//const int N = 55;
//int n, arr[N];
//struct cmp
//{
//    bool operator()(const int& a, const int& b)
//    {
//        return b < a;
//    }
//};
//priority_queue<long long, vector<long long>, cmp> q;
//int main() {
//    cin >> n;
//    long long _max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        long long t;
//        cin >> t;
//        _max = max(_max, t);
//        q.push(t);
//    }
//
//    // ������������С�����Կ��Ա���
//
//    // �����ǰ��ֵ��2���������ֵ����ôֱ��No
//
//    while (!q.empty())
//    {
//        long long t = q.top();
//        q.pop();
//        if (t == _max)
//        {
//            cout << "YES" << endl;
//            break;
//        }
//        t *= 2;
//        if (t > _max) {
//            cout << "NO" << endl;
//            break;
//        }
//        else if (t < _max) q.push(t);
//    }
//}
//// 64 λ������� printf("%lld")



//
//#include <iostream>
//using namespace std;
//// ��������
//const int N1 = 40, N2 = 2e4 + 10;
//int V, n, v[N1];
//int dp[N2]; // dp[i][j] ��ʾ�� i ����Ʒ��ѡ������������� j ������ѡ����ѡ����������ֵ
//int main() {
//    cin >> V >> n;
//    for (int i = 1; i <= n; i++) cin >> v[i];
//
//    // �����ֵ�������
//    // ���װ����������Ȼ�����װ�����ļ�ֵ
//
//    // ѡ / ��ѡ
//    // ѡ dp[i][j] = dp[i-1][j-v[i-1]] + v[i];
//    // ��ѡ dp[i][j] = dp[i-1][j]
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = V; j >= v[i]; j--)
//        {
//            dp[j] = max(dp[j - v[i]] + v[i], dp[j]);
//        }
//    }
//    //cout << dp[n][V] << endl;
//    int ret = V - dp[V];
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")





class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param m int����vector<vector<>>
     * @return int����
     */
    int n;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    void dfs(vector<vector<int>>& m, int i, int j, vector<vector<bool>>& vis)
    {
        for (int k = 0; k < 4; k++)
        {
            int x = j + dx[k], y = i + dy[k];
            if (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == false && m[x][y] == 1)
            {
                vis[x][y] = true;
                dfs(m, x, y, vis);
                vis[x][y] = false;
            }
        }
    }
    int citys(vector<vector<int>>& m) {
        n = m.size();
        // write code here
        // dfs ͳ�ƶ��ٸ�����
        vector<vector<bool>> vis;
        vis.resize(n, vector<bool>(n));
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == 1 && vis[i][j] == false)
                {
                    vis[i][j] = true;
                    dfs(m, i, j, vis);
                    vis[i][j] = false;
                    ret++;
                }
            }
        }

        return ret;
    }
};


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param m int����vector<vector<>>
     * @return int����
     */
    bool vis[201] = { 0 };
    int citys(vector<vector<int> >& m) {
        // write code here
        int n = m.size();

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ret++;
                dfs(m, i);
            }
        }
        return ret;
    }
    void dfs(vector<vector<int> >& m, int pos)
    {
        vis[pos] = true;

        for (int i = 0; i < m.size(); i++)
        {
            if (m[pos][i] == 1 && !vis[i])
            {
                dfs(m, i);
            }
        }
    }
};