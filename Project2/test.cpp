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
    int minOperations(string s) {
        int n = s.size();
        if (n == 2 && s[0] > s[1]) return -1;
        char ans1 = s[0], ans2 = s[0];
        for (int i = 0; i < n; i++)
        {
            if (s[i] < ans1) ans1 = s[i];
            if (s[i] > ans2) ans2 = s[i];
        }
        if (func(s, n)) return 0;
        if (ans2 == s[n - 1] || s[0] == ans1) return 1;
        // if((ans1 != s[n - 1] && ans1 != s[0]) || (ans2 != s[n - 1] && ans2 != s[0])) return 2; // jgg
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == ans1 || s[i] == ans2) return 2;
        }
        return 3;
    }
};