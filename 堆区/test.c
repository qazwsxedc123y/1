#define  _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

void test(Hp* php)
{
	HeapInit(php);
	Heappush(php, 20);
	Heappush(php, 10);
	Heappush(php, 15);
	//Heappush(php, 30);
	//Heappush(php, 40);
	//Heappush(php, 45);
	Heapprint(php);
	HeapPop(php);
	HeapPop(php);
	Heapprint(php);
	HeapDestroy(php);

}
void test1(Hp* php)
{
	HeapInit(php);
	int arr[] = { 50,20,30,35,15,40,10 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		Heappush(php, arr[i]);
	}
	HeapSort(php, php->_size);
	Heapprint(php);
}

void test_top_k()
{
	CreateNdata();
	Top_k(5);
}
int main()
{
	Hp hp;
	//test1(&hp);
	//test(&hp);
	test_top_k();
	return 0;
}