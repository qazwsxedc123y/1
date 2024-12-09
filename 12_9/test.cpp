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
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    long long countFairPairs(vector<int>& nums, int lower, int upper) {
//        long long ans = 0;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i++)
//        {
//            auto r = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
//            auto l = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
//            ans += r - l;
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    long long countFairPairs(vector<int>& nums, int lower, int upper) {
//        long long ans = 0;
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int left = n, right = left;
//        for (int j = 0; j < n; j++)
//        {
//            while (right && nums[right - 1] > upper - nums[j]) {
//                right--;
//            }
//            while (left && nums[left - 1] >= lower - nums[j]) {
//                left--;
//            }
//            ans += min(right, j) - min(left, j);
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    int hammingWeight(int n) {
//        int ret = 0;
//        while (n)
//        {
//            n &= (n - 1);
//            ret++;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> countBits(int n) {
//        vector<int> v;
//        for (int i = 0; i <= n; i++) {
//            int t = i;
//            int ret = 0;
//            while (t) {
//                t &= (t - 1);
//                ret++;
//            }
//            v.push_back(ret);
//        }
//        return v;
//    }
//};

//class Solution {
//public:
//    int hammingDistance(int x, int y) {
//        int ans = x ^ y, ret = 0;
//        while (ans) {
//            ans &= (ans - 1);
//            ret++;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ret = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            ret ^= nums[i];
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        unordered_map<int, int> hash;
//        for (auto& num : nums) {
//            hash[num]++;
//        }
//        auto it = hash.begin();
//        int ret = 0;
//        while (it != hash.end()) {
//            if (it->second == 1) {
//                ret = it->first;
//                break;
//            }
//            it++;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    bool isUnique(string astr) {
//        // 鸽巢原理
//        int n = astr.size();
//        if (n > 26) return false;
//        for (int i = 0; i < 26; i++) {
//            int sum = 0;
//            char ch = 'a' + i;
//            for (int j = 0; j < n; j++) {
//                if (astr[j] == ch) {
//                    sum++;
//                }
//                if (sum > 1) return false;
//            }
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int ret = 0;
//        for (auto num : nums) ret ^= num;
//        for (int i = 0; i <= nums.size(); i++) ret ^= i;
//        return ret;
//    }
//};

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        vector<int> v(nums.size() + 1);
//        for (auto num : nums) v[num]++;
//        int ret = 0;
//        for (int i = 0; i <= nums.size(); i++) {
//            if (v[i] == 0) {
//                ret = i;
//                break;
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int getSum(int a, int b) {
//        return a + b;
//    }
//};

//class Solution {
//public:
//    int getSum(int a, int b) {
//        while (b != 0) {
//            int carry = (a & b) << 1;
//            a ^= b;
//            b = carry;
//        }
//        return a;
//    }
//};

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        // 模3 位图
//        int ret = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            int sum = 0;
//            for (auto num : nums) { // 计算nums中所有数的第 i 位的和
//                if (((num >> i) & 1) == 1) sum++;
//            }
//            sum %= 3;// 当前为为sum
//            if (sum == 1)
//                ret |= (1 << i);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> missingTwo(vector<int>& nums) {
//        // 组合体：消失数字+只出现一次的数字3
//        // 分组
//        int ret = 0;
//        int N = nums.size() + 2;
//        for (auto num : nums) ret ^= num;
//        for (int i = 1; i <= N; i++) ret ^= i;
//        // 仅使得最小位的1保存
//        int t = (ret == INT_MIN ? ret : ret & (-ret));
//        // 分组
//        int ret1 = 0, ret2 = 0;
//        for (auto num : nums)
//        {
//            if (num & t)
//            {
//                ret1 ^= num;
//            }
//            else
//                ret2 ^= num;
//        }
//        for (int i = 1; i <= N; i++)
//        {
//
//            if (i & t)
//            {
//                ret1 ^= i;
//            }
//            else
//                ret2 ^= i;
//        }
//        return { ret1,ret2 };
//    }
//};

int main()
{
    Solution s;
    vector<int> v{ 2,2,2,-1,-1,-1,8,-7,0,-7,0,-7,0 };
    s.singleNumber(v);
	return 0;
}