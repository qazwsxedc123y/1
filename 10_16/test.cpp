#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.empty() || bills[0] != 5) {
            return false;
        }
        map<int, int> mp;
        if (bills[0] != 5)
        {
            return false;
        }
        int n = bills.size();
        mp[bills[0]]++;
        for (int i = 1; i < n; i++)
        {
            mp[bills[i]]++;
            int give = bills[i] - 5;
            if (give != 0)
            {
                if (give == 5)
                {
                    if (mp[5] > 0)
                    {
                        mp[give]--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (give == 15)
                {
                    if (mp[5] > 0 && mp[10] > 0)
                    {
                        mp[5]--;
                        mp[10]--;
                    }
                    else if (mp[5] >= 3)
                    {
                        mp[5] -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v{ 5,5,10,10,20 };
    s.lemonadeChange(v);
	return 0;
}

//class Solution {
//public:
//    bool fcc(string s, string goal)
//    {
//        vector<int> count(26);
//        for (int i = 0; i < s.size(); i++)
//        {
//            count[s[i] - 'a']++;
//            if (count[s[i] - 'a'] > 1)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//    bool buddyStrings(string s, string goal) {
//        int n = s.size();
//        int m = goal.size();
//        if (n != m) return false;
//        int count = 0;
//        string ret;
//        for (int i = 0; i < n; i++)
//        {
//            if (s[i] != goal[i])
//            {
//                count++;
//                ret.push_back(s[i]);
//                ret.push_back(goal[i]);
//            }
//        }
//        bool f = fcc(s, goal);
//        return (count == 2 && ret[0] == ret[3] && ret[1] == ret[2]) || (count == 0 && f);
//    }
//};

//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        return build(s) == build(t);
//    }
//    string build(string s)
//    {
//        string ret;
//        for (auto& e : s)
//        {
//            if (e != '#')
//            {
//                ret.push_back(e);
//            }
//            else if (!ret.empty())
//            {
//                ret.pop_back();
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
//        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
//            return false;
//        }
//        return !(rec1[2] <= rec2[0] ||   // left
//            rec1[3] <= rec2[1] ||   // bottom
//            rec1[0] >= rec2[2] ||   // right
//            rec1[1] >= rec2[3]);    // top
//
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//        int n = image.size();
//        for (int i = 0; i < n; i++)
//        {
//            int left = 0, right = n - 1;
//            while (left < right)
//            {
//                swap(image[i][left], image[i][right]);
//                image[i][left] ^= 1;
//                image[i][right] ^= 1;
//                left++;
//                right--;
//            }
//            if (left == right)
//            {
//                image[i][left] ^= 1;
//            }
//        }
//        return image;
//    }
//};


//class Solution {
//public:
//    vector<vector<int>> largeGroupPositions(string s) {
//        int n = s.size();
//        vector<vector<int>> ans;
//        int i = 0;
//        while (i < n)
//        {
//            int begin = i;
//            char flag = s[begin];
//            int end = begin;
//            while (i < n && s[i] == flag)
//            {
//                end++;
//                i++;
//            }
//            if (end - begin >= 3)
//            {
//                ans.push_back({ begin,end - 1 });
//            }
//
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<int> shortestToChar(string s, char c) {
//        vector<int> v;
//        vector<int> ans;
//        int n = s.size();
//        for (int i = 0; i < n; i++)
//        {
//            if (s[i] == c)
//            {
//                v.push_back(i);
//            }
//        }
//        int p = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (s[i] != c && p < v.size())
//            {
//                if (p > 0)
//                    ans.push_back(min(v[p] - i, i - v[p - 1]));
//                else
//                    ans.push_back(v[p] - i);
//            }
//            else
//            {
//                if (s[i] == c)
//                {
//                    ans.push_back(0);
//                    p++;
//                }
//                else
//                {
//                    ans.push_back(i - v[p - 1]);
//                }
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    string toGoatLatin(string sentence) {
//        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
//
//        int n = sentence.size();
//        int i = 0, cnt = 1;
//        string ans;
//        while (i < n)
//        {
//            int j = i;
//            while (j < n && sentence[j] != ' ')
//            {
//                j++;
//            }
//            cnt++;
//            if (cnt != 2)
//            {
//                ans += ' ';
//            }
//            if (vowels.count(sentence[i]))
//            {
//                ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
//            }
//            else
//            {
//                ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(cnt, 'a');
//            }
//            i = j + 1;
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    double minimumAverage(vector<int>& nums) {
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        double _min = nums[n - 1];
//        for (int i = 0; i < n / 2; i++)
//        {
//            double average = (nums[i] + nums[n - i - 1]) / 2.0;
//            _min = min(_min, average);
//        }
//        return _min;
//    }
//};