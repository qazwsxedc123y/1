#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm> 
#include <unordered_map> 
#include <unordered_set> 

using namespace std;
//class Solution {
//public:
//    vector<int> distributeCandies(int candies, int num_people) {
//        vector<int> v(num_people, 0);
//        int i = 0;
//        while (candies)
//        {
//            if (candies > i)
//            {
//                v[i % num_people] = v[i % num_people] + i + 1;
//                candies = candies - i - 1;
//            }
//            else
//            {
//                v[i % num_people] = v[i % num_people] + candies;
//                candies = 0;
//            }
//            i++;
//        }
//        return v;
//    }
//};


//class Solution {
//public:
//    vector<int> findPeaks(vector<int>& mountain) {
//        vector<int> v;
//        int n = mountain.size();
//        for (int i = 1; i < n - 1; i++)
//        {
//            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
//            {
//                v.push_back(i);
//            }
//        }
//        return v;
//    }
//};
//class Solution {
//public:
//    long long countCompleteDayPairs(vector<int>& hours) {
//        long long ret = 0;
//        unordered_map<int, int> mp;
//        for (auto& hour : hours)
//        {
//            int h = hour % 24;
//            int grap = (24 - h) % 24;
//            ret += mp[grap];
//            mp[h]++;
//        }
//        return ret;
//    }
//};



//const pair<int, string> valueSymbols[] = {
//    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
//    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
//    {5, "V"},    {4, "IV"},   {1, "I"},
//};
//class Solution {
//public:
//    string intToRoman(int num) {
//        string ret;
//        for (auto& [n, r] : valueSymbols) {
//            while (num >= n) {
//                num -= n;
//                ret += r;
//            }
//        }
//        return ret;
//    }
//}; 
 

//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        int n = nums.size();
//        int best = 1e7;
//        sort(nums.begin(), nums.end());
//        auto update = [&](int cur)
//            {
//                if (abs(cur - target) < abs(best - target))
//                {
//                    best = cur;
//                }
//            };
//        for (int i = 0; i < n; i++)
//        {
//            if (i > 0 && nums[i] == nums[i - 1])
//            {
//                continue;
//            }
//            int j = i + 1, k = n - 1;
//            while (j < k)
//            {
//                int sum = nums[i] + nums[j] + nums[k];
//                if (sum == target)
//                {
//                    return target;
//                }
//                update(sum);
//                //调整边界情况
//                if (sum > target)
//                {
//                    int k0 = k - 1;
//                    while (j < k0 && nums[k0] == nums[k])
//                    {
//                        --k0;
//                    }
//                    k = k0;
//                }
//                else
//                {
//                    int j0 = j + 1;
//                    while (j0 < k && nums[j] == nums[j0])
//                    {
//                        ++j0;
//                    }
//                    j = j0;
//                }
//            }
//        }
//        return best;
//    }
//};


int main()
{
    vector<int> v{ -1,2,1,-4 };

    Solution s;
    s.threeSumClosest(v, 1);
    return 0;
}

//class Solution {
//public:
//    int countCompleteDayPairs(vector<int>& hours) {
//        int n = hours.size();
//        int ret = 0;
//        unordered_map<int, int> mp;
//        for (int i = 0; i < n; i++)
//        {
//            int h = hours[i] % 24;
//            int gap = (24 - h) % 24;
//            ret += mp[gap];
//            mp[h]++;
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    int smallestRangeII(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int mx = nums.back(), mi = nums[0];
//        int ret = mx - mi;
//        for (int i = 1; i < n; i++)
//        {
//            // mx=max(nums[n-1]-k,nums[i]+k)
//            // mi=min(mi,nums[0]+k,nums[i]-k)
//            ret = min(ret, max(nums[n - 1] - k, nums[i - 1] + k) - min(nums[0] + k, nums[i] - k));
//        }
//        return ret;
//    }
//};