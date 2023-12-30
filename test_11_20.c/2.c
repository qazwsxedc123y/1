#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int MinIndex(int a[], int n)
//{
//	int min = a[0];
//	int k1 = 0;
//	int i = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		if (a[i] > a[i + 1])
//		{
//			min = a[i + 1];
//			k1 = i + 1;
//		}
//	}
//	return k1;
//}
//int MaxIndex(int a[], int n)
//{
//	int i = 0;
//	int max = a[n - 1];
//	int k2 = 0;
//	for (i = n - 1; i > 0; i--)
//	{
//		if (a[i - 1] > a[i])
//		{
//			max = a[i - 1];
//			k2 = i - 1;
//		}
//	}
//	return k2;
//}
//void PrintArr(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[10];
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int k1 = MinIndex(arr, n);
//	//»»Î»
//	int ret = arr[0];
//	arr[0] = arr[k1];
//	arr[k1] = ret;
//
//	int k2 = MaxIndex(arr, n);
//	ret = arr[n-1];
//	arr[n-1] = arr[k2];
//	arr[k2] = ret;
//	PrintArr(arr, n);
//}



