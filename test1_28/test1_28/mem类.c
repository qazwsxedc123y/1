#define  _CRT_SECURE_NO_WARNINGS

#include"ku.h"

//memcpy  ��ͷ�ļ���#include <string.h>

//struct  S
//{
//    char name[20];
//    int age;
//};
//void* my_memcpy(void* p1, const void* p2, int k)
////void���͵�ָ�벻�ܽ��н����ã�*��Ҳ���ܽ���++/--
//{
//    assert(p1 != NULL);
//    assert(p2 != NULL);
//    void* ret = p1;
//    while (k--)//��ʹ���ټ���
//    {
//        *(char*)p1 = *(char*)p2;
//        ++(char*)p1;
//        ++(char*)p2;
//    }
//    return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 5,6,7,8 };
//    struct S arr3[] = { {"����",20},{"����",30},{"����",10} };
//    struct S arr4[4] = { 0 };
//    my_memcpy(arr4, arr3, sizeof(arr3));
//	my_memcpy(arr1, arr2,sizeof(arr1));
//	return 0;
//}



//�����ص�����������  memmove

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr,arr+2,20);
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ",arr[i]);
	//}
//	return 0;
//}



//void* my_memmove(void* dest,const void* src,int k)
//{
//	assert(dest!=NULL);
//	assert(src!=NULL);
//	void* ret = dest;
//	if (dest < src)
//	{	
//		while (k--)//��ʹ���ټ���
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		while (k--)
//		{
//			*((char*)dest + k) = *((char*)src+k);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	my_memmove(arr+2, arr , 20);
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//��strcmp���

//int my_memcmp(int* p1[], int* p2[], int k)
//{
//	int ret = 0;
//	while (k--)
//	{
//		if (*p1 != *p2)
//		{
//			return *p1 - *p2;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[] = { 1,2,4,5,5,6, };
//	int ret= my_memcmp(arr1, arr2, 30);
//	printf("%d", ret);
//	return 0;
//}


//memset--�ڴ�����

//int main()
//{
//	int arr[6] = { 0 };
//	memset(arr, 7, 24);
//	//�ڴ��ŵ��ǰ��ֽڵ�λ���
//	//07 07 07 07.������
//	//����һ��int�ʹ�С--ת���þ��ǣ�117901063
//	return 0;
//}

void my_memset(void* p1, char s, int k)
{
	while (k--)
	{
		*(char*)p1 = s;
		++(char*)p1;
	}
}
int main()
{
	char arr[6] = { 0 };
	my_memset(arr, '#', 6);// ��С��λ���ֽ�
//��Ҫ�ı������    �ı���ŵ�����
	return 0;
}