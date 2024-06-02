#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
namespace test2
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		const T& front()
		{
			return _con.front();
		}
		const T& back()
		{
			return _con.back();
		}
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}