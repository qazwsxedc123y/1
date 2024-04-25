#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int part(int* a, int left, int right)
{
	//���ﲻ����ָ�룬�����±���ʣ��������Ȥ�Ļ������Գ���ָ��д��
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left<right && a[left] <= a[key])//ǰһ����Ϊ�˷�ֹ�����ڴ�while�Ѿ�����������
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
	return left;
}
void Hoare_sort(int* a, int left, int right)
{
	if(left >= right)
	{
		return;
	}
	int key = part(a, left, right);
	Hoare_sort(a, left, key - 1);
	Hoare_sort(a, key + 1, right);
	return ;
}
int part_2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
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
	return left;//���ش�ʱkeyi���±���
}
void Hole_sort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = part_2(a, left, right);
	Hole_sort(a, left, key - 1);
	Hole_sort(a, key + 1, right);
}
void Insertion_sort(int* a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int end = i;
		int tmp = a[i + 1];
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
void Select_sort(int* a, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int min = left;
		for (int i = left; i <= right; i++)
		{
			if (a[min] > a[i])
			{
				min = i;
			}
		}
		//����
		swap(&a[min], &a[left]);
		left++;
	}
}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;//(begin+end)>>1;
	//[left,mid],[mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//��������
	int i = left;
	//���п���

	int begin1 = left, begin2 = mid + 1;
	int end1 = mid, end2 = right;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])//ѡ1��
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//����˭�Ƚ������ٽ�ʣ�µĿ�����ȥ

	if (begin1 > end1)//1�Ƚ���  2û����
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

	//����󿽱���ȥ

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
}
void print_(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 9,5,1,3,7,4,6,0,8,2 };
	//Hoare_sort(arr, 0, 9);//������9��0
	//Hole_sort(arr, 0, 9);
	//insert(arr, 10);
	//Select_sort(arr, 10);
	MergeSort(arr, 10);
	print_(arr, 10);
	return 0;
}