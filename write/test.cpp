#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;




//#define swap_bits(num) (((num&0x55555555)<<1)|((num&0xAAAAAAAA)>>1))
////第一个是奇位  ，第二个为偶位
//int main()
//{
//	int num = 123;  // 0111 1011    10110111  183
//	printf("交换前: %d\n", num);
//	printf("预计答案:183\n");
//	int ret = swap_bits(num);
//	printf("交换后: %d\n", ret);
//	return 0;
//}

//默认对齐数的修改

//#pragma pack(4)//设置默认对齐数为4  此时这个结构体大小为12
////#pragma pack()//中不写数字的话，表示取消之前的指定对齐数，改为默认的值
////默认对齐数为1的话下面大小就是9
//struct s
//{
//	char a;
//	double d;
//};
//int main()
//{
//	printf("%d", sizeof(s));
//	return 0;
//}


//宏的使用  offsetof
//需要引用头文件  stddef.h
//作用查看该类型所在的偏移量
//第一个为类型名（不是变量名）
//第二个是成员名

//#define my_offsetof(type,member) (size_t)(&(((type*)0)->member))
////先将结构体地址手动置为0，此时member也会改变，然后将其指向member
////此时member的地址对应的就是偏移量
//struct s
//{
//	char a;
//	int c;
//	double d;
//};
//int main()
//{
//	printf("%d\n", my_offsetof(struct s, a));
//	printf("%d\n", offsetof(struct s, a));
//	return 0;
//}

//int main()
//{
//	int* p = new int[10];
//
//	// 将该函数放在main函数之后，每次程序退出的时候就会检测是否存在内存泄漏
//	_CrtDumpMemoryLeaks();
//	return 0;
//}

//
//                  先走析构函数
//delete 
//                  后进行调用operator  delete(与c语言的free差不多)

//          operator new
//new  
//          placement new

//class A 
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int b = 0)
//		: _b(b)
//	{
//		cout << "B():" << this << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//private:
//	int _b;
//};
//A a(2);
//
//int main()
//{
//	int tmp = 8;
//	int n = 1;
//	for (int i = 0; i < 31; i++)
//	{
//		if (tmp % 2 == 1)
//			break;
//		else
//		{
//
//
//				n *= 2;
//		}
//		tmp >>= 1;
//	}
//	return 0;
//}

//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构
//	//造函数和析构函数
//	A* a1 = new A(2);
//	A* a2 = (A*)malloc(sizeof(A));
//
//	free(a2);
//	delete a1;
//	return 0;
//}

//int main()
//{
//	//动态开辟一个int类型的对象
//	int* p1 = new int;
//	//动态开辟一个int类型的空间并初始化为10
//	int* p2 = new int(10);
//	//动态申请10个int类型的空间
//	int* p3 = new int[10];
//
//	//在c语言中我们动态开辟后又free，同样在c++中也有操作符delete
//	delete p1;
//	delete p2;
//	delete []p3;//注意数组的要加[]
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
//	printf("栈区的地址：%p\n", &aa);
//	int* pl = new int;
//	printf("堆区的地址：%p\n", pl);
//	string a("abcddddddddddddddddddddddddd", 16);
//	printf("a的地址:    %p\n", &a);
//	printf("a[0]的地址: %p\n", &a[0]);
//	a[1] = 'X';
//	cout << a << endl;
//	printf("a的地址:    %p\n", &a);
//	printf("a[0]的地址: %p\n", &a[0]);
//	string b("abc");
//	printf("b的地址:    %p\n", &b);
//	printf("b[0]的地址: %p\n", &b[0]);
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
//	string b("abcd",3);//这种构造方法是通过字符串abcd，然后只取前3个字符进行构造string
//	//但是这个字符串存放的其实是 abcd\0
//	cout << b.capacity() << endl;
//	cout << b.size() << endl;
//
//	if (b[3] == '\0')
//		cout << "yes" << endl;
//	else
//		cout << "no" << endl;
//	return 0;
//}