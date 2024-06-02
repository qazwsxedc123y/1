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
        // �ȿ�ͷ��ͷ�������
        if (root) {
            q.push(root);
            levelsize = 1;
        }
        while (!q.empty())
        {
            vector<int> v;
            // һ�����
            while (levelsize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                // �ò��������,����
                // ��һ���ڰ�������queue
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
