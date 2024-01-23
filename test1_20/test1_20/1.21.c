#define  _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include<stdlib.h>
//
//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//    int ar1[100], ar2[100];
//    int i = 0, j = 0, sum1 = 0, sum2 = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &ar1[i]);
//        sum1 += ar1[i];
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d", &ar2[i]);
//        sum2 += ar2[i];
//    }
//    int min = 1000, x=0, y=0;//x为左边界  y为右边界
//    for (i = 0; i < m; i++)//起始位置
//    {
//        int sum=sum2,t=0;
//        for (t = 0; t < i; t++)
//        {
//            sum -= ar2[t];
//        }
//        for (j = m - 1; j > i; j--)//从后向前
//        {
//            if (min > abs(sum - sum1))
//            {
//                min = abs(sum - sum1);
//                x = i;
//                y = j;
//            }
//            sum -= ar2[j];
//        }
//    }
//    int p = 0;
//    for (p = x; p <= y; p++)
//    {
//        printf("%d ", ar2[p]);
//    }
//    return 0;
//}

//int main()
//{
//	int i = 0,count=0;
//	for (i = 1; i <= 100; i++)
//	{
//		int j = i;
//		while (j)
//		{
//			if (j % 10 == 9)
//			{
//				count++;
//			}
//			j /= 10;
//		}
//	}
//	printf("一共有=%d ", count);
//}



//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}



//int main()
//{
//	int i = 0,count=0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)//判断是否被3整除
//		{
//			printf("%d ", i);
//			count++;//计算几个
//		}
//	}
//	printf("\n%d", count);
//}

//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;
//	b = ++c, c++, ++a, a++;
//	b += a++ + c;
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}