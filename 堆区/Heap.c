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

void adjustment_prev(Hp* php,int child)//降的排序   小堆
{
	assert("php");
	assert(!HeapEmpty(php));
	int parent = (child - 1) / 2;
	while (parent>=0)
	{
		if (php->a[child] < php->a[parent])//调换
		{
			swap(&php->a[child], &php->a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//不交换
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
	//为空 即为真  返回非零
	//不为空             0
}

HpDataType HeapTop(Hp* php)
{
	assert(!HeapEmpty(php));
	assert("php");
	return php->a[0];
}

void adjustment_down(Hp* php,int n,int parent )
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1 < php->_size) && (php->a[child] > php->a[child + 1]))
		{
			child++;
		}
		if (php->a[child] < php->a[parent])
		{
			swap(&php->a[child], &php->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Hp* php)//删去头节点
{
	assert("php");
	// 先将头与尾交换，然后删去尾，在调整
	swap(&php->a[0], &php->a[php->_size - 1]);
	php->_size--;
	adjustment_down(php,php->_size,0);
}
//o(n*logN)
void HeapSort(Hp* php, int n)
{
	//升序  大堆
	//降序  小堆

	//此为降序
	//小堆  先向上调整
	for (int i = 0; i < n; i++)
	{
		adjustment_prev(php, i);
	}
	int end = n - 1;
	while (end>0)
	{
		swap(&php->a[0], &php->a[end]);
		end--;
		adjustment_down(php, end, 0);

	}
}