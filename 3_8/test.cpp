#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;



//class Solution {
//public:
//    void reorderList(ListNode* head) {
//        if (head == nullptr)
//        {
//            return;
//        }
//        ListNode* mid = middleNode(head);
//        ListNode* l1 = head;
//        ListNode* l2 = mid->next;
//        mid->next = nullptr;
//        l2 = reverseList(l2);
//        mergeList(l1, l2);
//    }
//
//    ListNode* middleNode(ListNode* head) {
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while (fast->next != nullptr && fast->next->next != nullptr) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = nullptr;
//        ListNode* curr = head;
//        while (curr != nullptr) {
//            ListNode* nextTemp = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextTemp;
//        }
//        return prev;
//    }
//
//    void mergeList(ListNode* l1, ListNode* l2) {
//        ListNode* l1_tmp;
//        ListNode* l2_tmp;
//        while (l1 != nullptr && l2 != nullptr) {
//            l1_tmp = l1->next;
//            l2_tmp = l2->next;
//
//            l1->next = l2;
//            l1 = l1_tmp;
//
//            l2->next = l1;
//            l2 = l2_tmp;
//        }
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
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) return head;
//
//        ListNode* newhead = new ListNode(0);
//        newhead->next = head;
//
//        ListNode* prev = newhead, * cur1 = prev->next, * cur2 = cur1->next, * tmp = cur2->next;
//
//        while (cur1 && cur2)
//        {
//            // 交换
//            prev->next = cur2;
//            cur2->next = cur1;
//            cur1->next = tmp;
//
//            // 修改指针
//            prev = cur1;
//            cur1 = tmp;
//            if (cur1) cur2 = cur1->next;
//            if (cur2) tmp = cur2->next;
//        }
//        cur1 = newhead->next;
//        delete newhead;
//        return cur1;
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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* cur1 = l1, * cur2 = l2;
//        ListNode* newhead = new ListNode(0);
//        ListNode* prev = newhead;
//        int t = 0;
//        while (cur1 || cur2 || t)
//        {
//            if (cur1)
//            {
//                t += cur1->val;
//                cur1 = cur1->next;
//            }
//            if (cur2)
//            {
//                t += cur2->val;
//                cur2 = cur2->next;
//            }
//            prev->next = new ListNode(t % 10);
//            prev = prev->next;
//            t /= 10;
//        }
//        return newhead->next;
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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* head = nullptr, * tail = nullptr;
//        int carry = 0;
//        int sum = 0;
//        while (l1 || l2)
//        {
//            int n1 = l1 ? l1->val : 0;
//            int n2 = l2 ? l2->val : 0;
//            sum = n1 + n2 + carry;
//            if (sum >= 10)
//            {
//                carry = sum / 10;
//                sum %= 10;
//            }
//            else {
//                carry = 0;
//            }
//            if (!head) // 第一次
//            {
//                head = tail = new ListNode(sum);
//            }
//            else
//            {
//                tail->next = new ListNode(sum);
//                tail = tail->next;
//            }
//            if (l1)
//            {
//                l1 = l1->next;
//            }
//            if (l2)
//            {
//                l2 = l2->next;
//            }
//        }
//        if (carry != 0)
//        {
//            tail->next = new ListNode(carry);
//        }
//        return head;
//    }
//};