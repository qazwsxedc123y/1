#define  _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <string>
//using namespace std;
//int a, b;
//bool check1(int num)
//{
//    int num1 = 1;
//    while (num > 0)
//    {
//        num -= num1;
//        num1 += 2;
//    }
//    return num == 0;
//}
//bool check2(int num)// 判断是否为拆为两部分还是平方数
//{
//    string s = to_string(num);
//    int n = s.size();
//    for (int i = 1; i <= n - 1; i++)// 结束位置
//    {
//        int x = stoi(s.substr(0, i));
//        int y = stoi(s.substr(i));
//        if (x == 0 || y == 0) continue;
//        if (check1(x) && check1(y))
//        {
//            return true;
//        }
//    }
//    return false;
//}
//int main()
//{
//    a = 169;
//    b = 10000;
//    // 169
//    // 361
//    // 225
//    // 1444
//    // 1681
//    // 3249
//    // 4225
//    // 900
//    // 9025
//    for (int i = a; i <= b; i++)
//    {
//        if (check1(i) && check2(i))
//        {
//            cout << i << endl;
//        }
//    }
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//const int x = 123456;
//int n, k;
//int dp[505][505];
//int mod(int a)
//{
//	return a % x;
//}
//int main()
//{
//	cin >> n >> k;
//	dp[1][0] = 1;
//	for (int i = 2; i < n; i++)
//	{
//		dp[i][0] = 2;
//		for (int j = 0; j <= i; j++)
//		{
//			dp[i + 1][j] += mod(dp[i][j] * (j + 1));
//			dp[i + 1][j + 1] += mod(dp[i][j] * 2);
//			dp[i + 1][j + 2] += mod(dp[i][j] * (i - j - 2));
//		}
//	}
//	cout << dp[n][k - 1] % x;
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;
int p;
string change(int x, int p)
{
	// 将x转换为p进制的数
	string ret;
	int a, b;
	char c;
	while (x)
	{
		a = x / p;
		b = x % p;
		if(b<=9) ret += to_string(b);
		else {
			// b=10 ->A   b-10+'A'
			c = b + 'A' - 10;
			ret += c;
		}
		x = a;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	cin >> p;
	for (int i = 1; i < p; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// i*j=
			cout << change(i, p) << "*" << change(j, p) << "=" << change(j * i, p) << " ";
		}
		cout << endl;
	}
	return 0;
}