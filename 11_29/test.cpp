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

//class Solution {
//public:
//    int numSubarraysWithSum(vector<int>& nums, int goal) {
//        int n = nums.size();
//        int ret = 0;
//        int sum1 = 0, sum2 = 0;
//        for (int left1 = 0, left2 = 0, right = 0; right < n; right++)
//        {
//            // 进窗口
//            sum1 += nums[right];
//            sum2 += nums[right];
//            while (left1 <= right && sum1 >= goal) // 不满足条件
//            {
//                sum1 -= nums[left1++];
//            }
//            while (left2 <= right && sum2 >= goal + 1) // 不满足条件
//            {
//                sum2 -= nums[left2++];
//            }
//            ret += (left1 - left2);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int numberOfSubarrays(vector<int>& nums, int k) {
//        int n = nums.size(), count1 = 0, count2 = 0;
//        int ret = 0;
//        for (int left1 = 0, left2 = 0, right = 0; right < n; right++)
//        {
//            // 进窗口
//            if (nums[right] % 2 == 1)
//            {
//                count1++;
//                count2++;
//            }
//            while (left1 <= right && count1 >= k)// 个数大于等于k个时
//            {
//                if (nums[left1++] % 2 == 1) count1--;
//            }
//            while (left2 <= right && count2 >= k + 1)// 个数大于等于k+1个时
//            {
//                if (nums[left2++] % 2 == 1) count2--;
//            }
//            ret += (left1 - left2);
//        }
//        return ret;
//    }
//};

//class Solution {
//    const string VOWEL = "aeiou";
//
//    long long f(string& word, int k)
//    {
//        long long ans = 0;
//        // 这里用哈希表实现，替换成数组会更快
//        unordered_map<char, int> cnt1; // 每种元音的个数
//        int cnt2 = 0; // 辅音个数
//        int left = 0;
//        for (char b : word)
//        {
//            if (VOWEL.find(b) != string::npos)
//            {
//                cnt1[b]++;
//            }
//            else
//            {
//                cnt2++;
//            }
//            while (cnt1.size() == 5 && cnt2 >= k)
//            {
//                char out = word[left];
//                if (VOWEL.find(out) != string::npos)
//                {
//                    if (--cnt1[out] == 0)
//                    {
//                        cnt1.erase(out);
//                    }
//                }
//                else
//                {
//                    cnt2--;
//                }
//                left++;
//            }
//            ans += left;
//        }
//        return ans;
//    }
//
//public:
//    long long countOfSubstrings(string word, int k) {
//        return f(word, k) - f(word, k + 1);
//    }
//};

int main()
{
    int count1 = 0, count2 = 0;
    if (1) count1++, count2++;
    cout << count1 << "   " << count2 << endl;
    return 0;
}