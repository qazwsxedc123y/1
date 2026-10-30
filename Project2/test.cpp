#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = INT_MAX, cnt = 0;
        for (auto it = nums.begin(); it != nums.end(); )
        {
            if (ans == *it && cnt == 2)
            {
                it = nums.erase(it);
            }
            else if (ans != *it)
            {
                ans = *it;
                cnt = 1;
                it++;
            }
            else if (ans == *it)
            {
                cnt++;
                it++;
            }
        }
        int n = nums.size();
        return n;
    }
};


int main()
{
    Solution s;
    vector<int> v{ 0,0,1,1,1,1,2,3,3 };
    s.removeDuplicates(v);
    return 0;
}