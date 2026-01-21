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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        // 先将后半段进行翻转
        ListNode* mid = mid_node(head);
        ListNode* tmp = mid;
        mid = reverse_node(mid->next);
        tmp->next = nullptr;
        // 将进行按序插入
        sort_node(head, mid);
    }
    void sort_node(ListNode* node1, ListNode* node2)
    {
        ListNode* node1_tmp = node1, * node2_tmp = node2;
        while (node1 != nullptr && node2 != nullptr)
        {
            node1_tmp = node1->next;
            node2_tmp = node2->next;

            // 修改
            node1->next = node2;
            node1 = node1_tmp;

            node2->next = node1;
            node2 = node2_tmp;
        }
    }
    ListNode* mid_node(ListNode* head)
    {
        ListNode* fast = head, * slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse_node(ListNode* head)
    {
        // 将head为头，然后的全部翻转
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ret = reverse_node(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
};