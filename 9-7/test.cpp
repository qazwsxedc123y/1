#define  _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include <conio.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

//class Solution {
//public:
//    int myAtoi(string s) {
//        long long ret = 0;
//        int index = 0;
//        unsigned long len = s.size();
//        //去除前置空格
//        while (index < len)
//        {
//            if (s[index] != ' ')
//                break;
//            index++;
//        }
//        if (index == len) {
//            return 0;
//        }
//        int sign = 1;
//        if (s[index] == '-')
//        {
//            sign = -sign;
//            index++;
//        }
//        else if (s[index] == '+')
//        {
//            index++;
//        }
//        //开始读取数字
//        while (index < len)
//        {
//            char ch = s[index];
//            if (ch >= '0' && ch <= '9')
//                ret = ret * 10 + ch - '0';
//            else
//                break;
//            index++;
//            if ((ret * sign) > INT_MAX)
//                return INT_MAX;
//            else if ((ret * sign) < INT_MIN)
//                return INT_MIN;
//        }
//        return static_cast<int>(ret * sign);;
//    }
//};
// 
// 
//2147483647
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int sz = score.size();
        vector<string> v;
        v.resize(sz);
        map<int, int> m;//第一个是得分，第二个是顺序
        int i = 1;
        for (auto e : score)
        {
            m[e] = i++;
        }
        i = sz;
        //现在此时为升序,第一个是最后一名，也就是sz
        for (const auto& pair : m) {
            v[pair.second-1] = i--;
        }
        return v;
    }
};
int main()
{
    Solution s; 
    int arr[] = { 5,4,3,2,1 };
    vector<int> v(begin(arr), end(arr));
    s.findRelativeRanks(v);

    return 0;
}




//class Solution {
//public:
//    string convert(string s, int numRows) {
//        int n = s.size(), r = numRows;
//        int count = 0;
//        if (r == 1) {
//            return s;
//        }
//        vector<string> row(numRows);
//        int i = 0, flag = -1;
//        for (char e : s)
//        {
//            row[i].push_back(e);
//            if (i == 0 || i == r - 1)
//            {
//                flag *= -1;
//            }
//            i += flag;
//        }
//        string res;
//        for (auto rows : row)
//            res += rows;
//        return res;
//    }
//};
////class Solution {
////public:
////    string longestPalindrome(string s) {
////        int n = s.size();
////        if (n == 1)
////        {
////            return s;
////        }
////        int maxLen = 1;
////        int begin = 0;
////        vector<vector<bool>> dp(n, vector<bool>(n));
////        for (int i = 0; i < n; i++) {
////            dp[i][i] = true;
////        }
////        for (int i = 2; i <= n; i++)//长度
////        {
////            for (int l = 0; l < n; l++)//起始位置
////            {
////                int r = l + i - 1;
////                if (r >= n)
////                {
////                    break;
////                }
////                if (s[l] != s[r])
////                {
////                    dp[l][r] = false;
////                }
////                else
////                {
////                    if (r - l < 3)
////                        dp[l][r] = true;
////                    else
////                        dp[l][r] = dp[l - 1][r + 1];
////                }
////                if (dp[l][r] && i > maxLen)
////                {
////                    maxLen = i;
////                    begin = l;
////                }
////            }
////        }
////        return s.substr(begin, maxLen);
////    }
////};
//int main()
//{
//    int x = -123;
//    cout << x / 10 << endl;
//    cout << x % 10 << endl;
//
//    //Solution s;
//    //string a("aaaa");
//    //s.longestPalindrome(a);
//    return 0;
//}
//
////class Solution {
////public:
////    int lengthOfLongestSubstring(string s) {
////        unordered_set<char> occ;
////        int n = s.size();
////        if (n == 0)
////        {
////            return 0;
////        }
////        int ret = -1, r = -1;
////        for (int i = 0; i < n; i++)
////        {
////            if (i != 0)
////            {
////                occ.erase(s[i - 1]);
////            }
////            while (r + 1 < n && !occ.count(s[r + 1]))
////            {
////                occ.insert(s[r + 1]);
////                ++r;
////            }
////            ret = max(ret, r - i + 1);
////        }
////        return ret;
////    }
////};