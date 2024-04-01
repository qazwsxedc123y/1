#define  _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

void HeapInit(Hp* php)
{
	assert("php");
	php->a = NULL;
	php->_size = 0;
	php->_capacity = 0;
}

void HeapDestroy(Hp* php)
{
	assert("php");
	free(php->a);
	php->_size = 0;
	php->_capacity = 0;
}

void Check_capacity(Hp* php)
{
	assert("php");
	if (php->_capacity == php->_capacity)
	{
		int newcapacity = php->_capacity == 0 ? 4 : php->_capacity * 2;		
		HpDataType* tmp = (HpDataType*)realloc(php->a,sizeof(HpDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->_capacity = newcapacity;
		return;
	}
	else
	{
		return;
	}
}

void swap(HpDataType*p1, HpDataType*p2)
{
	HpDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void adjustment_prev(Hp* php,int child)//��������   С��
{
	assert("php");
	assert(!HeapEmpty(php));
	int parent = (child - 1) / 2;
	while (parent>=0)
	{
		if (php->a[child] < php->a[parent])//����
		{
			swap(&php->a[child], &php->a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//������
			break;
		}
	}
}
void Heappush(Hp* php, HpDataType x)
{
	assert("php");
	Check_capacity(php);
	php->a[php->_size] = x;
	php->_size++;
	adjustment_prev(php, php->_size - 1);
}

void Heapprint(Hp* php)
{
	assert("php");
	for (int i = 0; i < php->_size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

int HeapSize(Hp* php)
{
	assert(!HeapEmpty(php));
	assert("php");
	return php->_size;
}

int HeapEmpty(Hp* php)
{
	assert("php");
	return php->_size == 0;
	//Ϊ�� ��Ϊ��  ���ط���
	//��Ϊ��             0
}

HpDataType HeapTop(Hp* php)
{
	assert(!HeapEmpty(php));
	assert("php");
	return php->a[0];
}

void adjustment_down(HpDataType* a,int n,int parent )
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1 < n) && (a[child] > a[child + 1]))
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
void HeapPop(Hp* php)//ɾȥͷ�ڵ�
{
	assert("php");
	// �Ƚ�ͷ��β������Ȼ��ɾȥβ���ڵ���
	swap(&php->a[0], &php->a[php->_size - 1]);
	php->_size--;
	adjustment_down(php->a,php->_size,0);
}
//o(n*logN)
void HeapSort(Hp* php, int n)
{
	//����  ���
	//����  С��

	//��Ϊ����
	//С��  �����ϵ���
	for (int i = (n-1-1)/2; i >=0; i--)
	{
		adjustment_down(php->a,n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		swap(&php->a[0], &php->a[end]);
		end--;
		adjustment_down(php->a, end, 0);

	}
}

void CreateNdata()
{
	int n = 100000;//ʮ�����ڵ���
	srand(time(0));
	FILE* fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopne fail");
		return;
	}
	for (size_t i = 0; i < 1000; i++)
	{
		int x = rand() % n;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

//ȡ������ǰk��������С�ѵ���ʽ��ӡ
void Top_k(int k)
{
	//���ļ�
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopne fail");
		return;
	}
	int* kimheap = (int*)malloc(sizeof(int) * k);
	if (kimheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	//�ȶ�ȡǰk������
	int tmp;
	for (size_t i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kimheap[i]);

	}
	//���µ������γ�С��
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		adjustment_down(kimheap, k, 0);
	}
	//������ȡ������ͷ�Ƚ�
	while (!feof(fout))
	{
		fscanf(fout, "%d", &tmp);
		if (tmp > kimheap[0])
		{
			kimheap[0] = tmp;
			adjustment_down(kimheap, k, 0);
		}
	}
	for (size_t i = 0; i < k; i++)
	{
		printf("%d ", kimheap[i]);
	}
	printf("\n");
	fclose(fout);
}