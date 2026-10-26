#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 访问过，或不为岛屿
                if (vis[i][j] || grid[i][j] == 0) continue;

                queue<pair<int, int>> q;
                q.push({ i, j });
                vis[i][j] = true;

                long long sum = 0;
                while (!q.empty())
                {
                    auto [x, y] = q.front(); q.pop();
                    sum += grid[x][y];

                    for (int k = 0; k < 4; k++)
                    {
                        int a = x + dx[k], b = y + dy[k];
                        if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && grid[a][b] != 0)
                        {
                            vis[a][b] = true;
                            q.push({ a, b });
                        }
                    }
                }

                if (sum % k == 0) ret++;
            }
        }
        return ret;
    }
};