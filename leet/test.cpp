#include <iostream>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* per = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                if (per)
                {
                    per->next = cur->next;
                    cur = per->next;
                }
                else
                {
                    cur = head->next;
                    head = cur;
                }
            }
            else
            {
                per = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};


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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
        {
            return head;
        }
        head->next = removeElements(head->next, val);
        if (head->val == val)
        {
            return head->next;
        }
        else
        {
            return head;
        }

    }
};

int main()
{
    vector<int> ans{ 4,6,7,7 };
    Solution s;
    s.findSubsequences(ans);
    return 0;
}