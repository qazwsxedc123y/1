#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* pf;
	pf = fopen("test.txt", "wb");
	fputs("This is an apple.", pf);
	fseek(pf, 9, SEEK_SET);
	// �����Ѿ��ļ�ָ���������ʼλ�õ�ƫ��������Ϊ��9
	printf("%d\n", ftell(pf));
	// ƫ������Ϊ0
	rewind(pf);
	printf("%d\n", ftell(pf));
	fclose(pf);
	pf = NULL;
	return 0;
}



//int main()
//{
//	FILE* pf; // ����һ���ļ�ָ��
//	// ���ļ�
//	pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		// ��ʧ��
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

// // ���ļ�
//
//FILE* fopen(const char* filename, const char* mode);
//
//// �ر��ļ�
//
//int fclose(FILE* stream);