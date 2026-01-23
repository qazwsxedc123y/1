#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ret = 0;
        // 和已升序的进行对比，找到最大区间不同的两边界
        vector<int> tmp;
        tmp = nums;
        sort(tmp.begin(), tmp.end());
        // for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
        int _begin = 0, _end = tmp.size() - 1;
        while (_begin < _end && tmp[_begin] == nums[_begin]) _begin++; // 1

        if (_begin == _end) return 0;

        while (_end >= 0 && tmp[_end] == nums[_end]) _end--; // 5
        ret = _end - _begin + 1;
        return ret;
    }
};

int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}