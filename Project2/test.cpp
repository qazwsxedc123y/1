#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool func(string s, int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] > s[i]) return false;
        }
        return true;
    }
    int func1(string s, int n)
    {
        char ans1 = s[0], ans2 = s[0];
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] < ans1) ans1 = s[i];
            if (s[i] > ans2) ans2 = s[i];
        }
        if (ans2 <= s[n - 1]) return 1;
        else if (ans1 > s[n - 1]) return 3;
        else return 2;
    }
    int func2(string s, int n)
    {
        int ans1 = s[1], ans2 = s[1];
        for (int i = 2; i < n; i++)
        {
            if (s[i] < ans1) ans1 = s[i];
            if (s[i] > ans2) ans2 = s[i];
        }
        if (ans1 >= s[0]) return 1;
        else if (ans2 < s[0]) return 3;
        else return 2;
    }
    int minOperations(string s) {
        int n = s.size();
        if (n == 2 && s[0] > s[1]) return -1;
        if (func(s, n)) return 0;
        int ret = min(func1(s, n), func2(s, n));
        return ret;
    }
};