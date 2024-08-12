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
	//构造函数
	BSTree()
	{
		_root = nullptr;
	}
	 
	Node _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_key); //拷贝根结点
		newNode->_left = _Copy(root->_left); //拷贝左子树
		newNode->_right = _Copy(root->_right); //拷贝右子树
		return newNode;
	}

	//拷贝构造函数
	BSTree(const BSTree<K>& t)
	{
		_root = _Copy(t._root); //拷贝t对象的二叉搜索树
	}

	//现代写法
	BSTree<K>& operator=(BSTree<K> t) //编译器接收右值的时候自动调用拷贝构造函数
	{
		swap(_root, t._root); //交换这两个对象的二叉搜索树
		return *this; //支持连续赋值
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
		if (this != &t) //防止自己给自己赋值
		{
			free_tree(t._root);
			_root = _Copy(t._root); //拷贝t对象的二叉搜索树
		}
		return *this; //支持连续赋值
	}

	~BSTree()
	{
		free_tree(_root);//调用子函数
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)//第一次
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
		//删除的地方分为三种情况讨论
		//1.左孩子为空（无孩子结点）
		//2.右孩子为空
		//3.左右都不为空，替换为左的最大  右的最小
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
			else//找到了要删除的结点
			{
				if (cur->_left == nullptr)//情况一
				{
					//左为空
					//修改其父亲结点
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
				else if (cur->_right == nullptr)//情况二
				{
					//右为空
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
				else//情况三
				{
					//左右都不为空
					// 替换法
					// 右树的最小节点(最左节点)
					Node* parent = cur;
					Node* subLeft = cur->_right;
					while (subLeft->_left)
					{
						parent = subLeft;
						subLeft = subLeft->_left;
					}
					swap(cur->_key, subLeft->_key);
					if (subLeft == parent->_right)//删除的右子树无左结点
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
		else//找到了要删除的数
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
				//return _EraseR(subLeft, key);//这个不行是因为原本subLeft本身就不是引用
				//操作过程完全没问题，但他不会修改结点指向
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