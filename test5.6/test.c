#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int counst(char ch)
{
    return ch - 'A' + 1;
}
int titleToNumber(char* columnTitle) {
    int count = 0;
    long multiple = 1;
    for (int i = strlen(columnTitle) - 1; i >= 0; i--)
    {
        int k = counst(columnTitle[i]);
        count += k * multiple;
        multiple *= 26;
    }
    return count;
}
int counst(char ch)
{
    return ch - 'A' + 1;
}
int titleToNumber(char* columnTitle) {
int count = 0;
char* c = columnTitle;
for (int i = srtlen(c); i > 0; i--)
{
    count += counst(c[0]);
    c++;
}
return count;
}
//int majorityElement(int* nums, int numsSize) {
//    int territory = -1;
//    int count = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == territory)
//        {
//            //不需要替换人
//            count++;
//        }
//        else
//        {
//            //第一次/已经没有人
//            if (count == 0)
//            {
//                count++;
//                territory = nums[i];
//            }
//            else {
//                count--;
//            }
//        }
//    }
//    return territory;
//}
//char tran(char ch)
//{
//    return ch - 32;
//}
//bool isAlphanumeric(char c) 
//{
//    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
//}
//bool isPalindrome(char* s) 
//{
//    int len = strlen(s);
//    int left = 0;
//    int right = len - 1;
//    while (left < right)
//    {
//        while (left < right && !isAlphanumeric(s[left])) 
//        {
//            left++;
//        }
//        while (left < right && !isAlphanumeric(s[right]))
//        {
//            right--;
//        }
//        if (tolower(s[left]) != tolower(s[right]))
//        {
//            return false;
//        }
//        left++;
//        right--;
//    }
//    return true;
//}
//int main()
//{
//	char ch[] = "ABC";
//	return 0;
//}