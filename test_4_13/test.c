#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    digits[digitsSize - 1] += 1;
    for (int i = digitsSize - 1; i - 1 >= 0 && i >= 0; i--)
    {
        if (digits[i] == 10)
        {
            digits[i] -= 10;
            digits[i - 1] += 1;
        }
    }
    if (digits[0] == 10)
    {
        int* tmp = realloc(digits, sizeof(int) * (digitsSize + 1));
        if (tmp != NULL) {
            digitsSize += 1;
            digits = tmp;
        }
        memmove(digits + 1, digits, sizeof(int) * (digitsSize - 1));
        digits[1] -= 10;
        digits[0] = 1;
    }
    *returnSize = digitsSize;
    return digits;
}

int main()
{
    int* arr=(int*)malloc(4);
    arr[0] =  9 ;
    int n = 0;
    plusOne(arr, 1, &n);
    return 0;
}

//int strStr(char* haystack, char* needle) {
//    int i = 0;
//    int num1 = strlen(haystack);
//    int num2 = strlen(needle);
//    for (i = 0; i < num1 - num2 + 1; i++)//头对应的趟数
//    {
//        int j = 0;
//        for (j = 0; j < num2; j++)
//        {
//            if (haystack[j + i] != needle[j])
//            {
//                break;
//            }
//        }
//        if (j == num2)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
//int _searchInsert(int* nums, int n, int target)
//{
//    int left = 0;
//    int right = n - 1;
//    while (left < right)
//    {
//        int mid = (left + right) / 2;
//        if (nums[mid] < target)
//        {
//            left = mid + 1;
//        }
//        else if (nums[mid] > target)
//        {
//            right = mid - 1;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    int max = left > right ? left : right;
//    if (nums[max] >= target)
//    {
//        return max;
//    }
//    else
//    {
//        return max + 1;
//    }
//}
//int searchInsert(int* nums, int numsSize, int target) {
//    int Indix = _searchInsert(nums, numsSize, target);
//    return Indix;
//}
//int lengthOfLastWord(char* s) {
//    int s1 = strlen(s) - 1;
//    int count = 0;
//    while (s[s1] == ' ' && s1 >= 0)
//    {
//        s1--;
//    }
//    while (s1 >= 0 && s[s1--] != ' ')
//    {
//        count++;
//    }
//    return count;
//}

//int strStr(char* haystack, char* needle) {
//    int i = 0;
//    int num1 = strlen(haystack);
//    int num2 = strlen(needle);
//    for (i = 0; i < num1 - num2+1; i++)//头对应的趟数
//    {
//        int j = 0;
//        for (j = 0; j < num2; j++)
//        {
//            if (haystack[j+i] != needle[j])
//            {
//                break;
//            }
//        }
//        if (j >= num2)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    char ch1[] = "Hello World  ";
//    printf("%d ", strlen(ch1));
//    char ch2[] = "o";
//    //strStr(ch1, ch2);
//    return 0;
//}