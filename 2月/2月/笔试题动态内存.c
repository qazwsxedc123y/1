#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//��Ŀһ


//void GetMemory(char* p)
//{
//	//str��ֵ���ݵ���ʽ��p
//	//p��GetMemory�������βΣ�ֻ�ܺ����ڲ���Ч
//	//��GetMemory��������֮�󣬶�̬�����ڴ���δ�ͷ�
//	//�����޷��ҵ������Ի�����ڴ�й©
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);//ָ�����  &strΪ��ַ
//	//��������Ĭ���ǰ�ֵ���ݵģ����������յ����ǲ����Ŀ������Բ������޸Ĳ���Ӱ�쵽ԭʼ������
//	// ��ˣ�GetMemory(str)�Ǵ�ֵ���ã�����str��ֵ����NULL��������GetMemory�����еĲ���p��
//	// ����GetMemory�����ڲ���p���޸Ĳ���Ӱ�쵽str����
//	strcpy(str, "hello world");//��ʱstr����ΪNULL 
//	//�ڴ����ϵͳ���� 
//	//Ҳ����û���ͷŶ�̬�ڴ�ռ������
//	printf(str);
//}
////printf(str);��ʽ��ӡû����
////���*str="abcdfg"
////��ô��ӡ�ľ���abcdfg
////��printf("abcdfg");һ��


//����

//1

//void GetMemory(char** p)//  2
//{
//	*p = (char*)malloc(100);//  3
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);//  1
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);//  4
//	str = NULL;
//}

//2

//char* GetMemory(char* p)//  1
//{
//	p = (char*)malloc(100);
//	return p;//  2
//}
//void Test(void)
//{
//	char* str = NULL;
//	str=GetMemory(str);//  3
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);//  4
//	str = NULL;
//}



//��Ŀ��

//char* GetMemory(void)
//{
//	char p[] = "hello world";//�Ƿ�����
//	//p��ջ���ϻ��Զ��ͷ�
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	//��Ȼstrָ��p�ģ������p�ĵ�ַ
//	//��p�Ѿ����٣����ڷǷ�����
//	str = GetMemory();
//	printf(str);
//}

//�����������û����

//int* test()
//{
//	int* str = malloc(40);
//	return str;
//}
//int main()
//{
//	int* p = test();
//	return 0;
//}


//��Ŀ��

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
////��������ӡhello ���Ǵ����ڴ�й¶������

//����

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//��Ŀ��

//void Test(void)
//{
//	char* str = (char*)malloc(100);//str�൱�ڷ����  hello�൱�ڿ��˵�����
//	strcpy(str, "hello");
//	free(str);//free�൱���˷�
//	//�˷��Ժ�str���仹���ڣ��������Ȼû�иı�
//	if (str != NULL)//  û�н�str=NULL  �ɵ�һ��strcpy��֪str���Ͳ��ǿ�ָ��
//	// ���������if�жϱ���һ��Ϊ��
//	{//�ٴη�����ǿ���
//		//���Ǵ��ڷǷ����ʵ�����
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//����

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

