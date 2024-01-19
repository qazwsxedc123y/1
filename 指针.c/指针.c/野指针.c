#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



//
//int* test()
//{
//	 int a = 10;
//	return &a;
//}//当test()函数执行完毕后，a的内存空间会被释放
//
//int main()
//{
//	int* p = test();
//	*p = 20; //这会导致指针p指向的内存空间变为无效，这就是所谓的野指针
//	printf("%d", *p); 
//	return 0;
//}//虽然在某些情况下可能会输出20，但这并不是一种可靠的行为，
//因为这样的操作可能会导致程序崩溃或产生其他未定义的行为。因此，应该避免返回指向局部变量的指针



////指针越界  会报错
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		*p = 1;
//		p++;
//	}
//	for (i = 0; i < 12; i++)
//	printf("%d ", arr[i]);
//	return 0;
//}



//指针未初始化
//int main()
//{
//	int a;//局部变量不初始化，默认为随机值
//	int* p;
//	*p = 20;
//	printf("%d", *p);
//	return 0;
//}