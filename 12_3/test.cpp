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
//    int minimumLength(string s) {
//        int n = s.size();
//        int left = 0, right = n - 1;
//        while (left < right && s[left] == s[right])
//        {
//            char c = s[left];
//            while (left <= right && s[left] == c)
//            {
//                left++;
//            }
//            while (left < right && s[right] == c)
//            {
//                right--;
//            }
//        }
//        return right - left + 1;
//    }
//};

//class Solution {
//public:
//    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
//        int n = plants.size(), ret = 0;
//        int left = 0, right = n - 1;
//        int vala = capacityA, valb = capacityB;
//        while (left < right)
//        {
//            // 先Alice
//            if (vala < plants[left])// 不够浇水
//            {
//                ++ret;
//                vala = capacityA - plants[left++];
//            }
//            else// 够
//            {
//                vala -= plants[left++];
//            }
//            if (valb < plants[right])
//            {
//                ++ret;
//                valb = capacityB - plants[right--];
//            }
//            else
//            {
//                valb -= plants[right--];
//            }
//        }
//        if (left == right)
//        {
//            if (vala >= valb && vala < plants[left])// a浇水 但是水不够
//            {
//                ++ret;
//            }
//            //a浇水 但是a水够 / b浇水
//            if (vala < valb && valb < plants[left])// b浇水 
//            {
//                ++ret;
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        int n = nums.size();
//        int t = 0;// 设置为最后一个 <0 的
//        for (int i = 0; i < n; i++)
//        {
//            if (nums[i] < 0)
//            {
//                t = i;
//            }
//            else
//            {
//                break;
//            }
//        }
//        vector<int> ret;
//        int left = t, right = t + 1;// <0 >=0
//        while (left >= 0 || right < n)
//        {
//            if (left < 0)
//            {
//                ret.push_back(nums[right] * nums[right]);
//                right++;
//            }
//            else if (right >= n)
//            {
//                ret.push_back(nums[left] * nums[left]);
//                left--;
//            }
//            else if (nums[left] * nums[left] <= nums[right] * nums[right])// left进
//            {
//                ret.push_back(nums[left] * nums[left]);
//                left--;
//            }
//            else if (nums[left] * nums[left] > nums[right] * nums[right])
//            {
//                ret.push_back(nums[right] * nums[right]);
//                right++;
//            }
//        }
//        return ret;
//    }
//};



int main()
{

    return 0;
}