#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main()
{
	// 利用二分法找到数为5的下标
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int left = 0;
    int right = 10 - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;  // 计算中间位置

        // 检查中间元素
        if (arr[mid] == 5) {
            return mid;  // 找到目标值，返回下标
        }
        else if (arr[mid] < 5) {
            left = mid + 1;  // 如果目标值大于中间元素，忽略左半部分
        }
        else {
            right = mid - 1;  // 如果目标值小于中间元素，忽略右半部分
        }
    }
    printf("%d ",mid);
	return 0;
}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };// n
//	int n = 10;// 
//	int k = 5;// 
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - k; j++)
//		{
//			printf("%d ",arr[j]);
//		}
//		printf("\n");
//		k--;
//	}
//	return 0;
//}