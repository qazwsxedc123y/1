#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
// 
// 
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        // 背包问题
//        int n = coins.size();
//        // dp[i][j] 表示从前i种硬币凑齐j元所使用的最少数量
//        int dp[14][10005];
//        memset(dp, 0x3f, sizeof(dp));
//        for (int i = 0; i <= n; i++) dp[i][0] = 0;
//
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 0; j <= amount; j++)
//            {
//                // 当前位置的钱币不选
//                dp[i][j] = dp[i - 1][j];
//                // 当前位置选
//                if (j >= coins[i - 1])
//                {
//                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
//                }
//            }
//        }
//        return dp[n][amount] == 0x3f3f3f3f ? -1 : dp[n][amount];
//    }
//};


class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 2]; // dp[i] 表示达到第i阶的方法
        dp[1] = 1;
        dp[2] = 2;
        if (n <= 2) return n;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main()
{
	cout << (int)'6' << endl;
	return 0;
}