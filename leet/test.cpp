#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[32];
        for (int i = 0; i < s.size(); i++)
        {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (cnt[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
// grid = [[1,3,1],[1,5,1],[4,2,1]]
int main()
{
    vector<vector<int>> v;
    v.push_back({ 1,3,1 });
    v.push_back({ 1,5,1 });
    v.push_back({ 4,2,1 });
    Solution s;
    s.minPathSum(v);
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