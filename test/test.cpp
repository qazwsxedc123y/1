#define  _CRT_SECURE_NO_WARNINGS


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m == 0) // ��������
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


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        return dividend / divisor;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        // ʹ��ջ��д
        int maxret = 0;
        stack<int> stk;
        stk.push(-1);
        // Ϊ�˷���( ������
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                // û����֮ƥ���
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    maxret = max(maxret, i - stk.top());
                }
            }
        }
        return maxret;
    }
};