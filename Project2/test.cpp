#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), dummy2(0);
        ListNode* cur1 = &dummy1;
        ListNode* cur2 = &dummy2;

        for (ListNode* p = head; p != nullptr; p = p->next) {
            if (p->val < x) {
                cur1->next = p;
                cur1 = p;
            }
            else {
                cur2->next = p;
                cur2 = p;
            }
        }

        cur1->next = dummy2.next;
        cur2->next = nullptr;
        return dummy1.next;
    }
};
int main()
{
    return 0;
}