#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
//暴力求解法
//void mov(char * arr, int k)
//{
//  assert(arr!=NULL);
//	int i = 0,j=0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;
//		//左旋转一个字符
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		*(arr + len - 1) = tmp;
//	}
//}

//三步翻转法
//ab cdef
//ba  fedc
//bafedc
//cdefab


//void revsrse(char* left, char* right)
//{
//	while (left < right)//left 与   right  存的是地址
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void mov(char* arr, int k)
//{
//	int len = strlen(arr);
//	revsrse(arr, arr + k - 1);//逆序左边
//	revsrse(arr + k, arr + len - 1);//逆序右边
//	revsrse(arr, arr + len - 1);//逆序全部	
//}
//int main()
//{
//	char arr[] = "abcdef";
//	mov(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}



//int main()
//{
//    unsigned long pulArray[] = { 6,7,8,9,10 };
//    unsigned long* pulPtr;
//    pulPtr = pulArray;//6
//    *(pulPtr + 3) += 3;//12
//    printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//    return 0;//       12        
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0,tmp=0;
//	for (i = 0; i < sz; i++)
//	{
//		tmp^=arr[i];
//	}
//	printf("%d", tmp);
//	return 0;
//}
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
//int test(int m,int n)
//{
//	int count = 0, i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((m ^ n) & 1) == 0)//一样
//		{
//			
//		}
//		else
//			count++;
//		m >>= 1;
//		n >>= 1;
//	}
//	return count;
//}
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	int count=test(m, n);
//	printf("%d", count);
//	return 0;
//}
//void test(int n)
//{
//	int i = 32;
//	printf("奇数序列：\n");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n偶数序列：\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	test(n);
//
//	return 0;
//}
//int t(int p)
//{
//	int i = 32;
//	int count = 0;
//	while (i--)
//	{
//		int tmp = p & 1;
//		if (tmp == 1)
//		{
//			count++;
//		}
//		p = p >> 1;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count=t(a);
//	printf("%d", count);
//	return 0;
//}
//void test(int* p1, int* p2)
//{
//	*p1 = *p1 ^ *p2;
//	*p2 = *p1 ^ *p2;
//	*p1 = *p1 ^ *p2;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	test(&a,&b);
//	printf("a=%d  b=%d", a, b);
//	return 0;
//}
//10000101  原码
//11111010  反码
//11111011
//00001001--9
//00000011--3
//00001010--2+8
//00001100--12
//00000101--5
//00000100