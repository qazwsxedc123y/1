#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include <algorithm> 
#include<unordered_set>
#include<unordered_map>
#include<numeric>

using namespace std;

//class Solution {
//public:
//    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//        int n = spells.size(), m = potions.size();
//        sort(potions.begin(), potions.end());
//        vector<int> ret;
//        for (int i = 0; i < n; i++)
//        {
//            int left = 0, right = m - 1;
//            while (left < right)
//            {
//                int mid = left + (right - left) / 2;
//                long long tmp = potions[mid] * spells[i];
//                if (tmp >= success) right = mid;
//                else left = mid + 1;
//            }
//            ret.push_back(m - left);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//        int n = spells.size(), m = potions.size();
//        sort(potions.begin(), potions.end());
//        vector<int> ret;
//        for (int i = 0; i < n; i++)
//        {
//            int left = 0, right = m - 1;
//            while (left < right)
//            {
//                int mid = left + (right - left) / 2;
//                if ((long long)potions[mid] * spells[i] >= success) right = mid;
//                else left = mid + 1;
//            }
//            if ((long long)potions[left] * spells[i] < success)
//                ret.push_back(0);
//            else
//                ret.push_back(m - left);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int longestEqualSubarray(vector<int>& nums, int k) {
//        int n = nums.size();
//        int cnt[20]{ 0 };
//        int mx = 0, tmp = 0;
//        for (int i = 0; i < n; i++)
//        {
//            cnt[nums[i]]++;
//        }
//        for (int i = 0; i < 7; i++)
//        {
//            if (tmp < cnt[i])
//            {
//                mx = i;
//                tmp = cnt[i];
//            }
//        }
//        int ret = 0;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            // 进窗口
//            int in = nums[right];
//            if (in != mx) count++;
//            while (left<right && count>k)
//            {
//                int ou = nums[left++];
//                if (ou != mx) count--;
//            }
//            ret = max(ret, right - left + 1 - count);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int longestEqualSubarray(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<vector<int>> pos_lists(n + 1);
//        for (int i = 0; i < n; i++) {
//            int x = nums[i];
//            pos_lists[x].push_back(i);
//        }
//
//        int ans = 0;
//        for (auto& pos : pos_lists) {
//            int left = 0;
//            for (int right = 0; right < pos.size(); right++) 
//            {
//                while (pos[right] - pos[left]-right+left > k) // 要删除的数太多了
//                {
//                    left++;
//                }
//                ans = max(ans, right - left + 1);
//            }
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    string shortestBeautifulSubstring(string s, int k) {
//        int n = s.size();
//        int ans = n + 1;
//        int begin = 0;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            // 进窗口
//            if (s[right] == '1') count++;
//            while (count == k)
//            {
//                if (ans > right - left + 1)
//                {
//                    begin = left;
//                    ans = right - left + 1;
//                }
//                if (s[left++] == '1') count--;
//            }
//        }
//        if (ans == n + 1) return "";
//        string ret;
//        ret = s.substr(begin, ans);;
//        return ret;
//    }
//};

//class Solution {
//public:
//    string shortestBeautifulSubstring(string s, int k) {
//        int n = s.size();
//        int ans = n + 1;
//        int begin = 0;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//             进窗口
//            if (s[right] == '1') count++;
//            while (count == k)
//            {
//                if (ans >= right - left + 1)
//                {
//                    begin = left;
//                    ans = right - left + 1;
//                }
//                if (s[left++] == '1') count--;
//            }
//        }
//        if (ans == n + 1) return "";
//        return s.substr(begin, ans);
//    }
//};

//class Solution {
//public:
//    string shortestBeautifulSubstring(string s, int k) {
//        int n = s.size();
//        int ans = n + 1;  // 用于记录最短子串的长度
//        string bestSubstr = "";  // 存储字典序最小的最短子串
//
//        // 使用双指针滑动窗口方法
//        for (int left = 0, right = 0, count = 0; right < n; ++right) {
//            // 如果右指针指向 '1'，增加 '1' 的计数
//            if (s[right] == '1') count++;
//
//            // 当窗口内的 '1' 的个数为 k 时
//            while (count == k) {
//                string subStr = s.substr(left, right - left + 1);
//
//                // 如果找到一个更短的子串，或者相同长度但字典序更小
//                if (subStr.length() < ans || (subStr.length() == ans && subStr < bestSubstr)) {
//                    bestSubstr = subStr;
//                    ans = subStr.length();  // 更新最短长度
//                }
//
//                // 收缩窗口，左指针右移，减少窗口中的 '1' 的个数
//                if (s[left++] == '1') count--;
//            }
//        }
//
//        // 如果没有找到符合条件的美丽子字符串，返回 ""
//        return bestSubstr.empty() ? "" : bestSubstr;
//    }
//};

//class Solution {
//public:
//    int balancedString(string s) {
//        int n = s.size();
//        int ret = n;
//        int m = n / 4;
//        int cnt['X']{};
//        for (char c : s) ++cnt[c];
//        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) return 0; // 已经符合要求啦
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            --cnt[s[right]];
//            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m)
//            {
//                ret = min(ret, right - left + 1);
//                ++cnt[s[left++]];
//            }
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        int ret = INT_MAX;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long sum = 0;
        for (int left = 0, right = 0; right < n * 2; right++)
        {
            sum += nums[right % n];
            while (sum > target % total)
            {
                sum -= nums[left++ % n];
            }
            if (sum == target % total) ret = min(ret, right - left + 1);
        }
        return ret == INT_MAX ? -1 : ret + target / total * n;;
    }
};

int main()
{
    Solution s;
    vector<int> v1{ 1,3,2,3,1,3 };
    vector<int> v2{ 1,2,3,4,5 };
    string s1{ "110101000010110101"};
    return 0;
}