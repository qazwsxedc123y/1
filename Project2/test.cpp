#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int m, n;
    int dx[2] = { 1, 0 }; // 下,右
    int dy[2] = { 0, 1 };
public:
    void dfs(int i, int j, int* ret, vector<vector<int>>& grid, int pos)
    {
        // pos: 0->右  1->下
        if (i == m - 1 && j == n - 1)
        {
            (*ret)++;
            return;
        }
        else if (i >= m || j >= n) return;

        if (grid[i][j] == 1)
        {
            pos = (pos == 0 ? 1 : 0);
            dfs(i + dx[pos], j + dy[pos], ret, grid, pos);
        }
        else
        {
            dfs(i, j + 1, ret, grid, 0); // 右
            dfs(i + 1, j, ret, grid, 1); // 下
        }
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 1;

        int ret = 0;
        dfs(0, 0, &ret, grid, 0);
        return ret;
    }
};
class Solution {
    int m, n;
    int dx[2] = { 0, 1 }; // 右,下
    int dy[2] = { 1, 0 };
    static const int MOD = 1e9 + 7;
    vector<vector<array<long long, 2>>> memo;
public:
    long long dfs(int i, int j, vector<vector<int>>& grid, int pos)
    {
        // pos: 0->右  1->下
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        else if (i >= m || j >= n) return 0;
        if (memo[i][j][pos] != -1) return memo[i][j][pos];

        int i0 = i, j0 = j, p0 = pos;

        // 连续
        while (grid[i][j] == 1)
        {
            pos = (pos == 0 ? 1 : 0);
            i += dx[pos];
            j += dy[pos];
            if (i >= m || j >= n) return memo[i0][j0][p0] = 0; // 反射越界 -> 无效
            if (i == m - 1 && j == n - 1) return memo[i0][j0][p0] = 1; // 反射落点即终点
        }
        long long ans = 0;
        ans = (ans + dfs(i, j + 1, grid, 0)) % MOD; // 右
        ans = (ans + dfs(i + 1, j, grid, 1)) % MOD; // 下   
        return memo[i0][j0][p0] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 1;
        memo.assign(m, vector<array<long long, 2>>(n, { -1, -1 }));
        return dfs(0, 0, grid, 0);
    }
};
int main()
{
    Solution s;
    // grid = [[0,1,0],[0,0,1],[1,0,0]]
    vector<int> v1{ 0,1,0 };
    vector<int> v2{ 0,0,1 };
    vector<int> v3{ 1,0,0 };
    vector<vector<int>> v{ v1, v2, v3 };
    s.uniquePaths(v);
    return 0;
}