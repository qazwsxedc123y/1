#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        // 将A盘的n个，借助B盘，放到C盘
        dfs(A, B, C, A.size());
    }
    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        // 将A盘的n个，借助B盘，放到C盘
        if (n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        // 主要思路，先将A的n-1个移到B上，再将最后一个移到C上
        // 将B上的n-1个移到C上，   
        dfs(A, C, B, n - 1);
        C.push_back(A.back());
        A.pop_back();
        dfs(B, A, C, n - 1);
    }
};
int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}