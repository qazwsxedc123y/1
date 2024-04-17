#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//int _minDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    return _minDepth(root->left) < _minDepth(root->right) ?
//        _minDepth(root->left) + 1 :
//        _minDepth(root->right) + 1;
//}
//int minDepth(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return 0;
//    }
//    if (root->left == NULL && root->right == NULL)
//    {
//        return 1;
//    }
//    int ret1 = _minDepth(root->left);
//    int ret2 = _minDepth(root->right);
//    return ret1 < ret2 ? ret1 + 1 : ret2;
//}

//int singleNumber(int* nums, int numsSize) {
//    int max = nums[0];
//    int min = nums[0];
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (min > nums[i])
//        {
//            min = nums[i];
//        }
//        if (max < nums[i])
//        {
//            max = nums[i];
//        }
//    }
//    int* a = (int*)malloc(sizeof(int) * (max - min + 1));
//    memset(a, 0,sizeof(int) * (max - min + 1));
//    for (int i = 0; i < numsSize; i++)
//    {
//        a[nums[i] - min]++;
//    }
//    for (int i = 0; i < max - min + 1; i++)
//    {
//        if (a[i] == 1)
//        {
//            return i + min;
//            break;
//        }
//    }
//    free(a);
//    return -1;
//}
//int main()
//{
//    int arr[] = { 0,1,0,1,0,1,3 };
//    singleNumber(arr, 7);
//    return 0;
//}