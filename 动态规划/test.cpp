#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>

using namespace std;


//class Solution {
//public:
//    int tribonacci(int n) {
//        vector<int> dp(n + 1);
//        if (n == 0) return 0;
//        if (n == 1 || n == 2) return 1;
//        dp[0] = 0, dp[1] = 1, dp[2] = 1;
//        for (int i = 3; i <= n; i++) {
//            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//        }
//        return dp[n];
//    }
//};


//class Solution {
//    const int MOD = 1e9 + 7;
//public:
//    int waysToStep(int n) {
//        if (n == 1) return 1;
//        if (n == 2) return 2;
//        if (n == 3) return 4;
//        vector<int> dp(n + 1); // 表示到达第i层的方法有多少
//        dp[1] = 1, dp[2] = 2, dp[3] = 4;
//        for (int i = 4; i <= n; i++) {
//            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
//        }
//        return dp[n];
//    }
//};


//class Solution {
//    const int MOD = 1e9 + 7;
//public:
//    int waysToStep(int n) {
//        if (n == 1) return 1;
//        if (n == 2) return 2;
//        if (n == 3) return 4;
//        vector<long long> dp(n + 1); // 表示到达第i层的方法有多少
//        dp[1] = 1, dp[2] = 2, dp[3] = 4;
//        for (int i = 4; i <= n; i++) {
//            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
//        }
//        return dp[n];
//    }
//};


//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        // 是需要爬到下标为 n。
//        int n = cost.size();
//        vector<int> dp(n + 1); // dp[i] 表示爬到下标为i层楼梯需要支付的费用
//        dp[0] = dp[1] = 0;
//        for (int i = 2; i <= n; i++) {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[n];
//    }
//};


//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> dp(n); // 表示以下标 i 结尾，此时编码数为多少
//
//        // 初始化dp[0], dp[1]
//        if (s[0] != '0') dp[0] = 1;
//        else dp[0] = 0;
//        if (n == 1) return dp[0];
//
//        // 两个都是单独编码
//        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
//        // 两个一起编码
//        int t = (s[0] - '0') * 10 + s[1] - '0';
//        if (t >= 10 && t <= 26) dp[1] += 1;
//
//        for (int i = 2; i < n; i++)
//        {
//            // s[i] 单独编码
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            // s[i] 与 s[i-1] 一起编码
//            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
//            if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
//        }
//        return dp[n - 1];
//    }
//};


//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> dp(n); // 表示以下标 i 结尾，此时编码数为多少
//
//        // 初始化dp[0], dp[1]
//        if (s[0] != '0') dp[0] = 1;
//        else dp[0] = 0;
//        if (n == 1) return dp[0];
//
//        // 两个都是单独编码
//        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
//        // 两个一起编码
//        int t = (s[0] - '0') * 10 + s[1] - '0';
//        if (t >= 10 && t <= 26) dp[1] += 1;
//
//        for (int i = 2; i < n; i++)
//        {
//            // s[i] 单独编码
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            // s[i] 与 s[i-1] 一起编码
//            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
//            if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
//        }
//        return dp[n - 1];
//    }
//};


//class Solution {
//    int dp[101][101];
//
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//        if (obstacleGrid[0][0] == 1) return 0;
//        dp[1][1] = 1;
//
//        for (int i = 1; i <= m; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (i == 1 && j == 1)
//                    continue;
//                if (obstacleGrid[i - 1][j - 1] == 1) dp[i][j] = 0;
//                else
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m][n];
//    }
//};


//class Solution {
//    int dp[201][201]; // dp[i][j]表示 (i,j) 位置时，拿到的最高价值
//public:
//    int jewelleryValue(vector<vector<int>>& frame) {
//        int m = frame.size(), n = frame[0].size();
//        dp[1][1] = frame[0][0];
//
//        for (int i = 1; i <= m; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (i == 1 && j == 1)
//                    continue;
//                dp[i][j] = max(dp[i - 1][j] + frame[i - 1][j - 1], dp[i][j - 1] + frame[i - 1][j - 1]);
//            }
//        }
//        return dp[m][n];
//    }
//};


//class Solution {
//public:
//    int minFallingPathSum(vector<vector<int>>& matrix) {
//        int n = matrix.size();
//        // 为了防止越界，设置的dp表大小为n+1行，n+2列
//        vector<vector<int>> dp(n + 1, vector<int>(n + 2)); // dp[i][j]表示到达第(i+1,+1)下标的最小值
//        for (int j = 0; j < n + 2; j++) dp[0][j] = 0;
//        for (int i = 1; i < n + 1; i++) dp[i][0] = dp[i][n + 1] = INT_MAX;
//
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                // 取上面三个的最小值，然后+matrix[i-1][j-1]
//                dp[i][j] = matrix[i - 1][j - 1] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
//            }
//        }
//        // 遍历最后一行，取最小值
//        int ret = INT_MAX;
//        for (int j = 1; j < n + 1; j++) {
//            ret = min(ret, dp[n][j]);
//        }
//        return ret;
//    }
//};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp[i][j]表示到达(i-1,j-1)下标的最小和
        for (int i = 0; i <= m; i++) dp[i][0] = INT_MAX;
        for (int j = 0; j <= n; j++) dp[0][j] = INT_MAX;
        dp[0][0] = dp[0][1] = dp[1][0] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution s;
    s.numDecodings({ "10" });
    return 0;
}