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

			_root->_col = BLACK;
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
				Node* uncle = parent->_right;
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
				Node* uncle = parent->_right;
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
		cout << root->_kv.first << " ";
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