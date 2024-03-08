#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>



//char* my_strcat(char* strDestination, const char* strSource)
//{
//	char* ret = strDestination;
//	size_t sz = strlen(strDestination);
//	strDestination += sz;
//	while (*strSource != '\0')
//	{
//		*strDestination++ = *strSource++;
//	}
//	*strDestination = '\0';
//
//
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "aaaaaaa";
//	char arr2[] = "bbbb";
//	my_strcat(arr1, arr2);
//	return 0;
//}


//char* my_strcpy(char* strDestination, const char* strSource)
//{
//	char* ret = strDestination;
//	while (*strSource != '\0')
//	{
//		*strDestination++ = *strSource++;
//	}
//	*strDestination = '\0';
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "aaaaaaa";
//	char arr2[] = "bbbb";
//	my_strcpy(arr1, arr2);
//	return 0;
//}


//size_t my_strlen(const char* string)
//{
//	size_t count = 0;
//	while (*string++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t ret=my_strlen(arr);
//	printf("my_strlen=%zd\n", ret);
//	printf("strlen=%zd", strlen(arr));
//	return 0;
//}

//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}


//int is_leap_year(year)
//{
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        return 1;
//    else
//        return 0;
//}
//int main() {
//    int a, b;
//    while (scanf("%d%d", &a, &b) != EOF)
//    {
//        int ret = is_leap_year(a);
//        //是返回1 不是返回0
//        //1、3、5、7、8、10、12 每月31天，4、6、9、11为30天。
//        //2月正常为28天，如果为闰年，则多一天为29天。
//        switch (b)
//        {
//        case 1:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//        case 12:
//            printf("31");
//            break;
//        case 4:
//        case 6:
//        case 9:
//        case 11:
//            printf("30");
//            break;
//        case 2:
//            printf("%d", 28 + ret);
//            break;
//        default:
//            break;
//        }
//    }
//    return 0;
//}

//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int flag = 0;
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		if (arr[i] != arr[i + 1])
//		{
//			printf("%d ", arr[i]);
//		}
//		else
//			i++;
//	}
//	if (arr[sz - 2] != arr[sz - 1])
//		printf("%d ", arr[sz - 1]);
//	return 0;
//}