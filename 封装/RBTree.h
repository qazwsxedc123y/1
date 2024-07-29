#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	Self& operator--()
	{
		
	}
	Self& operator++()
	{
		
	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};


template<class K,class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator <T, T&, T*> iterator;
	typedef __TreeIterator <T,const T&,const T*> const_iterator;
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}	
	iterator end()
	{
		return iterator(nullptr);
	}
	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return const_iterator(cur);
	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);

			_root->_col = BLACK;
			return make_pair(iterator(_root), true);;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		KeyOfT kot;

		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);;
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		//Ĭ�Ͻ����ɫΪ��ɫ

		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//��ǰ��
			//parent����
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//Node* uncle = parent->_right;//�����
				if (uncle && uncle->_col == RED)
				{
					//�龰һ��cur->�죬parent->�죬grandfather->�ڣ�uncle������Ϊ��
						//     g
						//   p   u
						// c
						// 
						//�����p��u��Ϊ�ڣ�g��Ϊ�죬���gΪ�����ԣ�Ҫ�������ϵ���
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						//�龰����cur->�죬parent->�죬grandfather->�ڣ�uncle������/Ϊ��
							//     g
							//   p   u
							// c
							// 
						// �������g�ҵ�����p��Ϊ�ڣ�g��Ϊ�죬���gΪ�����ԣ�ֱ��break
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//�龰����cur->�죬parent->�죬grandfather->�ڣ�uncle������/Ϊ��
							//       g
							//   p      u
							//     c
						// �������p���������Ϊ�龰����
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else//�龰��ŷ�����
			{
				//1  uncle
				Node* uncle = grandfather->_left;//����һ
				//Node* uncle = parent->_right;//����һ
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}

				else
				{
					if (cur == parent->_right)//2
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else//3
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		//���
		_root->_col = BLACK;

		return make_pair(iterator(newnode), true);;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		Node* parentParent = parent->_parent;

		parent->_parent = subR;
		if (subRL)
			subRL->_parent = parent;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}
	}

	iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}
		return end();
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << kof(root->_data) << " ";
		_InOrder(root->_right);
	}
	bool Check(Node* root, int blacknum, const int refVal)
	{
		if (root == nullptr)
		{
			if (refVal != blacknum)
			{
				cout << "���ں�ɫ�ڵ���������ȵ�·��" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED)
		{
			if (root->_parent->_col == RED)
			{
				cout << "�������ĺ�ɫ�ڵ�" << endl;
				return false;
			}
		}
		if (root->_col == BLACK)
		{
			++blacknum;
		}
		return Check(root->_left, blacknum, refVal)
			&& Check(root->_right, blacknum, refVal);

	}
	bool IsBalance()
	{
		//1:�Ƿ���� ��-�� 
	   //ÿ��·����ɫ����Ƿ���ͬ����
	   //��Ĳ�������̵Ķ���
	   //����Ҷ��Ϊ��
		if (_root == nullptr)
			return true;
		if (_root->_col == RED)
			return false;
		int refVal = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++refVal;
			}
			cur = cur->_left;
		}
		int blacknum = 0;
		return Check(_root, blacknum, refVal);
	}
private:
	Node* _root = nullptr;
};