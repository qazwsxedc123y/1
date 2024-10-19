#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<map>
using namespace std;

//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//        {
//            return head;
//        }
//        ListNode* newhead = head->next;
//        head->next = swapPairs(newhead->next);
//        newhead->next = head;
//        return newhead;
//    }
//};


//class Solution {
//public:
//    void backtrack(vector<string>& ans, string& cur, int open, int close, int n)
//    {
//        if (cur.size() == n * 2)
//        {
//            ans.push_back(cur);
//            return;
//        }
//        if (n > open)
//        {
//            cur.push_back('(');
//            backtrack(ans, cur, open + 1, close, n);
//            cur.pop_back();
//        }
//        if (open > close)
//        {
//            cur.push_back(')');
//            backtrack(ans, cur, open, close + 1, n);
//            cur.pop_back();
//        }
//    }
//    vector<string> generateParenthesis(int n) {
//        //在原已经是的情况下，添加（），（一定在）左边
//        vector<string> result;
//        string current;
//        backtrack(result, current, 0, 0, n);
//        return result;
//    }
//};

//class Solution {
//    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
//        if (cur.size() == n * 2) {
//            ans.push_back(cur);
//            return;
//        }
//        if (open < n) {
//            cur.push_back('(');
//            backtrack(ans, cur, open + 1, close, n);
//            cur.pop_back();
//        }
//        if (close < open) {
//            cur.push_back(')');
//            backtrack(ans, cur, open, close + 1, n);
//            cur.pop_back();
//        }
//    }
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> result;
//        string current;
//        backtrack(result, current, 0, 0, n);
//        return result;
//    }
//};

int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}


////**
// //* Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
// //*/
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        // 快慢指针
//        int tmp = n;
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while (tmp--)
//        {
//            fast = fast->next;
//        }
//        ListNode* pre = nullptr;
//        while (fast)
//        {
//            pre = slow;
//            slow = slow->next;
//            fast = fast->next;
//        }
//        ListNode* _next = slow->next;
//        // 删除slow
//        if (pre == nullptr)
//        {
//            head = head->next;
//        }
//        else
//        {
//            pre->next = _next;
//        }
//        return head;
//    }
//};