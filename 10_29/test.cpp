#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int n = arr.size();
//        int dest = -1, cur = 0;
//        while (dest < n)
//        {
//            if (arr[cur])
//            {
//                dest++;
//            }
//            else
//            {
//                dest += 2;
//            }
//            if (dest >= n - 1) break;
//            cur++;
//        }
//        //cout<<arr[cur];
//        if (dest == n)
//        {
//            arr[n - 1] = 0;
//            dest -= 2;
//            cur--;
//        }
//        while (cur >= 0)
//        {
//            if (arr[cur])
//            {
//                arr[dest] = arr[cur];
//                cur--;
//                dest--;
//            }
//            else
//            {
//                arr[dest] = arr[cur];
//                dest--;
//                arr[dest] = arr[cur];
//                dest--;
//                cur--;
//            }
//        }
//    }
//};

//class Solution {
//public:
//    int bitsum(int n)
//    {
//        int ret = 0;
//        while (n)
//        {
//            int t = n % 10;
//            ret += t * t;
//            n /= 10;
//        }
//        return ret;
//    }
//    bool isHappy(int n) {
//        int slow = n, fast = bitsum(n);
//        while (slow != fast)
//        {
//            slow = bitsum(slow);
//            fast = bitsum(bitsum(fast));
//        }
//        return slow == 1;
//    }
//};

//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ret = 0;
//        for (int c = n - 1; c >= 2; c--) {
//            int a = 0, b = c - 1;
//            while (b > a) {
//                if (nums[a] + nums[b] > nums[c]) {
//                    ret += b - a;
//                    b--;
//                }
//                else {
//                    a++;
//                }
//            }
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& price, int target) {
//        sort(price.begin(), price.end());
//        int n = price.size();
//        int r = n - 1, l = 0;
//        while (r > l)
//        {
//            if (price[r] + price[l] > target)
//            {
//                r--;
//            }
//            else if (price[r] + price[l] < target)
//            {
//                l++;
//            }
//            else {
//                return { price[l],price[r] };
//            }
//        }
//        return { -1,-1 };
//    }
//};

int main()
{
    Solution s;
    vector<int> a{ 1,0,2,3,0,4 };
    //s.duplicateZeros(a);
	return 0;
}