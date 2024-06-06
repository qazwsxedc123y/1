#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int Get_key_Index(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[right])
	{
		if (a[left] > a[mid])
		{
			return left;
		}
		else if (a[right] < a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else if (a[left] == a[right])
	{
		return left;
	}
	else
	{
		if (a[right] > a[mid])
		{
			return right;
		}
		else if (a[left] < a[mid])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
}
int part_1_sort(int* a, int left, int right,int* arr)
{
	int midi = Get_key_Index(a, left, right);
	swap(&a[midi], &a[left]);
	swap(&arr[midi], &arr[left]);
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[keyi] <= a[right])
		{
			right--;
		}
		while (left < right && a[keyi] >= a[left])
		{
			left++;
		}
		swap(&a[left], &a[right]);
		swap(&arr[left], &arr[right]);
	}
	swap(&a[left], &a[keyi]);
	swap(&arr[left], &arr[keyi]);
	return left;//返回此时keyi的下标数
}
void Quick_sort_Hoare(int* a, int begin, int end,int* arr)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = part_1_sort(a, begin, end,arr);
	//三个区间  [begin,keyi-1]  keyi  [keyi+1,end]
	Quick_sort_Hoare(a, begin, keyi - 1,arr);
	Quick_sort_Hoare(a, keyi + 1, end,arr);
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		arr[i] = i;
	}
	Quick_sort_Hoare(nums, 0, numsSize - 1, arr);
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] == nums[j] && abs(arr[i] - arr[j]) <= k)
			{
				return true;
			}
			if (nums[i] != nums[j])
			{
				break;
			}
		}
	}
	return false;
}
int main()
{

	printf("%d", -1 % 9);
	return 0;
}
