#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
int mian()
{
	return 0;
}


//class Solution {
//    int tmp[500001];
//    // 降序  后面有多少个2倍还比我小
//public:
//    int mergeSort(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return 0;
//        int ret = 0;
//        int mid = (right - left) / 2 + left;
//        ret += mergeSort(nums, left, mid);
//        ret += mergeSort(nums, mid + 1, right);
//
//        int cur1 = left, cur2 = mid + 1, i = 0;
//        while (cur1 <= mid)
//        {
//            while (cur2 <= right && nums[cur2] >= nums[cur1] * 0.5) cur2++;
//            if (cur2 > right) break;
//            // 统计
//            ret += right - cur2 + 1;
//            cur1++;
//        }
//
//
//        // 合并
//        cur1 = left, cur2 = mid + 1;
//        while (cur1 <= mid && cur2 <= right)
//        {
//            // 降序
//            if (nums[cur1] >= nums[cur2])
//            {
//                tmp[i++] = nums[cur1++];
//            }
//            else
//            {
//                tmp[i++] = nums[cur2++];
//            }
//        }
//        while (cur1 <= mid) tmp[i++] = nums[cur1++];
//        while (cur2 <= right) tmp[i++] = nums[cur2++];
//
//        // 恢复
//        for (int j = left; j <= right; j++)
//        {
//            nums[j] = tmp[j - left];
//        }
//        return ret;
//    }
//    int reversePairs(vector<int>& nums) {
//        int ret = mergeSort(nums, 0, nums.size() - 1);
//        return ret;
//    }
//};


//class Solution {
//    vector<int> ret;
//    vector<int> index;
//    int tmpNums[500005];
//    int tmpIndex[500005];
//public:
//    // 降序
//    void mergeSort(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return;
//        int mid = (right - left) / 2 + left;
//        mergeSort(nums, left, mid);
//        mergeSort(nums, mid + 1, right);
//        int cur1 = left, cur2 = mid + 1, i = 0;
//        while (cur1 <= mid && cur2 <= right)
//        {
//            if (nums[cur1] <= nums[cur2])
//            {
//                tmpNums[i] = nums[cur2];
//                tmpIndex[i++] = index[cur2++];
//            }
//            else
//            {
//                ret[index[cur1]] += right - cur2 + 1;
//                tmpNums[i] = nums[cur1];
//                tmpIndex[i++] = index[cur1++];
//            }
//        }
//        while (cur1 <= mid)
//        {
//            tmpNums[i] = nums[cur1];
//            tmpIndex[i++] = index[cur1++];
//        }
//        while (cur2 <= right)
//        {
//            tmpNums[i] = nums[cur2];
//            tmpIndex[i++] = index[cur2++];
//        }
//
//        // 复原
//        for (int j = left; j <= right; j++)
//        {
//            nums[j] = tmpNums[j - left];
//            index[j] = tmpIndex[j - left];
//        }
//    }
//    vector<int> countSmaller(vector<int>& nums) {
//        int n = nums.size();
//        ret.resize(n);
//        index.resize(n);
//
//        for (int i = 0; i < n; i++)
//        {
//            index[i] = i;
//        }
//        mergeSort(nums, 0, n - 1);
//        return ret;
//    }
//};


//class Solution {
//    int t[50001];
//public:
//    int mergeSort(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return 0;
//        int mid = (right - left) / 2 + left;
//        int ret = 0;
//
//        ret += mergeSort(nums, left, mid);
//        ret += mergeSort(nums, mid + 1, right);
//
//        int cur1 = left, cur2 = mid + 1, i = 0;
//        while (cur1 <= mid && cur2 <= right)
//        {
//            if (nums[cur1] > nums[cur2])
//            {
//                ret += mid - cur1 + 1;
//                t[i++] = nums[cur2++];
//            }
//            else
//            {
//                t[i++] = nums[cur1++];
//            }
//        }
//        while (cur1 <= mid) t[i++] = nums[cur1++];
//        while (cur2 <= right) t[i++] = nums[cur2++];
//
//        for (int j = left; j <= right; j++)
//            nums[j] = t[j - left];
//        return ret;
//    }
//    int inversePairs(vector<int>& nums) {
//        int ret = 0;
//        ret = mergeSort(nums, 0, nums.size() - 1);
//        return ret;
//    }
//};


//class Solution {
//public:
//    void mergeSort(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return;
//        int mid = (right - left) / 2 + left;
//        mergeSort(nums, left, mid);
//        mergeSort(nums, mid + 1, right);
//
//        // 辅助
//        vector<int> t(right - left + 1);
//        int cur1 = left, cur2 = mid + 1, i = 0;
//        while (cur1 <= mid && cur2 <= right)
//        {
//            t[i++] = nums[cur1] > nums[cur2] ? nums[cur2++] : nums[cur1++];
//        }
//        while (cur1 <= mid) t[i++] = nums[cur1++];
//        while (cur2 <= right) t[i++] = nums[cur2++];
//
//        // 还原
//        for (int i = left; i <= right; i++)
//        {
//            nums[i] = t[i - left];
//        }
//    }
//    vector<int> sortArray(vector<int>& nums) {
//        mergeSort(nums, 0, nums.size() - 1);
//        return nums;
//    }
//};