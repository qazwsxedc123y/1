#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

//class Solution {
//public:
//    bool CheckPermutation(string s1, string s2) {
//        int count[26] = { 0 };
//        if (s1.size() != s2.size()) return false;
//        for (int i = 0; i < s1.size(); i++)
//        {
//            count[s1[i] - 'a']++;
//        }
//        for (int i = 0; i < s2.size(); i++)
//        {
//            count[s2[i] - 'a']--;
//            if (count[s2[i] - 'a'] < 0) return false;
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        unordered_set<int> hash;
//        for (auto num : nums)
//        {
//            if (hash.count(num)) return true;
//            hash.insert(num);
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        unordered_map<int, int> hash;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (hash.count(nums[i]))
//            {
//                if (i - hash[nums[i]] <= k) return true;
//            }
//            hash[nums[i]] = i;
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> ret;
//        unordered_map<string, vector<string>> hash;
//        // 先分组
//        for (int i = 0; i < strs.size(); i++)
//        {
//            string tmp = strs[i];
//            sort(tmp.begin(), tmp.end());
//            hash[tmp].push_back(strs[i]);
//        }
//
//        // 提取出来放到ret中
//        for (auto& [x, y] : hash)
//        {
//            ret.push_back(y);
//        }
//        return ret;
//    }
//};

///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//    struct cmp {
//        bool operator()(const ListNode* l1, const ListNode* l2)
//        {
//            return l1->val > l2->val;
//        }
//    };
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // 借助优先级队列 - 小根堆
//        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
//
//        // 让所有的头节点进入小根堆
//        for (auto l : lists)
//            if (l) heap.push(l);
//
//        // 合并k个节点
//        ListNode* ret = new ListNode(0);
//        ListNode* prev = ret;
//        while (!heap.empty())
//        {
//            ListNode* t = heap.top();
//            heap.pop();
//            prev->next = t;
//            prev = t;
//            if (t->next) heap.push(t->next);
//        }
//        prev = ret->next;
//        delete ret;
//        return prev;
//    }
//};



///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        return merge(lists, 0, lists.size() - 1);
//    }
//    ListNode* merge(vector<ListNode*>& lists, int left, int right)
//    {
//        if (left > right) return nullptr;
//        if (left == right) return lists[left];// 重点
//
//        // 平分数组
//        int mid = (right - left) / 2 + left;
//
//        // 递归处理左右区间
//        ListNode* l1 = merge(lists, left, mid);
//        ListNode* l2 = merge(lists, mid + 1, right);
//
//        // 把两个排序好
//        return sortTowList(l1, l2);
//    }
//    ListNode* sortTowList(ListNode* l1, ListNode* l2)
//    {
//        if (l1 == nullptr) return l2;// 要搞清楚返回谁
//        if (l2 == nullptr) return l1;
//
//        ListNode head;
//        ListNode* cur1 = l1, * cur2 = l2, * prev = &head;
//        head.next = nullptr;
//        while (cur1 && cur2)
//        {
//            if (cur1->val > cur2->val)
//            {
//                // cur2进
//                prev = prev->next = cur2;
//                cur2 = cur2->next;
//            }
//            else
//            {
//                prev = prev->next = cur1;
//                cur1 = cur1->next;
//            }
//        }
//        if (cur1) prev->next = cur1;
//        if (cur2) prev->next = cur2;
//        return head.next;
//    }
//};


///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        int n = 0;
//        ListNode* cur = head;
//        while (cur)
//        {
//            n++;
//            cur = cur->next;
//        }
//        // 一共n组
//        n /= k;
//        ListNode* newhead = new ListNode(0);
//        ListNode* prev = newhead;
//        cur = head;
//        for (int i = 0; i < n; i++)
//        {
//            ListNode* tmp = cur;
//            for (int j = 0; j < k; j++)
//            {
//                ListNode* next = cur->next;
//                cur->next = prev->next;
//                prev->next = cur;
//                cur = next;
//            }
//            prev = tmp;
//        }
//        prev->next = cur;
//        cur = newhead->next;
//        delete newhead;
//        return cur;
//    }
//};


int main()
{
    string s1 = "abc", s2 = "bad";
    Solution s;
    // s.CheckPermutation(s1, s2);
    return 0;
}
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> hash;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (hash.count(target - nums[i]))
//            {
//                return { i,hash[target - nums[i]] };
//            }
//            hash[nums[i]] = i;
//        }
//        return { -1, -1 };
//    }
//};