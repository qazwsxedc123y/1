#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
const int N = 105;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "Yes" << endl;
            continue;
        }
        vector<unordered_set<char>> str(N);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++)
            {
                str[i].insert(s[j]);
            }
        }

        int l = 0, r = n - 1;
        bool fg = true;
        while (l < r)
        {
            bool f = false;
            for (int i = 0; i < 32; i++)
            {
                char ans = 'a' + i;
                if (str[l].find(ans) != str[l].end() && str[r].find(ans) != str[r].end())
                {
                    f = true;
                    break;
                }
            }
            if (f == false) {
                fg = false;
                break;
            }
            l++;
            r--;
        }
        if (fg) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
// 64 位输出请用 printf("%lld")





class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int m, n;
    const int N = 202;
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        int m = grid.size();
        int n = grid[0].size();
        long long dp[N][N]; // dp[i][j] 表示到达[i-1,j-1]最大值
        // dp[1][1]  = grid[0][0];
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};



#include <iostream>
#include <algorithm>
using namespace std;
int func(int a, int b)
{
    if (a < b) swap(a, b);
    int c = 0;
    while (1)
    {
        c = a % b;
        if (c == 0) return b;
        a = b;
        b = c;
    }
    return 1;
}
int main() {
    long long n, x, t;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t <= x)
        {
            x += t;
        }
        else
        {
            x += func(x, t);
        }
    }
    cout << x << endl;
}
// 64 位输出请用 printf("%lld")