#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main()
{
	// ���ö��ַ��ҵ���Ϊ5���±�
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int left = 0;
    int right = 10 - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;  // �����м�λ��

        // ����м�Ԫ��
        if (arr[mid] == 5) {
            return mid;  // �ҵ�Ŀ��ֵ�������±�
        }
        else if (arr[mid] < 5) {
            left = mid + 1;  // ���Ŀ��ֵ�����м�Ԫ�أ�������벿��
        }
        else {
            right = mid - 1;  // ���Ŀ��ֵС���м�Ԫ�أ������Ұ벿��
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