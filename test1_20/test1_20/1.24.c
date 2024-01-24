#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>



//左旋字符




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

void revsrse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left<right)//left 与   right  存的是地址
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void mov(char* arr, int k)
{
	assert(arr != NULL);
	int len = strlen(arr);
	assert(k <= len);
	revsrse(arr,arr+k-1);//逆序左边
	revsrse(arr+k,arr+len-1);//逆序右边
	revsrse(arr,arr+len-1);//逆序全部	
}
int main()
{
	char arr[] = "abcdef";
	mov(arr, 2);
	printf("%s\n", arr);
	return 0;
}


//int main()
//{
//	char* arr[5] = { "asdcd","ab" };//这个数组的元素可以通过下标来访问，
// 例如arr[0]将返回指向字符串"asdcd"的指针。请注意，这个数组的元素是指向字符的指针，
// //而不是字符数组。如果你想要一个字符数组的数组，你可以使用以下声明：
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[10] = { 0,9,8,7,6,5,4,3,2,1 };
//	printf("修改前：\n");
//	printf("arr1:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	printf("修改后：\n");
//	printf("arr1:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	double sum = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum += arr[i];
//	}
//	printf("平均值为：%.2lf", sum / 10);
//}


//int main() {
//    int n = 0, m = 0;
//    int arr[10][10];
//    int i = 0, j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (j = 0; j < m; j++)
//    {
//        for (i = 0.; i < n; i++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer=%c\n", killer);
//		}
//	}
//	return 0;
//}


//int f(int a,int empty,int s)
//{
//	s += a;//s为一共喝了多少
//	empty += a;//空瓶数
//	a = empty / 2;//换完后又有了a瓶  去换
//	empty = empty - a * 2;//空瓶  喝完后
//	if (empty >= 2||a!=0)
//	{
//		return f(a, empty, s);
//	}
//	else
//		return s;
//}
//int main()
//{
//	int a = 0,empty=0,s=0;
//	scanf("%d", &a);
//	int sum = f(a,empty,s);
//	printf("%d", sum);
//	return 0;
//}