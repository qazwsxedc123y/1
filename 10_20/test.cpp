#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

//class Solution {
//public:
//    bool hasAllCodes(string s, int k) {
//        int n = s.size();
//        if (n < (1 << k) + k - 1) {
//            return false;
//        }
//        int num = stoi(s.substr(0, k), nullptr, 2);
//        unordered_set<int> hash = { num };
//        for (int i = 1; i + k <= n; i++)
//        {
//            num = (num - ((s[i - 1] - '0') << (k - 1))) * 2 + (s[i + k - 1] - '0');
//            hash.insert(num);
//        }
//        return hash.size() == (1 << k);
//    }
//};

//class Solution {
//public:
//    bool hasAllCodes(string s, int k) {
//        int n = s.size();
//        int su = 2 * k;
//        unordered_set<string> hash;
//        for (int left = 0, right = 0; right + k <= n; right++)
//        {
//            hash.insert(s.substr(right, k));
//        }
//        return hash.size() == (1 << k);
//    }
//};

//class Solution {
//public:
//    long long maxSum(vector<int>& nums, int m, int k) {
//        int n = nums.size();
//        long long ret = 0;
//        long long sum = 0;
//        unordered_map<int, int> cnt;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            // 进窗口
//            sum += nums[right];
//            cnt[nums[right]]++;
//            // 判断出
//            while (right - left + 1 >= k)
//            {
//                // 判断是否更新结果
//                if (cnt.size() >= m)
//                {
//                    ret = max(ret, sum);
//                }
//                // 出
//                if (--cnt[left] == 0)
//                {
//                    cnt.erase(nums[left]);
//                }
//                sum -= nums[left++];
//
//            }
//        }
//        return ret;
//    }
//};
//
//class Solution {
//public:
//    long long maxSum(vector<int>& nums, int m, int k) {
//        int n = nums.size();
//        long long ret = 0;
//        long long sum = 0;
//        unordered_map<int, int> cnt;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            // 进窗口
//            sum += nums[right];
//            cnt[nums[right]]++;
//            // 判断出
//            while (right - left + 1 >= k)
//            {
//                // 判断是否更新结果
//                if (cnt.size() >= m)
//                {
//                    ret = max(ret, sum);
//                }
//                // 出
//                cnt[nums[left]]--;
//                if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
//                sum -= nums[left++];
//
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    long long maximumSubarraySum(vector<int>& nums, int k) {
//        long long res = 0;
//        int n = nums.size();
//        long long curs = 0;
//        unordered_map<int, int> cnt;
//        int cf = 0;
//        for (int r = 0, l = 0; r < n; r++) {
//            curs += nums[r];
//            cnt[nums[r]]++;
//            if (cnt[nums[r]] == 2) cf++;
//            if (r - l + 1 > k) {
//                curs -= nums[l];
//                cnt[nums[l]]--;
//                if (cnt[nums[l]] == 1) cf--;
//                l++;
//            }
//            if (r - l + 1 == k) {
//                if (cf == 0) res = max(res, curs);
//            }
//        }
//        return res;
//    }
//};

int main()
{
    Solution s;
    vector<int> v{ 1,2,1,2,1,2,1 };
    s.maxSum(v, 3, 3);
	return 0;
}