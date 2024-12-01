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
//    int subarraysWithKDistinct(vector<int>& nums, int k) {
//        int n = nums.size();
//        int ret = 0;
//        unordered_map<int, int> hash1, hash2;// 一个是大于k个，一个是大于k+1个
//        for (int left1 = 0, left2 = 0, right = 0; right < n; right++)
//        {
//            hash1[nums[right]]++;
//            hash2[nums[right]]++;
//            while (left1 <= right && hash1.size() >= k)
//            {
//                if (--hash1[nums[left1]] == 0)
//                {
//                    hash1.erase(nums[left1]);
//                }
//                left1++;
//            }
//            while (left2 <= right && hash2.size() >= k + 1)
//            {
//                if (--hash2[nums[left2]] == 0)
//                {
//                    hash2.erase(nums[left2]);
//                }
//                left2++;
//            }
//            ret += (left1 - left2);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int smallestNumber(int n) {
//        int ret = n;
//        int tmp = n;
//        int i = 0;
//        while (tmp /= 2)
//        {
//            if ((ret & (1 << i)) == 0)
//            {
//                return ret |= (1 << i);
//            }
//            i++;
//        }
//        return ret;  // 理论上不会到达这里
//    }
//};

//class Solution {
//public:
//    int getLargestOutlier(vector<int>& nums) {
//        int n = nums.size();
//        int m = n - 2;
//        int ret = INT_MIN;
//        for (int left = 0, right = 0, sum = 0; right < n; right++) {
//            // 进窗口
//            sum += nums[right];
//            if (right - left + 1 >= m) {// 不满足
//                if (find(nums.begin(), nums.end(), sum) != nums.end()) {
//                    bool falg = false;
//                    for (int i = 0; i < n;) {
//                        if (i >= left && i <= right) i++;
//                        else if (nums[i] == sum && !falg) {
//                            i++;
//                            falg = true;
//                        }
//                        else {
//                            if (falg)
//                                ret = max(ret, nums[i]);
//                            i++;
//                        }
//                    }
//                }
//                sum -= nums[left++];
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int getLargestOutlier(vector<int>& nums) {
//        int n = nums.size();
//        int m = n - 2; // 计算特殊数字的数量
//        int ret = INT_MIN; // 用来存储最大异常值
//
//        // 创建一个集合，用来存储所有的特殊数字
//        unordered_set<int> numSet(nums.begin(), nums.end());
//
//        // 遍历数组并考虑每个元素作为可能的"和"
//        for (int i = 0; i < n; i++) {
//            int sum = nums[i]; // 假设nums[i]为和
//            // 从数组中移除当前元素，确保不把当前和作为异常值
//            numSet.erase(nums[i]);
//
//            // 计算和的其他特殊数字
//            for (int j = 0; j < n; j++) {
//                if (i != j) {
//                    sum += nums[j];
//                    numSet.erase(nums[j]);
//                }
//            }
//
//            // 验证是否为有效的“和”
//            if (numSet.find(sum) == numSet.end()) {
//                // 找到有效的“和”，计算异常值
//                for (int i = 0; i < n; i++) {
//                    if (nums[i] == sum) continue;
//                    ret = max(ret, nums[i]);
//                }
//            }
//            break;
//        }
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    int getLargestOutlier(vector<int>& nums) {
//        int n = nums.size();
//        multiset<int> ans;
//        long long sum = 0;
//        for (int i = 0; i < n; i++)
//            sum += nums[i], ans.insert(nums[i]);
//        long long ret = -1e9;
//        for (int i = 0; i < n; i++)
//        {
//            ans.erase(ans.find(nums[i]));
//            long long t = sum - nums[i] * 2;
//            if (ans.find(t) != ans.end()) ret = max(ret, t);
//            ans.insert(nums[i]);
//        }
//        return ret;
//    }
//};

int main()
{
    Solution s;
    //s.smallestNumber(5);
    vector<int> v{ -310,-702,-702 };
    s.getLargestOutlier(v);
    return 0;
}