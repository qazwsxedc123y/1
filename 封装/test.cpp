#define  _CRT_SECURE_NO_WARNINGS

#include"RBTree.h"
#include"MyMap.h"
#include"MySet.h"

int main()
{
	bit::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);

	bit::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s.begin();

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
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