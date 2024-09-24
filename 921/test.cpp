#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        sort(begin(jewels), end(jewels));
        sort(begin(stones), end(stones));
        int n1 = jewels.size();
        int n2 = stones.size();
        int p1 = 0;
        int ans = 0;
        for (int i = 0; i < n2 && p1<n1 ; i++)
        {
            if (stones[i] == jewels[p1])
            {
                ans++;
            }
            else if(stones[i] > jewels[p1])
            {
                i--;
                p1++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string s1{ "aA" };
    string s2{ "aAAbbbb" };
    s.numJewelsInStones(s1, s2);
    return 0;
}

//class Solution {
//public:
//    int dominantIndex(vector<int>& nums) {
//        map<int, int> mp;
//        int n = nums.size();
//        for (int i = 0; i < n; i++)
//        {
//            mp[nums[i]] = i;
//        }
//        auto it = mp.end();
//        --it;
//        int last = it->first;
//        --it;
//        int last_2 = it->first;
//        cout << last << " " << last_2;
//        mp[last] = 5;
//        if (last_2 * 2 <= last)
//            return mp[last];
//
//        return -1;
//    }
//};



//class Solution {
//public:
//    vector<int> selfDividingNumbers(int left, int right) {
//        vector<int> v;
//        for (int i = left; i <= right; i++)
//        {
//            int tmp = i;
//            if (tmp < 10)
//            {
//                v.push_back(i);
//            }
//            else if (tmp > 10)
//            {
//                while (tmp)
//                {
//                    int a = tmp % 10;
//                    if (a == 0 || i % a != 0)
//                    {
//                        break;
//                    }
//                    tmp /= 10;
//                }
//                if (tmp == 0)
//                    v.push_back(i);
//            }
//
//        }
//        return v;
//
//    }
//};



//class Solution {
//public:
//    int calPoints(vector<string>& ops) {
//        int ret = 0;
//        vector<int> points;
//        for (auto& op : ops) {
//            int n = points.size();
//            switch (op[0]) {
//            case '+':
//                ret += points[n - 1] + points[n - 2];
//                points.push_back(points[n - 1] + points[n - 2]);
//                break;
//            case 'D':
//                ret += 2 * points[n - 1];
//                points.push_back(2 * points[n - 1]);
//                break;
//            case 'C':
//                ret -= points[n - 1];
//                points.pop_back();
//                break;
//            default:
//                ret += stoi(op);
//                points.push_back(stoi(op));
//                break;
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    bool validPart(string s, int l, int r)
//    {
//        while (l <= r)
//        {
//            if (s[l] == s[r])
//            {
//                ++l;
//                --r;
//            }
//            else
//                return false;
//        }
//        return true;
//    }
//    bool validPalindrome(string s) {
//        int r = s.size() - 1;
//        int l = 0;
//        while (l <= r)
//        {
//            if (s[l] == s[r])
//            {
//                ++l;
//                --r;
//            }
//            else
//            {
//                return validPart(s, l + 1, r) || validPart(s, l, r - 1);
//            }
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    bool validPalindrome(string s) {
//        bool falg = true;
//        int r = s.size() - 2;
//        int l = 0;
//        while (l < r)
//        {
//            if (s[l] == s[r])
//            {
//                ++l;
//                --r;
//            }
//            else
//            {
//                if (falg)//没有删除过
//                {
//                    if (s[l + 1] == s[r])
//                    {
//                        ++l;
//                    }
//                    else if (s[l] == s[r - 1])
//                    {
//                        --r;
//                    }
//                    else
//                    {
//                        return false;
//                    }
//                    falg = false;//修改为删除过
//                }
//                else
//                    return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    Solution s;
//    char ch1[] = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
//    char ch2[] = "cupxpucu";
//    //char ch2[] = "cupxpuc";
//    string s1(begin(ch1),end(ch2));
//    string s2(begin(ch2),end(ch2));
//    int sz = s1.size();
//    s.validPalindrome(s1);
//    s.validPalindrome(s2);
//	//aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga
//	return 0;
//}