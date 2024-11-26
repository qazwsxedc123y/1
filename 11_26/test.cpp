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

//class Solution {
//public:
//    int maxConsecutiveAnswers(string answerKey, int k) {
//        int n = answerKey.size();
//        int ret = 0;
//        // 先统计最长的T
//        for (int left = 0, right = 0, change = 0; right < n; right++)
//        {
//            if (answerKey[right] == 'F') change++;
//            while (change > k)
//            {
//                char ou = answerKey[left++];
//                if (ou == 'F') change--;
//            }
//            ret = max(ret, right - left + 1);
//        }
//        for (int left = 0, right = 0, change = 0; right < n; right++)
//        {
//            if (answerKey[right] == 'T') change++;
//            while (change > k)
//            {
//                char ou = answerKey[left++];
//                if (ou == 'T') change--;
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0, n = nums.size();
        int right = n - 1;
        int ret = 0;
        while (left < right)
        {
            int mid = left + (right - left+1) / 2;
            if (nums[mid] < 0) left = mid;
            else right = mid - 1;
        }
        ret = left + 1;
        left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) right = mid;
            else left = mid + 1;
        }
        if (nums[left] != 0)
        ret = max(ret, n - left);
        return ret;
    }
};

int main()
{
    Solution s;
    string s1{ "TFFT" };
    vector<int> v{ -2,-1,-1,0,0,0 };
    s.maximumCount(v);
    return 0;
}