#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        // 使用动态规划
//        int n = nums.size();
//        vector<int> dp(n, 1); // dp[i]表示区间[0,i]之间最大递增子序列长度
//        for (int i = 1; i < n; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                if (nums[i] > nums[j])
//                {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        int ret = 0;
//        for (int i = 0; i < n; i++) ret = max(ret, dp[i]);
//        return ret;
//    }
//};


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // 使用动态规划
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i]表示区间[0,i]之间最大递增子序列长度
        vector<int> count(n, 1); // count[i]表示区间[0,i]之间最大递增子序列长度的个数
        int ret = 1, max_len = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] == dp[j] + 1) count[i] += count[j];
                    else if (dp[i] < dp[j] + 1) count[i] = count[j];
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (max_len < dp[i])
            {
                max_len = dp[i];
                ret = count[i];
            }
            else if (max_len == dp[i])
            {
                ret += count[i];
            }
        }
        return ret;
    }
};


int main()
{
    vector<vector<int>> v;
    v.push_back({ 1,1,1 });
    v.push_back({ 1,0,1 });
    v.push_back({ 1,1,1 });
    // [1,1,1],[1,0,1],[1,1,1]
    Solution s;
    s.setZeroes(v);
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