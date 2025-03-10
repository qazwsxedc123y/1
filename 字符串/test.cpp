#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string addBinary(string a, string b) {
//        // 模拟竖式运算
//        int i = a.size() - 1, j = b.size() - 1;
//        string ret;
//        int t = 0;
//        while (i >= 0 || j >= 0 || t) // 考虑特殊 最后还剩一个进位1
//        {
//            if (i >= 0) t = t + a[i--] - '0';
//            if (j >= 0) t = t + b[j--] - '0';
//            ret += t % 2 + '0';
//            t /= 2;
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};


//class Solution {
//public:
//    string longestPalindrome(string s) {
//        // 中间向两边扩展
//
//        // 一共要n次，统计
//        int n = s.size();
//        int begin = 0, len = 0;
//        for (int i = 0; i < n; i++)
//        {
//            // 先统计奇数
//            int left = i, right = i;
//            while (left >= 0 && right < n && s[left] == s[right])
//            {
//                left--;
//                right++;
//            }
//            if (right - left - 1 > len)
//            {
//                begin = left + 1;
//                len = right - left - 1;
//            }
//
//            // 统计偶数
//            left = i, right = i + 1;
//            while (left >= 0 && right < n && s[left] == s[right])
//            {
//                left--;
//                right++;
//            }
//            if (right - left - 1 > len)
//            {
//                begin = left + 1;
//                len = right - left - 1;
//            }
//        }
//        return s.substr(begin, len);
//    }
//};


//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        // 统一比较
//        int n = strs.size();
//        int sz = strs[0].size();
//        for (int i = 0; i < sz; i++)
//        {
//            char tmp = strs[0][i];
//            for (int j = 1; j < n; j++)
//            {
//                if (i == strs[j].size() || tmp != strs[j][i])
//                {
//                    return strs[0].substr(0, i);
//                }
//            }
//        }
//        return strs[0];
//    }
//};

//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        // 不进位相乘
//
//        int n1 = num1.size() - 1, n2 = num2.size() - 1;
//        int arr[n1 + n2 + 1];
//        for (int i = 0; i <= n2; i++) // 下
//        {
//            for (int j = 0; j <= n1; j++) // 上
//            {
//                int t = i + j;
//                int sum = 1;
//                sum *= num1[n1 - i];
//                sum *= num2[n2 - j];
//                arr[t] += sum;
//            }
//        }
//    }
//};

//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        // 无进位相乘
//        int m = num1.size(), n = num2.size();
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//
//        vector<int> tmp(n + m - 1);
//
//        // 先无进位相乘
//        for (int i = 0; i < m; i++)
//            for (int j = 0; j < n; j++)
//                tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');
//
//        // 处理进位
//        int cur = 0, t = 0;
//        string ret;
//        while (cur < n + m - 1 || t)
//        {
//            if (cur < n + m - 1) t += tmp[cur++];
//            ret += t % 10 + '0';
//            t /= 10;
//        }
//
//        // 处理前导零 
//        // 0*任何数
//        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};

int main()
{
    Solution s;
    return 0;
}

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        // 统一比较
//        int n = strs.size();
//        int i = 0;
//        int sz = strs[0].size();
//        for (; i < sz; i++)
//        {
//            char tmp = strs[0][i];
//            for (int j = 1; j < n; j++)
//            {
//                if (i == strs[j].size() || tmp != strs[i][j])
//                {
//                    return strs[0].substr(0, i);
//                }
//            }
//        }
//        return strs[0];
//    }
//};


//class Solution {
//public:
//    string longest(string l1, string l2)
//    {
//        int sz1 = l1.size();
//        int sz2 = l2.size();
//        int i = 0, j = 0;
//        while (i < sz1 && j < sz2)
//        {
//            if (l1[i] != l2[j]) break;
//            i++, j++;
//        }
//        return l1.substr(0, i);
//    }
//    string longestCommonPrefix(vector<string>& strs) {
//        // 挨个比较
//        string ret = strs[0];
//        for (int i = 1; i < strs.size(); i++)
//        {
//            ret = longest(ret, strs[i]);
//        }
//        return ret;
//    }
//};