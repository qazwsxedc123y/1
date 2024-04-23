#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;  
};
struct TreeNode* _sortedArrayToBST(int* nums, int left, int right)
{
    if (nums == NULL)
    {
        return NULL;
    }
    int mid = (left + right) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = _sortedArrayToBST(nums, left, mid - 1);
    root->right = _sortedArrayToBST(nums, mid + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return _sortedArrayToBST(nums, 0, numsSize - 1);
}
int main()
{
    return 0;
}