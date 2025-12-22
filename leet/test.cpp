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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return ret;
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
    ListNode* reverseList(ListNode* head) {
        // β�巨
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* _next = head->next;
        ListNode* nnext = nullptr;
        head->next = nullptr;
        while (_next != nullptr)
        {
            nnext = _next->next;
            _next->next = head;
            head = _next;
            _next = nnext;
        }
        return head;
    }
};
