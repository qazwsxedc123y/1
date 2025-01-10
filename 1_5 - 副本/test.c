#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* pf;
	pf = fopen("test.txt", "wb");
	fputs("This is an apple.", pf);
	fseek(pf, 9, SEEK_SET);
	// 现在已经文件指针相对于起始位置的偏移量设置为了9
	printf("%d\n", ftell(pf));
	// 偏移量变为0
	rewind(pf);
	printf("%d\n", ftell(pf));
	fclose(pf);
	pf = NULL;
	return 0;
}



//int main()
//{
//	FILE* pf; // 定义一个文件指针
//	// 打开文件
//	pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		// 打开失败
//		printf("fopen fail\n");
//		exit(1);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct _iobuf {
//	char* _ptr;
//	int   _cnt;
//	char* _base;
//	int   _flag;
//	int   _file;
//	int   _charbuf;
//	int   _bufsiz;
//	char* _tmpfname;
//};
//typedef struct _iobuf FILE;

// // 打开文件
//
//FILE* fopen(const char* filename, const char* mode);
//
//// 关闭文件
//
//int fclose(FILE* stream);