#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++) v[i][0] = 101;
        for (int i = 0; i < n; i++) v[0][i] = 101;
        v[0][0] = v[0][1] = v[1][0] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                v[i][j] = grid[i - 1][j - 1] + min(v[i - 1][j], v[i][j - 1]);
                cout << v[i][j] << " ";
            }
            cout << endl;
        }

        return v[m][n];
    }
};

class Solution {
private:
    vector<vector<int>> v;
public:
    int mem(int i, int j, vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0) return 1e5 + 7;

        if (v[i][j] >= 0) return v[i][j];

        v[i][j] = grid[i][j] + min(mem(i - 1, j, grid), mem(i, j - 1, grid));
        return v[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        v.resize(m, vector<int>(n, -1));
        v[0][0] = grid[0][0];
        return mem(m - 1, n - 1, grid);
    }
};

// grid = [[1,3,1],[1,5,1],[4,2,1]]
int main()
{
    vector<vector<int>> v;
    v.push_back({ 1,3,1 });
    v.push_back({ 1,5,1 });
    v.push_back({ 4,2,1 });
    Solution s;
    s.minPathSum(v);
    return 0;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */