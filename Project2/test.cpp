#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int func(int n)
    {
        int ret = 0;
        while (n)
        {
            if (n % 2) ret++;
            n /= 2;
        }
        return ret;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (func(h) + func(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};