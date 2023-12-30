#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void hanio(int n, char a, char b, char c)
//{
//	if (n == 1)
//		printf("%c-->%c\n", a, b);
//	else
//	{
//		hanio(n - 1, a, c, b);
//		printf("%c-->%c\n", a, b);
//		hanio(n - 1, c, b, a);
//	}
//}
//int main()
//{
//	int n;
//	printf("sss:");
//	scanf("%d", &n);
//	printf("ssw%der:\n", n);
//	hanio(n, 'a', 'b', 'c');
//	return 0;
//}

//int Fid(int n)
//{
//	int m = 0;
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	else
//	{
//		m = Fid(n - 1) + Fid(n - 2);
//		return m;
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret=Fid(n);
//	printf("%d", ret);
//	return 0;
//}