#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;


//int main()
//{
//	int* p = new int[10];
//
//	// ���ú�������main����֮��ÿ�γ����˳���ʱ��ͻ����Ƿ�����ڴ�й©
//	_CrtDumpMemoryLeaks();
//	return 0;
//}

//
//                  ������������
//delete 
//                  ����е���operator  delete(��c���Ե�free���)

//          operator new
//new  
//          placement new

class A 
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class B
{
public:
	B(int b = 0)
		: _b(b)
	{
		cout << "B():" << this << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int _b;
};
A a(2);
int main()
{
	//A a(2);
	B b(4);
	return 0;
}

//int main()
//{
//	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù�
//	//�캯������������
//	A* a1 = new A(2);
//	A* a2 = (A*)malloc(sizeof(A));
//
//	free(a2);
//	delete a1;
//	return 0;
//}

//int main()
//{
//	//��̬����һ��int���͵Ķ���
//	int* p1 = new int;
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* p2 = new int(10);
//	//��̬����10��int���͵Ŀռ�
//	int* p3 = new int[10];
//
//	//��c���������Ƕ�̬���ٺ���free��ͬ����c++��Ҳ�в�����delete
//	delete p1;
//	delete p2;
//	delete []p3;//ע�������Ҫ��[]
//	return 0;
//}


//using namespace std;
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	char char2[] = "abcd";
//	const char* pchar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4,sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2,sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//int main()
//{
//	test();
//	return 0;
//}



//int main()
//{
//	string t("abcdef");
//	string::iterator it = t.begin();
//	while (it != t.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//    vector<double> v{ 1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
//
//    vector<double>::iterator biggest = max_element(begin(v), end(v));
//    cout << "Max element is " << *biggest << " at position " << distance(begin(v), biggest) << endl;
//
//    auto smallest = min_element(begin(v), end(v));
//    cout << "min element is " << *smallest << " at position " << distance(begin(v), smallest) << endl;
//
//    return 0;
//}

//istream& operator>>(istream& in, string& s)
//{
//	s.clear();
//	char ch;
//	ch = in.get();
//	while (ch != ' ' && ch != '\n')
//	{
//		s += ch;
//		ch = in.get();
//	}
//	return in;
//}
//int main()
//{
//	int aa = 0;
//	printf("ջ���ĵ�ַ��%p\n", &aa);
//	int* pl = new int;
//	printf("�����ĵ�ַ��%p\n", pl);
//	string a("abcddddddddddddddddddddddddd", 16);
//	printf("a�ĵ�ַ:    %p\n", &a);
//	printf("a[0]�ĵ�ַ: %p\n", &a[0]);
//	a[1] = 'X';
//	cout << a << endl;
//	printf("a�ĵ�ַ:    %p\n", &a);
//	printf("a[0]�ĵ�ַ: %p\n", &a[0]);
//	string b("abc");
//	printf("b�ĵ�ַ:    %p\n", &b);
//	printf("b[0]�ĵ�ַ: %p\n", &b[0]);
//	return 0;
//}


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