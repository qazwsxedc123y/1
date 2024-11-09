#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;


template<class T>
T Add(const T& x, const T& y)
{
	return x + y;
}



#include<iostream>
using namespace std;

template<class T>
T Add(const T& x, const T& y);
int main()
{
	cout << Add(2, 3) << endl;
	return 0;
}




//class Solution {
//public:
//    string minWindow(string s, string t) {
//        int n = s.size();
//        int hash1[128] = { 0 };
//        int kinds = 0;
//        for (auto& e : t)
//        {
//            if (hash1[e] == 0)
//            {
//                kinds++;
//            }
//            hash1[e]++;
//        }
//        int mi = INT_MAX;
//        int hash2[128] = { 0 };
//        int begin = 0;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            char in = s[right];
//            if (++hash2[in] == hash1[in]) count++;
//            while (count == kinds)
//            {
//                if (right - left + 1 < mi)
//                {
//                    mi = right - left + 1;
//                    begin = left;
//                }
//                char ou = s[left];
//                if (hash2[ou] == hash1[ou]) count--;
//                hash2[ou]--;
//                left++;
//            }
//        }
//        if (begin == -1) return "";
//        else return s.substr(begin, mi);
//    }
//};
//
//int main()
//{
//    Solution s;
//    string s1{ "a" };
//    string s2{ "aa" };
//    s.minWindow(s1, s2);
//    return 0;
//}