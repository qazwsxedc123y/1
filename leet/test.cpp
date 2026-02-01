#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        for (int i = 0; i < s.size(); i++)
        {
            if (!ret.empty() && ret.back() == s[i]) ret.pop_back();
            else ret.push_back(s[i]);
        }
        return ret;
    }
};
int main()
{
    MyCircularQueue s(3);
    s.enQueue(1);
    s.enQueue(2);
    s.enQueue(3);
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