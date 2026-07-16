#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while (n)
    {
        int t = n % 10;
        n /= 10;
        s.push_back(t + '0');
    }
    reverse(s.begin(), s.end());
    string ret;
    int sz = s.size();
    int ans = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        if (ans == 3)
        {
            ret.push_back(',');
            ans = 0;
        }
        ret.push_back(s[i]);
        ans++;
    }
    reverse(ret.begin(), ret.end());
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 1, b = 2;
    if (n == 1)
    {
        cout << a << endl;
    }
    else if (n == 2)
    {
        cout << b << endl;
    }
    else
    {
        int c = 3;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c << endl;
    }

}
// 64 位输出请用 printf("%lld")

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */
    bool IsContinuous(vector<int>& numbers) {
        // write code here
        sort(numbers.begin(), numbers.end());
        // 先统计有几个0
        int ans = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0) ans++;
        }
        int t = numbers[ans];
        for (int i = ans + 1; i < numbers.size(); i++)
        {
            int a = abs(t - numbers[i]);
            if (a != 1 && ans >= a - 1 && a != 0)
            {
                cout << ans << endl;
                ans -= a - 1;
            }
            else if (a != 1 || a == 0) return false;
            t = numbers[i];
        }
        return true;
    }
};