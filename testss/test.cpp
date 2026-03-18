#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Solution {
public:
    string addBinary(string a, string b) {
        // 模拟
        int n1 = a.size(), n2 = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(n1, n2);
        int carry = 0;
        string ret;
        for (int i = 0; i < n; i++)
        {
            int t1 = (i < n1) ? a[i] - '0' : 0;
            int t2 = (i < n2) ? b[i] - '0' : 0;
            int sum = t1 + t2 + carry;
            carry = sum / 2;
            sum %= 2;
            ret.push_back(sum + '0');
        }
        if (carry) ret.push_back(carry + '0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        // 直接使用动态规划
        // 优化，使用一个数组
        int n = nums.size();
        int f[n + 1]; // f[i] 表示第i个屋子抢劫时的最大金额
        f[0] = 0, f[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
        }
        return f[n];
    }
};
int main()
{
	cout << (int)'6' << endl;
	return 0;
}