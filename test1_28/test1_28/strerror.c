#define  _CRT_SECURE_NO_WARNINGS

#include"ku.h"


//ʹ��errno  ��Ҫ����ͷ�ļ�   #include<errno.h>  
//ʹ�õİ��������ڴ��ļ�����ʹ��

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//r��ʾread
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));//�鿴��Ӧ����ʲô����
//	}
//	//�������Զ�Ӧ������  Ȼ���ٽ��������Ϊ������Ϣ
//	//��%s��ӡ����
//	else
//	{
//		printf("open file successfully\n");
//	}
//	return 0;
//}



//�ж��ַ�

// ��Ҫ����ͷ�ļ�#include <ctype.h>
 
//int main()
//{
//	char ch = ' ';
//	int ret = isprint(ch);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	//char ch = tolower('Q');//��дתСд  �����Сд�򲻶�
//	//putchar(ch);
//	//char s = toupper('q');//Сдת��д  ����Ǵ�д�򲻶�
//	//putchar(s); 
//	//printf("%c\n",)
//
//	char arr[] = "i am s sss";
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}