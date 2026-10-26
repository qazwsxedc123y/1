#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 读取后，vis标记
        int dx[4] = { 0, 1, 0, -1 }; int dy[4] = { 1, 0, -1, 0 }; // 右下左上
        vector<int> ret;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int maxnum = m * n;
        int curnum = 1;
        int x = 0, y = 0, dir = 0;
        while (curnum <= maxnum)
        {
            ret.push_back(matrix[x][y]);
            vis[x][y] = true;
            int next_x = x + dx[dir], next_y = y + dy[dir];
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || vis[next_x][next_y] == true)
            {
                dir = (dir + 1) % 4;
            }
            x += dx[dir], y += dy[dir];
            curnum++;
        }
        return ret;
    }
};