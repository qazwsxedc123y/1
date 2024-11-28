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
//    int findLengthOfShortestSubarray(vector<int>& arr) {
//        int n = arr.size(), right = n - 1;
//        while (right && arr[right - 1] <= arr[right]) right--;
//        if (right == 0) return 0;// 已经符合要求了，直接返回
//        int ret = right;// 删除0-right
//        for (int left = 0; ; right++)
//        {
//            while (right == n || arr[left] <= arr[right])
//            {
//                ret = min(ret, right - left - 1);
//                if (arr[left] > arr[left + 1]) return ret;
//                left++;
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int numberOfSubstrings(string s) {
//        int cnt[3] = { 0 };
//        int n = s.size();
//        int ret = 0;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            // 进窗口
//            cnt[s[right] - 'a']++;
//            // 更新结果
//            while (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1)
//            {
//                cnt[s[left++] - 'a']--;
//            }
//            ret += left;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int countCompleteSubarrays(vector<int>& nums) {
//        int n = nums.size();
//        unordered_map<int, int> hash1;
//        for (auto& num : nums) hash1[num]++;
//        int ans = hash1.size();
//        unordered_map<int, int> hash2;
//        int ret = 0;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            // 进
//            if (hash2[nums[right]] == 0) count++;
//            hash2[nums[right]]++;
//            while (count == ans)
//            {
//                if (--hash2[nums[left++]] == 0) count--;
//            }
//            ret += left;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    long long countGood(vector<int>& nums, int k) {
//        long long ans = 0;
//        unordered_map<int, int> cnt;
//        int pairs = 0;
//        int n = nums.size();
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            pairs += cnt[nums[right]]++;
//            while (pairs >= k)
//            {
//                pairs -= --cnt[nums[left++]];
//            }
//            ans += left;
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    int countKConstraintSubstrings(string s, int k) {
//        int n = s.size();
//        int ret = 0;
//        for (int left = 0, right = 0, count0 = 0, count1 = 0; right < n; right++)
//        {
//            // 进窗口
//            s[right] == '0' ? count0++ : count1++;
//            while (count0 > k && count1 > k)
//            {
//                s[left++] == '0' ? count0-- : count1--;
//            }
//            ret += right - left + 1;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    long long countSubarrays(vector<int>& nums, long long k) {
//        int n = nums.size();
//        long long ret = 0LL;
//        long long sum = 0LL;
//        for (int left = 0, right = 0, ans = 0; right < n; right++)
//        {
//            // 进窗口
//            sum += nums[right];
//            while (sum * (right - left + 1) >= k)// 出窗口      
//                sum -= nums[left++];
//            ret += right - left + 1;
//        }
//        return ret;
//    }
//};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> s;
        long long ret = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > 2)// 不满足
            {
                s.erase(s.find(nums[left++]));
            }
            ret += right - left + 1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string s1{ "10101" };
    return 0;
}