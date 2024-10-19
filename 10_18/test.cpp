#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<map>

using namespace std;
#pragma once

// 请完成哈希表的如下操作
// 哈希函数采用除留余数法﻿
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 哈希表中支持字符串的操作
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};

// 以下采用开放定址法，即线性探测解决冲突
namespace open_address
{
	enum State
	{
		EXIST,
		EMPTY,
		DELETE

	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// 负载因子0.7就扩容
			if (_n * 10 / _tables.size() >= 7)//扩容
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}
				_tables.swap(newHT._tables);
			}
			Hash hf;
			// 线性探测
			size_t hashi = hf(kv.first) % _tables.size();
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}
		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state != DELETE
					&& _tables[hashi]._kv.first == key)
					return &_tables[hashi];
				++hashi;
				hashi %= _tables.size();
			}

			//没有找到
			return NULL;
		}
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)//存在
			{
				--_n;
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}
		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._state == EXIST)
				{
					cout << "[" << i << "]->" << _tables[i]._kv.first << ":" << _tables[i]._kv.second << endl;
				}
				else if (_tables[i]._state == EMPTY)
				{
					printf("[%zd]->\n", i);
				}
				else
				{
					printf("[%zd]->D\n", i);
				}
			}
			cout << endl;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;  // 表中存储数据个数
	};
	void TestHT1()
	{
		HashTable<int, int> ht;
		int a[] = { 4,14,24,34,5,7,1,6,10,56,11,35 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(-3, -3));
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(-3, -3));
		ht.Print();
		ht.Erase(3);
		ht.Print();
		if (ht.Find(3))
		{
			cout << "3存在" << endl;
		}
		else
		{
			cout << "3不存在" << endl;
		}

		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
	}
	void TestHT2()
	{
		string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		//HashTable<string, int, HashFuncString> ht;
		HashTable<string, int> ht;
		for (auto& e : arr)
		{
			HashData<string, int>* ret = ht.Find(e);
			if (ret)//存在
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}
		ht.Print();

		ht.Insert(make_pair("apple", 1));
		ht.Insert(make_pair("sort", 1));

		ht.Insert(make_pair("abc", 1));
		ht.Insert(make_pair("acb", 1));
		ht.Insert(make_pair("aad", 1));

		ht.Print();
	}
}
int main()
{
	open_address::TestHT1();
	open_address::TestHT2();
	return 0;
}







// 实现完成后，请对整形 和 字符串完成测试

//class Solution {
//public:
//    vector<string> uncommonFromSentences(string s1, string s2) {
//        unordered_map<string, int> mp1;
//        unordered_map<string, int> mp2;
//        vector<string> ret;
//        int n1 = s1.size();
//        int n2 = s2.size();
//        int i = 0;
//        string tmp;
//        while (i < n1)
//        {
//            while (i < n1 && s1[i] != ' ')
//            {
//                tmp += s1[i++];
//            }
//            i++;
//            mp1[tmp]++;
//            tmp.clear();
//        }
//        i = 0;
//        while (i < n2)
//        {
//            while (i < n2 && s2[i] != ' ')
//            {
//                tmp += s2[i++];
//            }
//            i++;
//            mp2[tmp]++;
//            tmp.clear();
//        }
//        auto it = mp2.begin();
//        while (it != mp2.end())
//        {
//            if (mp1.find(it->first) == mp1.end() && it->second == 1)
//            {
//                ret.push_back(it->first);
//            }
//            it++;
//        }
//        auto it = mp1.begin();
//        while (it != mp1.end())
//        {
//            if (mp2.find(it->first) == mp2.end() && it->second == 1)
//            {
//                ret.push_back(it->first);
//            }
//            it++;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        int n = nums.size();
//        unordered_set<int> s;
//        for (int i = 0; i < n; i++)
//        {
//            if (s.find(nums[i]) != s.end())// 没有
//            {
//                return true;
//            }
//            s.insert(nums[i]);
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set <int> s1;
//        for (auto num : nums1)
//        {
//            s1.insert(num);
//        }
//        vector<int> ret;
//        for (auto num : nums2)
//        {
//            if (s1.count(num) != 0 && !ret.find(num)!=ret.end())
//            {
//                ret.push_back(num);
//            }
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    string s1{ "this apple is sweet" };
//    string s2{ "this apple is sour" };
//    vector<int> v{ 1,2,3,4 };
//    s.containsDuplicate(v);
//    return 0;
//}