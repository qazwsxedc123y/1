#define  _CRT_SECURE_NO_WARNINGS
//
//class Solution {
//    vector<int> ret;
//public:
//    void dfs(int pos, int num, int n, int k)
//    {
//        if (pos == n)
//        {
//            ret.push_back(num);
//            return;
//        }
//
//        for (int i = 0; i <= 9; i++)
//        {
//            int ans = num % 10;
//            if (i - ans == k || ans - i == k)
//            {
//                dfs(pos + 1, num * 10 + i, n, k);
//            }
//        }
//    }
//    vector<int> numsSameConsecDiff(int n, int k) {
//        // 可以采用dfs
//        for (int i = 1; i <= 9; i++) dfs(1, i, n, k);
//        return ret;
//    }
//};
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针
        ListNode* fast = head;
        while (n--)
        {
            fast = fast->next;
        }
        ListNode* slow = head, * pre = nullptr;
        while (fast)
        {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }
        if (pre == nullptr) // 要删除头位
        {
            head = head->next;
        }
        else
        {
            pre->next = slow->next;
        }
        return head;
    }
};