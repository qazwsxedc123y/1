#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<assert.h>
using namespace std;
namespace test
{
	template<class k, class v>
	struct AVLTreeNode
	{
		AVLTreeNode* _left;
		AVLTreeNode* _right;
		AVLTreeNode* _parent;
		int _bf;
		pair<k, v> _kv;
		AVLTreeNode(const pair<k, v>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
			, _kv(kv)
		{}
	};
	template<class k, class v>
	class AVLTree
	{
		typedef AVLTreeNode<k, v> Node;
	public:
		bool Insert(const pair<k, v>& kv)
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
				if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(kv);
			if (parent->_kv.first > kv.first)
			{				
				parent->_left = cur;
				cur->_parent = parent;
			}
			else
			{				
				parent->_right = cur;
				cur->_parent = parent;
			}
			//调整
			while (parent)
			{
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == -1 || parent->_bf == 1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == -2 || parent->_bf == 2)
				{
					if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(parent);
					}
					// 1、旋转让这颗子树平衡了
					// 2、旋转降低了这颗子树的高度，恢复到跟插入前一样的高度，
					// 所以对上一层没有影响，不用继续更新
					break;
				}
				else
				{
					break;
				}
			}
			return true;
		}
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			subR->_left = parent;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			Node* parent_parent = parent->_parent;
			parent->_parent = subR;
			if (_root == parent)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (parent_parent->_left == parent)
				{
					parent_parent->_left = subR;
				}
				else
				{
					parent_parent->_right = subR;
				}
				subR->_parent = parent_parent;
			}
			subR->_bf = parent->_bf = 0;
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}
			subL->_right = parent;
			Node* parent_parent = parent->_parent;
			parent->_parent = subL;
			if (_root == parent)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (parent_parent->_left == parent)
				{
					parent_parent->_left = subL;
				}
				else
				{
					parent_parent->_right = subL;
				}
				subL->_parent = parent_parent;
			}
			parent->_bf = subL->_bf = 0;
		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(parent->_right);
			RotateL(parent);

			//调整平衡因子
			if (bf == 0)
			{
				// subRL自己就是新增
				parent->_bf = subR->_bf = subRL->_bf = 0;
			}
			else if (bf == -1)
			{
				//在b上增加
				parent->_bf = 0;
				subRL -> _bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 1)
			{
				subR->_bf = subRL->_bf = 0;
				parent->_bf = -1;
			}
			else
			{
				assert(false);
			}
		}
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			RotateL(parent->_left);
			RotateR(parent);

			//调整平衡因子
			if (bf == 0)
			{
				// subLR自己就是新增
				parent->_bf = subL->_bf = subLR->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subL->_bf = subLR->_bf = 0;
			}
			else if (bf == 1)
			{
				parent->_bf = subLR->_bf = 0;
				subL->_bf = -1;
			}
			else
			{
				assert(false);
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
		bool IsBalance()
		{
			return _IsBalance(_root);
		}
		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);

			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}

		bool _IsBalance(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}

			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			if (rightHeight - leftHeight != root->_bf)
			{
				cout << root->_kv.first << "平衡因子异常" << endl;
				return false;
			}
			return abs(rightHeight - leftHeight) < 2
				&& _IsBalance(root->_left)
				&& _IsBalance(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
	void test_1()
	{
		const int N = 30;
		vector<int> v;
		v.reserve(N);
		//srand(time(0));

		for (size_t i = 0; i < N; i++)
		{
			v.push_back(rand());
			cout << v.back() << endl;
		}

		AVLTree<int, int> t;
		for (auto e : v)
		{
			if (e == 5705)
			{
				int x = 0;
				cout << "error" << endl;
			}

			t.Insert(make_pair(e, e));
			cout << "Insert:" << e << "->" << t.IsBalance() << endl;
		}

		cout << t.IsBalance() << endl;
	}
}
int main()
{
	test::test_1();
	return 0;
}