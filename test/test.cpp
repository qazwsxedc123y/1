#define  _CRT_SECURE_NO_WARNINGS


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (words[i].find(x) != string::npos)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            int sz = words[i].size();
            for (int j = 0; j < sz; j++)
            {
                if (words[i][j] == x)
                {
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};