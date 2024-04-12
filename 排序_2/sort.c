#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"SLlist.h"

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void Insertion_sort(int* a,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int end = i;
		int tmp = a[i+1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
}
void  Bubble_sort(int* a, int len)
{
	for (int i = 0; i < len - 1; i++)//趟数
	{
		int count = 0;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
void Select_sort(int* a, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)
		{
			if (a[min] > a[i])
			{
				min = i;
			}
			if (a[max] < a[i])
			{
				max = i;
			}
		}
		//交换
		if (max == left)
		{
			max = min;
		}
		swap(&a[min], &a[left]);
		swap(&a[max], &a[right]);
		left++;
		right--;
	}
}

//未优化版--希尔排序
void shell_sort_1(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//分组，将间隔为gap分为一组，共gap个组
		for (int i = 0; i < gap; i++)
		{
			for (int j = i; j < n - gap; j += gap)
			{
				int end = j;
				int tmp = a[end+gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//优化版--希尔排序

void shell_sort_2(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//前gap个全不为一组
		gap = gap / 3 + 1;//分组，将间隔为gap分为一组，共gap个组
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Adjust_Down(int* a, int parent,int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Heap_sort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		Adjust_Down(a, i, n);//传的为父亲
	}
}

//快速排序

//调整key为 left，right，mid 三个中的中间值

int Get_key_Index(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[right])
	{
		if (a[left] > a[mid])
		{
			return left;
		}
		else if (a[right] < a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else if(a[left]==a[right])
	{
		return left;
	}
	else
	{
		if (a[right] > a[mid])
		{
			return right;
		}
		else if (a[left] < a[mid])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
}

//快速排序
//Hoare版

int part_1_sort(int* a, int left, int right)
{
	int midi = Get_key_Index(a,left,right);	
	swap(&a[midi], &a[left]);
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[keyi] <= a[right])
		{
			right--;
		}
		while (left<right && a[keyi] >= a[left])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[keyi]);
	return left;//返回此时keyi的下标数
}
void Quick_sort_Hoare(int* a,int begin,int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = part_1_sort(a, begin, end);
	//三个区间  [begin,keyi-1]  keyi  [keyi+1,end]
	Quick_sort_Hoare(a, begin, keyi - 1);
	Quick_sort_Hoare(a, keyi + 1, end);
}

//快速排序
//挖坑版

int part_2_sort(int* a, int left, int right)
{
	int midi = Get_key_Index(a, left, right);
	swap(&a[midi], &a[left]);
	int key = a[left];
	int hole = left;//下标
	while (left < right)
	{
		while (left < right && key <= a[right])
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && key >= a[left])
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return left;//返回此时keyi的下标数
}
void Quick_sort_Hole(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyi = part_2_sort(a, begin, end);
	//三个区间  [begin,keyi-1]  keyi  [keyi+1,end]
	Quick_sort_Hole(a, begin, keyi - 1);
	Quick_sort_Hole(a, keyi + 1, end);
}

//快速排序
//双指针版
int part_3_sort(int* a,int left,int right)
{
	int midi = Get_key_Index(a, left, right);
	swap(&a[midi], &a[left]);
	int keyi =left;
	int cur = left+1;
	int prev = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)		
		{
			prev++;
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}
void Quick_sort_Pointer_item(int* a, int begin, int end)
{
	part_3_sort(a, begin, end);
}

//快速排序
//栈区实现

void Quick_sort_stack(int* a, int begin, int end)
{
	//采用非递归实现
	//存下标
	//先制造出栈再初始化
	ST st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);
	while (!StackEmpty(&st))//不为空
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right= StackTop(&st);
		StackPop(&st);
		int keyi = part_1_sort(a, left, right);//返回keyi//进行为第二次做准备
		if (keyi + 1 < right)//右区间存在,进栈
		{
			StackPush(&st, right);
			StackPush(&st, keyi+1);
		}
		if (left < keyi - 1)
		{
			StackPush(&st, keyi-1);
			StackPush(&st, left);
		}
	}
}

void _MergeSort(int* a,int left,int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;//(begin+end)>>1;
	//[left,mid],[mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//排完序了
	int i = left;
	//进行拷贝

	int begin1 = left, begin2 = mid + 1;
	int end1 = mid, end2 = right;
	while (begin1<=end1&&begin2<=end2)
	{
		if (a[begin1] < a[begin2])//选1进
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//不管谁先结束，再将剩下的拷贝进去

	if (begin1 > end1)//1先结束  2没结束
	{
		while (begin2 <= end2)
		{
			tmp[i++] = a[begin2++];
		}
	}
	else
	{
		while (begin1 <= end1)
		{
			tmp[i++] = a[begin1++];
		}
	}

	//再最后拷贝回去

	memcpy(a+left, tmp+left, sizeof(int)*(right-left+1));
}

void MergeSort(int* a, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort(a, 0, n-1,tmp);

}

//归并排序--非递归实现

void _MergeSort_non(int* a, int left, int right, int* tmp)
{
	int gap = 1;//每组的大小
	int n = right + 1;
	while (gap < n)
	{
		for (int i = 0; i <= right; i += gap * 2)
		{
			int j = i;
			int begin1 = i,begin2= i + gap;
			int end1 = i + gap - 1, end2 = i + 2 * gap - 1;

			//printf("[%d,%d][%d,%d]\n", begin1, endl, begin2, end2);

			//修正区间--防止越界
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//进行区间排序--两个组合并排序，先排好序进去到tmp中，再拷贝回去
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] > a[begin2])//2进去
				{
					tmp[j++] = a[begin2++];
				}
				else
				{
					tmp[j++] = a[begin1++];
				}
			}
			//不管谁先结束，再将剩下的拷贝进去

			if (begin1 > end1)//1先结束  2没结束
			{
				while (begin2 <= end2)
				{
					tmp[j++] = a[begin2++];
				}
			}
			else
			{
				while (begin1 <= end1)
				{
					tmp[j++] = a[begin1++];
				}
			}

			//再从tmp拷回去

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
}
void MergeSort_non(int* a, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort_non(a, 0, n - 1, tmp);
}

//计数排序

void Count_Sort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min) 
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int* )malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min] ++;//存的值大小为a[i]
	}
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
}

void print_(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);
	int* a9 = (int*)malloc(sizeof(int) * N);
	int* a10 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
		a10[i] = a1[i];
	}

	int begin1 = clock();
	//Insertion_sort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//Bubble_sort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//Select_sort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	shell_sort_2(a4, N);
	int end4 = clock();

	int begin5 = clock();
	Heap_sort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	Quick_sort_Hoare(a6, 0,N-1);
	int end6 = clock();

	int begin7 = clock();
	Quick_sort_Hole(a7, 0, N - 1);
	int end7 = clock();

	int begin8 = clock();
	MergeSort(a8, N);
	int end8 = clock();

	int begin9 = clock();
	MergeSort_non(a9, N);
	int end9 = clock();
	
	int begin10 = clock();
	Count_Sort(a10, N);
	int end10 = clock();

	printf("Insertion_sort:%d\n", end1 - begin1);
	printf("Bubble_sort:%d\n", end2 - begin2);
	printf("Select_sort:%d\n", end3 - begin3);
	printf("shell_sort_2:%d\n", end4 - begin4);
	printf("Heap_sort:%d\n", end5 - begin5);
	printf("Quick_sort_Hoare:%d\n", end6 - begin6);
	printf("Quick_sort_Hole:%d\n", end7 - begin7);
	printf("MergeSort:%d\n", end8 - begin8);
	printf("MergeSort_non:%d\n", end9 - begin9);
	printf("Count_Sort:%d\n", end10 - begin10);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
	free(a10);
}

int main()
{
	int a[] = { 9,0,1,3,7,6,4,10,2,5 };
	int len = sizeof(a) / sizeof(a[0]);
	//插入排序
	//Insertion_sort(a, len); 
	 
	// 冒泡排序
	//Bubble_sort(a, len);

	//选择排序
	//选择排序也叫简单选择排序，在每一趟排序时，找到最小值，
	// 将其与第一个值进行交换，冒泡排序是每一趟结束后能找到最大值，两种算法有相似性
	//Select_sort(a, len);

	//希尔排序
	//shell_sort_1(a, len);
	//shell_sort_2(a, len);
	
	// 堆排序
	//Heap_sort(a, len);

	//快速排序--hoare版
	//int mid=Get_key_Index(a, 0, len - 1);
	
	//Quick_sort_Hoare(a, 0, len - 1);

	//快速排序--挖坑版
	//Quick_sort_Hole(a, 0, len - 1);

	//快速排序--双指针
	//Quick_sort_Pointer_item(a, 0, len - 1);

	//快速排序
    //栈区实现

	//Quick_sort_stack(a, 0, len - 1);

	//归并排序

	//MergeSort(a, len);

	//归并排序--非递归
	//MergeSort_non(a, len);

	//计数排序
	//Count_Sort(a, len);

	//print_(a, len);

	//测试效率
	TestOP();
	return 0;
}