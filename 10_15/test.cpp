#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>

using namespace std;


//class Solution {
//public:
//    bool rotateString(string s, string goal) {
//        int n = s.size();
//        int sz = goal.size();
//        if (n != sz)
//        {
//            return false;
//        }
//        goal += goal;
//        if (goal.find(s) != -1)
//            return true;
//        return false;
//    }
//};


//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int n = cost.size();
//        vector<int> dp(n + 1);
//        dp[0] = dp[1] = 0;
//        for (int i = 2; i <= n; i++)
//        {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[n];
//    }
//};
 


//class Solution {
//public:
//    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, int flag)
//    {
//        if (image[sr][sc] != flag) return;
//        image[sr][sc] = color;
//
//        if (sr - 1 >= 0 && sr - 1 < n && sc >= 0 && sc < m)
//            dfs(image, sr - 1, sc, color, n, m, flag);
//        if (sr + 1 >= 0 && sr + 1 < n && sc >= 0 && sc < m)
//            dfs(image, sr + 1, sc, color, n, m, flag);
//        if (sr >= 0 && sr < n && sc - 1 >= 0 && sc - 1 < m)
//            dfs(image, sr, sc - 1, color, n, m, flag);
//        if (sr >= 0 && sr < n && sc + 1 >= 0 && sc + 1 < m)
//            dfs(image, sr, sc + 1, color, n, m, flag);
//
//    }
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//        int n = image.size();
//        int m = image[0].size();
//        int flag = image[sr][sc];
//        if (image[sr][sc] != color)
//        {
//            dfs(image, sr, sc, color, n, m, flag);
//        }
//        return image;
//    }
//};

//class Solution {
//public:
//    double largestSumOfAverages(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<double> prefix(n + 1);
//        for (int i = 0; i < n; i++)
//        {
//            prefix[i + 1] = prefix[i] + nums[i];
//        }
//        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
//         dp[i][j]表示将[0,i]分为j组的最大平均值
//         dp[i][1]=p[i]/i
//        for (int i = 1; i <= n; i++)
//        {
//            dp[i][1] = prefix[i] / i;
//        }
//        for (int j = 2; j <= k; j++)
//        {
//            for (int i = j; i <= n; i++)
//            {
//                for (int x = j - 1; x < i; x++)
//                {
//                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
//                }
//            }
//        }
//        return dp[n][k];
//    }
//};


//class Solution {
//public:
//    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
//        if (plants.empty() || plants.front().empty())
//            return false;
//        int n = plants.size();
//        int m = plants[0].size();
//        //cout<<n<<" "<<m;
//        int i = 0, j = m - 1;
//        while (i < n && j >= 0)
//        {
//            if (plants[i][j] > target)
//            {
//                j--;
//            }
//            else if (plants[i][j] == target)
//                return true;
//            else
//            {
//                i++;
//            }
//        }
//        return false;
//    }
//};
int main()
{

	return 0;
}