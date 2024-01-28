#define  _CRT_SECURE_NO_WARNINGS

#include"ku.h"


//使用errno  需要引用头文件   #include<errno.h>  
//使用的案例可以在打开文件里面使用

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//r表示read
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));//查看对应的是什么错误
//	}
//	//其所可以对应错误码  然后再将错误码改为错误信息
//	//再%s打印出来
//	else
//	{
//		printf("open file successfully\n");
//	}
//	return 0;
//}



//判断字符

// 需要包含头文件#include <ctype.h>
 
//int main()
//{
//	char ch = ' ';
//	int ret = isprint(ch);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	//char ch = tolower('Q');//大写转小写  如果是小写则不动
//	//putchar(ch);
//	//char s = toupper('q');//小写转大写  如果是大写则不动
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