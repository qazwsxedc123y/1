#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;


//class Solution {
//    int dp[100010] = { 0 };// dp[i] ��ʾ��dp[i]Ϊ��β����Ϊi��������
//    int pos = 0;
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ��������ϸ����������еĳ���
//     * @param a int����vector ����������
//     * @return int����
//     */
//    int LIS(vector<int>& a) {
//        // write code here
//        int n = a.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (pos == 0 || a[i] > dp[pos])
//            {
//                dp[++pos] = a[i];
//            }
//            else
//            {
//                // ���ֲ��Ҳ���ĺ���λ��
//                int l = 1, r = pos;
//                while (l < r)
//                {
//                    int mid = (l + r) / 2;
//                    if (dp[mid] >= a[i]) r = mid;
//                    else l = mid + 1;
//                }
//                dp[l] = a[i];
//            }
//        }
//        return pos;
//    }
//};



//const int N = 1010;
//int dp[N][N] = { 0 };
//int n, m;
//string s1, s2;
//int main() {
//    cin >> n >> m >> s1 >> s2;
//    s1 = ' ' + s1;
//    s2 = ' ' + s2;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
//            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//        }
//    }
//
//    cout << dp[n][m] << endl;
//}
//// 64 λ������� printf("%lld")




//#include <iostream>

//int sum = 0;
//const int N = 20, M = N * 9;
//int n;
//string s;
//bool fun()
//{
//    bool dp[M];
//    memset(dp, false, sizeof(dp)); // ��ʼ��Ϊ false
//    dp[0] = true;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = sum; j >= (s[i] - '0'); j--)
//        {
//            dp[j] = dp[j] || dp[j - (s[i] - '0')];
//        }
//    }
//    return dp[sum];
//}
//int main() {
//
//    cin >> s;
//    n = s.size();
//    for (int i = 0; i < n; i++) sum += s[i] - '0';
//
//    if (sum % 2 != 0) cout << "No" << endl;
//
//    else
//    {
//        sum /= 2;
//        if (fun()) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}
//// 64 λ������� printf("%lld")



//int main() {
//    int n;
//    while (cin >> n)
//    {
//        int ret = 1;
//        while (ret - 1 <= n) ret *= 2;
//        cout << ret / 2 - 1 << endl;
//    }
//}
//// 64 λ������� printf("%lld")




//const int N = 1010;
//int dp[N][N]; // dp[i][j]��ʾ s1 ��[0, i]������ s2 ��[0, j]������С�ı������
//string s1, s2;
//int main() {
//    cin >> s1 >> s2;
//    s1 = ' ' + s1;
//    s2 = ' ' + s2;
//    int n1 = s1.size(), n2 = s2.size();
//    // ��ʼ��a
//    for (int i = 0; i < n1; i++) dp[i][0] = i;
//    for (int j = 0; j < n2; j++) dp[0][j] = j;
//
//    for (int i = 1; i <= n1; i++)
//    {
//        for (int j = 1; j <= n2; j++)
//        {
//            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
//
//            else
//            {
//                dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
//            }
//        }
//    }
//
//    cout << dp[n1][n2] << endl;
//}
//// 64 λ������� printf("%lld")