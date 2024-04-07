#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

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
	for (int i = 0; i < len - 1; i++)//����
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
		//����
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

//δ�Ż���--ϣ������
void shell_sort_1(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//���飬�����Ϊgap��Ϊһ�飬��gap����
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

//�Ż���--ϣ������

void shell_sort_2(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//ǰgap��ȫ��Ϊһ��
		gap = gap / 3 + 1;//���飬�����Ϊgap��Ϊһ�飬��gap����
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
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
	}

	int begin1 = clock();
	Insertion_sort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	Bubble_sort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	Select_sort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	shell_sort_2(a4, N);
	int end4 = clock();

	printf("Insertion_sort:%d\n", end1 - begin1);
	printf("Bubble_sort:%d\n", end2 - begin2);
	printf("Select_sort:%d\n", end3 - begin3);
	printf("shell_sort_2:%d\n", end4 - begin4);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
}

int main()
{
	//int a[] = { 9,5,1,3,7,6,4,0,2,8 };
	//int len = sizeof(a) / sizeof(a[0]);
	//��������
	//Insertion_sort(a, len);
	 
	// ð������
	//Bubble_sort(a, len);

	//ѡ������
	//ѡ������Ҳ�м�ѡ��������ÿһ������ʱ���ҵ���Сֵ��
	// �������һ��ֵ���н�����ð��������ÿһ�˽��������ҵ����ֵ�������㷨��������
	//Select_sort(a, len);

	//ϣ������
	//shell_sort_1(a, len);
	//shell_sort_2(a, len);
	//print_(a, len);

	//����Ч��
	TestOP();
	return 0;
}