#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>

int main()
{
	int a = 10;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
#define a 1
		break;
	case 2:
#define a 2
		break;
	case 3:
#define a 3
		break;
	default:
		break;
	}
	printf("%d ", a);
	return 0;
}
//void swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void SelectSort(int* a, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		int min = left;
//		int max = right;
//		for (int i = left; i <= right; i++)
//		{
//			if (a[min] > a[i])
//			{
//				min = i;
//			}
//			if (a[max] < a[i])
//			{
//				max = i;
//			}
//		}
//		//交换
//		if (max == left)
//		{
//			max = min;
//		}
//		swap(&a[min], &a[left]);
//		swap(&a[max], &a[right]);
//		left++;
//		right--;
//	}
//}
//
//void AdjustDwon(int* a, int root, int n)
//{
//	int child = root * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child + 1] < a[child])
//		{
//			child++;
//		}
//		if (a[child] < a[root])
//		{
//			swap(&a[child], &a[root]);
//			root = child;
//			child = root * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//
//void HeapSort(int* a, int n)
//{
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		AdjustDwon(a, i, n);//传的为父亲
//	}
//}
//
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;//分组，将间隔为gap分为一组，共gap个组
//		for (int i = 0; i < gap; i++)
//		{
//			for (int j = i; j < n - gap; j += gap)
//			{
//				int end = j;
//				int tmp = a[end + gap];
//				while (end >= 0)
//				{
//					if (tmp < a[end])
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = a[i + 1];
//		while (end >= 0)
//		{
//			if (a[end] > tmp)
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//			a[end + 1] = tmp;
//		}
//	}
//}
//void BubbleSort(int* a, int n)
//{
//	for (int i = 0; i < n; i++)//一共n-1趟
//	{
//		int j = 0;
//		int count = 1;
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				swap(&a[j], &a[j + 1]);
//				count = 0;
//			}
//		}
//		if (count == 1)
//		{
//			break;
//		}
//	}
//}
//
////快速排序
////Hoare版
//
//int PartSort1(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[keyi] <= a[right])
//		{
//			right--;
//		}
//		while (left < right && a[keyi] >= a[left])
//		{
//			left++;
//		}
//		swap(&a[left], &a[right]);
//	}
//	swap(&a[left], &a[keyi]);
//	return left;//返回此时keyi的下标数
//}
//void QuickSort1(int* a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int keyi = PartSort1(a, begin, end);
//	//三个区间  [begin,keyi-1]  keyi  [keyi+1,end]
//	QuickSort1(a, begin, keyi - 1);
//	QuickSort1(a, keyi + 1, end);
//}
//
////快速排序
////挖坑版
//
//int PartSort2(int* a, int left, int right)
//{
//	int key = a[left];
//	int hole = left;//下标
//	while (left < right)
//	{
//		while (left < right && key <= a[right])
//		{
//			right--;
//		}
//		a[hole] = a[right];
//		hole = right;
//		while (left < right && key >= a[left])
//		{
//			left++;
//		}
//		a[hole] = a[left];
//		hole = left;
//	}
//	a[hole] = key;
//	return left;//返回此时keyi的下标数
//}
//void QuickSort2(int* a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int keyi = PartSort2(a, begin, end);
//	//三个区间  [begin,keyi-1]  keyi  [keyi+1,end]
//	QuickSort2(a, begin, keyi - 1);
//	QuickSort2(a, keyi + 1, end);
//}
//
////快速排序
////双指针版
//void QuickSort3(int* a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int keyi = begin;
//	int cur = begin + 1;
//	int prev = begin;
//	while (cur <= end)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//		{
//			swap(&a[cur], &a[prev]);
//		}
//		cur++;
//	}
//	swap(&a[keyi], &a[prev]);
//	keyi = prev;
//	QuickSort3(a, begin, keyi - 1);
//	QuickSort3(a, keyi + 1, end);
//}
//void print(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//    int arr[] = { 9,5,1,7,3,4,6,0,8,2 };
//	//SelectSort(arr, 10);
//	//ShellSort(arr, 10);
//	BubbleSort(arr, 10);
//	int arr1[] = { 9,5,1,7,3,4,6,0,8,2 };
//	//HeapSort(arr1, 10);
//	//InsertSort(arr1, 10);
//	QuickSort1(arr1, 0, 9);
//	int arr2[] = { 9,5,1,7,3,4,6,0,8,2 };
//	QuickSort2(arr2, 0, 9);
//	int arr3[] = { 9,5,1,7,3,4,6,0,8,2 };
//	QuickSort3(arr3, 0, 9);
//	print(arr, 10);
//	print(arr1, 10);
//	print(arr2, 10);
//	print(arr3, 10);
//    return 0;
//}
//
//char* addBinary(char* a, char* b) {
//    int carry = 0;
//    int len1 = (int)strlen(a);
//    int len2 = (int)strlen(b);
//    if (len1 == 0 && len2 == 0)//两个字符串都为0,任意返回一个
//    {
//        return a;
//    }
//    char* com=0;
//    int size = 0;
//    //填完
//    if (len1 >= len2)
//    {
//        char* com = (char*)malloc(sizeof(char) * len1 + 1);
//        size = len1 + 1;
//        for (int i = len1; i > 0; i--)
//        {
//            com[i] = a[i] ^ b[i] + carry;
//            if (com[i] == 0)
//            {
//                carry = 1;
//            }
//            else
//            {
//                carry = 0;
//            }
//        }
//        if (carry == 0)
//        {
//            com[0] = '0';
//        }
//        else
//        {
//            com[0] = '1';
//        }
//
//    }
//    else
//    {
//        char* com = (char*)malloc(sizeof(char) * len2 + 1);
//        size = len2 + 1;
//        for (int i = len2; i > 0; i--)
//        {
//            com[i] = a[i] ^ b[i] + carry;
//            if (com[i] == 0)
//            {
//                carry = 1;
//            }
//            else
//            {
//                carry = 0;
//            }
//        }
//        com[0] = carry;
//    }
//    //调整首位是否需要进位
//    if (com[0] == 0)
//    {
//        memmove(com, com + 1, sizeof(char) * (size - 1));
//        char* tmp = realloc(com, sizeof(char) * (size - 1));
//        if (tmp != NULL)
//        {
//            com = tmp;
//        }
//        size -= 1;
//    }
//    return com;
//}
//int main()
//{
//    int* arr=(int*)malloc(4);
//    arr[0] =  9 ;
//    int n = 0;
//    char a[] = "1";
//    char b[] = "0";
//    addBinary(a, b);
//    return 0;
//}

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