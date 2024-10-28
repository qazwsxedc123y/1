#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
using namespace std;



namespace bit
{
	// 为了实现简单，在哈希桶的迭代器类中需要用到hashBucket本身，
	template<class K, class V, class KeyOfValue, class HF>
	class HashBucket;

	// 注意：因为哈希桶在底层是单链表结构，所以哈希桶的迭代器不需要--操作
	template <class K, class V, class KeyOfValue, class HF>
	struct HBIterator
	{
		typedef HashBucket<K, V, KeyOfValue, HF> HashBucket;
		typedef HashBucketNode<V>* PNode;
		typedef HBIterator<K, V, KeyOfValue, HF> Self;

		HBIterator(PNode pNode = nullptr, HashBucket* pHt = nullptr)
		{
			_pNode = pNode;
			_pHt = pHt;
		}
		Self& operator++()
		{
			// 当前迭代器所指节点后还有节点时直接取其下一个节点
			if (_pNode->_pNext)
				_pNode = _pNode->_pNext;
			else
			{
				// 找下一个不空的桶，返回该桶中第一个节点
				size_t bucketNo = _pHt->HashFunc(KeyOfValue()(_pNode->_data)) + 1;
				for (; bucketNo < _pHt->BucketCount(); ++bucketNo)
				{
					if (_pNode = _pHt->_ht[bucketNo])
						break;
				}
			}

			return *this;
		}
		Self operator++(int)
		{
			Self temp = *this;
			++(*this);
			return temp;
		}
		V& operator*()
		{
			return _pNode->_data;
		}
		V* operator->()
		{
			return *_pNode->_data;
		}
		bool operator==(const Self& it) const
		{
			return _pNode == it;
		}
		bool operator!=(const Self& it) const
		{
			return !_pNode == it;
		}
		PNode _pNode;             // 当前迭代器关联的节点
		HashBucket* _pHt;         // 哈希桶--主要是为了找下一个空桶时候方便
	};

	// unordered_map中存储的是pair<K, V>的键值对，K为key的类型，V为value的类型，HF哈希函数类型
	// unordered_map在实现时，只需将hashbucket中的接口重新封装即可
	template<class K, class V, class HF = DefHashF<K>>
	class unordered_map
	{
		typedef HashBucket<K, pair<K, V>, KeyOfValue, HF> HT;
		// 通过key获取value的操作
		struct KeyOfValue
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
	public:
		typename typedef HT::Iterator iterator;
	public:
		unordered_map() : _ht()
		{}
		////////////////////////////////////////////////////
		iterator begin() { return _ht.begin(); }
		iterator end() { return _ht.end(); }
		////////////////////////////////////////////////////////////
		// capacity
		size_t size()const { return _ht.size(); }
		bool empty()const { return _ht.empty(); }
		///////////////////////////////////////////////////////////
		// Acess
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.InsertUnique(pair<K, V>(key, V()));
			return ret.fisrt->second;
		}
		const V& operator[](const K& key)const;
		//////////////////////////////////////////////////////////
		// lookup
		iterator find(const K& key) { return _ht.Find(key); }
		size_t count(const K& key) { return _ht.Count(key); }
		/////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const pair<K, V>& valye)
		{
			return _ht.Insert(valye);
		}

		iterator erase(iterator position)
		{
			return _ht.Erase(position);
		}
		////////////////////////////////////////////////////////////
		// bucket
		size_t bucket_count() { return _ht.BucketCount(); }
		size_t bucket_size(const K& key) { return _ht.BucketSize(key); }
	private:
		HT _ht;
	};
}








//namespace bit
//{
//	// 为了实现简单，在哈希桶的迭代器类中需要用到hashBucket本身，
//	template<class K, class V, class KeyOfValue, class HF>
//	class HashBucket;
//
//	// 注意：因为哈希桶在底层是单链表结构，所以哈希桶的迭代器不需要--操作
//	template <class K, class V, class KeyOfValue, class HF>
//	struct HBIterator
//	{
//		typedef HashBucket<K, V, KeyOfValue, HF> HashBucket;
//		typedef HashBucketNode<V>* PNode;
//		typedef HBIterator<K, V, KeyOfValue, HF> Self;
//
//		HBIterator(PNode pNode = nullptr, HashBucket* pHt = nullptr)
//		{
//			_pNode = pNode;
//			_pHt = pHt;
//		}
//		Self& operator++()
//		{
//			// 当前迭代器所指节点后还有节点时直接取其下一个节点
//			if (_pNode->_pNext)
//				_pNode = _pNode->_pNext;
//			else
//			{
//				// 找下一个不空的桶，返回该桶中第一个节点
//				size_t bucketNo = _pHt->HashFunc(KeyOfValue()(_pNode->_data)) + 1;
//				for (; bucketNo < _pHt->BucketCount(); ++bucketNo)
//				{
//					if (_pNode = _pHt->_ht[bucketNo])
//						break;
//				}
//			}
//
//			return *this;
//		}
//		Self operator++(int)// 后置++
//		{
//			Self temp = *this;
//			++(*this);
//			return temp;
//		}
//		V& operator*()
//		{
//			return _pNode->_data;
//		}
//		V* operator->()
//		{
//			return *_pNode->_data;
//		}
//		bool operator==(const Self& it) const
//		{
//			return _pNode == it;
//		}
//		bool operator!=(const Self& it) const
//		{
//			return !_pNode == it;
//		}
//		PNode _pNode;             // 当前迭代器关联的节点
//		HashBucket* _pHt;         // 哈希桶--主要是为了找下一个空桶时候方便
//	};
//
//	// unordered_set中存储的是K类型，HF哈希函数类型
//	// unordered_set在实现时，只需将hashbucket中的接口重新封装即可
//	template<class K, class HF = DefHashF<K>>
//	class unordered_set
//	{
//		typedef HashBucket<K, K, KeyOfValue, HF> HT;
//		// 通过key获取value的操作
//		struct KeyOfValue
//		{
//			const K& operator()(const K& data)
//			{
//				return data;
//			}
//		};
//	public:
//		typename typedef HT::Iterator iterator;
//	public:
//		unordered_set() : _ht()
//		{}
//		////////////////////////////////////////////////////
//		iterator begin() { return _ht.begin(); }
//		iterator end() { return _ht.end(); }
//		////////////////////////////////////////////////////////////
//		// capacity
//		size_t size()const { return _ht.size(); }
//		bool empty()const { return _ht.empty(); }
//		///////////////////////////////////////////////////////////
//		// lookup
//		iterator find(const K& key) { return _ht.Find(key); }
//		size_t count(const K& key) { return _ht.Count(key); }
//		/////////////////////////////////////////////////
//		// modify
//		pair<iterator, bool> insert(const K& valye)
//		{
//			return _ht.Insert(valye);
//		}
//
//		iterator erase(iterator position)
//		{
//			return _ht.Erase(position);
//		}
//		////////////////////////////////////////////////////////////
//		// bucket
//		size_t bucket_count() { return _ht.BucketCount(); }
//		size_t bucket_size(const K& key) { return _ht.BucketSize(key); }
//	private:
//		HT _ht;
//	};
//}


//HashFunc<int>
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//HashFunc<string>
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		// BKDR
		size_t hashi = 0;
		for (auto e : key)
		{
			hashi *= 31;
			hashi += e;
		}
		return hashi;
	}
};
namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};


	// K 为 T 中key的类型
	// T 可能是键值对，也可能是K
	// KeyOfT: 从T中提取key
	// Hash将key转化为整形，因为哈市函数使用除留余数法
	template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{

		typedef HashNode<T> Node;
	public:
		HashTable()
		{
			_tables.resize(10, nullptr);
		}

		// 哈希桶的销毁
		~HashTable()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		// 插入值为data的元素，如果data存在则不插入
		bool Insert(const T& data)
		{
			Hash hf;
			KeyOfT kot;
			if (Find(kot(data)))
			{
				return true;
			}
			if (_n == _tables.size())// 需要扩容
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);
				for (int i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 挪动到映射的新表
						size_t hashi = hf(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					cur = nullptr;
				}
			}
			size_t hashi= hf(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return true;
		}

		// 在哈希桶中查找值为key的元素，存在返回true否则返回false﻿
		bool Find(const K& key)
		{
			Hash hf;
			KeyOfT kot;
			size_t hashi = hf(kot(key)) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return true;
				}
				cur = cur->_next;
			}
			return false;
		}

		// 哈希桶中删除key的元素，删除成功返回true，否则返回false
		bool Erase(const K& key)
		{
			Hash hf;
			KeyOfT kot;
			size_t hashi = hf(kot(key)) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)//找到了要删除的
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		vector<Node*> _tables;  // 指针数组
		size_t _n = 0;			// 表中存储数据个数
	};
}




////基类
//class Person
//{
//protected:
//	string _name; //姓名
//	string _sex;  //性别
//	int _age;     //年龄
//};
////派生类
//class Student : public Person
//{
//protected:
//	int _class;   //班级
//};
//int main()
//{
//	Person p; // 基类对象
//	Student s; // 派生类对象
//	// 派生类对象赋值给基类对象
//	// 为什么不可以把基类对象赋值给派生类对象
//
//	Person* ptr = &s; //派生类对象赋值给基类指针
//
//	Person& ref = s; //派生类对象赋值给基类引用
//	return 0;
//}