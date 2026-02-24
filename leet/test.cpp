#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

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
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        // 快慢指针
//        ListNode* s = head, * f = head, * p = nullptr;
//        while (n--)
//        {
//            f = f->next;
//        }
//        while (f)
//        {
//            p = s;
//            s = s->next;
//            f = f->next;
//        }
//        // 删除s
//        if (p) p->next = s->next;
//        else head = head->next;
//        return head;
//    }
//};
//
//
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        // 暴力
//        int n = matrix.size(), m = matrix[0].size();
//        // 统计需要修改的行与列
//        unordered_set<int> ans_x, ans_y;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (matrix[i][j] == 0)
//                {
//                    ans_x.insert(i);
//                    ans_y.insert(j);
//                }
//            }
//        }
//
//        // 进行修改
//        for (auto e : ans_x)
//        {
//            for (int x = 0; x < m; x++)
//            {
//                matrix[e][x] = 0;
//            }
//        }
//        for (auto e : ans_y)
//        {
//            for (int y = 0; y < n; y++)
//            {
//                matrix[y][e] = 0;
//            }
//        }
//    }
//};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 暴力 + 优化(优化空间复杂度)
        int n = matrix.size(), m = matrix[0].size();
        // 统计需要修改的行与列
        // unordered_set<int> ans_x, ans_y; // 反正早晚要修改，那么直接用第一行与第一列
        bool ans_x = false, ans_y = false;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0) ans_x = true;
        }
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0) ans_y = true;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 进行修改
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (ans_x)
        {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        if (ans_y)
        {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }
    }
};

int main()
{
    vector<vector<int>> v;
    v.push_back({ 1,1,1 });
    v.push_back({ 1,0,1 });
    v.push_back({ 1,1,1 });
    // [1,1,1],[1,0,1],[1,1,1]
    Solution s;
    s.setZeroes(v);
    return 0;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */