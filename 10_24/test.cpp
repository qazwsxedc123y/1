#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include<iostream>
#include<cmath>  // 引入头文件
#include<algorithm >  // 引入 sort 函数

using namespace std;


//class Solution {
//public:
//    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
//        int n = s.size();
//        string ret;
//        int h = 0;   // 子串哈希值
//        long long p = 1;  // power^right % modulo
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            // 进窗口
//            h = (h + (s[right] - 'a' + 1) * p) % modulo;
//            if (right - left + 1 >= k)
//            {
//                if (h == hashValue)
//                {
//                    ret = s.substr(left, k);
//                }
//                // 出
//                if (h == 0) h = modulo;
//                h = (h - (s[left++] - 'a' + 1) + modulo) % modulo;
//                p = (p * power) % modulo;  // 更新 power^right % modulo
//            }
//            p = (p * power) % modulo;  // Update p for next iteration
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int divisorSubstrings(int num, int k) {
//        vector<int> v; //存放num这个数串每个位的值
//        int n;  //代表数串每个位数的值
//        int num1 = num; //将num赋给num1
//        int res = 0;//美丽值-返回的结果
//        while (num1 != 0) {//从个位 十位 百位...依次压入v容器中
//            n = num1 % 10;//余数
//            num1 = num1 / 10;//自除更新num1
//            v.push_back(n);
//        }
//        reverse(v.begin(), v.end());//逆序v容器的元素
//        int left = 0;//左边界
//        int right = k - 1;//右边界 //0到k-1正好k个数
//        for (left, right; right < v.size(); right++, left++) {//滑动窗口方式模拟验证
//            int tmp = v[left];//初始化tmp  滑动窗口左边界代表 窗口内数串的最高位
//            for (int i = left + 1; i <= right; i++) {
//                tmp = tmp * 10 + v[i]; //模拟滑动窗口中元素组成一个数
//            }
//            if (tmp == 0)//如果为0，直接下一次循环
//                continue;
//            if (num % tmp == 0) {//如果可整除，美丽值结果+1
//                res++;
//            }
//        }
//        return res;//返回结果
//    }
//};

//class Solution {
//public:
//    int minimumDifference(vector<int>& nums, int k) {
//        int ret = INT_MAX;
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            if (right - left + 1 == k)
//            {
//                ret = min(ret, (nums[right] - nums[left++]));
//            }
//        }
//        return ret;
//    }
//};

int main()
{
    Solution s;
    string s1{ "leetcode" };
    s.divisorSubstrings(240, 2);
    return 0;
}