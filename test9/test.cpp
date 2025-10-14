#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <queue>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        // 两边之和大于第三边，两边之差小于第三边
//        // 模拟
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                int left = j + 1, right = n - 1, k = j;
//                while (left <= right)
//                {
//                    int mid = (left + right) / 2;
//                    if (nums[mid] < nums[i] + nums[j])
//                    {
//                        // 在右边
//                        k = mid;
//                        left = mid + 1;
//                    }
//                    else
//                    {
//                        right = mid - 1;
//                    }
//                }
//                ans += k - j;
//            }
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        // 两边之和大于第三边，两边之差小于第三边
//        // 模拟
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int k = i;
//            for (int j = i + 1; j < n; j++)
//            {
//                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j])
//                {
//                    k++;
//                }
//                ans += max(k - j, 0);
//            }
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    string simplifyPath(string path) {
//        // 从左向右遍历
//        // 如果是 .. 上一路径
//        // . 不用管
//        // 最后不能以 / 收尾
//        int n = path.size();
//        string ret;
//        for (int i = 0; i < n; i++) {
//            if (path[i] == '/') {
//                // 合并/
//                while (i + 1 < n && path[i + 1] == '/')
//                    i++;
//                if (ret.empty() || ret.back() != '/') {
//                    ret += '/';
//                }
//            }
//
//            else if (path[i] == '.') {
//                // 开始查有几个 .
//                int count = 1;
//                int k = i + 1;
//                while (k < n && path[k] == '.') {
//                    count++;
//                    k++;
//                }
//                if ((k == n || path[k] == '/') && ret.back() == '/' && count <= 2)
//                {
//                    if (count == 1)
//                    {
//                        // 啥都不需要做
//                        if (i + 1 < n)
//                            i++;
//                    }
//                    else if (count == 2)
//                    {
//                        // 向前删 ..
//                        ///.../a/
//                        // 删除到两个 / 停止
//                        if (!ret.empty() && ret != "/")
//                        {
//                            // 删除当前目录
//                            if (ret.back() == '/')
//                                ret.pop_back();
//                            // 找到前一个斜杠
//                            while (!ret.empty() && ret.back() != '/')
//                            {
//                                ret.pop_back();
//                            }
//                            if (ret.empty())
//                                ret = "/";
//                        }
//                    }
//                }
//                else
//                {
//                    // 添加
//                    ret.append(count, '.');
//                }
//                i = k - 1;
//            }
//            else
//                ret += path[i];
//        }
//        while (ret.size() > 1 && ret.back() == '/')
//            ret.pop_back();
//        if (ret.size() == 0)
//            ret.push_back('/');
//        return ret;
//    }
//};


//class Solution {
//public:
//    double largestTriangleArea(vector<vector<int>>& points) {
//        // S = 1/2 * |(x2 - x1) * (y3-y1) - (y2 - y1) * (x3 - x1)|
//        // 暴力
//        int n = points.size();
//        double ret = 0;
//        for (int i = 0; i < n; i++) // 1
//        {
//            for (int j = i + 1; j < n; j++) // 2
//            {
//                for (int m = j + 1; m < n; m++) // 3
//                {
//                    double s = std::abs((points[j][0] - points[i][0]) * (points[m][1] - points[i][1])
//                        - (points[j][1] - points[i][1]) * (points[m][0] - points[i][0])) / 2.0;
//                    ret = max(ret, s);
//                }
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int largestPerimeter(vector<int>& nums) {
//        // 排序后，只需保证两边之和大于第三边即可
//        sort(nums.begin(), nums.end(), greater<int>());
//        int n = nums.size();
//        int ret = 0;
//        for (int i = 0; i < n; i++) // 最大
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                if (j != i + 1) break;
//                for (int m = j + 1; m < n; m++)
//                {
//                    if (nums[i] < nums[j] + nums[m])
//                    {
//                        return nums[i] + nums[j] + nums[m];
//                    }
//                    else break;
//                }
//            }
//        }
//        return 0;
//    }
//};


//class Solution {
//public:
//    int largestPerimeter(vector<int>& nums) {
//        // 排序后，只需保证两边之和大于第三边即可
//        sort(nums.begin(), nums.end(), greater<int>());
//        int n = nums.size();
//        int ret = 0;
//        for (int i = 0; i < n - 2; i++) // 最大
//        {
//            if (nums[i] < nums[i + 1] + nums[i + 2]) return nums[i] + nums[i + 1] + nums[i + 2];
//        }
//        return 0;
//    }
//};


//class Solution {
//public:
//    int minScoreTriangulation(vector<int>& values) {
//        int n = values.size();
//        vector f(n, vector<int>(n));
//        for (int i = n - 3; i >= 0; i--)
//        {
//            for (int j = i + 2; j < n; j++)
//            {
//                f[i][j] = INT_MAX;
//                for (int k = i + 1; k < j; k++)
//                {
//                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
//                }
//            }
//        }
//        return f[0][n - 1];
//    }
//};


//class Solution {
//public:
//    int triangularSum(vector<int>& nums) {
//        int n = nums.size();
//        for (int i = 0; i < n - 1; i++) // n - 1次循环
//        {
//            for (int j = 0; j < n - 1 - i; j++)
//            {
//                nums[j] += nums[j + 1];
//                nums[j] %= 10;
//            }
//        }
//        return nums[0];
//    }
//};


//class Solution {
//public:
//    bool is_0(int num)
//    {
//        while (num != 0) {
//            if (num % 10 == 0) return true;
//            num /= 10;
//        }
//        return false;
//    }
//    long long countNoZeroPairs(long long n) {
//        int ret = 0;
//        for (int i = 1; i <= n / 2; i++) {
//            int e1 = i, e2 = n - i;
//            if (is_0(e1) && is_0(e2)) {
//                // 含有0
//                cout << e1 << " " << e2 << endl;
//                continue;
//            }
//            else
//            {
//                if (e1 == e2) ret += 1;
//                else ret += 2;
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int alternatingSum(vector<int>& nums) {
//        int ret = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i % 2 == 0)
//            {
//                ret += nums[i];
//            }
//            else ret -= nums[i];
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int longestSubsequence(vector<int>& nums) {
//        int n = nums.size();
//        int total = 0;
//        bool flag = true;
//        for (auto e : nums) {
//            total ^= e;
//            if (e != 0) flag = false;
//        }
//
//
//        if (total != 0)
//            return n;
//
//        // 为0
//        if (flag) return 0;
//        else return n - 1;
//    }
//};


//class Solution {
//public:
//    string removeSubstring(string s, int k) {
//        vector<pair<char, int>> stack;
//
//        for (char c : s) {
//            if (!stack.empty() && stack.back().first == c) {
//                stack.back().second++;
//            }
//            else {
//                stack.emplace_back(c, 1);
//            }
//
//            while (stack.size() >= 2) {
//                auto& close = stack.back();
//                auto& open = stack[stack.size() - 2];
//
//                if (open.first == '(' && close.first == ')' &&
//                    open.second >= k && close.second >= k) {
//
//                    open.second -= k;
//                    close.second -= k;
//                    if (open.second == 0) {
//                        stack.erase(stack.end() - 2);
//                    }
//                    if (close.second == 0) {
//                        stack.pop_back();
//                    }
//                }
//                else {
//                    break;
//                }
//            }
//        }
//
//        string result;
//        for (auto& [c, count] : stack) {
//            result.append(count, c);
//        }
//
//        return result;
//    }
//};


//class Solution {
//public:
//    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
//        int n = nums.size();
//        if (k == 1) return true;
//        for (int i = 0; i <= n - 2 * k; i++)
//        {
//            bool flag = true;
//            for (int j = 1; j < k; j++)
//            {
//                if (nums[j + i] <= nums[j + i - 1])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag == false) continue;
//
//            for (int j = 1; j < k; j++)
//            {
//                if (nums[j + i + k] <= nums[j + i + k - 1])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag == false) continue;
//            return true;
//        }
//        return false;
//    }
//};


//class Solution {
//public:
//    int longestBalanced(string s) {
//        int ret = 0;
//        int n = s.size();
//        for (int i = 0; i < n; i++) {
//            int cnt[26] = { 0 };
//            int count = 0;
//            for (int j = i; j < n; j++) {
//                int ans = cnt[s[j] - 'a']++;
//                bool flag = true;
//                for (int m = 0; m < 26; m++) {
//                    if (ans != cnt[m]) {
//                        flag = false;
//                        break;
//                    }
//                }
//                if (flag) ret = max(ret, j - i + 1);
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int longestBalanced(string s) {
//        int ret = 0;
//        int n = s.size();
//        for (int i = 0; i < n; i++) {
//            int cnt[26] = { 0 };
//            int count = 0;
//            for (int j = i; j < n; j++) {
//                int ans = ++cnt[s[j] - 'a'];
//                bool flag = true;
//                for (int m = 0; m < 26; m++) {
//                    if (ans != cnt[m] && cnt[m] != 0) {
//                        flag = false;
//                        break;
//                    }
//                }
//                if (flag) ret = max(ret, j - i + 1);
//            }
//        }
//        return ret;
//    }
//};



int main()
{
    Solution s;
    string str = "abbac";
    s.longestBalanced(str);
	return 0;
}

