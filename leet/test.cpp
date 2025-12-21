#define  _CRT_SECURE_NO_WARNINGS

//
//class Solution {
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, 1, -1 };
//    int ret = 0;
//    int n, m;
//    typedef pair<int, int> PII;
//    int count;
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        n = grid.size();
//        m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 1)
//                {
//                    count = 1;
//                    bfs(grid, i, j);
//                    ret = max(ret, count);
//                }
//            }
//        }
//        return ret;
//    }
//    void bfs(vector<vector<int>>& grid, int i, int j)
//    {
//        queue<PII> q;
//        q.push({ i, j });
//        grid[i][j] = 0;
//
//        while (!q.empty())
//        {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++)
//            {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
//                {
//                    count++;
//                    q.push({ x, y });
//                    grid[x][y] = 0;
//                }
//            }
//        }
//    }
//};
//
//
//class Solution {
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, 1, -1 };
//    vector<vector<bool>> vis;
//    int ret = 0;
//    int n, m;
//    int count;
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        n = grid.size();
//        m = grid[0].size();
//        vis = vector<vector<bool>>(n, vector<bool>(m));
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (vis[i][j] != true && grid[i][j] == 1)
//                {
//                    count = 0;
//                    dfs(grid, i, j);
//                    ret = max(ret, count);
//                    // cout << ret << " " << endl;
//                }
//            }
//        }
//        return ret;
//    }
//    void dfs(vector<vector<int>>& grid, int i, int j)
//    {
//        count++;
//        vis[i][j] = true;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = dx[k] + i, y = dy[k] + j;
//            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && vis[x][y] == false)
//            {
//                dfs(grid, x, y);
//            }
//        }
//    }
//};