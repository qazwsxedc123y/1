#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include <algorithm> 
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <ranges>

using namespace std;

//class Solution {
//public:
//    int get(const vector<vector<int>>& dp, int m, int n, int x, int y) {
//        x = max(min(x, m), 0);
//        y = max(min(y, n), 0);
//        return dp[x][y];
//    }
//    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
//        int m = mat.size(), n = mat[0].size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//        for (int i = 1; i <= m; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
//            }
//        }
//        vector<vector<int>> ret(m, vector<int>(n));
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                ret[i][j] = get(dp, m, n, i + k + 1, j + k + 1) - get(dp, m, n, i - k, j + k + 1) - get(dp, m, n, i + k + 1, j - k) + get(dp, m, n, i - k, j - k);
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
//        int n = nums.size(), m = queries.size();
//        sort(nums.begin(), nums.end());
//        vector<int> ret(m), dp(n + 1);
//        for (int i = 1; i <= n; i++)
//        {
//            dp[i] = dp[i - 1] + nums[i - 1];
//        }
//        for (int i = 0; i < m; i++)
//        {
//            ret[i] = upper_bound(dp.begin(), dp.end(), queries[i]) - dp.begin() - 1;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int sec(vector<int>& dp, int t)
//    {
//        int left = 0, right = dp.size() - 1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if (dp[mid] <= t)
//            {
//                left = mid + 1;
//            }
//            else {
//                right = mid - 1;
//            }
//        }
//        return left - 1;
//    }
//    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
//        int n = nums.size(), m = queries.size();
//        sort(nums.begin(), nums.end());
//        vector<int> ret(m), dp(n + 1);
//        for (int i = 1; i <= n; i++)
//        {
//            dp[i] = dp[i - 1] + nums[i - 1];
//        }
//        for (int i = 0; i < m; i++)
//        {
//            if (queries[i] > dp[n])
//            {
//                ret[i] = n;
//            }
//            else
//            {
//                ret[i] = sec(dp, queries[i]);
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int f(string s)
//    {
//        vector<int> t(26);
//        for (auto& c : s)
//            t[c - 'a']++;
//        for (int i = 0; i < 26; i++)
//            if (t[i]) return t[i];
//        return 0;
//    }
//    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
//        int n = queries.size(), m = words.size();
//        vector<int> v, ret;
//        for (int i = 0; i < m; i++)
//            v.push_back(f(words[i]));
//        sort(v.begin(), v.end());
//        for (int i = 0; i < n; i++)
//        {
//            int t = f(queries[i]);
//            for (int j = 0; i < m; j++)
//            {
//                if (v[j] == t) {
//                    ret.push_back(j + 1);
//                    break;
//                }
//                else if (v[j] > t) {
//                    ret.push_back(j);
//                    break;
//                }
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int f(string s)
//    {
//        vector<int> t(26);
//        for (auto& c : s)
//            t[c - 'a']++;
//        for (int i = 0; i < 26; i++)
//            if (t[i]) return t[i];
//        return 0;
//    }
//    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
//        int n = queries.size(), m = words.size();
//        vector<int> v, ret;
//        for (int i = 0; i < m; i++)
//            v.push_back(f(words[i]));
//        sort(v.begin(), v.end());
//        for (int i = 0; i < n; i++)
//        {
//            int t = f(queries[i]);
//            int left = 0, right = m, mid;
//            while (left < right)
//            {
//                mid = left + (right - left) / 2;
//                if (v[mid] > t)
//                {
//                    right = mid;
//                }
//                else
//                {
//                    left = mid + 1;
//                }
//            }
//            ret.push_back(m - left);
//        }
//        return ret;
//    }
//};

int main()
{
    Solution s;
    vector<string> v1{ "cbd" };
    vector<string> v2{ "zaaaz" };
    s.numSmallerByFrequency(v1, v2);
    return 0;
}