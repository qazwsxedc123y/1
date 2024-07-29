#define  _CRT_SECURE_NO_WARNINGS

#include"RBTree.h"
#include"MyMap.h"
#include"MySet.h"

int main()
{
	bit::map<string, string> s;
	s.insert(make_pair("sort", ""));
	s.insert(make_pair("sort", "xx"));
	s.insert(make_pair("left", ""));
	s.insert(make_pair("right", "ұ"));
	cout << s.IsBalance() << endl;
	return 0;
}


//int main()
//{
//	bit::map<string, string> s;
//	s.insert(make_pair("sort", ""));
//	s.insert(make_pair("sort", "xx"));
//	s.insert(make_pair("left", ""));
//	s.insert(make_pair("right", "ұ"));
//	cout << s.IsBalance() << endl;
//	return 0;
//}