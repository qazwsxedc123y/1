#pragma once
#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<bitset>
using namespace std;

//位图

namespace _bitset
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);
		}
		void set(size_t x)//添加
		{
			int i = x / 32;
			int j = x % 32;
			//有1则1 |
			_bits[i] |= (1 << j);
		}
		void reset(size_t x)//删除
		{
			int i = x / 32;
			int j = x % 32;
			//只改一位将1变为0,如果为0则还是0
			_bits[i] &= (~(1 << j));
		}
		bool test(size_t x)//检测是否存在
		{
			int i = x / 32;
			int j = x % 32;
			//存在返回 真，反之为 假

			return _bits[i] & (1 << j);
		}
	private:
		vector<int> _bits;
	};


	//给100亿个无符号的整数，查找出现了一次的那个数
	//位图（双）
	template<size_t N>
	class twobitset_1
	{
	public:
		void set(size_t x)
		{
			//00->出现0次
			//01->出现1次
			//10->出现2次及以上
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				_bs2.set(x);
			}
			else if (!_bs1.test(x) && _bs2.test(x))
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
		}
		void PrintOnce()
		{
			//01->出现1次
			for (size_t i = 0; i < N; i++)
			{
				if (!_bs1.test(i) && _bs2.test(i))
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};


	template<size_t N>
	class twobitset_2
	{
	public:
		void set(size_t x)
		{
			//00->出现0次
			//01->出现1次
			//10->出现2次
			//11->出现2次以上
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				_bs2.set(x);
			}
			else if (!_bs1.test(x) && _bs2.test(x))
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
			else if (_bs1.test(x) && !_bs2.test(x))//10
			{
				_bs2.set(x);
			}
		}
		void PrintUnderTwo()
		{
			//01->出现1次
			//10->出现2次
			for (size_t i = 0; i < N; i++)
			{
				if (!_bs1.test(i) && _bs2.test(i))//一次
				{
					cout << "[1]->" << i << endl;
				}
				if (_bs1.test(i) && !_bs2.test(i))//两次
				{
					cout << "[2]->" << i << endl;
				}
			}
			cout << endl << endl;
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}