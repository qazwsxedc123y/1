#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

using namespace std;


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//        vector<vector<int>> ret;
//        if (root == nullptr) return ret;
//        queue<TreeNode*> q;
//        q.push(root);
//        int level = 1;
//
//        while (q.size())
//        {
//            int sz = q.size();
//            vector<int> tmp;
//            for (int i = 0; i < sz; i++)
//            {
//                TreeNode* t = q.front();
//                q.pop();
//                tmp.push_back(t->val);
//                if (t->left) q.push(t->left);
//                if (t->right) q.push(t->right);
//            }
//            if (level % 2 == 0) // 是偶数那么就需要逆序
//            {
//                reverse(tmp.begin(), tmp.end());
//            }
//            level++;
//            ret.push_back(tmp);
//        }
//        return ret;
//    }
//};


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    int widthOfBinaryTree(TreeNode* root) {
//        vector<pair<TreeNode*, unsigned int>> q; // 用数组模拟队列
//        q.push_back({ root, 1 });
//        unsigned int ret = 0;
//        while (q.size())
//        {
//            // 先更新这一层的宽度
//            auto& [x1, y1] = q[0];
//            auto& [x2, y2] = q.back();
//            ret = max(ret, y2 - y1 + 1);
//
//            // 让下一层进队列
//            vector<pair<TreeNode*, unsigned int>> tmp; // 下一层进入这个数组
//            for (auto& [x, y] : q)
//            {
//                if (x->left)
//                {
//                    tmp.push_back({ x->left, 2 * y + 1 });
//                }
//                if (x->right)
//                {
//                    tmp.push_back({ x->right, 2 * y + 2 });
//                }
//            }
//            q = tmp;
//        }
//        return (int)ret;
//    }
//};


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    int widthOfBinaryTree(TreeNode* root) {
//        queue<pair<TreeNode*, unsigned int>> q;
//        q.push({ root, 1 });
//        unsigned int ret = 0;
//        while (q.size())
//        {
//            int sz = q.size();
//            unsigned int left = q.front().second;
//            unsigned int right = q.back().second;
//            ret = max(ret, right - left + 1);
//            for (int i = 0; i < sz; i++)
//            {
//                auto [x, y] = q.front();
//                q.pop();
//                if (x->left) q.push({ x->left, y * 2 + 1 });
//                if (x->right) q.push({ x->right, y * 2 + 2 });
//            }
//        }
//        return (int)ret;
//    }
//};


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    vector<int> largestValues(TreeNode* root) {
//        vector<int> ret;
//        if(root == nullptr) return ret;
//        queue<TreeNode*> q;
//        q.push(root);
//        int level = 0;
//        while (q.size())
//        {
//            int sz = q.size();
//            int ans = INT_MIN;
//            for (int i = 0; i < sz; i++)
//            {
//                TreeNode* tmp = q.front();
//                q.pop();
//                ans = max(ans, tmp->val);
//                if (tmp->left) q.push(tmp->left);
//                if (tmp->right) q.push(tmp->right);
//            }
//            ret.push_back(ans);
//        }
//        return ret;
//    }
//};