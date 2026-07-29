#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, h, b, k;
    cin >> a >> h >> b >> k;
    long long ret = 0;
    while (h > 0 && k > 0)
    {
        int ans = 1e9 + 10;
        ans = min(ans, min(h / b, k / a));
        if (ans == 0) ans = 1;
        ret += a * ans;
        ret += b * ans;
        h -= b * ans;
        k -= a * ans;
    }
    if (h <= 0 && k > 0) ret += 10 * b;
    else if (h > 0 && k <= 0) ret += 10 * a;
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")


#include <climits>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
int main() {
    int n;
    long long dp[N], a[N];
    cin >> n;
    dp[0] = 0;
    long long ret = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];
        ret = max(ret, dp[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            ret = max(ret, dp[i] - dp[j]);
        }
    }
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ret = 0;
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            ret = n;
            break;
        }
        else if (s[l + 1] != s[r] || s[l] != s[r + 1])
        {
            ret = n - 1;
            break;
        }
        l++;
        r--;
    }
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ret = 0;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1]) ret = n;
    }
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")
