#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char* pathname, int flags);
int open(const char* pathname, int flags, mode_t mode);

pathname: Ҫ�򿪻򴴽���Ŀ���ļ�
flags : ���ļ�ʱ�����Դ���������ѡ��������һ�����߶���������С������㣬����flags��
���� :
		O_RDONLY: ֻ����
		O_WRONLY : ֻд��
		O_RDWR : ����д��
				����������������ָ��һ����ֻ��ָ��һ��
		O_CREAT : ���ļ������ڣ��򴴽�������Ҫʹ��modeѡ���ָ�����ļ��ķ���Ȩ��
		O_APPEND : ׷��д
����ֵ��
		�ɹ����´򿪵��ļ�������
		ʧ�ܣ� - 1


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
//		//ע�ⷵ��ֵ�Ͳ������˴��пӣ���ϸ�鿴man�ֲ���ڸú�����˵��
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