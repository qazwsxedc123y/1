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
#include <algorithm>
#include <queue>       // 用于 priority_queue
#include <functional>  // 用于 greater less 比较器

using namespace std;

//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int n = nums.size();
//        int left = -1, right = n, i = 0;
//        while (i < right)
//        {
//            if (nums[i] == 0) {
//                swap(nums[++left], nums[i++]);
//            }
//            else if (nums[i] == 1) {
//                i++;
//            }
//            else {
//                swap(nums[--right], nums[i]);
//            }
//        }
//    }
//};

//class Solution {
//public:
//    int getRandom(vector<int>& nums, int left, int right)
//    {
//        int r = rand();// 获得一个随机数
//        return nums[r % (right - left + 1) + left];
//    }
//    void partation(vector<int>& nums, int left, int right)
//    {
//        if (left >= right) return;
//        int key = getRandom(nums, left, right);
//        // 分为两部分 <ket =key >key
//        int i = left, l = left - 1, r = right + 1;// 定义左指针为-1，右指针为n
//        while (i < r)
//        {
//            if (nums[i] < key)
//            {
//                swap(nums[++l], nums[i++]);
//            }
//            else if (nums[i] == key)
//            {
//                i++;
//            }
//            else
//            {
//                swap(nums[--r], nums[i]);
//            }
//        }
//        partation(nums, left, l);
//        partation(nums, r, right);
//    }
//    vector<int> sortArray(vector<int>& nums) {
//        int n = nums.size();
//        srand(time(NULL));// 生成一个随机数种子
//        partation(nums, 0, n - 1);
//        return nums;
//    }
//};

//class Solution {
//public:
//    int getRandom(vector<int>& nums, int left, int right)
//    {
//        int r = rand();// 获得一个随机数
//        return nums[r % (right - left + 1) + left];
//    }
//    int partation(vector<int>& nums, int left, int right, int k)
//    {
//        int l = left - 1, r = right + 1, i = left;
//        int key = getRandom(nums, left, right);
//        while (i < r)
//        {
//            if (nums[i] < key)
//            {
//                swap(nums[++l], nums[i++]);
//            }
//            else if (nums[i] == key)
//            {
//                i++;
//            }
//            else
//            {
//                swap(nums[--r], nums[i]);
//            }
//        }
//        int c = right - r + 1, b = r - l - 1;
//        if (c >= k) return partation(nums, r, right, k);
//        else if (b + c >= k) return key;
//        else return partation(nums, left, l, k - b - c);// 注意要返回k-b-c
//    }
//    int findKthLargest(vector<int>& nums, int k) {
//        int n = nums.size();
//        srand(time(NULL));// 生成随机数种子
//        return partation(nums, 0, n - 1, k);
//    }
//};

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int> maxHeap(nums.begin(), nums.end());
//        while (--k)
//        {
//            maxHeap.pop();
//        }
//        return maxHeap.top();
//    }
//};

//class Solution {
//public:
//    vector<int> smallestK(vector<int>& arr, int k) {
//        sort(arr.begin(), arr.end());
//        vector<int> ret;
//        for (int i = 0; i < k; i++) {
//            ret.push_back(arr[i]);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> smallestK(vector<int>& arr, int k) {
//        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
//        vector<int> ret;
//        while (k--)
//        {
//            ret.push_back(minHeap.top());
//            minHeap.pop();
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int getRandom(vector<int>& arr, int left, int right)
//    {
//        int r = rand();// 获得一个随机数
//        return arr[r % (right - left + 1) + left];
//    }
//    void partation(vector<int>& arr, int left, int right, int k)
//    {
//        if (left >= right) return;
//        int key = getRandom(arr, left, right);
//        int i = left, l = left - 1, r = right + 1;// 定义左指针为-1，右指针为n
//        while (i < r)
//        {
//            if (arr[i] < key)
//            {
//                swap(arr[++l], arr[i++]);
//            }
//            else if (arr[i] == key)
//            {
//                i++;
//            }
//            else
//            {
//                swap(arr[--r], arr[i]);
//            }
//        }
//        int a = l - left + 1, b = r - l - 1;
//        if (a > k) partation(arr, left, l, k);
//        else if (a + b >= k) return;
//        else partation(arr, r, right, k - a - b);
//    }
//    vector<int> smallestK(vector<int>& arr, int k) {
//        srand(time(NULL));// 设置一个随机数的种子
//        partation(arr, 0, arr.size() - 1, k);
//        return { arr.begin(),arr.begin() + k };
//    }
//};

//class Solution {
//public:
//    // 使用归并排序进行解题
//    void mergeSort(vector<int>& nums, int left, int right)
//    {
//        // 处理临界情况
//        if (left >= right) return;
//        // 1.选择中间点进行划分区间
//        int mid = (right - left) / 2 + left;
//        // 分为两个区间
//        // [left,mid] [mid+1,right] 
//        // 2.把总区间分为两个小区间，分为两个问题进行讨论
//        // 对两个区间分别排序
//        mergeSort(nums, left, mid);
//        mergeSort(nums, mid + 1, right);
//        // 3.进行两个小区间合并
//        vector<int> t(right - left + 1);
//        int cur1 = left, cur2 = mid + 1, i = 0;
//        while (cur1 <= mid && cur2 <= right)
//        {
//            t[i++] = nums[cur1] > nums[cur2] ? nums[cur2++] : nums[cur1++];
//        }
//        // 处理没有处理的剩余区间
//        while (cur1 <= mid) t[i++] = nums[cur1++];
//        while (cur2 <= right) t[i++] = nums[cur2++];
//        // 4.还原
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

int main()
{
    Solution s;
    vector<int> v{ 1,3,5,7,2,4,6,8 };
    s.smallestK(v, 4);
    return 0;
}