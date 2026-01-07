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
    ListNode* get_i(ListNode* head, int i)
    {
        while (i--)
        {
            head = head->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 0;
        ListNode* tail = head;
        while (tail)
        {
            tail = tail->next;
            n++;
        }

        for (int i = 1; i < n; i++)
        {
            ListNode* key_node = get_i(head, i);
            int key_val = key_node->val;

            int j = i - 1;
            ListNode* prev_node = get_i(head, j);

            while (j >= 0 && prev_node->val > key_val)
            {
                ListNode* curr_node = get_i(head, j + 1);
                curr_node->val = prev_node->val;

                j--;
                if (j >= 0) {
                    prev_node = get_i(head, j);
                }
            }

            ListNode* insert_node = get_i(head, j + 1);
            insert_node->val = key_val;
        }
        return head;
    }
};