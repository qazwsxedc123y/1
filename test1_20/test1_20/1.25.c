#define  _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include<stdio.h>
#include<assert.h>

//void revsrse(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)//left ��   right  ����ǵ�ַ
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void mov(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len = strlen(arr);
//	assert(k <= len);
//	revsrse(arr, arr + k - 1);//�������
//	revsrse(arr + k, arr + len - 1);//�����ұ�
//	revsrse(arr, arr + len - 1);//����ȫ��	
//}
//int int_left_mov(char* s1, char* s2)
//{
//	int i = 0;
//	int len = strlen(s1);
//	for (i = 0; i < len; i++)
//	{
//		mov(s1, 1);
//		if (strcmp(s1, s2) == 0)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = int_left_mov(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}


//int main()
//{
//	char arr[] = "abcdef";
//	mov(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	char ar1[30] = "abc";
//	char ar2[] = "efd";
//	strcat(ar1, ar2);
//	return 0;
//}



//�鿴arr2�Ƿ����ͨ��arr1�����õ�

//int int_left_mov(char* s1, char* s2)
//{
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	strncat(s1, s1, len1);//���������ַ��������ʱ�ô�n��  �����ʱ��strcat
//	//abcdefabcdef
//	// 2 �ж�s2�Ƿ�Ϊs1 ���Ӽ�
//	//strstr���Ӽ�  ����ֵΪָ��
//	char* ret = strstr(s1, s2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = int_left_mov(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}


//int findnum(int arr[3][3], int k, int* px, int* py)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (x <= *px-1 && y >= 0)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 7;
//	int x = 3;
//	int y = 3;
//	int ret = findnum(arr, k, &x, &y);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//		printf("�±�Ϊ��%d %d\n", x, y);
//	}
//	else
//	{
//		printf("�޷��ҵ�\n");
//	}
//	return 0;
//}


//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 4;
////	int ret = a, b;
//	c = a, b;
//	printf("%d", c);
//}

//int f(const char* str)
//{
////	int count = 0;
//	char* p1 = str;
//	while (*p1 != '\0')
//	{
////		count++;
////		str++;
//		p1++;
//	}
//	return p1-str;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = f(arr);//strlen�ķ���ֵΪunsigned int
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int* p1 = arr;
//	int* p2 = &arr + 1;
//	printf("%d", p2 - p1);//9
//	return 0;
//}

//ʵ��strlen�ĵݹ�д��

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen(arr);//strlen�ķ���ֵΪunsigned int
//	printf("%d", ret);
//	return 0;
//}

//strcpy��ʵ��

//char* my_strcpy(char* str,const char* src)
//{
//	assert(str!=NULL);
//	assert(src != NULL);
//	char* ret = str;
//	
//	while (*str++ = *src++)//�����Ľ��Ϊ���ʽ�Ľ��   
//
//		//��������  \0
//		
//		//������󿽱�����'\0'  ��ô�����Ϊ'\0'  Ϊ��  
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char ar1[] = "as";
//	char ar2[] = "bit";
//	my_strcpy(ar1, ar2);
////	strcpy(ar1, ar2);
//	printf("%s", ar1);
//	return 0;
//}


//strcat
 

//char* my_strcat(char* dest,const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//�ҵ�\0
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//׷��
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//����char* ����
//	return ret;
//}
//int main()
//{
//	char ar1[30] = "adesew";
//	char ar2[] = "bit";
//	my_strcat(ar1, ar2);
//	printf("%s", ar1);
//}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++, str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	char ar1[] = "adfg";
	char ar2[] = "adfge";
	int ret = my_strcmp(ar1, ar2);
	printf("%d", ret);
	return 0;
}