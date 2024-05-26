#pragma once
#include <string.h>
#include<assert.h>
#include<iostream>
using namespace std;
namespace test
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const 
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(const vector<T>& v)
		{
			reserve(v.(capacity));
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*(_finish) = val;
					++_finish;
				}
			}

		}
		void push_back(const T& x)
		{
			insert(end(), x);

			//if (_finish == _endofstorage)
			//{
			//	//����
			//	size_t sz = size();
			//	size_t cp = capacity() == 0 ? 4 : capacity() * 2;
			//	T* tmp = new T[cp];
			//	if (_start)
			//	{
			//		memcpy(tmp, _start, sizeof(T) * sz);
			//		delete[]_start;
			//	}
			//	_start = tmp;
			//	_finish = _start + sz;
			//	_endofstorage = _start + cp;
			//}
			//*_finish = x;
			//++_finish;
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				//����
				size_t sz = size();
				size_t cp = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[cp];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + cp;
			}
			T* end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			T* end = _finish - 1;
			while (pos < end)
			{
				*pos = *(pos + 1);
				++pos;
			}
			--_finish;
			return pos;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
			//return *(_start + pos);
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			//return *(_start + pos);
			return _start[pos];
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			*it *= 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.erase(v.end());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
