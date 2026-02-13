#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int myAtoi(string s) {
//        long long ret = 0;
//        int i = 0, n = s.size();
//        //去除前置空格
//        while (i < n)
//        {
//            if (s[i] != ' ')
//                break;
//            i++;
//        }
//        int flag = 1;
//        if (s[i] == '-')
//        {
//            flag = -1;
//            i++;
//        }
//        else if (s[i] == '+') i++;
//        while (i < n)
//        {
//            char ch = s[i];
//            if (ch >= '0' && ch <= '9')
//                ret = ret * 10 + ch - '0';
//            else
//                break;
//            i++;
//            if (ret * flag > INT_MAX)
//                return INT_MAX;
//            else if (ret * flag < INT_MIN)
//                return INT_MIN;
//        }
//
//        return ret * flag;
//    }
//};


class Solution {
public:
    int minDistance(string word1, string word2) {
        // 一定要变为相同长度
        // A插入，B插入，替换
        int n = word1.size(), m = word2.size();
        if (n * m == 0) return n + m;
        int dp[n + 1][m + 1]; // dp[i][j] 表示word1 到 i 位置转换成 word2 到 j 位置需要最少步数
        // 初始化
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int i = 0; i <= m; i++) dp[0][i] = i;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 替换 dp[i-1][j-1]
                // A插入 dp[i][j-1]
                // B插入 dp[i-1][j]
                if (word1[i - 1] != word2[j - 1]) dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
                else dp[i][j] = dp[i - 1][j - 1];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][m];
    }
};

int main()
{
    vector<string> v({ "eat", "tea", "tan", "ate", "nat", "bat" });
    string str("(())(())");
    Solution s;
    s.longestValidParentheses(str);
    return 0;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */