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
//        vector<int> dp(n + 1); // ��ʾ�����i��ķ����ж���
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
//        vector<long long> dp(n + 1); // ��ʾ�����i��ķ����ж���
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
//        // ����Ҫ�����±�Ϊ n��
//        int n = cost.size();
//        vector<int> dp(n + 1); // dp[i] ��ʾ�����±�Ϊi��¥����Ҫ֧���ķ���
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
//        vector<int> dp(n); // ��ʾ���±� i ��β����ʱ������Ϊ����
//
//        // ��ʼ��dp[0], dp[1]
//        if (s[0] != '0') dp[0] = 1;
//        else dp[0] = 0;
//        if (n == 1) return dp[0];
//
//        // �������ǵ�������
//        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
//        // ����һ�����
//        int t = (s[0] - '0') * 10 + s[1] - '0';
//        if (t >= 10 && t <= 26) dp[1] += 1;
//
//        for (int i = 2; i < n; i++)
//        {
//            // s[i] ��������
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            // s[i] �� s[i-1] һ�����
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
//        vector<int> dp(n); // ��ʾ���±� i ��β����ʱ������Ϊ����
//
//        // ��ʼ��dp[0], dp[1]
//        if (s[0] != '0') dp[0] = 1;
//        else dp[0] = 0;
//        if (n == 1) return dp[0];
//
//        // �������ǵ�������
//        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
//        // ����һ�����
//        int t = (s[0] - '0') * 10 + s[1] - '0';
//        if (t >= 10 && t <= 26) dp[1] += 1;
//
//        for (int i = 2; i < n; i++)
//        {
//            // s[i] ��������
//            if (s[i] != '0') dp[i] += dp[i - 1];
//            // s[i] �� s[i-1] һ�����
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
//    int dp[201][201]; // dp[i][j]��ʾ (i,j) λ��ʱ���õ�����߼�ֵ
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
//        // Ϊ�˷�ֹԽ�磬���õ�dp���СΪn+1�У�n+2��
//        vector<vector<int>> dp(n + 1, vector<int>(n + 2)); // dp[i][j]��ʾ�����(i+1,+1)�±����Сֵ
//        for (int j = 0; j < n + 2; j++) dp[0][j] = 0;
//        for (int i = 1; i < n + 1; i++) dp[i][0] = dp[i][n + 1] = INT_MAX;
//
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                // ȡ������������Сֵ��Ȼ��+matrix[i-1][j-1]
//                dp[i][j] = matrix[i - 1][j - 1] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
//            }
//        }
//        // �������һ�У�ȡ��Сֵ
//        int ret = INT_MAX;
//        for (int j = 1; j < n + 1; j++) {
//            ret = min(ret, dp[n][j]);
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp[i][j]��ʾ����(i-1,j-1)�±����С��
//        for (int i = 0; i <= m; i++) dp[i][0] = INT_MAX;
//        for (int j = 0; j <= n; j++) dp[0][j] = INT_MAX;
//        dp[0][0] = dp[0][1] = dp[1][0] = 0;
//
//        for (int i = 1; i <= m; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
//            }
//        }
//
//        return dp[m][n];
//    }
//};


//class Solution {
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon) {
//        int m = dungeon.size(), n = dungeon[0].size();
//        // dp[i][j]��ʾ��(i,j)Ϊ���ʱ�����ĵ���С��������
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
//        dp[m][n - 1] = dp[m - 1][n] = 1;
//
//        for (int i = m - 1; i >= 0; i--)
//        {
//            for (int j = n - 1; j >= 0; j--)
//            {
//                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
//                dp[i][j] = max(1, dp[i][j]);
//            }
//        }
//        return dp[0][0];
//    }
//};


//class Solution {
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon) {
//        int m = dungeon.size(), n = dungeon[0].size();
//        // dp[i][j]��ʾ��(i,j)Ϊ���ʱ�����ĵ���С��������
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
//        dp[m][n - 1] = dp[m - 1][n] = 1;
//
//        for (int i = m - 1; i >= 0; i--)
//        {
//            for (int j = n - 1; j >= 0; j--)
//            {
//                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
//                dp[i][j] = max(1, dp[i][j]);
//            }
//        }
//        return dp[0][0];
//    }
//};


//class Solution {
//    // ��״̬dp
//public:
//    int massage(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 0) return 0;
//        vector<int> f(n); // f[i]��ʾѡ��iλ��ʱ��nums[i]��ѡ������£���ʱ���ԤԼʱ��
//        vector<int> g(n); // g[i]��ʾѡ��iλ��ʱ��nums[i]��ѡ������£���ʱ���ԤԼʱ��
//        // ��ʼ��
//        f[0] = nums[0], g[0] = 0;
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = g[i - 1] + nums[i];
//            g[i] = max(f[i - 1], g[i - 1]);
//        }
//        return max(f[n - 1], g[n - 1]);
//    }
//};


//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        // ѡ��һ���� ��ѡ��һ��
//        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
//    }
//    int rob1(vector<int>& nums, int left, int right) {
//        if (left > right) return 0;
//        // ����dp��
//        // ��ʼ��
//        // ���
//        // ���ؽ��
//        int n = nums.size();
//        vector<int> f(n);
//        auto g = f;
//
//        f[left] = nums[left];
//        for (int i = left + 1; i <= right; i++) {
//            f[i] = g[i - 1] + nums[i];
//            g[i] = max(f[i - 1], g[i - 1]);
//        }
//        return max(f[right], g[right]);
//    }
//};


//class Solution {
//public:
//    int deleteAndEarn(vector<int>& nums) {
//        // Ԥ����
//        int N = 10001;
//        int n = nums.size();
//        int arr[10001] = { 0 };
//        for (auto x : nums) arr[x] += x;
//
//        // ����dp��
//        vector<int> f(N);
//        auto g = f;
//        // ���        
//        // ��ʼ��
//        for (int i = 1; i < N; i++)
//        {
//            f[i] = g[i - 1] + arr[i];
//            g[i] = max(g[i - 1], f[i - 1]);
//        }
//        // ����ֵ
//
//        return max(f[N - 1], g[N - 1]);
//    }
//};


int main()
{
    Solution s;
    s.numDecodings({ "10" });
    return 0;
}