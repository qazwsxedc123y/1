#define  _CRT_SECURE_NO_WARNINGS

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
    ListNode* _head;
    int sz = 0;
    Solution(ListNode* head) {
        _head = head;
        while (head != nullptr)
        {
            sz++;
            head = head->next;
        }
    }

    int getRandom() {
        int index = rand() % sz;
        ListNode* tail = _head;
        while (index)
        {
            tail = tail->next;
            index--;
        }
        return tail->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
