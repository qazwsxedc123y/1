class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        // 创建numrows个，然后拼接到一起
        vector<string> tmp(numRows);
        int ans = 0, dir = 0;// dir - 0向下 - 1向上
        for (int i = 0; i < s.size(); i++)
        {
            tmp[ans].push_back(s[i]);
            if (dir == 0) ans++; a
            else ans--;
            if (ans == numRows)
            {
                dir = 1;
                ans -= 2;
            }
            if (ans == -1)
            {
                dir = 0;
                ans += 2;
            }
        }

        for (int i = 0; i < numRows; i++)
        {
            ret += tmp[i];
        }
        return ret;
    }
};