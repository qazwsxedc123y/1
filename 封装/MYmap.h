#pragma once
#include"RBTree.h"
namespace bit
{
	template<class K, class V>
	class map
	{
	public:
		//�º���
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		// ����ģ��ȡ��Ƕ���ͣ���typename���߱���������������
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
			pair < iterator, bool> ret = insert(make_pair(key, V()));//Ĭ�Ϲ���Ϊ0
			//V()�������V() ��һ����ʱ������ V ���͵Ķ���
			// ��ʹ�� V ���͵�Ĭ�Ϲ��캯������һ��Ĭ�ϵ�ֵ����
			// ��������Ŀ����Ϊ��ȷ����ʹӳ����û�иü���
			// Ҳ�ܹ�����һ��Ĭ�Ϲ����ֵ�����ã��Ա��ڲ����¼�ֵ��ʱ��
			// ͨ���������ã�����ֱ��Ϊ�¼�����һ��Ĭ�Ϲ����ֵ��
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
