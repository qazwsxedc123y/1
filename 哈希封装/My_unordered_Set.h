#pragma once

#include"HashTable.h"
namespace test
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
	public:
		struct SetKeyOFT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename hash_bucket::HashTable<K, K, SetKeyOFT, Hash>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOFT, Hash>::const_iterator const_iterator;

		//iterator begin()
		//{
		//	return _ht.begin();
		//}

		//iterator end()
		//{
		//	return _ht.end();
		//}

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, K, SetKeyOFT, Hash> _ht;
	};
	void test_set()
	{
		unordered_set<int> dict;
		dict.insert(5);
		dict.insert(25);
		dict.insert(35);
		dict.insert(3);
		dict.insert(2);
		for (auto& e : dict)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}