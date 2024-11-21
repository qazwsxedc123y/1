#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ret; // 存储结果
        int n = nums.size(); // 数组长度
        vector<int> cnt(101, 0); // 用于存储窗口内数的频次，范围是[-50, 50]，偏移50使其变为[0, 100]

        for (int left = 0, right = 0; right < n; right++) {
            // 进窗口
            cnt[nums[right] + 50]++;

            // 当窗口大小大于等于k时，开始计算结果
            if (right - left + 1 >= k) {
                // 计算当前窗口的x个最小值
                int count = 0;
                for (int i = 0; i <= 100; i++)
                {
                    count += cnt[i]; // 累计当前窗口中小于等于i的数字个数
                    if (count >= x)
                    { // 找到第x个最小的数
                        ret.push_back(i - 50 < 0 ? i - 50 : 0); // 记得加偏移
                        break;
                    }
                }

                // 滑动窗口，移除left元素
                cnt[nums[left] + 50]--;
                left++;
            }
        }

        return ret;
    }
};
