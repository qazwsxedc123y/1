#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    bool CheckPermutation(string s1, string s2) {
//        int count[26] = { 0 };
//        if (s1.size() != s2.size()) return false;
//        for (int i = 0; i < s1.size(); i++)
//        {
//            count[s1[i] - 'a']++;
//        }
//        for (int i = 0; i < s2.size(); i++)
//        {
//            count[s2[i] - 'a']--;
//            if (count[s2[i] - 'a'] < 0) return false;
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        unordered_set<int> hash;
//        for (auto num : nums)
//        {
//            if (hash.count(num)) return true;
//            hash.insert(num);
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (hash.count(nums[i]))
//            {
//                if (i - hash[nums[i]] <= k) return true;
//            }
//            hash[nums[i]] = i;
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> ret;
//        unordered_map<string, vector<string>> hash;
//        // 先分组
//        for (int i = 0; i < strs.size(); i++)
//        {
//            string tmp = strs[i];
//            sort(tmp.begin(), tmp.end());
//            hash[tmp].push_back(strs[i]);
//        }
//
//        // 提取出来放到ret中
//        for (auto& [x, y] : hash)
//        {
//            ret.push_back(y);
//        }
//        return ret;
//    }
//};

int main()
{
    string s1 = "abc", s2 = "bad";
    Solution s;
    // s.CheckPermutation(s1, s2);
    return 0;
}
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> hash;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (hash.count(target - nums[i]))
//            {
//                return { i,hash[target - nums[i]] };
//            }
//            hash[nums[i]] = i;
//        }
//        return { -1, -1 };
//    }
//};