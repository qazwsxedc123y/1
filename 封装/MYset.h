#pragma once
#include"RBTree.h"

namespace bit
{
	template<class K>
	class set
	{
	public:
		//·Âº¯Êý
		struct SetKeyOfT 
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
		bool IsBalance()
		{
			return _t.IsBalance();
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}