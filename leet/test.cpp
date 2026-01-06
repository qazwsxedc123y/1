#define  _CRT_SECURE_NO_WARNINGS
//
//class Solution {
//    vector<int> ret;
//public:
//    void dfs(int pos, int num, int n, int k)
//    {
//        if (pos == n)
//        {
//            ret.push_back(num);
//            return;
//        }
//
//        for (int i = 0; i <= 9; i++)
//        {
//            int ans = num % 10;
//            if (i - ans == k || ans - i == k)
//            {
//                dfs(pos + 1, num * 10 + i, n, k);
//            }
//        }
//    }
//    vector<int> numsSameConsecDiff(int n, int k) {
//        // 可以采用dfs
//        for (int i = 1; i <= 9; i++) dfs(1, i, n, k);
//        return ret;
//    }
//};
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 滑动窗口，但存在负数得情况，滑动窗口不行
        // 前缀和
        int n = nums.size();
        int ret = 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + nums[i - 1];
        for (int i = 0; i <= n; i++) // 右边界
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[i] - dp[j] == k) ret++;
            }
        }
        return ret;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 滑动窗口，但存在负数得情况，滑动窗口不行
        // 前缀和
        int n = nums.size();
        int ret = 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + nums[i - 1];
        unordered_map<int, int> cnt;

        for (int i = 0; i <= n; i++) // 右边界
        {
            if (cnt.find(dp[i] - k) != cnt.end()) ret += cnt[dp[i] - k];
            cnt[dp[i]]++;
        }
        return ret;
    }
};