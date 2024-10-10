#define  _CRT_SECURE_NO_WARNINGS

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
};
template<class K, class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator <T, T&, T*> iterator;
	typedef __TreeIterator <T, const T&, const T*> const_iterator;
private:
	Node* _root = nullptr;
};