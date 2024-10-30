#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


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
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> ret;
//        for (int first = 0; first < n; first++)
//        {
//            if (first > 0 && nums[first] == nums[first - 1])
//            {
//                continue;
//            }
//            for (int second = first + 1; second < n; second++)
//            {
//                if (second > first + 1 && nums[second] == nums[second - 1])
//                {
//                    continue;
//                }
//                int fourth = n - 1;
//                int ans = target - nums[first] - nums[second];
//                for (int third = second + 1; third < n; third++)
//                {
//                    if (third > second + 1 && nums[third] == nums[third - 1])
//                    {
//                        continue;
//                    }
//                    while (fourth > third && nums[third] + nums[fourth] > ans)
//                    {
//                        fourth--;
//                    }
//                    if (third >= fourth) break;
//                    if (nums[third] + nums[fourth] == ans)
//                    {
//                        ret.push_back({ nums[first],nums[second],nums[third],nums[fourth] });
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//};

//
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> ret;
//        for (int first = 0; first < n; first++)
//        {
//            if (first > 0 && nums[first] == nums[first - 1])
//            {
//                continue;
//            }
//            for (int second = first + 1; second < n; second++)
//            {
//                if (second > first + 1 && nums[second] == nums[second - 1])
//                {
//                    continue;
//                }
//                int fourth = n - 1;
//                int third = second + 1;
//                long long ans = (long long)target - nums[first] - nums[second];
//                while (third < fourth)
//                {
//                    if (nums[third] + nums[fourth] > ans)
//                    {
//                        fourth--;
//                    }
//                    else if (nums[third] + nums[fourth] < ans)
//                    {
//                        third++;
//                    }
//                    else
//                    {
//                        ret.push_back({ nums[first],nums[second],nums[third],nums[fourth] });
//                        third++, fourth--;
//                        while (third < fourth && nums[third] == nums[third - 1]) third++;
//                        while (third < fourth && nums[fourth] == nums[fourth - 1]) fourth--;
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//};

class Solution {
public:
    bool isodd_or_even(int t)// Å¼·µ»Øtrue Ææ·µ»Øfalse
    {
        int r = t - '0';
        return r % 2 == 0;
    }
    string getSmallestString(string s) {
        int cur = 0, dest = 1;
        int n = s.size();
        while (dest < n)
        {
            if (isodd_or_even(s[cur]) == isodd_or_even(s[dest]))
            {
                if (s[cur] > s[dest])
                {
                    swap(s[cur], s[dest]);
                    break;
                }
            }
            cur++, dest++;
        }
        return s;
    }
};
int main()
{
    Solution s;
    vector<int> a{ -1,0,-5,-2,-2,-4,0,1,-2 };
    string b{ "45320"};
    //s.fourSum(a, -9);
    s.getSmallestString(b);
	return 0;
}