#define  _CRT_SECURE_NO_WARNINGS
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        vector<ListNode*> v1, v2;
        ListNode* list = head;
        while (list)
        {
            if (list->val < x) v1.push_back(list);
            else v2.push_back(list);
            list = list->next;
        }

        // Æ´½Ó
        ListNode* nhead = nullptr, * cur = nhead;
        for (int i = 0; i < v1.size(); i++)
        {
            if (nhead == nullptr)
            {
                nhead = v1[0];
                cur = nhead;
            }
            else
            {
                cur->next = v1[i];
                cur = v1[i];
            }
        }
        for (int i = 0; i < v2.size(); i++)
        {
            if (nhead == nullptr)
            {
                nhead = v2[0];
                cur = nhead;
            }
            else
            {
                cur->next = v2[i];
                cur = v2[i];
            }

        }
        cur->next = nullptr;
        return nhead;

    }
};
int main()
{
    return 0;
}