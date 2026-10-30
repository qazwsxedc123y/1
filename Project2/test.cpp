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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        int n = 0;
        ListNode* list = head;
        while (list)
        {
            list = list->next;
            n++;
        }
        k %= n;
        while (k--)
        {
            ListNode* _nnext = head, * _next = head;
            while (_next->next)
            {
                _nnext = _next;
                _next = _next->next;
            }
            _next->next = head;
            head = _next;
            _nnext->next = nullptr;
        }
        return head;
    }
};