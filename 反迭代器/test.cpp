#define  _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include"vector.h"
int main()
{
	test::list<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.push_back(5);
	test::list<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	test::list<int>::reserve_iterator i = s.rbegin();
	while (i != s.rend())
	{
		cout << *i << " ";
		++i;
	}
	cout << endl;

	test::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	test::vector<int>::iterator t = v.begin();
	while (t != v.end())
	{
		cout << *t << " ";
		++t;
	}
	cout << endl;
	test::vector<int>::reserve_iterator m = v.rbegin();
	while (m != v.rend())
	{
		cout << *m << " ";
		++m;
	}
	cout << endl;
	return 0;
}