#define  _CRT_SECURE_NO_WARNINGS
#include "SL.h"


int main()
{
	SL* SLList=NULL;
	SLPushFront(&SLList, 5);
	SLPushback(&SLList,1);
	SLPushback(&SLList,2);
	SLPushback(&SLList,3);
	SLPushback(&SLList,4);
	SLPrint(SLList);

	SLPopBack(&SLList);
	SLPrint(SLList);

	SLPopFront(&SLList);
	SLPrint(SLList);
	return 0;
}

//int main()
//{
//	int* p = 0x11221122;
//	int** ps = &p;
//	int* pr = &p;
//	*pr = 0x11111133;
//	return 0;
//}


//void test(int* p)
//{
//	
//}
//int main()
//{
//	int* p;
//	test(p);
//	return 0;
//}


//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int del(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("*****************************\n");
//	printf("****  1. add    2. sub   ****\n");
//	printf("****  3. mul    4. del   ****\n");
//	printf("****  0. exit            ****\n");
//	printf("*****************************\n");
//}
//void cacl(int (*pf) (int, int))
//{
//	int x, y, ret;
//	printf("请输入两个操作数：");
//	scanf("%d%d", &x, &y);
//	ret = pf(x, y);
//	printf("%d\n", ret);
//}
//int main()
//{
//	int input;
//	do {
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			cacl(add);
//			break;
//		case 2:
//			cacl(sub);
//			break;
//		case 3:
//			cacl(mul);
//			break;
//		case 4:
//			cacl(del);
//			break;
//		}
//	} while (input);
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	printf("请输入三角的大小:>");
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	int arr[100][100];
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//A说：不是我。
//
//B说：是C。
//
//C说：是D。
//
//D说：C在胡说
//
//已知3个人说了真话，1个人说的是假话。
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		char killer = 'A';
//		killer += i;
//		if ((killer != 'A')+(killer=='C')+(killer=='D')+(killer!='D')==3)
//		{
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}

//int search(int p[5][5], int x, int y,int k)//x为行  y为列
//{
//	int i = y;
//	while (y >=0 && x <=i)
//	{
//		if (p[x][y] < k)
//		{
//			x++;
//		}
//		else if (p[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{10,11,12,18,19} };
//	int x = sizeof(arr) / sizeof(arr[0]);
//	x -= 1;
//	int k = 0;
//	printf("请输入要查找的数：>");
//	scanf("%d", &k);
//	printf("\n");
//	int ret=search(arr, 0, x,k);
//	//返回1  找到了
//	// 0  没有
//	if (ret == 1)
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("没有\n");
//	}
//	return 0;
//}



//int isRotation(char* s1, char* s2) 
//{
//    int len1 = strlen(s1);
//    int len2 = strlen(s2);
//    if (len1 != len2) 
//    {
//        return 0;
//    }
//    char temp[1000];
//    strcpy(temp, s1);
//    strcat(temp, s1);
//    if (strstr(temp, s2) != NULL) 
//    {
//        return 1;
//    }
//    else 
//    {
//        return 0;
//    }
//}
//int main() 
//{
//    char s1[] = "AABCD";
//    char s2[] = "BCDAA";
//    if (isRotation(s1, s2)) 
//    {
//        printf("1\n");
//    }
//    else 
//    {
//        printf("0\n");
//    }
//    return 0;
//}


//void my_sort(int* p, int x, int y)
//{
//	while (1)
//	{
//		int left = x;
//		int right = y - 1;
//		while (p[right] % 2 == 0)//是偶
//		{
//			right--;
//		}
//		while (p[left] % 2 != 0)
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			int tmp = p[left];
//			p[left] = p[right];
//			p[right] = tmp;
//		}
//		else
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_sort(arr,0,sz);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int my_strlen(char* p)
//{
//	int ret = 0;
//	while (*p++ != '\0')
//	{
//		ret++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "asdfgh";
//	int ret=my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


//void bubble_sort(int arr[], int sz)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 0;
//		for (j = 0; j < sz - 1 - i; j++)
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
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);	
//	bubble_sort(arr, sz);
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}