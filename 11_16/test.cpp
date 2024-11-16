#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>

using namespace std;
//
//class Solution {
//public:
//    vector<string> findRepeatedDnaSequences(string s) {
//        unordered_map<string, int> hash;
//        vector<string> ret;
//        int n = s.size();
//        if (n < 10) return ret;
//        for (int i = 0; i < n - 10 + 1; i++)
//        {
//            string tmp = s.substr(i, 10);
//            hash[tmp]++;
//            if (hash[tmp] == 2)
//            {
//                ret.push_back(tmp);
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//    const int L = 10;
//    unordered_map<char, int> bin = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
//public:
//    vector<string> findRepeatedDnaSequences(string s) {
//        int n = s.size();
//        vector<string> ans;
//        if (n <= 10) return ans;
//        int x = 0;
//        for (int i = 0; i < 9; i++) x = (x << 2) | bin[s[i]];
//        unordered_map<int, int> mp;
//        for (int i = 0; i <= n - L; i++)
//        {
//            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << 20) - 1);
//            if (++mp[x] == 2) ans.push_back(s.substr(i, L));
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int> ans;
//        int n = nums.size();
//        priority_queue<pair<int,int>> q;
//        for (int i = 0; i < k - 1; i++)
//        {
//            q.emplace(make_pair(nums[i],i));
//        }
//        for (int i = k - 1; i < n; i++)
//        {
//            q.emplace(make_pair(nums[i], i));
//            ans.push_back(q.top().first);
//            while (q.top().second <= i - k)
//            {
//                q.pop();
//            }
//        }
//        return ans;
//    }
//};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++)
        {
            q.emplace(make_pair(nums[i], i));
        }
        vector<int> ans{ q.top().first };
        for (int i = k; i < n; i++)
        {
            q.emplace(make_pair(nums[i], i));
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v1{ 1,3,-1,-3,5,3,6,7 };
    vector<int> v2{ 1,-1 };
    s.maxSlidingWindow(v2, 1);
    return 0;
}