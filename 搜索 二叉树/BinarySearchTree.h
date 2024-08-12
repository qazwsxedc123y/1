#pragma once
#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	//���캯��
	BSTree()
	{
		_root = nullptr;
	}
	 
	Node _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_key); //���������
		newNode->_left = _Copy(root->_left); //����������
		newNode->_right = _Copy(root->_right); //����������
		return newNode;
	}

	//�������캯��
	BSTree(const BSTree<K>& t)
	{
		_root = _Copy(t._root); //����t����Ķ���������
	}

	//�ִ�д��
	BSTree<K>& operator=(BSTree<K> t) //������������ֵ��ʱ���Զ����ÿ������캯��
	{
		swap(_root, t._root); //��������������Ķ���������
		return *this; //֧��������ֵ
	}

	void free_tree(Node* root)
	{
		if (root != nullptr)
		{
			if (root->_left != nullptr)
			{
				free_tree(root->_left);
				root->_left = nullptr;
			}
			if (root->_right != nullptr)
			{
				free_tree(root->_right);
				root->_right = nullptr;
			}
			free(root);
			root = nullptr;
		}
	}

	const BSTree<K>& operator=(const BSTree<K>& t)
	{
		if (this != &t) //��ֹ�Լ����Լ���ֵ
		{
			free_tree(t._root);
			_root = _Copy(t._root); //����t����Ķ���������
		}
		return *this; //֧��������ֵ
	}

	~BSTree()
	{
		free_tree(_root);//�����Ӻ���
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)//��һ��
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& key)
	{
		//ɾ���ĵط���Ϊ�����������
		//1.����Ϊ�գ��޺��ӽ�㣩
		//2.�Һ���Ϊ��
		//3.���Ҷ���Ϊ�գ��滻Ϊ������  �ҵ���С
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
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
					swap(cur->_key, subLeft->_key);
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
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}
private:
	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else//�ҵ���Ҫɾ������
		{
			if (root->_left == nullptr)
			{
				Node* del = root;
				root = root->_right;
				delete del;

				return true;
			}
			else if (root->_right == nullptr)
			{
				Node* del = root;
				root = root->_left;
				delete del;

				return true;
			}
			else
			{
				Node* subLeft = root->_right;
				while (subLeft->_left)
				{
					subLeft = subLeft->_left;
				}
				swap(root->_key, subLeft->_key);
				return _EraseR(root->_right, key);
				//return _EraseR(subLeft, key);//�����������Ϊԭ��subLeft����Ͳ�������
				//����������ȫû���⣬���������޸Ľ��ָ��
			}
		}
	}
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else
		{
			return false;
		}
	}
	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		else
		{
			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
	//Node* _root = nullptr;
};