#define  _CRT_SECURE_NO_WARNINGS


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m == 0) // ¿ÉÒÔÕû³ý
            {
                ret -= i;
            }
            else
            {
                ret += i;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        int ret = n * (n + 1) / 2 - k * (k + 1) * m;
        return ret;
    }
};

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }
};