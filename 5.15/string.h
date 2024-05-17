#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace A
{
	class string
	{
	public:

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		const char* c_str() const
		{
			return _str;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		bool empty() const
		{
			return _size == 0;
		}
		//void shrink_to_fit()
		//{

		//}
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		size_t size() const
		{
			return _size;
		}
		void resize(size_t n)
		{
			if (_size >= n)
			{
				erase(n);
			}
			else
			{
				append(n - _size, '\0');
				_str[_size] = '\0';
			}
		}
		void resize(size_t n, char c)
		{
			if (_size >= n)
			{
				erase(n);
			}
			else
			{
				append(n - _size, c);
				_str[_size] = '\0';
			}
		}
		void reserve(size_t n = 0)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//第n+1个位置存的是'/0'
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0)
		{
			const char* p = strstr(_str + pos, sub);
			if (p)
			{
				return p - _str;
			}
			else
			{
				return npos;
			}
			return npos;
		}
		char& operator[] (size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[] (size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = c;
			++_size;
			_str[_size] = '\0';
		}
		string& append(size_t n, char c)
		{
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}
			size_t begin = _size;
			_size += n;
			for (size_t i = begin; i < _size; i++)
			{
				_str[i] = c;
			}
			return *this;
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& append(const string& str)
		{
			append(str._str);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <  _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end1 = _size + 1;
			size_t end2 = _size + len + 1;
			while (end1 > pos)
			{
				_str[end2 - 1] = _str[end1 - 1];
				end2--;
				end1--;
			}
			_str[_size + len] = '\0';
			strncpy(_str + pos, str, len);
			//for (int i = 0; i < len; i++)
			//{
			//	_str[i] = str[i];
			//}
			_size+=len;
			return *this;
		}
		void erase(size_t pos, size_t len = npos)//len的位置不删除
		{
			assert(pos < _size);
			if (len == _size || len + pos >= _size) 
			{
				_str[pos] = '\0';
				_size = pos;
				return;
			}
			size_t begin = pos + len;
			while (begin <= _size)
			{
				_str[begin - len] = _str[begin];
				begin++;
			}
			_size -= len;
		}
		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos = -1;;
	};
	ostream& operator<<(ostream& out, const string& s)
	{
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/
		for (auto ch : s)
			out << ch;

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		//in >> ch;
		ch = in.get();
		s.reserve(128);

		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			//in >> ch;
			ch = in.get();
		}

		return in;
	}
	void test1_string()
	{
		string s1("hello");
		string s3("hello world");
		char s2[] = "meme";
		size_t i = 5;
		size_t j = 6;
		size_t ret = i - j;
		s1.resize(12,'c');
		//s1.insert(0, s2);
		//s1.erase(4, 0);
		cout << s1 << endl;
		//s1.append(s2);
		//cout << s1 << endl;
		//s1.reserve(25);		
	}
	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)++;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto& ch : s1)
		{
			ch++;
			cout << ch << " ";
		}
		cout << endl;

		cout << s1.c_str() << endl;
	}
	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.push_back(' ');
		s1.append("hello bit hello bit");

		cout << s1.c_str() << endl;

		s1 += '#';
		s1 += "*********************";
		cout << s1.c_str() << endl;

		string s2;
		s2 += '#';
		s2 += "*********************";
		cout << s2.c_str() << endl;
	}
	void test_string3()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(5, '%');
		cout << s1.c_str() << endl;

		s1.insert(s1.size(), '%');
		cout << s1.c_str() << endl;

		s1.insert(0, '%');
		cout << s1.c_str() << endl;
	}
	void test_string4()
	{
		string s1("hello");
		string s2("hello world");
		s1.append(5, 'x');
		s1.resize(7);
		cout << s1 << endl;

		//cout << (s1 >= s2) << endl;

		//s1[0] = 'z';
		//cout << (s1 >= s2) << endl;

		//cout << s1 << endl;
		//cin >> s1;
		//cout << s1 << endl;

		/*char ch1, ch2;
		cin >> ch1 >> ch2;*/
	}
}