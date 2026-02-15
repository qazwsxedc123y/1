#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 单调栈
        int n = height.size(), ret = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[st.top()] <= height[i])
            {
                // 假装是水泥，然后进行填充
                int t = height[st.top()];
                st.pop();
                if (st.empty()) break;
                int left = st.top();
                int h = min(height[i], height[left]) - t;
                ret += h * (i - left - 1);
            }
            st.push(i);
        }

        return ret;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 并不可用贪心
        // 使用动态规划
        // 背包问题
        // dp[i][j] 表示 表示从前i个硬币凑，钱数为j，所使用的最少张数
        int n = coins.size();
        int dp[14][10050];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }

        return dp[n][amount] == 0x3f3f3f3f ? -1 : dp[n][amount];
    }
};


int main()
{
    vector<string> v({ "eat", "tea", "tan", "ate", "nat", "bat" });
    string str("(())(())");
    Solution s;
    s.longestValidParentheses(str);
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