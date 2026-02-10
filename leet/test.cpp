#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // Ä£Äâ
        int n1 = a.size(), n2 = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(n1, n2);
        int carry = 0;
        string ret;
        for (int i = 0; i < n; i++)
        {
            int x = i < n1 ? (a[i] - '0') : 0;
            int y = i < n2 ? (b[i] - '0') : 0;
            int t = x + y + carry;
            carry = t / 2;
            t %= 2;
            ret.push_back(t + '0');
        }
        if (carry) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
    vector<int> v({ 5,6,2 });
    Solution s;
    s.largestRectangleArea(v);
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