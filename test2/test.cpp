#define  _CRT_SECURE_NO_WARNINGS


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//long long a[10001], b[10001], n;
//int main()
//{
//    cin >> n;
//    for (long long i = 0; i < n; i++) {
//        cin >> a[i] >> b[i];
//    }
//
//    long long Max = INT_MAX, Min = 0;
//    for (long long i = 0; i < n; i++) {
//        Max = min(Max, a[i] / b[i]);
//        Min = max(Min, (a[i] + 1) / b[i]);
//    }
//    cout << Min << " " << Max;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//int n;
//long long a[100001];
//int Rnum(long long num) {
//    while (num / 10) {
//        num /= 10;
//    }
//    return num;
//}
//int Lnum(long long num) {
//    return num % 10;
//}
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    vector<int> dp(n, 1); //��ʾ��iΪ��β������Ҫ��������
//    int ret = 0;
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            int right = Rnum(a[i]);
//            int left = Lnum(a[j]);
//            if (left == right) dp[i] = max(dp[i], dp[j] + 1);
//        }
//        ret = max(ret, dp[i]);
//    }
//
//    return n - ret;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//int k;
//char c1, c2;
//string s;
//
//int main()
//{
//    cin >> k >> s >> c1 >> c2;
//    // ����һ��Ҫ����k
//    int n = s.size();
//    int left = 0;
//    int ret = 0;
//    for (; left < n - k; left++) {
//        int right = left + k - 1;
//        if (s[left] == c1) {
//            while (right < n) {
//                if (s[right] == c2) ret++;
//                right++;
//            }
//        }
//    }
//    cout << ret;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//int k;
//char c1, c2;
//string s;
//
//int main()
//{
//    cin >> k >> s >> c1 >> c2;
//    // ����һ��Ҫ����k
//    int n = s.size();
//    vector<int> starts, ends;
//    for (int i = 0; i < n; i++) {
//        if (s[i] == c1) starts.push_back(i);
//        if (s[i] == c2) ends.push_back(i);
//    }
//
//    long long ret = 0;
//    for (auto i : starts) {
//        ret += ends.end() - lower_bound(ends.begin(), ends.end(), i + k - 1);
//    }
//    cout << ret;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100001;
vector<pair<int, int>> g[N];
int n, m, s[N], t[N];
bool vis[N]; // ���Ƿ��±�ǣ����Ƿ��߹�
// dfs����ʵ�ֿ�s��t�Ƿ���ͨ
bool dfs(int s, int t, int id) {
    if (s == t) return true;

    for (int i = 0; i < g[s].size(); i++) {
        int nxt = g[s][i].first, edgedd = g[s][i].second;
        // �������Ѿ���ɾ
        if (edgedd == id) continue;
        // ������߹�
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        if (dfs(nxt, t, id)) return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({ v, i });
        g[v].push_back({ u, i });
    }

    for (int i = 1; i <= m; i++) cin >> s[i] >> t[i];

    // �Ӻ���ǰ
    for (int i = n - 1; i >= 1; i--) {

        //ɾ����i����
        bool flag = true;
        for (int j = 1; j <= m; j++) {
            memset(vis, 0, sizeof(vis));
            vis[s[j]] = true;
            if (dfs(s[j], t[j], i)) {
                // ������ͨ
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << i << " ";
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
