#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char* pathname, int flags);
int open(const char* pathname, int flags, mode_t mode);

pathname: 要打开或创建的目标文件
flags : 打开文件时，可以传入多个参数选项，用下面的一个或者多个常量进行“或”运算，构成flags。
参数 :
		O_RDONLY: 只读打开
		O_WRONLY : 只写打开
		O_RDWR : 读，写打开
				这三个常量，必须指定一个且只能指定一个
		O_CREAT : 若文件不存在，则创建它。需要使用mode选项，来指明新文件的访问权限
		O_APPEND : 追加写
返回值：
		成功：新打开的文件描述符
		失败： - 1


//int main()
//{
//	FILE* pf;
//	pf = fopen("test.txt", "w");
//	if (!pf)
//	{
//		printf("fopen fail\n");
//		exit(1);
//	}
//	char buf[1024];
//	while (1)
//	{
//		//注意返回值和参数，此处有坑，仔细查看man手册关于该函数的说明
//		size_t s = fread(buf, 1, strlen(msg), fp);
//	}
//	fclose(pf);
//	return 0;
//}



//int main()
//{
//	FILE* pf;
//	pf = fopen("test.txt", "w");
//	if (!pf)
//	{
//		printf("fopen fail\n");
//		exit(1);
//	}
//	const char* msg = "hello world\n";
//	int cnt = 5;
//	while (cnt--)
//	{
//		fwrite(msg, strlen(msg), 1, pf);
//		printf("%d\n",ftell(pf));
//	}
//	fclose(pf);
//	return 0;
//}