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


int main()
{
    Solution s;
    s.distributeCandies(60, 5);
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