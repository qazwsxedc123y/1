#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1.��NULLָ��Ľ����ò���

//int main()
//{
//	int* p = (int*)malloc(_CRT_INT_MAX);//pΪ��ָ��
//	*(p+1) = 20;//p����Ϊ��ָ�룬��һ��Ϊ��ָ��
//	free(p);
//	p = NULL;
//	return 0;
//}

//2. �Զ�̬���ٿռ��Խ�����

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		exit(1);
//		//exit(0): ����ִ�г����˳�����exit(EXIT_SUCCESS)
//
//		//exit(1) : ������ִ�е����˳�����exit(EXIT_FAILURE)
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i <= 10; i++)
//		{
//			*(p + i) = i;//��i��10��ʱ��Խ�����
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//3. �ԷǶ�̬�����ڴ�ʹ��free�ͷ�

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//free��mallocʹ�÷�Χ���Ƕ���
//	//��int a = 10;  int* p = &a;���Ǵ���ջ����free�޷��ͷŷǶ�̬���ٿռ�
//	p = NULL;
//	return 0;
//}

//4. ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����

//int main()
//{
//	int* p = (int*)malloc(40);
//	p++;
//	free(p);//�ͷŵĲ���ԭ����p����p+1��ĵ�ַ
// //�ᵼ��ϵͳ����
//	p = NULL;
//	return 0;
//}

//5. ��ͬһ�鶯̬�ڴ����ͷ�

//int main()
//{
//	int* p = (int*)malloc(40);
//	//....��ʡ�Բ�����̬���ٵĿռ�Ĳ�����
//	free(p);
//	//p=NULL;
//	free(p);
//	//�ᵼ��ϵͳ��������
//	//���ǵ�һ���ͷ��Ժ�ֱ��p=NULL�ٴ��ͷž�û��ϵ
//	//��Ϊ���freeһ����ָ�룬��û���κ����鷢����
//	return 0;
//}

//6. ��̬�����ڴ������ͷţ��ڴ�й©��

//int main()
//{
//	while (1)
//	{
//		int* p = (int*)malloc(100);//һֱ���ٲ��ͷ�
//		//�ͻ���ɵ���cpu���ڴ���������ɵ��Ա��������غ���
//	}
//	//�����ͷŲ���ʹ?�Ķ�̬���ٵĿռ������ڴ�й©��
//	//�мǣ���̬���ٵĿռ�?��Ҫ�ͷţ�������ȷ�ͷ�
//	return 0;
//}

