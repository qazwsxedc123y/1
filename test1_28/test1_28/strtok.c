#define  _CRT_SECURE_NO_WARNINGS

#include"ku.h"

//	切割字符串，特定的符号位切割

//int main()
//{
//	char arr[] = "bisi@sws.5245";
//	char p[] = "@.";
//	char buff[1024] = { 0 };
//	//切割buff  因strtok会改变原有的数组内容，所以一般是改变拷贝的数组
//	strcpy(buff, arr);
//
//	char* ret=NULL;
//
//	//内部使用了静态变量  static
//	//第一次传的是arr  后续的传参全是NULL
//
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))//返回值是一个地址
//	{    // 语句一              //语句二        //语句三
//		printf("%s\n", ret);
//	}
//
//
//	//ret = strtok(arr, p);
//	//while (ret != NULL)
//	//{
//	//	printf("%s\n", ret);
//	//	ret = strtok(NULL, p);
//	//}
// 
//	 
//	//char* ret = strtok(arr, p);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p);
//	//printf("%s\n", ret);
//	return 0;
//}

//int a = 20;
//void print()
//{
//	printf("    1%d ", a);
//}
//int main()
//{
//	print();
//	return 0;
//}