#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
//int trailingZeroes(int n) {
//    int ans = 0;
//    for (int i = 5; i <= n; i += 5)
//    {
//        for (int x = i; x % 5 == 0; x /= 5)
//        {
//            ans++;
//        }
//    }
//    return ans;
//}
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
int part_1_sort(int* a, int left, int right)
{
	int midi = Get_key_Index(a, left, right);
	swap(&a[midi], &a[left]);
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
	}
	swap(&a[left], &a[keyi]);
	return left;//返回此时keyi的下标数
}
void Quick_sort_Hoare(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = part_1_sort(a, begin, end);
	//三个区间  [begin,keyi-1]  keyi  [keyi+1,end]
	Quick_sort_Hoare(a, begin, keyi - 1);
	Quick_sort_Hoare(a, keyi + 1, end);
}
bool containsDuplicate(int* nums, int numsSize) {
	Quick_sort_Hoare(nums, 0, numsSize - 1);
	for (int i = 0; i < numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			return true;
		}
	}
	return false;
}
bool isHappy(int n) {
    if (n == 1)
    {
        return true;
    }
    if (n == 0 || n == 1 || n == 4 || n == 16 || n == 37 || n == 58
        || n == 89 || n == 145 || n == 42 || n == 20)
    {
        return false;
    }
    int sum = 0;
    int m = 0;
    while (n)
    {
        m = n % 10;
        sum += pow(m, 2);
        n /= 10;
    }
    return isHappy(sum);
}

int main()
{
    isHappy(7);
}