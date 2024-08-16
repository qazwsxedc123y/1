#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<set>
#include <functional>
#include<vector>
#include<assert.h>
using namespace std;


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _pRoot;
		while (cur)
		{
			if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		if (parent->_data > data)
		{
			parent->_pLeft = cur;
			cur->_pParent = parent;
		}
		else
		{
			parent->_pRight = cur;
			cur->_pParent = parent;
		}
		//调整
		while (parent)
		{
			if (parent->_pLeft == cur)
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
				parent = parent->_pParent;
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

	// AVL树的验证
	bool IsAVLTree()
	{
		return _IsAVLTree(_pRoot);
	}

private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot)
	{
		if (pRoot == nullptr)
		{
			return true;
		}

		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);
		if (rightHeight - leftHeight != pRoot->_bf)
		{
			cout << pRoot-> _data << "平衡因子异常" << endl;
			return false;
		}
		return abs(rightHeight - leftHeight) < 2
			&& _IsAVLTree(pRoot->_pLeft)
			&& _IsAVLTree(pRoot->_pRight);
	}
	size_t _Height(Node* pRoot)
	{
		if (pRoot == nullptr)
			return 0;

		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	// 右单旋
	void RotateR(Node* pParent)
	{
		Node* subL = pParent->_pLeft;
		Node* subLR = subL->_pRight;

		pParent->_pLeft = subLR;
		if (subLR)
		{
			subLR->_pParent = pParent;
		}
		subL->_pRight = pParent;
		Node* parent_parent = pParent->_pParent;
		pParent->_pParent = subL;
		if (_pRoot == pParent)
		{
			_pRoot = subL;
			subL->_pParent = nullptr;
		}
		else
		{
			if (parent_parent->_pLeft == pParent)
			{
				parent_parent->_pLeft = subL;
			}
			else
			{
				parent_parent->_pRight = subL;
			}
			subL->_pParent = parent_parent;
		}
		pParent->_bf = subL->_bf = 0;
	}
	// 左单旋
	void RotateL(Node* pParent)
	{
		Node* subR = pParent->_pRight;
		Node* subRL = subR->_pLeft;

		pParent->_pRight = subRL;
		subR->_pLeft = pParent;
		if (subRL)
		{
			subRL->_pParent = pParent;
		}
		Node* parent_parent = pParent->_pParent;
		pParent->_pParent = subR;
		if (_pRoot == pParent)
		{
			_pRoot = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (parent_parent->_pLeft == pParent)
			{
				parent_parent->_pLeft = subR;
			}
			else
			{
				parent_parent->_pRight = subR;
			}
			subR->_pParent = parent_parent;
		}
		subR->_bf = pParent->_bf = 0;
	}
	// 右左双旋
	void RotateRL(Node* pParent)
	{
		Node* subR = pParent->_pRight;
		Node* subRL = subR->_pLeft;
		int bf = subRL->_bf;

		RotateR(pParent->_pRight);
		RotateL(pParent);

		//调整平衡因子
		if (bf == 0)
		{
			// subRL自己就是新增
			pParent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			//在b上增加
			pParent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			subR->_bf = subRL->_bf = 0;
			pParent->_bf = -1;
		}
		else
		{
			assert(false);
		}
	}
	// 左右双旋
	void RotateLR(Node* pParent)
	{
		Node* subL = pParent->_pLeft;
		Node* subLR = subL->_pRight;
		int bf = subLR->_bf;

		RotateL(pParent->_pLeft);
		RotateR(pParent);

		//调整平衡因子
		if (bf == 0)
		{
			// subLR自己就是新增
			pParent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			pParent->_bf = 1;
			subL->_bf = subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			pParent->_bf = subLR->_bf = 0;
			subL->_bf = -1;
		}
		else
		{
			assert(false);
		}
	}

private:
	Node* _pRoot;
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
	}

	AVLTree<int> t;
	for (auto e : v)
	{
		t.Insert(e);
	}

	cout << t.IsAVLTree() << endl;
}
int main()
{
	test_1();
	return 0;
}











//int main()
//{
//	string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
//	map<string, int> ht;
//	for (auto& e : arr)
//	{
//		ht[e]++;
//	}
//
//	for (auto& kv : ht)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
////	cout << endl;
//
//	//打印结果：
//    //苹果 : 6
//    //甜瓜 : 1
//    //西瓜 : 3
//    //香蕉 : 3
//
//	ht["苹果"] = 100;
//
//	//打印结果：
//	//苹果 : 100
//	//甜瓜 : 1
//	//西瓜 : 3
//	//香蕉 : 3
//	return 0;
//}



//int main()
//{
//    map<int, string> m;
//
//    m.insert(make_pair(2, "two"));
//    m.insert(make_pair(1, "one"));
//    m.insert(make_pair(3, "three"));
//
//    auto it = m.begin();
//    m.erase(it); // 删除了  2, "two"
//
//    m.erase(1); // 删除了   1, "one"
//
//    m.erase(m.begin(), m.end());// 删除了   3, "three"
//    return 0;
//}

//void to_upper(string& s)
//{
//    for (auto& e : s)
//    {
//        if (e >= 'A' && e <= 'Z')
//        {
//            e += 32;
//        }
//    }
//}
//int main() {
//    map<string, int> mp;
//    string s;
//    while (getline(cin, s))
//    {
//        if (s.back() == '.')
//            s.pop_back();
//        to_upper(s);
//        mp[s]++;
//    }
//    auto it = mp.begin();
//    while (it != mp.end())
//    {
//        cout << it->second << ":" << it->first << endl;
//        it++;
//    }
//    return 0;
//}


//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x)
//        : val(x)
//        , left(nullptr)
//        , right(nullptr)
//    {}
//};
//
//class Solution {
//public:
//    TreeNode* _build(vector<int>& inorder, vector<int>& postorder, int& posi, int inbegin, int inend)
//    {
//        //分割区间[inbegin,rooti-1]rooti[rooti+1,inend]
//        if (inbegin > inend)
//            return nullptr;
//        int rooti = inbegin;
//        while (postorder[posi] != inorder[rooti])
//            ++rooti;
//        TreeNode* root = new TreeNode(postorder[posi--]);
//
//        root->right = _build(inorder, postorder, posi, rooti + 1, inend);
//        root->left = _build(inorder, postorder, posi, inbegin, rooti - 1);
//        return root;
//    }
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        int sz = inorder.size();
//        int i = sz - 1;
//        TreeNode* root = _build(inorder, postorder, i, 0, sz - 1);
//        return root;
//    }
//};
//
//int main()
//{
//    //inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//    vector<int> v1 = { 9,3,15,20,7 };
//    vector<int> v2 = { 9,15,7,20,3 };
//    Solution s;
//    s.buildTree(v1, v2);
//    return 0;
//}

//template<class T>
//class test
//{
//public:
//    T operator()(T x, T y) const {
//        return x + y;
//    }
//};
//int main()
//{
//    int arr[5]{ 0 };
//    return 0;
//}



////基类1
//class Base1
//{
//public:
//	virtual void func1() { cout << "Base1::func1()" << endl; }
//	virtual void func2() { cout << "Base1::func2()" << endl; }
//private:
//	int _b1;
//};
////基类2
//class Base2
//{
//public:
//	virtual void func1() { cout << "Base2::func1()" << endl; }
//	virtual void func2() { cout << "Base2::func2()" << endl; }
//private:
//	int _b2;
//};
////多继承派生类
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void func1() { cout << "Derive::func1()" << endl; }
//	virtual void func3() { cout << "Derive::func3()" << endl; }
//private:
//	int _d1;
//};
//typedef void(*VF)();//函数指针,打印虚表地址及其内容
//void printfVF(VF* a)
//{
//	for (size_t i = 0; a[i] != 0; i++)
//	{
//		printf("[%d]:%p->", i, a[i]);//打印虚表当中的虚函数地址
//		VF f = a[i];
//		f();//使用虚函数地址调用虚函数
//	}
//	printf("\n");
//}


//class A
//{
//
//public:
//
//  void f() { cout << "A::f()" << endl; }
//
//  int a;
//
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//	void f(int a) { cout << "B::f()" << endl; }
//
//	int a;
//
//};
//class A
//{
//public:
//	virtual void f()
//	{cout << "A::f()" << endl;}
//};
//class B : public A
//{
//private:
//	virtual void f()
//	{cout << "B::f()" << endl;}
//};

//int main()
//{
//	size_t i = 1;
//	for (int j = 0; j < 31; j++)
//	{
//		i *= 2;
//	}
//	i++;
//	cout << i;
//	return 0;
//}



//int main()
//{
//	Base1 b1;
//	printfVF((VF*)(*((int*)&b1)));
//	Base2 b2;
//	printfVF((VF*)(*((int*)&b2)));//打印基类对象d的虚表地址及其内容
//	Derive d;
//	printfVF((VF*)(*((int*)&d)));//打印基类对象d的虚表地址及其内容
//	printfVF((VF*)*((int*)((char*) &d + sizeof(Base1))));
//	return 0;
//}



//int static_i = 0;
//int main()
//{
//	Base b;
//	Base* p = &b;
//	printf("vfptr:%p\n", *((int*)p)); //000FDCAC
//	int i = 0;
//	printf("栈上地址:%p\n", &i);       //005CFE24
//	printf("数据段地址:%p\n", &static_i);     //0010038C
//
//	int* k = new int;
//	printf("堆上地址:%p\n", k);       //00A6CA00
//	const char* cp = "hello world";
//	printf("代码段地址:%p\n", cp);    //000FDCB4
//	return 0;
//}