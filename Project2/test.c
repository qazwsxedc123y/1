#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>



//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    if (num == NULL)
//    {
//        int* res = malloc(sizeof(int) * fmax(10, numSize + 1));
//        *returnSize = 0;
//        for (int i = numSize - 1; i >= 0; --i) {
//            int sum = num[i] + k % 10;
//            k /= 10;
//            if (sum >= 10) {
//                k++;
//                sum -= 10;
//            }
//            res[(*returnSize)++] = sum;
//        }
//        for (; k > 0; k /= 10) {
//            res[(*returnSize)++] = k % 10;
//        }
//        for (int i = 0; i < (*returnSize) / 2; i++) {
//            int tmp = res[i];
//            res[i] = res[(*returnSize) - 1 - i];
//            res[(*returnSize) - 1 - i] = tmp;
//        }
//        return res;
//    }
//    if (k == 0)
//    {
//        *returnSize = numSize;
//        return num;
//    }
//    int *a=(int*)malloc(sizeof(int) * numSize);
//    if (a == NULL)
//    {
//        assert("malloc fail\n");
//        return NULL;
//    }
//    *returnSize = 0;
//    int ary = 0;
//    for (int i = numSize - 1; i >= 0; i--)
//    {
//        int sum = k % 10 + num[i] + ary;
//        ary = 0;
//        if (sum >= 10)
//        {
//            ary = sum / 10;
//            a[i] = sum % 10;
//        }
//        else
//        {
//            a[i] = sum;
//        }
//        k /= 10;
//
//        (*returnSize)++;
//    }
//    if (a[0] >= 10|| ary !=0)
//    {
//        int* tmp = (int*)realloc(a, sizeof(int) * (numSize+1));
//        if (tmp != NULL)
//        {
//            a = tmp;
//        }
//        memmove(a+1, a , sizeof(int) * numSize);
//        a[0] = a[1] / 10+ary;
//        a[1]  %= 10;
//        (*returnSize)++;
//    }
//    return a;
//}
//void a()
//{
//    int* a = (int*)malloc(sizeof(int) * 4);
//    int* tmp=realloc(a, sizeof(int) * 5);
//}
//int main()
//{
//
//   // a();
//    int arr[] = { 2,1,5 };
//    int sz = 0;
//    addToArrayForm(arr, 3, 806, &sz);
//    return 0;
//}


//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;  
//};
//struct TreeNode* _sortedArrayToBST(int* nums, int left, int right)
//{
//    if (nums == NULL)
//    {
//        return NULL;
//    }
//    int mid = (left + right) / 2;
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->val = nums[mid];
//    root->left = _sortedArrayToBST(nums, left, mid - 1);
//    root->right = _sortedArrayToBST(nums, mid + 1, right);
//    return root;
//}
//struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
//    return _sortedArrayToBST(nums, 0, numsSize - 1);
//}
//int main()
//{
//    return 0;
//}