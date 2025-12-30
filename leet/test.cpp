#define  _CRT_SECURE_NO_WARNINGS
//
//class Solution {
//    vector<int> ret;
//public:
//    void dfs(int pos, int num, int n, int k)
//    {
//        if (pos == n)
//        {
//            ret.push_back(num);
//            return;
//        }
//
//        for (int i = 0; i <= 9; i++)
//        {
//            int ans = num % 10;
//            if (i - ans == k || ans - i == k)
//            {
//                dfs(pos + 1, num * 10 + i, n, k);
//            }
//        }
//    }
//    vector<int> numsSameConsecDiff(int n, int k) {
//        // 可以采用dfs
//        for (int i = 1; i <= 9; i++) dfs(1, i, n, k);
//        return ret;
//    }
//};
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> tmp(n + m - 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp[i + j] += ((num1[i] - '0') * (num2[j] - '0'));
            }
        }

        // for(int i = 0; i < tmp.size(); i++) cout << tmp[i];

        // 调整进位
        int cur = 0, array = 0;
        string ret;
        while (cur < n + m - 1)
        {
            tmp[cur] += array;
            ret.push_back(tmp[cur] % 10 + '0');
            array = tmp[cur] / 10;
            cur++;
        }
        if (array != 0)
        {
            ret.push_back(array + '0');
        }

        // 处理前导0
        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
int main()
{
    Solution s;
    string s1 = "123";
    string s2 = "456";
    s.multiply(s1, s2);
    return 0;
}