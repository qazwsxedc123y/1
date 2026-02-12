#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        // 使用栈
//        int ret = 0, ans = -1;
//        stack<int> st; // 只入 ( 的
//        st.push(-1);
//        int n = s.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (s[i] == '(') // 直接入栈
//            {
//                st.push(i);
//            }
//            else // 看看是否匹配，进行出栈
//            {
//                st.pop();
//                if (st.empty())
//                {
//                    // 去除的是 -1，栈内无匹配
//                    st.push(-1);
//                    ans = i;
//                }
//                else
//                {
//                    ret = max(ret, i - ans);
//                }
//            }
//        }
//
//        return ret;
//    }
//};


class Solution {
public:
    int longestValidParentheses(string s) {
        // 动态规划
        // dp[i]表示以下标 i 字符结尾的最长有效括号的长度
        int ret = 0, n = s.size();
        vector<int> dp(n, 0);
        // 初始化，dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    if (i >= 2) dp[i] = dp[i - 2] + 2;
                    else dp[i] = 2;
                }
                else
                {
                    // "()(())"
                    // 前有dp[i-1]个配对
                    int ans = i - dp[i - 1] - 1; // 看与s[ans]是否配对
                    // "(())(())"
                    if (ans >= 0 && s[ans] == '(')
                    {
                        if (ans - 1 >= 0 && dp[ans - 1] != 0) dp[i] = dp[ans - 1] + dp[i - 1] + 2;
                        else dp[i] = dp[i - 1] + 2;
                    }
                }
                ret = max(ret, dp[i]);
            }
        }
        return ret;
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