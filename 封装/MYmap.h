#pragma once
#include"RBTree.h"
namespace bit
{
	template<class K, class V>
	class map
	{
	public:
		//仿函数
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		// 对类模板取内嵌类型，加typename告诉编译器这里是类型
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;
		iterator begin() const
		{
			return _t.begin();
		}
		iterator end() const
		{
			return _t.end();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
		V& operator[](const K& key)
		{
			pair < iterator, bool> ret = insert(make_pair(key, V()));//默认构造为0
			//V()：在这里，V() 是一个临时创建的 V 类型的对象。
			// 它使用 V 类型的默认构造函数创建一个默认的值对象。
			// 这样做的目的是为了确保即使映射中没有该键，
			// 也能够返回一个默认构造的值的引用，以便在插入新键值对时，
			// 通过返回引用，可以直接为新键关联一个默认构造的值。
			return ret.first->second;
		}
		bool IsBalance()
		{
			return _t.IsBalance();
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}
