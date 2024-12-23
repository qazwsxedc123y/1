//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//int n, a[114514], p, l;//数组开大一点
//string q;
//#include<iostream>
//using namespace std;
//int main()
//{
//	int ans = 0;
//	for (int i = 1; i <= 5; i++)
//	{
//		char a, b, c, d;
//		cin >> a >> b >> c >> d;
//		if (a == c && d - b == 1) ans++;
//	}
//	cout << ans;
//	return 0;
//}
//void C()//乘法
//{
//	for (int i = 1; i <= l; i++)
//		a[i] *= 2;//按位乘2
//	for (int i = 1; i <= l; i++)//进位
//	{
//		a[i + 1] += a[i] / 10;
//		a[i] %= 10;
//	}
//	if (a[l + 1])//如果最高位的前一位进位后不是0就要增加长度
//		l++;
//}
//int main()
//{
//	cin >> n >> q;//q为输入的小数
//	reverse(q.begin(), q.end());//反转q方便后续做题
//	p = q.find(".");//p用来分割整数、小数部分
//	q.erase(p, 1);//把烦人的小数点删了
//	l = q.size();//l为小数总长
//	for (int i = 0; i < l; i++)
//		a[i + 1] = q[i] - 48;//字符串转整数数组
//	for (int i = 1; i <= n; i++)//n次乘2
//		C();
//	if (a[p] >= 5)//小数部分第一位为5四舍五入进位
//		a[p + 1]++;
//	for (int i = p + 1; i <= l; i++)//检查进位
//	{
//		a[i + 1] += a[i] / 10;
//		a[i] %= 10;
//	}
//	if (a[l + 1])//再次检查最高位
//		l++;
//	for (int i = l; i > p; i--)//因为前面逆序了所以这里倒着输出
//		cout << a[i];
//	return 0;
//}


//#include <iostream>
//#include <string>
//
//using namespace std;
//long long n, t;
//string s;
//int main()
//{
//    cin >> n >> t;
//    cin >> s;
//
//    //超时，需要优化
//    for (int i = 0; i < t; i++)
//    {
//        for (int j = n - 1; j >= 1; j--)
//        {
//            s[j] = (s[j] - '0') ^ (s[j - 1] - '0') + '0';
//        }
//    }
//    cout << s;
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;
long long n, t, x = 1;
string s;
int main()
{
    n = 5, t = 9;
    s = 10110;
    // 2 -> 2
    // 3 -> 4
    // 4 -> 4
    // 5 -> 8
    // 6 -> 8
    // 7 -> 16
    // 分解线 1 3 5 7 9
    //超时，需要优化
    while (n > x) 
        x = x << 1;
    t = t % x;
    for (int i = 0; i < t; i++)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            s[j] = (s[j] - '0') ^ (s[j - 1] - '0') + '0';
        }
    }
    cout << s;
    return 0;
}