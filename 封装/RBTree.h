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
		//默认结点颜色为红色

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
			//大前提
			//parent在左
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//Node* uncle = parent->_right;//错误二
				if (uncle && uncle->_col == RED)
				{
					//情景一：cur->红，parent->红，grandfather->黑，uncle存在且为红
						//     g
						//   p   u
						// c
						// 
						//解决：p，u改为黑，g改为红，最后g为红所以，要继续向上调整
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						//情景二：cur->红，parent->红，grandfather->黑，uncle不存在/为黑
							//     g
							//   p   u
							// c
							// 
						// 解决：对g右单旋，p改为黑，g改为红，最后g为黑所以，直接break
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//情景三：cur->红，parent->红，grandfather->黑，uncle不存在/为黑
							//       g
							//   p      u
							//     c
						// 解决：对p左单旋，后变为情景二。
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else//情景大概反着来
			{
				//1  uncle
				Node* uncle = grandfather->_left;//错误一
				//Node* uncle = parent->_right;//错误一
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
		//最后
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
				cout << "存在黑色节点数量不相等的路径" << endl;
				return false;
			}
			return true;
		}
		if (root->_col == RED)
		{
			if (root->_parent->_col == RED)
			{
				cout << "有连续的红色节点" << endl;
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
		//1:是否存在 红-红 
	   //每条路径黑色结点是否相同个数
	   //最长的不超过最短的二倍
	   //根，叶子为黑
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