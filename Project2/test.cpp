#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, vector<int>> str;
        int n = pattern.size();
        for (int i = 0; i < n; i++)
        {
            str[pattern[i]].push_back(i);
        }
        // ²ð·Ös
        vector<string> words;
        for (int i = 0; i < s.size(); i++)
        {
            string t;
            while (i < s.size() && s[i] != ' ')
            {
                t += s[i++];
            }
            words.push_back(t);
            // cout << t << endl;
        }
        int m = words.size();
        if (n != m) return false;
        unordered_set<string> used;
        for (auto& [c, pos] : str)
        {
            string t = words[pos[0]];
            for (int i : pos) if (words[i] != t) return false;
            if (used.find(t) != used.end()) return false;
            used.insert(t);
        }
        return true;
    }
};