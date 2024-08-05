#pragma once

#include"HashTable.h"
namespace test
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
	public:
		struct MapKeyOFT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash>::const_iterator const_iterator;
		
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

		bool insert(const pair<const K, V>& kv)
		{
			return _ht.Insert(kv);
		}
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash>_ht;
	};
	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("insert", "插入"));

		for (auto& kv : dict)
		{
			//kv.first += 'x';
			//kv.second += 'x';

			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}
}
