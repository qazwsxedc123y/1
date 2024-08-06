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

		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash>::iterator iterator;
		//typedef typename hash_bucket::HashTable<K, pair<const K,const V>, MapKeyOFT, Hash>::const_iterator const_iterator;
		
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		/*const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}*/

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			auto ret = _ht.Insert(make_pair(kv.first,kv.second));
			return pair<iterator, bool>(iterator(ret.first._node, ret.first._pht, ret.first._hashi), ret.second);

			//return _ht.Insert(kv);
		}
		V& operator[](const K& key)
		{
			//pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
		const V& operator[](const K& key) const
		{
			pair<iterator, bool>ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
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
		string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		unordered_map<string, int> ht;
		for (auto& e : arr)
		{
			ht[e]++;
		}

		for (auto& kv : ht)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}
}
