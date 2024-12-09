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

//class Solution {
//public:
//    string modifyString(string s) {
//        int n = s.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (s[i] == '?')
//            {
//                for (char ch = 'a'; ch <= 'z'; ch++)
//                {
//                    if ((i == 0 || ch != s[i - 1]) && (i == n - 1 || ch != s[i + 1]))
//                    {
//                        s[i] = ch;
//                    }
//                }
//            }
//        }
//        return s;
//    }
//};

//class Solution {
//public:
//    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//        int ret = 0;
//        int x = 0;
//        for (int i = 0; i < timeSeries.size() - 1; i++)
//        {
//            x = timeSeries[i + 1] - timeSeries[i];
//            if (x >= duration) {
//                ret += duration;
//            }
//            else {
//                ret += x;
//            }
//        }
//        return ret + duration;
//    }
//};


////int main()
////{
////    Solution s;
////    vector<int> v{ 2,2,2,-1,-1,-1,8,-7,0,-7,0,-7,0 };
////    s.singleNumber(v);
////    int n = 5, x = 1;
////    n &= (~(1 << x));
////
////	return 0;
////}


//class Solution {
//public:
//    string countAndSay(int n) {
//        string ret = "1";
//        for (int i = 2; i <= n; i++)
//        {
//            int right = 0, left = 0, count = 0;
//            // push 个数+left指向的数
//            string t;
//            int n = ret.size();
//            while (right < n)
//            {
//                while (right < n && ret[right] == ret[left])
//                {
//                    right++;
//                }
//                count = right - left;
//                t += to_string(count);
//                t += ret[left];
//                left = right;
//            }
//            ret = t;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int minNumberOfFrogs(string croakOfFrogs) {
//        int ret = 0;
//        string t = "croak";
//        int n = t.size();
//        vector<int> hash(n);// 用数组模拟哈希表
//        for (auto ch : croakOfFrogs)
//        {
//            if (ch == 'c')
//            {
//                if (hash[n - 1] != 0) hash[n - 1]--;
//                hash[0]++;
//            }
//            else if (ch == 'r')
//            {
//                if (hash[0] == 0) return -1;
//                else {
//                    hash[0]--;
//                    hash[1]++;
//                }
//            }
//            else if (ch == 'o')
//            {
//                if (hash[1] == 0) return -1;
//                else {
//                    hash[1]--;
//                    hash[2]++;
//                }
//            }
//            else if (ch == 'a')
//            {
//                if (hash[2] == 0) return -1;
//                else {
//                    hash[2]--;
//                    hash[3]++;
//                }
//            }
//            else
//            {
//                if (hash[3] == 0) return -1;
//                else {
//                    hash[3]--;
//                    hash[4]++;
//                }
//            }
//        }
//        for (int i = 0; i < n - 1; i++) {
//            if (hash[i] != 0) return -1;
//        }
//        return hash[n - 1];
//    }
//};

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ret = 0;
        string t = "croak";
        int n = t.size();
        vector<int> hash(n);// 用数组模拟哈希表
        unordered_map<char, int> index;// 存储[x,x这个字符的对应的hash的下标]
        for (int i = 0; i < n; i++)
        {
            index[t[i]] = i;
        }
        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] != 0) hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[ch];// 获取当前字符是什么
                if (hash[i - 1] == 0) return -1;
                hash[i - 1]--;
                hash[i]++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (hash[i] != 0) return -1;
        }
        return hash[n - 1];
    }
};

int main()
{
    Solution s;
    string s1;
    s.minNumberOfFrogs(s1);
    return 0;
}