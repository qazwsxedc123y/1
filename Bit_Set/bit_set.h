#pragma once
#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<bitset>
using namespace std;

//λͼ

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
		void set(size_t x)//���
		{
			int i = x / 32;
			int j = x % 32;
			//��1��1 |
			_bits[i] |= (1 << j);
		}
		void reset(size_t x)//ɾ��
		{
			int i = x / 32;
			int j = x % 32;
			//ֻ��һλ��1��Ϊ0,���Ϊ0����0
			_bits[i] &= (~(1 << j));
		}
		bool test(size_t x)//����Ƿ����
		{
			int i = x / 32;
			int j = x % 32;
			//���ڷ��� �棬��֮Ϊ ��

			return _bits[i] & (1 << j);
		}
	private:
		vector<int> _bits;
	};


	//��100�ڸ��޷��ŵ����������ҳ�����һ�ε��Ǹ���
	//λͼ��˫��
	template<size_t N>
	class twobitset_1
	{
	public:
		void set(size_t x)
		{
			//00->����0��
			//01->����1��
			//10->����2�μ�����
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
			//01->����1��
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
			//00->����0��
			//01->����1��
			//10->����2��
			//11->����2������
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
			//01->����1��
			//10->����2��
			for (size_t i = 0; i < N; i++)
			{
				if (!_bs1.test(i) && _bs2.test(i))//һ��
				{
					cout << "[1]->" << i << endl;
				}
				if (_bs1.test(i) && !_bs2.test(i))//����
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