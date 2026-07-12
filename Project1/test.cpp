#define  _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string str;
//    int begin = 0, end = 0, ans = 0;
//    int left = 0, right = 0;
//    cin >> str;
//    int n = str.size();
//    while (right < n)
//    {
//        if ((str[right] >= 'a' && str[right] <= 'z') || (str[right] >= 'A' && str[right] <= 'Z')) // 不是数字
//        {
//            right++;
//            left = right;
//        }
//        else
//        {
//            while (right < n && str[right] >= '0' && str[right] <= '9')
//            {
//                right++;
//            }
//            int len = right - left;
//            if (len > ans)
//            {
//                ans = len;
//                begin = left;
//                end = right - 1;
//            }
//            left = right;
//        }
//    }
//    cout << str.substr(begin, ans) << endl;
//}
//// 64 位输出请用 printf("%lld")



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    const int N = 205;
    int n, m;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    void dfs(int x, int y, vector<vector<char> >& grid, vector<vector<bool> >& vis)
    {
        for (int k = 0; k < 4; k++)
        {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1' && vis[a][b] == false)
            {
                vis[a][b] = true;
                dfs(a, b, grid, vis);
            }
        }
    }
    int solve(vector<vector<char> >& grid) {
        // write code here
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(N, vector<bool>(N));
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == false)
                {
                    ret++;
                    vis[i][j] = true;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ret;
    }
};



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> v(6);
    while (t--) {
        cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];
        sort(v.begin(), v.end());

        if ((v[0] + v[1] > v[2] && v[3] + v[4] > v[5]) ||
            (v[0] + v[1] > v[3] && v[2] + v[4] > v[5]) ||
            (v[0] + v[1] > v[4] && v[2] + v[3] > v[5]) ||
            (v[0] + v[1] > v[5] && v[2] + v[3] > v[4]) ||
            (v[1] + v[2] > v[3] && v[0] + v[4] > v[5]) ||
            (v[1] + v[2] > v[4] && v[0] + v[3] > v[5]) ||
            (v[1] + v[2] > v[5] && v[0] + v[3] > v[4]) ||
            (v[1] + v[3] > v[4] && v[0] + v[2] > v[5]) ||
            (v[1] + v[3] > v[5] && v[0] + v[2] > v[4]) ||
            (v[0] + v[2] > v[3] && v[1] + v[4] > v[5])) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")