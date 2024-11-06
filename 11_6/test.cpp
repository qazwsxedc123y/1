#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int ret = 0;
//        int n = fruits.size();
//        unordered_map<int, int> mp;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            //进窗口
//            mp[fruits[right]]++;
//            count++;
//            //判断 出窗口
//            while (mp.size() > 2)
//            {
//                mp[fruits[left]]--;
//                if (mp[fruits[left]] == 0)
//                {
//                    mp.erase(fruits[left]);
//                }
//                count--;
//            }
//            ret = max(ret, count);
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> v;
//        int len = words[0].size();
//        int n = s.size();
//        int m = words.size();
//
//        if (n < len * m) return v; // 长度不够的情况
//
//        unordered_map<string, int> hash1; // 记录每个单词出现的次数
//        for (const auto& word : words) hash1[word]++;
//
//        // 外层循环：从 0 到 len-1，每次从不同位置开始
//        for (int i = 0; i < len; i++)
//        {
//            unordered_map<string, int> hash2; // 记录当前窗口中单词出现的次数
//            int left = i, right = i, count = 0;
//
//            while (right + len <= n)
//            {
//                // 进窗口
//                string in = s.substr(right, len);
//                right += len;
//
//                if (hash1.find(in) != hash1.end())
//                {
//                    hash2[in]++;
//                    if (hash2[in] <= hash1[in])
//                    {
//                        count++;
//                    }
//                }
//
//                // 判断出窗口，收缩窗口
//                while (right - left > len * m)
//                {
//                    string out = s.substr(left, len);
//                    left += len;
//
//                    if (hash1.find(out) != hash1.end())
//                    {
//                        if (hash2[out] <= hash1[out])
//                        {
//                            count--;
//                        }
//                        hash2[out]--; // 直接减少，不调用 erase
//                    }
//                }
//
//                // 如果窗口内包含了所有单词
//                if (count == m)
//                {
//                    v.push_back(left);
//                }
//            }
//        }
//        return v;
//    }
//};

//
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> v;
//        int len = words[0].size();
//        int n = s.size();
//        int m = words.size();
//        unordered_map<string, int> hash1;
//        for (auto& word : words) hash1[word]++;
//        for (int i = 0; i < len; i++)
//        {
//            unordered_map<string, int> hash2;
//            for (int left = i, right = i, count = 0; right < n; right += len)
//            {
//                // 进窗口
//                string in = s.substr(right, len);
//                hash2[in]++;
//                if (hash2[in] <= hash1[in]) count++;
//                //判断出
//                if (right - left + 1 > len * m)
//                {
//                    string out = s.substr(left, len);
//                    if (hash2[out] <= hash1[out]) count--;
//                    hash2[out]--;
//                    if (hash2[out] == 0)
//                    {
//                        hash2.erase(out);
//                    }
//                    left += len;
//                }
//                if (count == m)
//                {
//                    v.push_back(left);
//                }
//            }
//        }
//        return v;
//    }
//};

int main()
{
    Solution s;
    vector<int> v{ 3,3,3,1,2,1,1,2,3,3,4 };
    string s1{ "barfoothefoobarman" };
    vector<string> s2{ "foo","bar" };
    s.findSubstring(s1, s2);
    return 0;
}