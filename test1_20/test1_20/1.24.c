#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>



//�����ַ�




//������ⷨ
//void mov(char * arr, int k)
//{
//  assert(arr!=NULL);
//	int i = 0,j=0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;
//		//����תһ���ַ�
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		*(arr + len - 1) = tmp;
//	}
//}

//������ת��
//ab cdef
//ba  fedc
//bafedc
//cdefab

void revsrse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left<right)//left ��   right  ����ǵ�ַ
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void mov(char* arr, int k)
{
	assert(arr != NULL);
	int len = strlen(arr);
	assert(k <= len);
	revsrse(arr,arr+k-1);//�������
	revsrse(arr+k,arr+len-1);//�����ұ�
	revsrse(arr,arr+len-1);//����ȫ��	
}
int main()
{
	char arr[] = "abcdef";
	mov(arr, 2);
	printf("%s\n", arr);
	return 0;
}


//int main()
//{
//	char* arr[5] = { "asdcd","ab" };//��������Ԫ�ؿ���ͨ���±������ʣ�
// ����arr[0]������ָ���ַ���"asdcd"��ָ�롣��ע�⣬��������Ԫ����ָ���ַ���ָ�룬
// //�������ַ����顣�������Ҫһ���ַ���������飬�����ʹ������������
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[10] = { 0,9,8,7,6,5,4,3,2,1 };
//	printf("�޸�ǰ��\n");
//	printf("arr1:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	printf("�޸ĺ�\n");
//	printf("arr1:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2:");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	double sum = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum += arr[i];
//	}
//	printf("ƽ��ֵΪ��%.2lf", sum / 10);
//}


//int main() {
//    int n = 0, m = 0;
//    int arr[10][10];
//    int i = 0, j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (j = 0; j < m; j++)
//    {
//        for (i = 0.; i < n; i++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer=%c\n", killer);
//		}
//	}
//	return 0;
//}


//int f(int a,int empty,int s)
//{
//	s += a;//sΪһ�����˶���
//	empty += a;//��ƿ��
//	a = empty / 2;//�����������aƿ  ȥ��
//	empty = empty - a * 2;//��ƿ  �����
//	if (empty >= 2||a!=0)
//	{
//		return f(a, empty, s);
//	}
//	else
//		return s;
//}
//int main()
//{
//	int a = 0,empty=0,s=0;
//	scanf("%d", &a);
//	int sum = f(a,empty,s);
//	printf("%d", sum);
//	return 0;
//}