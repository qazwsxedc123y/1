#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count_1 = 0;// 统计一的个数
        for (auto& num : nums) count_1 += num;
        int count_0 = n - count_1;
        int ret = n;
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            // 进窗口
            count += nums[right];
            // 判断
            if (right - left + 1 >= count_1)
            {
                ret = min(ret, count_1 - count);
                count -= nums[left++];
            }
        }
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            // 进窗口
            if (nums[right] == 0)
            {
                count += 1;
            }
            // 判断
            if (right - left + 1 >= count_0)
            {
                ret = min(ret, count_0 - count);
                if (nums[left++] == 0) count -= 1;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> v{ 1,1,1,0,0,1,0,1,1,0 };
    s.minSwaps(v);
    return 0;
}