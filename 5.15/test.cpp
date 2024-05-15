#define  _CRT_SECURE_NO_WARNINGS
#include"string.h"

void test1()
{
	string s1;
	getline(cin, s1, '!');
	cout << s1 << endl;
	size_t i = s1.rfind(' ');//从后往前找
	//cout << s1[i] << endl;
	if (i != string::npos)
	{
		cout << s1.size() - (i + 1) << endl;
	}
	else
	{
		cout << s1.size() << endl;
	}
}
void test2()
{
	//净网行动
	char str1[] = "hello world";
	char str2[] = "比特 hello";
	str2[1]++;
	str2[1]++;
	str2[1]++;
	str2[1]++;

	str2[3]--;
	str2[3]--;
	str2[3]--;
	str2[3]--;

	char str3[10];
	cout << str3 << endl;

	cout << sizeof(str1) << endl;
	cout << sizeof(str2) << endl;

	wchar_t ch1;
	cout << sizeof(ch1) << endl;

	char16_t ch2;
	char32_t ch3;
	cout << sizeof(ch2) << endl;
	cout << sizeof(ch3) << endl;
}
int main()
{
	A::test_string4();
	//A::test1_string();

	//test2();
	//test1();
}