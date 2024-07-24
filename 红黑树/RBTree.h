#pragma once
#include<map>
#include<set>

enum Colour
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K,V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		//默认结点颜色为红色

		if (parent->_kv.first < kv.first)
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
				if ()
				{
				//情景一：cur->红，parent->红，grandfather->黑，uncle存在且为红
					//     g
					//   p   u
					// c
					// 
					//解决：p，u改为黑，g改为红，最后g为红所以，要继续向上调整
				}
				else
				{
				//情景二：cur->红，parent->红，grandfather->黑，uncle不存在/为黑
					//     g
					//   p   u
					// c
					// 
					// 解决：对g右单旋，p改为黑，g改为红，最后g为黑所以，直接break
				//情景三：cur->红，parent->红，grandfather->黑，uncle不存在/为黑
					//       g
					//   p      u
					//     c
					// 解决：对p左单旋，后变为情景二。
				}
			}
			else//情景大概反着来
			{

			}			
		}
		//最后
		_root->_col = BLACK;

		return true;
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
private:
	Node* _root = nullptr;
};