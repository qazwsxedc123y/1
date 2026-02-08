#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    int lastStoneWeight(vector<int>& stones) {
//        // 使用大堆来写
//        priority_queue<int> q;
//        for (auto c : stones) q.push(c);
//
//        while (q.size() > 1)
//        {
//            int x = q.top();
//            q.pop();
//            int y = q.top();
//            q.pop();
//            // x >= y
//            int ans = x - y;
//            if (ans != 0) q.push(ans);
//        }
//
//        return q.empty() ? 0 : q.top();
//    }
//};
//
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        int n = temperatures.size();
//        vector<int> ret(n), pos(101, INT_MAX);
//        for (int i = n - 1; i >= 0; i--)
//        {
//            int ans = INT_MAX;
//            for (int j = temperatures[i] + 1; j <= 100; j++)
//            {
//                ans = min(pos[j], ans);
//            }
//            if (ans != INT_MAX)
//            {
//                ret[i] = ans - i;
//            }
//            pos[temperatures[i]] = i;
//        }
//        return ret;
//    }
//};
//
//
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        // 尝试使用单调栈
//        // 从右往左
//        int n = temperatures.size();
//        stack<int> st;
//        vector<int> ans(n);
//        for (int i = n - 1; i >= 0; i--)
//        {
//            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
//            {
//                st.pop();
//            }
//            if (!st.empty())
//            {
//                ans[i] = st.top() - i;
//            }
//            st.push(i);
//        }
//
//        return ans;
//    }
//};
//
//
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        // 尝试使用单调栈
//        // 从左往右
//        int n = temperatures.size();
//        stack<int> st;
//        vector<int> ans(n);
//        for (int i = 0; i < n; i++)
//        {
//            while (!st.empty() && temperatures[st.top()] < temperatures[i])
//            {
//                int t = st.top();
//                ans[t] = i - t;
//                st.pop();
//            }
//            st.push(i);
//        }
//
//        return ans;
//    }
//};
// grid = [[1,3,1],[1,5,1],[4,2,1]]

//class Solution {
//public:
//    int trap(vector<int>& height) {
//        // 使用单调栈，假装填充的是水泥
//        int n = height.size();
//        int ret = 0;
//        stack<int> st;
//        for (int i = 0; i < n; i++)
//        {
//            while (!st.empty() && height[st.top()] <= height[i])
//            {
//                int t = height[st.top()];
//                st.pop();
//                if (st.empty()) break;
//                int left = st.top();
//                int h = min(height[i], height[left]) - t;
//                ret += h * (i - left - 1);
//            }
//            st.push(i);
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 每个位置向前勾勒
        int n = heights.size();
        if (n == 1) return heights[0];
        stack<int> st;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            int t = heights[i];
            while (!st.empty() && t <= heights[st.top()])
            {
                int h_pos = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                ret = max(ret, heights[h_pos] * (i - left - 1));
            }
            st.push(i);
        }
        return ret;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> occ;
        int n = s.size();
        if (n == 0) return 0;
        int ret = -1, l = 0;
        for (int r = 0; r < n; r++)
        {
            occ[s[r]]++;
            while (l < r && occ[s[r]] > 1)
            {
                occ[s[l]]--;
                if (occ[s[l]] <= 0) occ.erase(s[l]);
                l++;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};

int main()
{
    vector<int> v({ 5,6 });
    Solution s;
    s.largestRectangleArea(v);
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