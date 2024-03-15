#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        ListNode* ret1 = nullptr; // Head of the list with nodes < x
//        ListNode* ret2 = nullptr; // Head of the list with nodes >= x
//        ListNode* tail1 = nullptr; // Tail of the list with nodes < x
//        ListNode* tail2 = nullptr; // Tail of the list with nodes >= x
//
//        while (pHead) {
//            if (pHead->val < x) {
//                if (!ret1) {
//                    ret1 = pHead;
//                    tail1 = pHead;
//                }
//                else {
//                    tail1->next = pHead;
//                    tail1 = pHead;
//                }
//            }
//            else {
//                if (!ret2) {
//                    ret2 = pHead;
//                    tail2 = pHead;
//                }
//                else {
//                    tail2->next = pHead;
//                    tail2 = pHead;
//                }
//            }
//            pHead = pHead->next;
//        }
//
//        // Connect the two lists
//        if (tail1) {
//            tail1->next = ret2;
//        }
//
//        if (tail2) {
//            tail2->next = nullptr;
//        }
//
//        // Return the head of the modified list
//        return ret1 ? ret1 : ret2;
//    }
//
//
//};



//class PalindromeList {
//public:
//    ListNode* mid_ListNode(ListNode* A)
//    {
//        ListNode* fast = A, * slow = A;
//        while (fast && fast->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
//    ListNode* Reserve(ListNode* A)
//    {
//        ListNode* tail = NULL;
//        ListNode* tail2 = NULL;
//        ListNode* p = A;
//        while (p)
//        {
//            ListNode* next = p->next; // ������һ���ڵ�
//            p->next = tail2; // ��ת��ǰ�ڵ��ָ��
//            tail2 = p; // ���� tail2
//            p = next; // ��������һ���ڵ�
//        }
//        A = tail2;
//        return tail2;
//    }
//    bool chkPalindrome(ListNode* A) {
//        // write code here
//        assert(A);
//        ListNode* mid = mid_ListNode(A);
//        mid=Reserve(mid);
//        while (mid && A)
//        {
//            if (A->val != mid->val)
//            {
//                return false;
//            }
//            mid = mid->next;
//            A = A->next;
//        }
//        return true;
//    }
//};
