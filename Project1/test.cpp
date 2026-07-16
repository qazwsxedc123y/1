class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    bool func(int begin, int end, string& A)
    {
        while (begin <= end)
        {
            if (A[begin++] != A[end--])
            {
                return false;
            }
        }
        return true;
    }
    int getLongestPalindrome(string A) {
        // write code here
        // 动态规划- 空间复杂度n2
        // 暴力
        int n = A.size();
        int ret = 0;
        for (int i = 0; i < n; i++) // i开头
        {
            for (int j = i; j < n; j++) // j结尾
            {
                if (func(i, j, A))
                {
                    ret = max(ret, j - i + 1);
                }
            }
        }
        return ret;

    }
};


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    // 无手续费
    vector<int> f(n + 1); // f[i]表示当天有，最大利润
    auto g = f; // g[i]表示当天无，最大利润
    f[0] = -prices[0];
    g[0] = 0;
    for (int i = 1; i < n; i++)
    {
        g[i] = max(g[i - 1], f[i - 1] + prices[i]);
        f[i] = max(f[i - 1], g[i - 1] - prices[i]);
    }
    cout << max(f[n - 1], g[n - 1]);
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n = 0;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    // 无手续费
    int a = N, b = 0;
    for (int i = 0; i < n; i++)
    {
        b = max(b, prices[i] - a);
        a = min(a, prices[i]);
    }
    cout << b;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, x, y;
// 下 右
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
const int N = 21;
// int mx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// int my[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int main() {
    cin >> n >> m >> x >> y;
    // 动态规划
    int dp[N][N]; // dp[i-1][j-1] 到达i,j的条数
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) // x
    {
        for (int j = 1; j <= m; j++) // y
        {
            if (i == 1 && j == 1) continue;
            else if (abs(x - i) + abs(y - j) == 3 && x != i && y != j) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][m] << endl;
}
// 64 位输出请用 printf("%lld")