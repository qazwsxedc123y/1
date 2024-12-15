#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//
//using namespace std;
//class Solution {
//public:
//    int beautifulSplits(vector<int>& nums) {
//        int n = nums.size();
//        int count = 0;
//
//        // 遍历所有可能的分割点
//        for (int i = 1; i < n - 1; i++) {  // nums1 的结束位置，i > 0
//            if (i == 6) int a;
//            for (int j = i + 1; j < n; j++) {  // nums2 的结束位置，j > i
//                // 判断 nums1 是否是 nums2 的前缀
//                // 长度一 i  长度二 j-i 长度三 n-j
//                bool condition1 = true;
//                for (int k = 0; k < i && k < j; k++) {
//                    if (nums[k] != nums[k + i]) {
//                        condition1 = false;
//                        break;
//                    }
//                    else if (j-i < i) {
//                        condition1 = false;
//                        break;
//                    }
//                }
//                // 判断 nums2 是否是 nums3 的前缀
//                bool condition2 = true;
//                for (int k = 0; k + i < j && k + j < n; k++) {
//                    if (nums[k + i] != nums[k + j]) {
//                        condition2 = false;
//                        break;
//                    }
//                    else if (n - j < j - i) {
//                        condition2 = false;
//                        break;
//                    }
//                }
//                if (condition1 || condition2) {
//                    count++;
//                }
//            }
//        }
//
//        return count;
//    }
//};

//int main()
//{
//    Solution s;
//    vector<int> v{ 1,1,0,1,3,2,2,2 };
//    s.beautifulSplits(v);
//    return 0;
//}
//
//long long n, a[200005], ret, t, dp[200005];
//int main()
//{
//    //cin >> n;
//    //t = n;
//    //int i = 0;
//    //while (t--) {
//    //    cin >> a[i++];
//    //}
//    n = 4;
//    a[0] = 1;
//    a[1] = 3;
//    a[2] = 6;
//    a[3] = 9;
//    for (int i = 1; i <= n; i++) {
//        dp[i] = dp[i - 1] + a[i-1];
//    }
//    for (int i = 0; i < n - 1; i++) {
//        t = a[i] * (dp[n] - dp[i+1]);
//        ret += t;
//    }
//    cout << ret;
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;
const int _month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool check_valid(int data)
{
    int year = data / 10000;
    int month = data % 10000 / 100;
    int day = data % 100;
    if (day == 0 || month == 0 || month > 12 || (month != 2 && day > _month[month])) return false;// 不合理
    if (month == 2)
    {
        // 判断是否为闰年，month是否为<=29
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return false;
            }
        }
    }
    return true;
}
bool check_huiwen(string s)
{
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}
bool check_AB(string s)
{
    if (!check_huiwen(s)) return false;
    int n = s.size();
    if (s[0] != s[2] || s[1] != s[3] || s[0] == s[1]) return false;
    return true;
}
int main()
{
    // 20200202
    // 20211202
    // 21211212
    int n;
    cin >> n;
    int falg = 0;
    for (int i = n + 1;; i++)
    {
        if (check_valid(i))// 查看日期是否合法
        {
            string s = to_string(i);// 读取
            if (check_huiwen(s) && !falg)
            {
                cout << i << endl;
                falg = 1;
            }
            if (check_AB(s))
            {
                cout << s << endl;
                return 0;
            }
        }
    }
    return 0;
}