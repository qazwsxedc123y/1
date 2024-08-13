#pragma once
#include<string>

namespace test
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		pair<K, V> _data;
		BSTreeNode(const pair<K, V>& data)
			:_left(nullptr)
			, _right(nullptr)
			, _data(data)
		{}
	};
	template<class K, class V>
	class _BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(make_pair(key, value));
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				parent = cur;
				if (cur->_data.first < key)
				{
					cur = cur->_right;
				}
				else if (cur->_data.first > key)
				{
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur= new Node(make_pair(key, value));
			if (parent->_data.first > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_data.first < key)
				{
					cur = cur->_right;
				}
				else if (cur->_data.first > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_data.first < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_data.first > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else//�ҵ���Ҫɾ���Ľ��
				{
					if (cur->_left == nullptr)//���һ
					{
						//��Ϊ��
						//�޸��丸�׽��
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)//�����
					{
						//��Ϊ��
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur = parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else//�����
					{
						//���Ҷ���Ϊ��
						// �滻��
						// ��������С�ڵ�(����ڵ�)
						Node* parent = cur;
						Node* subLeft = cur->_right;
						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}
						//swap(cur->_key, subLeft->_key);
						swap(cur->_data, subLeft->_data);
						if (subLeft == parent->_right)//ɾ����������������
						{
							parent->_right = subLeft->_right;
						}
						else
						{
							parent->_left = subLeft->_right;
						}
						delete subLeft;
					}
					return true;
				}
			}
			return false;
		}
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return ;
			_InOrder(root->_left);
			cout << root->_data.first << ":" << root->_data.second;
			_InOrder(root->_right);
		}
		void InOrder()
		{
			_InOrder(_root);
		}
	private:
		Node* _root = nullptr;
	};

	void TestBSTree()
	{
		_BSTree<string, string> dict;
		dict.Insert("insert", "����");
		dict.Insert("erase", "ɾ��");
		dict.Insert("left", "���");
		dict.Insert("string", "�ַ���");

		string str;
		while (cin >> str)
		{
			auto ret = dict.Find(str);
			if (ret)
			{
				cout << str << ":" << ret->_data.second << endl;
			}
			else
			{
				cout << "����ƴд����" << endl;
			}
		}

		string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
		// ͳ��ˮ�����ֵĴ�
		_BSTree<string, int> countTree;
		for (auto str : strs)
		{
			auto ret = countTree.Find(str);
			if (ret == NULL)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_data.second++;
			}
		}
		countTree.InOrder();
	}
}