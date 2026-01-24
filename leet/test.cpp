#include <iostream>
#include <vector>
using namespace std;

// select id, length(string) - length(replace(string, ',', '')) from strings;
int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}