#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<stack>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int aa = 0;
	printf("ջ���ĵ�ַ��%p\n", &aa);
	int* pl = new int;
	printf("�����ĵ�ַ��%p\n", pl);
	string a("abcddddddddddddddddddddddddd", 16);
	printf("a�ĵ�ַ:    %p\n", &a);
	printf("a[0]�ĵ�ַ: %p\n", &a[0]);
	a[1] = 'X';
	cout << a << endl;
	printf("a�ĵ�ַ:    %p\n", &a);
	printf("a[0]�ĵ�ַ: %p\n", &a[0]);
	string b("abc");
	printf("b�ĵ�ַ:    %p\n", &b);
	printf("b[0]�ĵ�ַ: %p\n", &b[0]);
	return 0;
}


//int main()
//{
//	string b("abcd");
//	cout << b.c_str();
//	return 0;
//}
//int main()
//{
//	string b("abcd",3);//���ֹ��췽����ͨ���ַ���abcd��Ȼ��ֻȡǰ3���ַ����й���string
//	//��������ַ�����ŵ���ʵ�� abcd\0
//	cout << b.capacity() << endl;
//	cout << b.size() << endl;
//
//	if (b[3] == '\0')
//		cout << "yes" << endl;
//	else
//		cout << "no" << endl;
//	return 0;
//}