#define  _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include<stdlib.h>
//#include<stdio.h>
//#include<stdbool.h>
#include"sltest.h"
void meun()
{
	printf("***************************\n");
	printf("******1. SLPushBack  ******\n");//后添加
	printf("******2. SLPushFront ******\n");//前添加
	printf("******3. SLPopBack   ******\n");//后删除
	printf("******4. SLPopFront  ******\n");//前删除
	printf("******5. SLErase     ******\n");//特定位置删除
	printf("******6. SLInSert  ******\n");//特定位置添加
	printf("******7. SLPrintf    ******\n");//打印
	printf("******    0. exit    ******\n");
	printf("***************************\n");
}

int main()
{
	SL s;
	SLInit(&s);
	int input;
	do{		
		meun();	
		scanf("%d", &input);
		switch (input)
		{
		case PushBack://1
			SLPushBack(&s, 1);
			break;
		case PushFront://2
			SLPushFront(&s, 2);
			break;
		case POPBACK://3
			SLPopBack(&s);
			break;
		case SLPRINTF://7
			SLprintf(&s);
			break;
		case EXIT:
			printf("退出成功\n");
			SLDestroy(&s);
			break;
		}
	} while (input);
	return 0;
}


//bool isValid(char* s) {
//    int len = strlen(s);
//    int i = 0;
//    for (i = 0; i < len - 1; i = i + 2)
//    {
//        if (s[i] != s[i + 1])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//	char s[] = "()";
//	int len = strlen(s);
//    isValid(s);
//	return 0;
//}

//int romanToInt(char* s) {
//    int len = strlen(s);
//    int i = 0;
//    int* a = (int*)malloc(sizeof(int*) * len);
//    int sum = 0;
//    for (i = 0; i < len; i++)
//    {
//        switch (s[i])
//        {
//        case 'I':
//            a[i] = 1;
//            break;
//        case 'V':
//            a[i] = 5;
//            break;
//        case 'X':
//            a[i] = 10;
//            break;
//        case 'L':
//            a[i] = 50;
//            break;
//        case 'C':
//            a[i] = 100;
//            break;
//        case 'D':
//            a[i] = 500;
//            break;
//        case 'M':
//            a[i] = 1000;
//            break;
//        defaule:
//            break;
//        }
//    }
//    for (i = 0; i < len; i = i + 2)
//    {
//        if (a[i] >= a[i + 1])
//        {
//            sum += a[i];
//        }
//        else
//        {
//            sum -= a[i];
//        }
//    }
//    return sum;
//}
//int main()
//{
//    char arr[] = "III";
//    romanToInt(arr);
//    return 0;
//}

//int main()
//{
//	char arr[] = {'a','b','c','d'};
//	char ar[] = "asdfgh";
//	int c = strlen(ar);
//	sizeof(arr);//sizeof不是函数
//	//strlen是c语言的库函数  专门计算字符串长度(\0之前) 不计算\0
//	return 0;
//}

//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++, buf2++;
//	}
//}
//int com(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void Bubble_sort(void* base,size_t num,size_t width,int (*com)(const void* e1, const void* e2))
//{
//	int j, i;
//	for (i = 0; i < num - 1; i++)
//	{
//		int count = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (com((char*)base + j * width, (char*)base + (j + 1) * width)>0)
//			{
//					swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}	
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble_sort(arr, sz, sizeof(arr[0]), com);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//struct stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//};
//int compare(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//int con_name(const void* e1, const void* e2)
//{
//	return (strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name));
//}//这里一定要记得强制类型转换
//int main()
//{
//	struct stu s[3] = { {"李四",20,"男"},{"王五",20,"男"} ,{"赵四",20,"男"} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]),compare);
//	int i = 0; 
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s %d %s\n", s[i].name, s[i].age, s[i].sex);
//	}
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