#include<string>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> vv;
        int levelsize = 0;
        // 先开头把头进入队列
        if (root) {
            q.push(root);
            levelsize = 1;
        }
        while (!q.empty())
        {
            vector<int> v;
            // 一层出完
            while (levelsize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                // 该层进入数组,挨个
                // 下一层在挨个进入queue
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            levelsize = v.size();
            vv.push_back(v);
        }
        return vv;
    }
};
