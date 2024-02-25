#define  _CRT_SECURE_NO_WARNINGS
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//stdin 从标准输入流读取--键盘
//stdout 输出到标准输出流--打印到屏幕
//gets(buf);
//puts(buf);


int main()
{
	int c;
	FILE* pf=fopen("test.txt", "r");
	if (!pf)
	{
		perror("test.txt");
		return 0;
	}
	//feof
	//当⽂件读取结束的时候，判断是读取结束的原因是否是：遇到⽂件尾结束。
	// ⽂本⽂件读取是否结束，判断返回值是否为 EOF (-1)（ fgetc ），或者 NULL （ fgets ）
	//文件操作
	
	while ((c = fgetc(pf)) != EOF)
	{
		putchar(c);
	}
	printf("\n");
	//判断是什么原因结束的
	if (ferror(pf))
	{
		puts("err");

	}
	else if (feof(pf))//正常结束返回-1
		//非正常为上 if
	{
		puts("End of file reached successfully");
	}
	fclose(pf);
	pf = NULL;
	return 0;
}



//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//1.文件指针定位操作
//	fseek(pf, -2, SEEK_END);
//	//     单位为字节  
//	//SEEK_END在f之后
//	//2.读取文件
//	//返回⽂件指针相对于起始位置的偏移量
//	long ch=ftell(pf);
//	printf("%ld\n", ch);
//
//	//让⽂件指针的位置回到⽂件的起始位置
//	rewind(pf);
//	ch = ftell(pf);
//	printf("%ld\n", ch);
//	/*int ch = fgetc(pf);
//	printf("%c\n", ch);*/
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//struct s
//{
//	int n;
//	float s;
//	char arr[10];
//};
//int main()
//{
//	//struct s s = { 100,3.14f,"abcdef" };
//	struct s tmp = { 0 };
//	FILE* pf=fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	//fwrite(&s, sizeof(struct s), 1, pf);
//
//	fread(&tmp, sizeof(struct s), 1, pf);
//	printf("%d %f %s\n", tmp.n, tmp.s, tmp.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct s
//{
//	int n;
//	float s;
//	char arr[10];
//};
//int main()
//{
//	char buf[1024] = {0};
//	struct s s = { 100,3.14f,"abcdef" };
//	struct s tmp = { 0 };
//	//把格式化的数据转化为字符串储存在buf内
//	sprintf(buf, "%d %f %s", s.n, s.s, s.arr);
//
//	//把buf的数据格式化存储到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.s), tmp.arr);
//
//	printf("%d %f %s\n", tmp.n, tmp.s, tmp.arr);
//	return 0;
//}



//struct s
//{
//	int n;
//	float s;
//	char arr[10];
//};
//int main()
//{
//	//struct s s = { 100,3.14f,"bit"};
//	struct s s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	//格式化的形式写文件
//	//fprintf(pf, "%d %f %s", s.n, s.s, s.arr);//写到pf
//
//	//格式化的形式读取文件
//	fscanf(pf, "%d %f %s", &(s.n), &(s.s), s.arr);//从pf读
//	printf("%d %f %s", s.n, s.s, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//⽂本⾏输⼊/输出函数

//int main()
//{
//	int buf[1024] = { 1,2,4,5,6 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	//fputs("hello", pf);
//	
//	//读文件  char *fgets( char *string, int n, FILE *stream );
//	//1  Storage location for data
//
//	fgets(buf, 1024, pf);
//	printf("%s", buf);
//  puts(buf);//打印会自加\n
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
// 
	//读文件
	//输入流  从什么什么获取信息  键盘/屏幕/文件
	//int ch = fgetc(pf);
	//printf("%c", ch);
	//ch = fgetc(pf);
	//printf("%c", ch); 
	//ch = fgetc(pf);
	//printf("%c", ch);
	 
	//写文件内容
	//输出流  --输出内容到pf指针位置
	//fputc('b',pf);
	//fputc('i',pf);
	//fputc('t',pf);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	FILE* pFile;
//	pFile = fopen("test.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputc("r", pf);
//	fputc("c", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}