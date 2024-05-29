#define  _CRT_SECURE_NO_WARNINGS
#include"vector.h"
#include"string"
using namespace std;

int main()
{
	const char* ch[5] = { "","","","abc","ccc" };
	string cha = ch[3];
	for (auto e : cha)
	{
		cout << e << " ";
	}
	test::test_vector8();
	return 0;
}