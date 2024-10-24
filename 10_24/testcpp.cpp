#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//        int ans = 0;
//        bool flag = false;
//        for (int i = n - 1; i > 0; i--)
//        {
//            int right = i;
//            int left = 0;
//            while (right >= left)
//            {
//                if (nums[right] < nums[i])
//                {
//                    swap(nums[right], nums[i]);
//                    flag = true;
//                    break;
//                }
//                --right;
//            }
//            if (!flag && i == 1 && right <= left)//没有进行交换，需要返回正序 剩下的操作什么都不做
//            {
//                sort(nums.begin(), nums.end());
//                ans = -1;
//                break;
//            }
//            ans = right;
//            if (flag)
//            {
//                break;
//            }
//        }
//        if(ans!=-1)
//        {
//            for (int i = n - 1; i > ans; i--)
//            {
//                for (int j = n - 1; j > ans + 1; j--)
//                {
//                    if (nums[j] < nums[j - 1])
//                    {
//                        swap(nums[j], nums[j - 1]);
//                    }
//                }
//            }
//        }
//    }
//};

//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//        int i = n - 2, j = n - 1, k = n - 1;
//        while (i >= 0 && nums[i] >= nums[j])
//        {
//            i--;
//            j--;
//        }
//        if (i >= 0)
//        {
//            while (nums[i] >= nums[k])
//            {
//                --k;
//            }
//            swap(nums[i], nums[k]);
//        }
//        sort(nums.begin() + j, nums.end());
//    }
//};

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n = (int)nums.size();
//        if (!n) {
//            return -1;
//        }
//        if (n == 1) {
//            return nums[0] == target ? 0 : -1;
//        }
//        int l = 0, r = n - 1;
//        while (l <= r) {
//            int mid = (l + r) / 2;
//            if (nums[mid] == target) return mid;
//            if (nums[0] <= nums[mid]) {
//                if (nums[0] <= target && target < nums[mid]) {
//                    r = mid - 1;
//                }
//                else {
//                    l = mid + 1;
//                }
//            }
//            else {
//                if (nums[mid] < target && target <= nums[n - 1]) {
//                    l = mid + 1;
//                }
//                else {
//                    r = mid - 1;
//                }
//            }
//        }
//        return -1;
//    }
//};

int main()
{
    Solution s;
    vector<int> v{ 3,2,1 };
    s.nextPermutation(v);
	return 0;
}