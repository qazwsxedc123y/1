#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string addBinary(string a, string b) {
//        // ģ����ʽ����
//        int i = a.size() - 1, j = b.size() - 1;
//        string ret;
//        int t = 0;
//        while (i >= 0 || j >= 0 || t) // �������� ���ʣһ����λ1
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
//        // �м���������չ
//
//        // һ��Ҫn�Σ�ͳ��
//        int n = s.size();
//        int begin = 0, len = 0;
//        for (int i = 0; i < n; i++)
//        {
//            // ��ͳ������
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
//            // ͳ��ż��
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
//        // ͳһ�Ƚ�
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

int main()
{
    Solution s;
    vector <string> strs({ "flower", "flow", "flight" });
    s.longestCommonPrefix(strs);
    return 0;
}

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        // ͳһ�Ƚ�
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
//        // �����Ƚ�
//        string ret = strs[0];
//        for (int i = 1; i < strs.size(); i++)
//        {
//            ret = longest(ret, strs[i]);
//        }
//        return ret;
//    }
//};