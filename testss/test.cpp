#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 先排序，再合并
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            if (ret.empty() || ret.back()[1] < l)
            {
                ret.push_back({ l, r });
            }
            else
            {
                ret.back()[1] = max(ret.back()[1], r);
            }
        }
        return ret;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        if (n == 1) return heights[0];

        heights.push_back(-1);
        n += 1;
        stack<int> st;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
            {
                int h_pos = st.top();
                st.pop();
                int left = -1;
                if (!st.empty()) left = st.top();

                ret = max(ret, heights[h_pos] * (i - left - 1));
            }
            st.push(i);
        }
        return ret;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 考的是单调栈
        int n = matrix.size(), m = matrix[0].size();
        vector<int> h(m);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0') h[j] = 0;
                else h[j]++;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};

int main()
{
	cout << (int)'6' << endl;
	return 0;
}