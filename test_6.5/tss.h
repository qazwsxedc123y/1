#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<deque>
#include<queue>
#include<vector>
using namespace std;

namespace test
{
	template<class T, class Container = vector<T>>
	class priority
	{
	public:
		priority()
		{}
		void adjust_up(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
	private:
		Container _con;
	};
	void test_1()
	{
		priority <int> s;
		s.push(40);
		s.push(30);
		s.push(50);
		s.push(20);
	}
}