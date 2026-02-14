#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int d1 = 0, d2 = 0;
        TreeNode* left = root->left, * right = root->right;

        while (left)
        {
            d1++;
            left = left->left;
        }
        while (right)
        {
            d2++;
            right = right->right;
        }
        if (d1 == d2) return pow(2, d1 + 1) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = -1, right = m * n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int x = matrix[mid / n][mid % n];
            if (x == target) {
                return true;
            }
            (x < target ? left : right) = mid;
        }
        return false;
    }
};


int main()
{
    vector<string> v({ "eat", "tea", "tan", "ate", "nat", "bat" });
    string str("(())(())");
    Solution s;
    s.longestValidParentheses(str);
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