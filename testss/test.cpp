#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
//
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
        int n = matrix.size(), m = matrix[0].size();
        int x = -1, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] > target)
            {
                // 必在上一行
                x = i - 1;
                break;
            }
            else if (matrix[i][0] == target) return true;
        }
        if (x == -1) x = n - 1;
        cout << x << endl;
        for (int i = 0; i < m; i++)
        {
            if (matrix[x][i] == target) return true;
        }

        return false;
    }
};

int main()
{
	cout << (int)'6' << endl;
	return 0;
}