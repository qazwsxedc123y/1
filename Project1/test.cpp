#include <iostream>
using namespace std;
int func(int a, int b)
{
    int c = 0;
    while (1)
    {
        if (a < b) swap(a, b);
        c = a - b;
        if (b == c || c == 0) return b;
        a = b;
        b = c;
    }
    return 1;
}
int main() {
    int a, b;
    cin >> a >> b;
    // a * b * 最小公因数
    int ans = func(a, b);
    long long ret = a * b / ans;
    cout << ret << endl; // 大数相乘
}
// 64 位输出请用 printf("%lld")


#include <queue>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr) {
        // write code here
        int ret = 0;
        priority_queue<int> q;
        for (auto e : arr)
        {
            q.push(e);
        }
        int ans = q.top();
        q.pop();
        int len = 1;
        while (!q.empty())
        {
            int t = q.top();
            q.pop();
            // cout << ans << " " << t << " " << len << endl;
            if (t == ans - 1)
            {
                len++;
            }
            else if (t == ans)
            {
                continue;
            }
            else
            {
                ret = max(ret, len);
                len = 1;
            }
            ans = t;
        }
        ret = max(ret, len);
        return ret;
    }
};


#include <iostream>
#include <vector>
using namespace std;
const int N = 510;
int main() {
    int n, m;
    cin >> n >> m;
    int dp[N][N]; // dp[i + 1][j + 1] 表示到达i,j处最多得分
    vector<vector<char>> v(N, vector<char>(N));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int t;
    if (v[0][0] == 'l') t = 4;
    else if (v[0][0] == 'o') t = 3;
    else if (v[0][0] == 'v') t = 2;
    else if (v[0][0] == 'e') t = 1;
    dp[1][1] = t;


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1) continue;
            int t = 0;
            if (v[i - 1][j - 1] == 'l') t = 4;
            else if (v[i - 1][j - 1] == 'o') t = 3;
            else if (v[i - 1][j - 1] == 'v') t = 2;
            else if (v[i - 1][j - 1] == 'e') t = 1;

            dp[i][j] = t + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")2 3
