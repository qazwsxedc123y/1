#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data = T(), Colour col = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _col(col)

	{}
};

// 请模拟实现红黑树的插入--注意：为了后序封装map和set，本文在实现时给红黑树多增加了一个头结点
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	// 在红黑树中插入值为data的节点，插入成功返回true，否则返回false
	// 注意：为了简单起见，本次实现红黑树不存储重复性元素
	bool Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		// 第一次插入结点
		if (pRoot == nullptr)
		{
			pRoot = new Node(data, BLACK);
			//////////////////////////////////////////////////////////////////////////
			pRoot->_pParent = _pHead;
			return true;
		}
		// 找待插入节点在二叉搜索树中的位置
		// 并保存其双亲节点
		else
		{
			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (data < pCur->_data)
					pCur = pCur->_pLeft;
				else if (data > pCur->_data)
					pCur = pCur->_pRight;
				else
					return false;
			}
			// 插入新节点
			pCur = new Node(data);
			if (data < pParent->_data)
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;
			pCur->_pParent = pParent;
			//调整
			// l pCur新节点默认颜色 : 红色
			// 如果pParent的颜色是黑色的，满足红黑树性质
			// 如果pParent的颜色是红色的，违反了性质三--不能有连在一起的
			// ...
			while (pParent != _pHead && pParent->_col == RED)//大前提
			{
				Node* grandfather = pParent->_pParent;
				//parent在左
				if (pParent == grandfather->_pLeft)
				{
					Node* uncle = grandfather->_pRight;
					//Node* uncle = pParent->_pRight;//错误二
					if (uncle && uncle->_col == RED)
					{
						//情景一：pCur->红，pParent->红，grandfather->黑，uncle存在且为红
							//     g
							//   p   u
							// c
							// 
							//解决：p，u改为黑，g改为红，最后g为红所以，要继续向上调整
						pParent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						//////////////////////////////////////
						pCur = grandfather;
						if (pCur == pRoot)
						{
							pCur->_pParent = _pHead;
						}
						pParent = pCur->_pParent;
					}
					else
					{
						if (pCur == pParent->_pLeft)
						{
							//情景二：pCur->红，pParent->红，grandfather->黑，uncle不存在/为黑
								//     g
								//   p   u
								// c
								// 
							// 解决：对g右单旋，p改为黑，g改为红，最后g为黑所以，直接break
							RotateR(grandfather);
							pParent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//情景三：pCur->红，pParent->红，grandfather->黑，uncle不存在/为黑
								//       g
								//   p      u
								//     c
							// 解决：对p左单旋，后变为情景二。
							RotateL(pParent);
							RotateR(grandfather);
							pCur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
				else//情景大概反着来
				{
					//1  uncle
					Node* uncle = grandfather->_pLeft;//错误一
					//Node* uncle = pParent->_pRight;//错误一
					if (uncle && uncle->_col == RED)
					{
						pParent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						pCur = grandfather;
						/////////////////////////////////////////////
						if (pCur == pRoot)
						{
							pCur->_pParent = _pHead;
						}
						pParent = pCur->_pParent;
					}

					else
					{
						if (pCur == pParent->_pRight)//2
						{
							RotateL(grandfather);
							pParent->_col = BLACK;
							grandfather->_col = RED;
						}
						else//3
						{
							RotateR(pParent);
							RotateL(grandfather);
							pCur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
			}
			Node*& _root = GetRoot();
			//最后
			_root->_col = BLACK;

			return true;
		}
	}

	// 检测红黑树中是否存在值为data的节点，存在返回该节点的地址，否则返回nullptr
	Node* Find(const T& data)
	{
		Node* pCur = GetRoot();
		while (pCur)
		{
			if (pCur->_data == data)
				break;
			else if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return pCur;
	}

	// 获取红黑树最左侧节点
	Node* LeftMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}

	// 获取红黑树最右侧节点
	Node* RightMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;
		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}
		return pCur;
	}

	// 检测红黑树是否为有效的红黑树，注意：其内部主要依靠_IsValidRBTRee函数检测
	bool IsValidRBTRee()
	{
		//1:是否存在 红-红 
		//每条路径黑色结点是否相同个数
		//最长的不超过最短的二倍
		//根，叶子为黑
		Node* _root = GetRoot();
		if (nullptr == _root)
			return true;
		if (_root->_col == RED)
			return false;
		Node* pCur = _root;
		size_t refVal = 0;
		while (pCur)
		{
			if (pCur->_col == BLACK)
				refVal++;
			pCur = pCur->_pLeft;
		}
		size_t blacknum = 0;
		return _IsValidRBTRee(_root, blacknum, refVal);
	}
private:
	bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (pRoot == nullptr)
		{
			if (pathBlack != blackCount)
			{
				cout << "存在黑色节点数量不相等的路径" << endl;
				return false;
			}
			return true;
		}
		Node* pParent = pRoot->_pParent;
		if (pRoot->_col == RED)
		{
			if (pParent != _pHead && pRoot->_pParent->_col == RED)
			{
				cout << "有连续的红色节点" << endl;
				return false;
			}
		}
		if (pRoot->_col == BLACK)
		{
			++blackCount;
		}
		return _IsValidRBTRee(pRoot->_pLeft, blackCount, pathBlack)
			&& _IsValidRBTRee(pRoot->_pRight, blackCount, pathBlack);
	}
	// 左单旋
	void RotateL(Node* pParent)
	{
		Node*& _root = GetRoot();
		Node* subR = pParent->_pRight;
		Node* subRL = subR->_pLeft;

		pParent->_pRight = subRL;
		subR->_pLeft = pParent;

		Node* parentParent = pParent->_pParent;

		pParent->_pParent = subR;
		if (subRL)
			subRL->_pParent = pParent;

		if (_root == pParent)
		{
			_root = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (parentParent->_pLeft == pParent)
			{
				parentParent->_pLeft = subR;
			}
			else
			{
				parentParent->_pRight = subR;
			}

			subR->_pParent = parentParent;
		}
	}
	// 右单旋
	void RotateR(Node* pParent)
	{
		Node*& _root = GetRoot();
		Node* subL = pParent->_pLeft;
		Node* subLR = subL->_pRight;

		pParent->_pLeft = subLR;
		if (subLR)
			subLR->_pParent = pParent;

		Node* parentParent = pParent->_pParent;

		subL->_pRight = pParent;
		pParent->_pParent = subL;

		if (_root == pParent)
		{
			_root = subL;
			subL->_pParent = nullptr;
		}
		else
		{
			if (parentParent->_pLeft == pParent)
			{
				parentParent->_pLeft = subL;
			}
			else
			{
				parentParent->_pRight = subL;
			}

			subL->_pParent = parentParent;
		}
	}
	// 为了操作树简单起见：获取根节点
	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}
private:
	Node* _pHead;
};
int main()
{
	const int N = 10000;
	vector<int> v;
	v.reserve(N);
	//srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
	}
	size_t begin2 = clock();
	RBTree<int> t;
	for (auto e : v)
	{
		//if (e == 26500)
		//{
		//	int a = 32;
		//}
		t.Insert(e);
		//cout << "Insert:" << e << "->" << t.IsValidRBTRee() << endl;
	}
	size_t end2 = clock();
	cout << t.IsValidRBTRee() << endl;
	return 0;
}
