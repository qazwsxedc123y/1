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
//        // ��a�̵�n��������c�̣��ŵ�b��
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
//    // ���õݹ����
//    double myPow(double x, int n) {
//        return n > 0 ? pow(x, (long long)n) : 1.0 / pow(x, -(long long)n);
//    }
//    double pow(double x, long long n) {
//        if (n == 0) return 1.0;
//        double tmp = pow(x, n / 2);
//        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
//    }
//};


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
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//        if (root->left == nullptr) return root->val;
//
//        bool left = evaluateTree(root->left);
//        bool right = evaluateTree(root->right);
//
//        if (root->val == 2) // or
//        {
//            return left || right;
//        }
//        else
//        {
//            return left && right;
//        }
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
//    int sumNumbers(TreeNode* root) {
//        return dfs(root, 0);
//    }
//    int dfs(TreeNode* root, int presum) {
//        presum = presum * 10 + root->val;
//
//        if (root->left == nullptr && root->right == nullptr)
//            return presum;
//
//        int ret = 0;
//        if (root->left)
//            ret += dfs(root->left, presum);
//        if (root->right)
//            ret += dfs(root->right, presum);
//
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
//    TreeNode* pruneTree(TreeNode* root) {
//        if (root == nullptr) return nullptr;
//
//        root->left = pruneTree(root->left);
//        root->right = pruneTree(root->right);
//
//        if (root->left == nullptr && root->right == nullptr && root->val == 0)
//        {
//            root = nullptr;
//        }
//
//        return root;
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
//    long pre = LONG_MIN;
//public:
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) return true;
//
//        // ���Ϊ��������������ô�������Ϊ����
//        bool left = isValidBST(root->left);
//
//        bool falg = true;
//        if (root->val <= pre) {
//            falg = false;
//        }
//        pre = root->val;
//        bool right = isValidBST(root->right);
//
//        return left && right && falg;
//    }
//};


//class Solution {
//    long pre = LONG_MIN; // ����ΪINT_MIN��������С
//public:
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) return true;
//
//        // ���Ϊ��������������ô�������Ϊ����
//        bool left = isValidBST(root->left);
//        // ��֦
//        if (left == false) return false;
//
//        bool falg = true;
//        if (root->val <= pre) {
//            falg = false;
//        }
//        pre = root->val;
//        // ��֦
//        if (falg == false) return false;
//        bool right = isValidBST(root->right);
//
//        return left && right && falg;
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
//    int count;
//    int ret;
//public:
//    int kthSmallest(TreeNode* root, int k) {
//        // ���ö����������������Ϊ������ص�
//        count = k;
//        dfs(root);
//        return ret;
//    }
//    void dfs(TreeNode* root) {
//        // ��֦ count == 0
//        if (root == nullptr) return;
//        dfs(root->left);
//
//        //
//        count--;
//        if (count == 0) ret = root->val;
//
//        dfs(root->right);
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
//    vector<string> ret;
//public:
//    vector<string> binaryTreePaths(TreeNode* root) {
//        string path;
//        if (root == nullptr) return ret;
//        dfs(root, path);
//        return ret;
//    }
//    void dfs(TreeNode* root, string path) {
//        // ǰ�����
//        path += to_string(root->val);
//        // ��Ҷ�ӽڵ�
//        if (root->left == nullptr && root->right == nullptr) {
//            ret.push_back(path);
//            return;
//        }
//        // ����Ҷ�ӽڵ�����⴦��
//        path += "->";
//        if (root->left) dfs(root->left, path);
//        if (root->right) dfs(root->right, path);
//    }
//};


//class Solution {
//    vector<string> ret;
//public:
//    vector<string> binaryTreePaths(TreeNode* root) {
//        string path;
//        if (root == nullptr) return ret;
//        dfs(root, path);
//        return ret;
//    }
//    void dfs(TreeNode* root, string path) {
//        // ǰ�����
//        if (root == nullptr) return;
//        path += to_string(root->val);
//        // ��Ҷ�ӽڵ�
//        if (root->left == nullptr && root->right == nullptr) {
//            ret.push_back(path);
//            return;
//        }
//        // ����Ҷ�ӽڵ�����⴦��
//        path += "->";
//        dfs(root->left, path);
//        dfs(root->right, path);
//    }
//};