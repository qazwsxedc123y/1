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
		//Ĭ�Ͻ����ɫΪ��ɫ

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
			//��ǰ��
			//parent����
			if (parent == grandfather->_left)
			{
				if ()
				{
				//�龰һ��cur->�죬parent->�죬grandfather->�ڣ�uncle������Ϊ��
					//     g
					//   p   u
					// c
					// 
					//�����p��u��Ϊ�ڣ�g��Ϊ�죬���gΪ�����ԣ�Ҫ�������ϵ���
				}
				else
				{
				//�龰����cur->�죬parent->�죬grandfather->�ڣ�uncle������/Ϊ��
					//     g
					//   p   u
					// c
					// 
					// �������g�ҵ�����p��Ϊ�ڣ�g��Ϊ�죬���gΪ�����ԣ�ֱ��break
				//�龰����cur->�죬parent->�죬grandfather->�ڣ�uncle������/Ϊ��
					//       g
					//   p      u
					//     c
					// �������p���������Ϊ�龰����
				}
			}
			else//�龰��ŷ�����
			{

			}			
		}
		//���
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