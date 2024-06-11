#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    bool iswin1(int n)//1ря╬╜дцмЙ
    {
        if (n <= 0)
        {
            return true;
        }
        if (n - 1 <= 0 || n - 2 <= 0 || n - 3 <= 0)
        {
            return false;
        }
        return iswin2(n - 1) || iswin2(n - 2) || iswin2(n - 3);
    }

    bool iswin2(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n - 1 <= 0 || n - 2 <= 0 || n - 3 <= 0)
        {
            return true;
        }
        return iswin1(n - 1) || iswin1(n - 2) || iswin1(n - 3);
    }
    bool canWinNim(int n)
    {
        return iswin1(n - 1) || iswin1(n - 2) || iswin1(n - 3);
    }
};
int main()
{
    Solution a;
    cout << a.canWinNim(4) << endl;
	return 0;
}