#define  _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include <stdio.h>


//int main()
//{
//	while (1)
//	{
//		Sleep(1000);
//		printf("he");
//	}
//	return 0;
//}



//int bin_search(int arr[], int left, int right, int key)//升序
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < key)//在中间的右边
//		{
//			left = mid;
//		}
//		else if (arr[mid] = key)
//		{
//			return mid;
//		}
//		else
//		{
//			right = mid;
//		}
//	}
//	return -1;
//}


//void print(int arr[],int k)
//{
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = 0;	
//		tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left++, right--;
//	}
//}
//void init(int arr[], int k)
//{
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		arr[i] = 0;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);//打印  前
//	reverse(arr, sz);//逆置
//	print(arr, sz);//打印  后
//	init(arr, sz);//初始化
//	print(arr, sz);//打印
//	return 0;
//}


//void biao(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	biao(n);
//	return 0;
//}


//int panduan(int n)
//{
//	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	while (scanf("%d", &year) != EOF)
//	{
//		int ret = panduan(year);
//		if (ret)
//		{
//			printf("%d年是闰年\n", year);
//		}
//		else
//		{
//			printf("%d年不是闰年\n", year);
//		}
//	}
//	return 0;
//}


//int is_prime(int num) 
//{
//    if (num <= 1)
//    {
//        return 0;
//    }
//    for (int i = 2; i * i <= num; i++) 
//    {
//        if (num % i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main() {
//    for (int i = 100; i <= 200; i++) 
//    {
//        if (is_prime(i))
//        {
//            printf("%d  ", i);
//        }
//    }
//    return 0;
//}
