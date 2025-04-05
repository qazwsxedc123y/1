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


//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp[i][j]表示到达(i-1,j-1)下标的最小和
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
//        // dp[i][j]表示以(i,j)为起点时所消耗的最小健康点数
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
//        // dp[i][j]表示以(i,j)为起点时所消耗的最小健康点数
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
//    // 多状态dp
//public:
//    int massage(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 0) return 0;
//        vector<int> f(n); // f[i]表示选到i位置时，nums[i]必选的情况下，此时最长的预约时长
//        vector<int> g(n); // g[i]表示选到i位置时，nums[i]不选的情况下，此时最长的预约时长
//        // 初始化
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
//        // 选第一个， 不选第一个
//        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
//    }
//    int rob1(vector<int>& nums, int left, int right) {
//        if (left > right) return 0;
//        // 创建dp表
//        // 初始化
//        // 填表
//        // 返回结果
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
//        // 预处理
//        int N = 10001;
//        int n = nums.size();
//        int arr[10001] = { 0 };
//        for (auto x : nums) arr[x] += x;
//
//        // 创建dp表
//        vector<int> f(N);
//        auto g = f;
//        // 填表        
//        // 初始化
//        for (int i = 1; i < N; i++)
//        {
//            f[i] = g[i - 1] + arr[i];
//            g[i] = max(g[i - 1], f[i - 1]);
//        }
//        // 返回值
//
//        return max(f[N - 1], g[N - 1]);
//    }
//};


//class Solution {
//public:
//    int minCost(vector<vector<int>>& costs) {
//        int n = costs.size();
//        vector<vector<int>> dp(n + 1, vector<int>(3));
//        // 填表
//        for (int i = 1; i <= n; i++) {
//            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
//            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
//            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
//        }
//        int ret;
//        ret = min(dp[n][0], min(dp[n][1], dp[n][2]));
//        return ret;
//    }
//};


//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        // 0 -> 买入   1 -> 冷冻期  2 -> 可交易
//        vector<vector<int>> dp(n, vector<int>(3));
//        dp[0][0] = -prices[0];
//
//        // 填表
//        for (int i = 1; i < n; i++) {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
//            dp[i][1] = dp[i - 1][0] + prices[i];
//            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
//        }
//        // 小优化 因为最后答案肯定不是买入，所以可以忽略dp[n-1][0]
//
//        return max(dp[n - 1][1], dp[n - 1][2]);
//    }
//};


//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        // 0 -> 买入  1 -> 可交易
//        // vector<vector<int>> dp(n, vector<int>(2));
//
//        vector<int> f(n); // 买入
//        auto g = f; // 可交易
//
//        f[0] = -prices[0] - fee;
//        g[0] = 0;
//
//        for (int i = 1; i < n; i++) {
//            f[i] = max(f[i - 1], g[i - 1] - prices[i] - fee);
//            g[i] = max(g[i - 1], f[i - 1] + prices[i]);
//        }
//
//        // 小优化，最优解，肯定是最后一天不买
//        return g[n - 1];
//    }
//};


//class Solution {
//public:
//    const int INF = 0x3f3f3f3f;
//    int maxProfit(vector<int>& prices) {
//        // 创建dp表
//        // 初始化
//        // 填表
//        // 返回值
//        int n = prices.size();
//
//        // f[i][j] 表示第i天结束后，完成了j笔交易，此时处于买入状态下，的最大利润
//        // g[i][j] 表示第i天结束后，完成了j笔交易，此时处于可交易状态下，的最大利润   
//        vector<vector<int>> f(n, vector<int>(3, -INF));
//        auto g = f;
//
//        // 初始化
//        f[0][0] = -prices[0], g[0][0] = 0;
//
//        // 填表
//        for (int i = 1; i < n; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
//                g[i][j] = g[i - 1][j];
//                // 处理边界条件
//                if (j >= 1)
//                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
//            }
//        }
//
//        // 返回值为g的最后一行的最大值
//        return max(g[n - 1][0], max(g[n - 1][1], g[n - 1][2]));
//    }
//};


//class Solution {
//    const int INF = 0x3f3f3f3f;
//public:
//    int maxProfit(int k, vector<int>& prices) {
//        // 创建dp表
//        // 初始化
//        // 填表
//        // 返回值
//        int n = prices.size();
//
//        // f[i][j] 表示第i天结束后，完成了j笔交易，此时处于买入状态下，的最大利润
//        // g[i][j] 表示第i天结束后，完成了j笔交易，此时处于可交易状态下，的最大利润   
//        vector<vector<int>> f(n, vector<int>(k + 1, -INF));
//        auto g = f;
//
//        // 初始化
//        f[0][0] = -prices[0], g[0][0] = 0;
//
//        // 填表
//        for (int i = 1; i < n; i++)
//        {
//            for (int j = 0; j < k + 1; j++)
//            {
//                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
//                g[i][j] = g[i - 1][j];
//                // 处理边界条件
//                if (j >= 1)
//                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
//            }
//        }
//
//        // 返回值为g的最后一行的最大值
//        int ret = -INF;
//        for (int i = 0; i <= k; i++) {
//            ret = max(ret, g[n - 1][i]);
//        }
//        return ret;
//    }
//};


//class Solution {
//    const int INF = 0x3f3f3f3f;
//public:
//    int maxSubarraySumCircular(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> f(n + 1); // f[i]表示以i为结尾的子数组的最大和
//        auto g = f; // g[i]表示以i为结尾的子数组的最小和
//        f[0] = g[0] = 0;
//
//        // 返回值的处理，找到f中的最大值，g中的最小值，然后sum - g
//        int sum = 0, fmax = -INF, gmin = INF;
//        for (int i = 1; i < n + 1; i++) {
//            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
//            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
//            fmax = max(fmax, f[i]);
//            gmin = min(gmin, g[i]);
//            sum += nums[i - 1];
//        }
//
//        int ret = max(fmax, sum - gmin);
//        if (sum == gmin) ret = fmax;
//        return ret;
//    }
//};


//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) return nums[0];
//        vector<int> f(n + 1); // f[i]表示以i为结尾，最大的非空连续子数组最大积 （正数）
//        auto g = f; // g[i]表示以i为结尾，最大的非空连续子数组最小积 （负数）
//        f[0] = g[0] = 1;
//        int ret = 0;
//        for (int i = 1; i < n + 1; i++) {
//            if (nums[i - 1] > 0) {
//                f[i] = max(f[i - 1] * nums[i - 1], nums[i - 1]);
//                g[i] = min(g[i - 1] * nums[i - 1], nums[i - 1]);
//            }
//            else if (nums[i - 1] < 0) {
//                f[i] = max(g[i - 1] * nums[i - 1], nums[i - 1]);
//                g[i] = min(f[i - 1] * nums[i - 1], nums[i - 1]);
//            }
//            ret = max(ret, f[i]);
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int getMaxLen(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> f(n + 1); // f[i]表示以i为结尾，乘积为正数的，最长子数组的长度
//        auto g = f; // g[i]表示以i为结尾，乘积为负数的，最长子数组的长度
//        f[0] = g[0] = 0;
//        int ret = 0;
//        for (int i = 1; i < n + 1; i++) {
//            if (nums[i - 1] > 0) {
//                f[i] = f[i - 1] + 1;
//                // g[i] = g[i-1] + 1; // 特殊条件，如果g[i-1] 为0的话，也就是前面全是正数
//                g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
//            }
//            else if (nums[i - 1] < 0) {
//                // f[i] = g[i-1] + 1; // 同理，特殊条件
//                f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
//                g[i] = f[i - 1] + 1;
//            }
//            ret = max(ret, f[i]);
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> dp(n);
//        if (n < 3) return 0;
//        int ret = 0;
//        dp[0] = dp[1] = 0;
//        for (int i = 2; i < n; i++) {
//            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
//                dp[i] = dp[i - 1] + 1;
//            }
//            else dp[i] = 0;
//            ret += dp[i];
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int maxTurbulenceSize(vector<int>& nums) {
//        // 分两个统计，一个为第一个为下降趋势，另一个为第一个为上升趋势
//        // 但是这样对于状态表达，就会需要用到nums[i-2]，这样显然不是最优
//        // 所以改状态表示
//        // 一个表示最后的状态为上升状态，另一个表示为最后的状态为下降状态。下最长湍流子数组的长度
//        int n = nums.size();
//        vector<int> f(n, 1); // 先全部初始化为1
//        auto g = f;
//        int ret = 1;
//        for (int i = 1; i < n; i++) {
//            if (nums[i] > nums[i - 1]) {
//                f[i] = g[i - 1] + 1;
//            }
//            else if (nums[i] < nums[i - 1]) {
//                g[i] = f[i - 1] + 1;
//            }
//            ret = max(ret, max(f[i], g[i]));
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        // 优化，先将字典序中的单词扔进哈希表内
//        unordered_set<string> hash;
//        for (auto& e : wordDict) hash.insert(e);
//
//        int n = s.size();
//        vector<bool> dp(n + 1); // dp[i]表示以[0，i]区间的字符串，是否可以由字典序构成。
//        dp[0] = true; // 保证后续的填表正确
//        s = ' ' + s; // 使原始的字符串的下标统一 +1
//        // 大致思路是下标j为为最后一个单词的起始位置
//        // 是查看是否[0,j-1]是否可以构成，然后再查看[j,i]单词是否可以用字典序构成
//        for (int i = 1; i < n + 1; i++)
//        {
//            for (int j = i; j >= 1; j--)
//            {
//                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
//                {
//                    dp[i] = true;
//                }
//            }
//        }
//
//        return dp[n];
//    }
//};


int main()
{
    Solution s;
    s.maxProfit()
    return 0;
}