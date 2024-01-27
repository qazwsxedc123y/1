#define  _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include<stdio.h>
#include<assert.h>

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++, str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char ar1[] = "sssgdes";
//	char ar2[] = "adf";
//	strncpy(ar1, ar2, 4);
////	int ret = my_strcmp(ar1, ar2);
////	int ret = my_strcmp(ar1, ar2);
////	printf("%d", ret);
//	return 0;
//}

//char* my_strcpy(char* str,const char* src)
//{
//	assert(str!=NULL);
//	assert(src != NULL);
//	char* ret = str;
//	
//	while (*str++ = *src++)//拷贝的结果为表达式的结果   
//
//		//拷贝包含  \0
//		
//		//比如最后拷贝的是'\0'  那么结果就为'\0'  为假  
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

//
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//char* my_strncpy(char* best,const char* src, int k)
//{
//	assert(best && src);
//	int len = strlen(src);
//	char* ret = best;
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		if (i < len)
//		{
//			*best++ = *src++;
//		}
//		else
//		{
//			*best++ = '\0';
//		}
//	}
//	return ret; 
//}

//char* my_strncpy(char* dest, char* src, int k)
//{
//	assert(dest && src);
//	int i = 0;
//	char* ret = dest;
//	while (*src && i < k)
//	{
//		*dest++ = *src++;
//		i++;
//	}
//	int j = 0;
//	for (j = i; j < k; j++)
//	{
//		*dest++ = '\0';
//	}
//	return ret;
//}
//int main()
//{
//	char ar1[] = "abcdef";
//	char ar2[] = "sss";
//	my_strncpy(ar1, ar2, 4);
//	printf("%s", ar1);
//	return 0;
//}


//char* my_strncpy(char* best, const char* src, int k)
//{
//    assert(best && src);
//    int len = strlen(src);
//    char* ret = best;
//    int i = 0;
//    for (i = 0; i < k; i++)
//    {
//        if (i < len)
//        {
//            *best++ = *src++;
//        }
//        else
//        {
//            *best++ = '\0';
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    char ar1[10] = "abcdef";
//    const char* ar2 = "sss";
//    my_strncpy(ar1, ar2, 2);
//    printf("%s", ar1);
//    return 0;
//}

//模拟实现strncat

//char* my_strncat(char* str,const char* src, int k)
//{
//	char* ret = str;
//	while (*str++)
//		;
//	str--;
//	while(k--)
//	{
//		if (!(*str++ = *src))
//			return ret;
//	}
//	*str = '\0';
//	return ret;
//}
//int main()
//{
//	char ar1[20] = "abcde";
//	char ar2[] = "sss";
//	my_strncat(ar1, ar2, 2);
//	printf("%s", ar1);
//	return 0;
//}

//模拟实现strncmp

//int my_strncmp(const char* str,const char* src, int k)
//{
//	assert(str && src);
//	while (k--)
//	{
//		if (*str != *src)
//			return *str - *src;
//		else
//			str++, src++;
//	}
//	return 0;
//}
//int main()
//{
//	char ar1[] = "abcdee";
//	char ar2[] = "abcdef";
//	int ret=my_strncmp(ar1, ar2, 6);
//	system("pause");//暂停一下
//	printf("%d", ret);
//	return 0;
//}

int main() {
    char a[100];
 //   scanf("%s", a);
    gets(a);
    int count = strlen(a);
    printf("%d\n", count);
    return 0;
}
