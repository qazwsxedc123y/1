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

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = 0;
        unordered_map<int, int> hash1, hash2;// 一个是大于k个，一个是大于k+1个
        for (int left1 = 0, left2 = 0, right = 0; right < n; right++)
        {
            hash1[nums[right]]++;
            hash2[nums[right]]++;
            while (left1 <= right && hash1.size() >= k)
            {
                if (--hash1[nums[left1]] == 0)
                {
                    hash1.erase(nums[left1]);
                }
                left1++;
            }
            while (left2 <= right && hash2.size() >= k + 1)
            {
                if (--hash2[nums[left2]] == 0)
                {
                    hash2.erase(nums[left2]);
                }
                left2++;
            }
            ret += (left1 - left2);
        }
        return ret;
    }
};

int main()
{
    return 0;
}