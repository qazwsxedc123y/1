#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        // 可以采用dfs遍历的方法
        dfs(0, -101, nums);
        return ret;
    }
    void dfs(int cur, int _end, vector<int>& nums)
    {
        if (cur == nums.size())
        {
            if (tmp.size() >= 2)
            {
                ret.push_back(tmp);
                // cout << "1" << endl;
            }
            return;
        }
        if (nums[cur] >= _end)
        {
            // 入
            tmp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            tmp.pop_back();
        }
        // 剩下的即不符合要求
        // 但也要往前走
        if (nums[cur] != _end) dfs(cur + 1, _end, nums);

    }
};

int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}