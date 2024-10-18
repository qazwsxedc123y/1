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

		bool Insert(const pair<K, V>& kv);
		HashData<K, V>* Find(const K& key);
		bool Erase(const K& key);

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;  // 表中存储数据个数
	};
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