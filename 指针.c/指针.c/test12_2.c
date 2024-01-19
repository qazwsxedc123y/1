#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//利用指针打印数组内容   倒序
//
//int main()
//{
//    int arr[50];
//    int i = 0;
//    do {
//        scanf("%d", &arr[i]);
//        i++;
//    } while (getchar() != '\n' && i < 50);
//    int sz = i;
//    int* p = &arr[i-1];
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ",*(p-i));
//    }
//    return 0;
//}




//指针数组----  数组（存放指针的数组）
//数组指针----  指针（存放数组的指针）

//指针数组
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}


//二维指针

//int main()
//{
//	int a = 10;
//	int* p = &a; //p自己本身的地址与a不同。p是一个指针变量，其值是a的地址，而不是a本身的地址。
////	*表示p为指针  而int表示其所指向的对象的类型为int
//	int* *  ppa = &p;//ppa就是一个二级指针
////     第二个*表示ppa为指针   int*表示ppa所指向的对象为int*
////	*ppa//表示的是pa的值    *pa表示的是a的值
//		//   所以**ppa表示的是a的值
//		printf("%d\n", p);
//		printf("%d\n", *p);
//		printf("%d\n", *ppa);
//		printf("%d\n", **ppa);
//	return 0;
//}



//  指针改变数组的值

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//		printf("%d ==== %d\n", *(p + i), arr[i]);
//	}
//
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%p  ====   %p\n", &arr[i], p + i);
//	}*/
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n",arr);//3064  3104
//	printf("%p\n", &arr+1);//1.  &数组名中数组名表示整个数组
// //2.  strlen中数组名也是表示整个数组
//	return 0;
//}




//指针方法  （指针-指针）
//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}



//递归方法
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len=%d", len);
//	return 0;
//}


//指针-整数   正确写法
//int main()
//{
//	int a = 5;
//	float arr[5];
//	float* vp;
//	for (vp = &arr[5]; vp > &arr[0];)
//		*--vp = 0;
//	for (int i = 0; i < 5; i++)
//		{
//			printf("%d ", arr[i]);
//	    }
//	return 0;
//}

//错误写法  不符合语法但可以跑 

//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，
// 但是不允许与指向第一个元素之前的那个内存位置的指针进行比较

//int main()
//{
//	int a = 5;
//	float arr[5];
//	float* vp;
//	for (vp = &arr[5 - 1]; vp >= &arr[0]; vp--)
//		*vp = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//指针+整数
//int main()
//{
//	int a = 5;
//	float arr[5];
//	float* vp;
//	for (vp = &arr[0]; vp < &arr[5];)
//	{
//		*vp++ = 0;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int* p = &arr[9];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p);
//		p=p-2;
//	}
//}


//指针-指针（地址-地址）
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	printf("%d\n", &arr[9] - &arr[0]);//9
//	printf("%d\n", &arr[0] - &arr[9]);//-9
//	return 0;
//}


//指针类型

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	char* p = arr;
//	for (i = 0; i < 10; i++)
//	{	
//		*(p + i) = 1;
//	}
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}



//int main()
//{
//	//p  是指针变量用来存放地址  int*为指针的类型
//	int a = 0x12542134;
//	int* p = &a;
//	char* pa = &a;
////printf("%p\n", *pa); 将会打印指针pa所指向的地址的值 printf("%p\n", pa); 将会打印指针pa本身的地址值
//
////	指针类型决定了指针进行解引用操作的时候能够访问空间的大小
//// 	   也决定了指针走一步的大小（即加一后向后偏移了几个字节
////  int *  可以访问四个字节
////  char * 可以访问一个字节
////  double *  可以访问八个字节
//	printf("%p\n", p);
//	printf("%p\n", pa);
//	*p = 0;
//	*pa = 0;
//	printf("%0x\n", *p);
//	printf("%0x\n", *pa);
//	return 0;
//}