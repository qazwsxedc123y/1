#define  _CRT_SECURE_NO_WARNINGS

//class Solution {
//public:
//    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
//        dfs(A, B, C, A.size());
//    }
//    void dfs(vector<int>& a, vector<int>& b, vector<int>& c, int n)
//    {
//        if (n == 1)
//        {
//            c.push_back(a.back());
//            a.pop_back();
//            return;
//        }
//        // 将a盘的n个，借助c盘，放到b盘
//        dfs(a, c, b, n - 1);
//        c.push_back(a.back());
//        a.pop_back();
//        dfs(b, a, c, n - 1);
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
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr) return list2;
//        if (list2 == nullptr) return list1;
//        if (list1->val < list2->val)
//        {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//        else
//        {
//            list2->next = mergeTwoLists(list1, list2->next);
//            return list2;
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
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) return head;
//
//        ListNode* newhead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//
//        return newhead;
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
//        ListNode* next = head->next;
//        head->next = swapPairs(head->next->next);
//        next->next = head;
//        return next;
//    }
//};


//class Solution {
//public:
//    // 利用递归解题
//    double myPow(double x, int n) {
//        return n > 0 ? pow(x, (long long)n) : 1.0 / pow(x, -(long long)n);
//    }
//    double pow(double x, long long n) {
//        if (n == 0) return 1.0;
//        double tmp = pow(x, n / 2);
//        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
//    }
//};