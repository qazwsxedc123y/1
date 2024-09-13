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

// ��ģ��ʵ�ֺ�����Ĳ���--ע�⣺Ϊ�˺����װmap��set��������ʵ��ʱ���������������һ��ͷ���
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

	// �ں�����в���ֵΪdata�Ľڵ㣬����ɹ�����true�����򷵻�false
	// ע�⣺Ϊ�˼����������ʵ�ֺ�������洢�ظ���Ԫ��
	bool Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		// ��һ�β�����
		if (pRoot == nullptr)
		{
			pRoot = new Node(data, BLACK);
			//////////////////////////////////////////////////////////////////////////
			pRoot->_pParent = _pHead;
			return true;
		}
		// �Ҵ�����ڵ��ڶ����������е�λ��
		// ��������˫�׽ڵ�
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
			// �����½ڵ�
			pCur = new Node(data);
			if (data < pParent->_data)
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;
			pCur->_pParent = pParent;
			//����
			// l pCur�½ڵ�Ĭ����ɫ : ��ɫ
			// ���pParent����ɫ�Ǻ�ɫ�ģ�������������
			// ���pParent����ɫ�Ǻ�ɫ�ģ�Υ����������--����������һ���
			// ...
			while (pParent != _pHead && pParent->_col == RED)//��ǰ��
			{
				Node* grandfather = pParent->_pParent;
				//parent����
				if (pParent == grandfather->_pLeft)
				{
					Node* uncle = grandfather->_pRight;
					//Node* uncle = pParent->_pRight;//�����
					if (uncle && uncle->_col == RED)
					{
						//�龰һ��pCur->�죬pParent->�죬grandfather->�ڣ�uncle������Ϊ��
							//     g
							//   p   u
							// c
							// 
							//�����p��u��Ϊ�ڣ�g��Ϊ�죬���gΪ�����ԣ�Ҫ�������ϵ���
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
							//�龰����pCur->�죬pParent->�죬grandfather->�ڣ�uncle������/Ϊ��
								//     g
								//   p   u
								// c
								// 
							// �������g�ҵ�����p��Ϊ�ڣ�g��Ϊ�죬���gΪ�����ԣ�ֱ��break
							RotateR(grandfather);
							pParent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//�龰����pCur->�죬pParent->�죬grandfather->�ڣ�uncle������/Ϊ��
								//       g
								//   p      u
								//     c
							// �������p���������Ϊ�龰����
							RotateL(pParent);
							RotateR(grandfather);
							pCur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
				else//�龰��ŷ�����
				{
					//1  uncle
					Node* uncle = grandfather->_pLeft;//����һ
					//Node* uncle = pParent->_pRight;//����һ
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
			//���
			_root->_col = BLACK;

			return true;
		}
	}

	// ����������Ƿ����ֵΪdata�Ľڵ㣬���ڷ��ظýڵ�ĵ�ַ�����򷵻�nullptr
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

	// ��ȡ����������ڵ�
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

	// ��ȡ��������Ҳ�ڵ�
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

	// ��������Ƿ�Ϊ��Ч�ĺ������ע�⣺���ڲ���Ҫ����_IsValidRBTRee�������
	bool IsValidRBTRee()
	{
		//1:�Ƿ���� ��-�� 
		//ÿ��·����ɫ����Ƿ���ͬ����
		//��Ĳ�������̵Ķ���
		//����Ҷ��Ϊ��
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
				cout << "���ں�ɫ�ڵ���������ȵ�·��" << endl;
				return false;
			}
			return true;
		}
		Node* pParent = pRoot->_pParent;
		if (pRoot->_col == RED)
		{
			if (pParent != _pHead && pRoot->_pParent->_col == RED)
			{
				cout << "�������ĺ�ɫ�ڵ�" << endl;
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
	// ����
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
	// �ҵ���
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
	// Ϊ�˲��������������ȡ���ڵ�
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
