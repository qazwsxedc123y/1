#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr) {
//        int left = 0, right = arr.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (arr[mid] >= arr[mid - 1]) left = mid;
//            else right = mid - 1;
//        }
//        return left;
//    }
//};

//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int n = nums.size();
//        int left = 0, right = n - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] <= nums[n - 1]) right = mid;
//            else left = mid + 1;
//        }
//        return nums[left];
//    }
//};

//class Solution {
//public:
//    int takeAttendance(vector<int>& records) {
//        // 方法一 哈希表
//        // 暴力查找
//        // 高斯公式
//        // 位运算
//        int left = 0, right = records.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (records[mid] == mid) left = mid + 1;
//            else right = mid;
//        }
//        return left == records[left] ? left + 1 : left;
//    }
//};



int main()
{

    return 0;
}