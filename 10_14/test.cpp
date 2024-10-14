#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<set>
#include <sstream>  

using namespace std;



//class Solution {
//public:
//    string mostCommonWord(string paragraph, vector<string>& banned) {
//        unordered_set<string> bannedSet;
//        for (auto& word : banned) {
//            bannedSet.emplace(word);
//        }
//        int n = paragraph.size();
//        cout << n;
//        int m = banned.size();
//        map<string, int> frequencies;
//        string tmp;
//        int maxFrequency = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            if (i < n && isalpha(paragraph[i]))
//            {
//                tmp += tolower(paragraph[i]);
//            }
//            else if (tmp.size() > 0)
//            {
//
//                if (!bannedSet.count(tmp))
//                {
//                    frequencies[tmp]++;
//                    maxFrequency = max(maxFrequency, frequencies[tmp]);
//                    cout << maxFrequency << " ";
//                }
//                tmp = "";
//            }
//        }
//        string ret = "";;
//        for (auto& [word, frequency] : frequencies)
//        {
//            if (frequency == maxFrequency)
//            {
//                cout << word << " ";
//                ret = word;
//                break;
//            }
//        }
//        return ret;
//    }
//};


//int main()
//{
//	char ch[] = "hit";
//	string banned(begin(ch), end(ch));
//	string s{ "Bob hit a ball, the hit BALL flew far after it was hit." };
//	unordered_set<string> bannedSet;
//	for (auto& word : banned) 
//	{
//		bannedSet.emplace(word);
//	}
//	return 0;
//}




//class Solution {
//public:
//    // 看的题解写出来的
//    int superEggDrop(int k, int n) {
//        if (n == 1)
//            return 1;
//        vector<vector<int>> f(n + 1, vector<int>(k + 1));
//        for (int i = 1; i <= k; i++)
//        {
//            f[1][i] = 1;
//        }
//        int ans = 0;
//        for (int i = 2; i <= n; i++)
//        {
//            for (int j = 1; j <= k; j++)
//            {
//                f[i][j] = 1 + f[i - 1][j] + f[i - 1][j - 1];
//            }
//            if (f[i][k] >= n)
//            {
//                ans = i;
//                break;
//            }
//        }
//        return ans;
//    }
//};