#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����ָ���ӡ��������   ����
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




//ָ������----  ���飨���ָ������飩
//����ָ��----  ָ�루��������ָ�룩

//ָ������
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


//��άָ��

//int main()
//{
//	int a = 10;
//	int* p = &a; //p�Լ�����ĵ�ַ��a��ͬ��p��һ��ָ���������ֵ��a�ĵ�ַ��������a����ĵ�ַ��
////	*��ʾpΪָ��  ��int��ʾ����ָ��Ķ��������Ϊint
//	int* *  ppa = &p;//ppa����һ������ָ��
////     �ڶ���*��ʾppaΪָ��   int*��ʾppa��ָ��Ķ���Ϊint*
////	*ppa//��ʾ����pa��ֵ    *pa��ʾ����a��ֵ
//		//   ����**ppa��ʾ����a��ֵ
//		printf("%d\n", p);
//		printf("%d\n", *p);
//		printf("%d\n", *ppa);
//		printf("%d\n", **ppa);
//	return 0;
//}



//  ָ��ı������ֵ

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
//	printf("%p\n", &arr+1);//1.  &����������������ʾ��������
// //2.  strlen��������Ҳ�Ǳ�ʾ��������
//	return 0;
//}




//ָ�뷽��  ��ָ��-ָ�룩
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



//�ݹ鷽��
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


//ָ��-����   ��ȷд��
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

//����д��  �������﷨�������� 

//����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚϣ�
// ���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�

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


//ָ��+����
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


//ָ��-ָ�루��ַ-��ַ��
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	printf("%d\n", &arr[9] - &arr[0]);//9
//	printf("%d\n", &arr[0] - &arr[9]);//-9
//	return 0;
//}


//ָ������

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
//	//p  ��ָ�����������ŵ�ַ  int*Ϊָ�������
//	int a = 0x12542134;
//	int* p = &a;
//	char* pa = &a;
////printf("%p\n", *pa); �����ӡָ��pa��ָ��ĵ�ַ��ֵ printf("%p\n", pa); �����ӡָ��pa����ĵ�ֵַ
//
////	ָ�����;�����ָ����н����ò�����ʱ���ܹ����ʿռ�Ĵ�С
//// 	   Ҳ������ָ����һ���Ĵ�С������һ�����ƫ���˼����ֽ�
////  int *  ���Է����ĸ��ֽ�
////  char * ���Է���һ���ֽ�
////  double *  ���Է��ʰ˸��ֽ�
//	printf("%p\n", p);
//	printf("%p\n", pa);
//	*p = 0;
//	*pa = 0;
//	printf("%0x\n", *p);
//	printf("%0x\n", *pa);
//	return 0;
//}