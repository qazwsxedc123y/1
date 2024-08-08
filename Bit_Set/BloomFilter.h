#pragma once

#include"bit_set.h"
struct BKDRHash
{
	size_t operator()(const string& key)
	{
		// BKDR
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			char ch = key[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 5381;
		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};
namespace BF
{
	template<size_t N,
		class K = string,
		class HashFunc1= BKDRHash,
		class HashFunc2= APHash,
		class HashFunc3= DJBHash>
	class BloomFilter
	{
	public:
		void Set(const K& key)
		{
			size_t hashi1 = HashFunc1()(key) % N;
			size_t hashi2 = HashFunc2()(key) % N;
			size_t hashi3 = HashFunc3()(key) % N;
			_bs.set(hahi1);
			_bs.set(hahi2);
			_bs.set(hahi3);

			/*cout << hash1 << endl;
			cout << hash2 << endl;
			cout << hash3 << endl << endl;*/

		}

		//一般不支持删除，删除一个值可能会影响其他值
		//非要支持删除，也是可以的，用多个位标记一个值，存引用计数
		//但是这样话，空间消耗的就变大了
		void Reset(const K& key);

		bool Test(const K& key)
		{
			// 判断不存在是准确的
			// 判断存在是不准确的（有概率）
			size_t hashi1 = HashFunc1()(key) % N;
			if (_bs.test(hashi1) == false)
				return false;

			size_t hashi2 = HashFunc2()(key) % N;
			if (_bs.test(hashi2) == false)
				return false;

			size_t hashi3 = HashFunc3()(key) % N;
			if (_bs.test(hashi3) == false)
				return false;

			// 存在误判的
			return true;
		}

	private:
		bitset<N> _bs;
	};
}