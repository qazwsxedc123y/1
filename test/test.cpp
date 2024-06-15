#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        vector<int> v;
        while (num)
        {
            if (num % 2 == 1)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
            num /= 2;
        }
        int ret = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ret = ret * 2 + v[i];
        }
        return ret;
    }
};
int main()
{
    double s = 2.2;
    const int& t = s;
    double& r = s;
	return 0;
}