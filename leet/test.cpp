#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 可以先把所有的string排序后，在进行比对
        // 在将其插入到对应的哈希内
        unordered_map<string, vector<int>> hash1; // 排好后的 + 数组
        vector<vector<string>> ret;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            hash1[t].push_back(i);
        }

        for (auto& pair : hash1)
        {
            string t = pair.first;
            vector<int> value = pair.second;
            vector<string> str;
            for (int i = 0; i < value.size(); i++)
            {
                str.push_back(strs[value[i]]);
            }
            ret.push_back(str);
        }

        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 可以先把所有的string排序后，在进行比对
        // 在将其插入到对应的哈希内
        unordered_map<string, vector<string>> hash1; // 排好后的 + 数组
        vector<vector<string>> ret;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            hash1[t].push_back(strs[i]);
        }

        for (auto& pair : hash1)
        {
            ret.push_back(pair.second);
        }

        return ret;
    }
};

int main()
{
    vector<string> v({ "eat", "tea", "tan", "ate", "nat", "bat" });
    Solution s;
    s.groupAnagrams(v);
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