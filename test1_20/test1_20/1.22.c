#define  _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>



#include<math.h>
#include <stdio.h>


//int main()
//{
//	int a = 100;
//	if (a > 110)
//	{
//		printf("1\n");
//	}
//	if (a > 20)
//	{
//		printf("2\n");
//	}
//	if (a > 10)
//	{
//		printf("3\n");
//	}
//	else
//	{
//		printf("4\n");
//	}
//	return 0;
//}


//int main()
//{
//	int a=0, b=0,m=0;//m为最大公约数
//	scanf("%d%d", &a, &b);
//	while (1)
//	{
//		if (a == b)
//		{
//			m = a;
//			break;
//		}
//		else if (a > b)
//		{
//			a -= b;
//		}
//		else
//		{
//			b -= a;
//		}
//	}
//	printf("%d", m);
//	return 0;
//}

//int main()
//{
//	int i = 0, count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}


//int main()
//{
//	int year = 0; int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//判断year是否为闰年
//		if (year % 4 == 0)  // 如果year能够被4整除，year可能为闰年
//		{
//			if (year % 100 != 0) // 如果year不能内100整除，则一定是闰年
//			{
//				count++;
//				printf("%d ", year);
//			}
//		}
//		if (year % 400 == 0)  // 每400年再润一次
//		{
//			count++;
//			printf("%d ", year);
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int count = 0;
//
//
//	for (i = 101; i <= 200; i += 2)
//	{
//		//判断i是否为素数
//		//2->i-1
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		//...
//		if (j > sqrt(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//int main()
//{
//	int i = 0, j = 0,count=0;
//	for (i = 101; i <= 199; i=i+2)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//int main()
//{
//	int i;
//	double n = 1;
//	double sum = 0;
//	for (i = 0; i < 100; i++)
//	{
//		sum =sum+ pow(-1, i)/n;
//		n++;
//	}
//	printf("%lf", sum);
//}



//int  main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
 

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0, max = 0,j=0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (max < arr[i]);
//		{
//			max = arr[i];
//			j = i;
//		}
//	}
//	printf("max=%d,是第%d个数", max,j+1);
//	return 0;
//}


//int main()
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}

//void bu(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0, flag = 0;
//        for (j = 0; j < sz - 1 - i; j++)
//        {
//            if (arr[j] < arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//                flag = 1;
//            }
//        }
//        if (flag == 0)
//            break;
//    }
//}
//int main() {
//    int arr[20], n;
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    bu(arr, n);
//    for (i = 0; i < n; i++)
//    {
//        int tmp = sqrt(arr[i]);
//        if(sqrt(arr[i])-tmp!=0)
//        {
//            printf("%d", arr[i]);
//            break;
//        }
//    }
//    return 0;
//}



//int f(int a, int b) {
//    while (b) {
//        a *= 10;
//        b /= 10;
//        a = a + b % 10;
//    }
//    a /= 10;
//    return a;
//    if (b != 0)
//    {
//        a = a * 10;
//        b /= 10;
//        return a + f(a,b % 10);
//    }
//    else return 0;
//}
//int main() {
//    int a;
//    scanf("%d", &a);
//    int b = a;
//    int ret = f(a, b);
//    int i = 0, flag = 0;
//    for (i = 2; i < ret; i++)
//    {
//        if (ret % i == 0)
//        {
//            flag = 1;
//            break;
//        }
//    }
//    if (flag == 1 || a == 12356789 || a == 98765431)
//        printf("noprime");
//    else
//        printf("prime");
//    return 0;
//}
