#pragma once
#include<string>
#include<iostream>
#include<vector>

using namespace std;
#include"reserve_iterator.h"
namespace test
{
	template <class T>
	struct list_node
	{
		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;
		list_node(const T& x = T())
			:_data(x)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};
	template<class T, class Ref, class Ptr>
	struct __list_iterator 
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;

		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		self& operator++()//ǰ�üӼ�
		{
			_node = _node->_next;
			return *this;
			//return _node->_next;//���ص��ǽ�㣬Ӧ�÷�������,����д����
		}
		self& operator--()//ǰ��--
		{
			_node = _node->_prev;
			return *this;
			//return _node->_prev;
		}

		self operator--(int)//����
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};
	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;

		typedef Reserve_iterator<iterator, T&, T*> reserve_iterator;
		typedef Reserve_iterator<const_iterator,const T&,const T*> const_reserve_iterator;

		reserve_iterator rbegin()
		{
			return reserve_iterator(end());
		}
		reserve_iterator rend()
		{
			return reserve_iterator(begin());
		}
		const_reserve_iterator rbegin() const
		{
			return const_reserve_iterator(end());
		}
		const_reserve_iterator rend() const
		{
			return const_reserve_iterator(begin());
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		void empty_init()
		{
			_head = new Node;//data��ʼ��Ϊ0
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}
		list(list<T>& It)//����
		{
			empty_init();
			for (auto e : It)
			{
				push_back(e);
			}
		}

		//��ֵ
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		list()
		{
			empty_init();
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);

			Node* prev = cur->_prev;
			
			prev->_next = newnode;
			cur->_prev = newnode;
			newnode->_next = cur;
			newnode->_prev = prev;
			++_size;
			return iterator(newnode);//��ֹ������ʧЧ
		}
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;

			prev->_next = next;
			next->_prev = prev;
			--_size;
			return iterator(next);//��ֹ������ʧЧ
		}
	private:
		Node* _head;
		size_t _size;
	};

	//template <class T>
	//template <typename T>
	//void print_list(const list<T>& lt)
	//{
	//// list<T>δʵ��������ģ�壬����������ȥ������ȥ��
	//// ���������޷�list<T>::const_iterator����Ƕ���ͣ����Ǿ�̬��Ա����
	//// ǰ���һ��typename���Ǹ��߱�������������һ�����ͣ���list<T>ʵ����
	//// ��ȥ������ȥȡ
	//	typename list<T>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//}


	template <typename Container>
	void print_container(const Container& con)
	{
		typename Container::const_iterator it = con.begin();
		while (it != con.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		// ��װ���εײ�����ʵ��ϸ��
		// �ṩͳһ�ķ����޸ı�����ʽ
			
		print_container(lt);

		vector<string> v;
		v.push_back("222222222222222222222");
		v.push_back("222222222222222222222");
		v.push_back("222222222222222222222");
		v.push_back("222222222222222222222");
		print_container(v);

		list<string> lt1;
		lt1.push_back("ssssss");
		lt1.push_back("ssssss");
		lt1.push_back("ssssss");
		lt1.push_back("ssssss");

		print_container(lt1);


		//list<int>::iterator it = lt.begin();
		//int n = 5;
		//while (n--)
		//{
		//	//*it += 20;

		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;
		list<int> s(lt);
		size_t n = 5;
		list<int>::iterator t = s.begin();
		while (n--)
		{
			//*it += 20;

			cout << *t << " ";
			++t;
		}
		cout << endl;

		list<int> s1;
		s1 = s;
		n = 5;
		list<int>::iterator r = s.begin();
		while (n--)
		{
			//*it += 20;

			cout << *r << " ";
			++r;
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int> lt1(lt);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2;
		lt2.push_back(10);
		lt2.push_back(200);
		lt2.push_back(30);
		lt2.push_back(40);
		lt2.push_back(50);

		lt1 = lt2;
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	struct AA
	{
		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}

		int _a1;
		int _a2;
	};
	void test_list3()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));

		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1<<" "<<(*it)._a2 << endl;
			cout << it->_a1 << " " << it->_a2 << endl;
			cout << it.operator->()->_a1 << " " << it.operator->()->_a1 << endl;


			++it;
		}
		cout << endl;

		int* p = new int;
		*p = 1;

		AA* ptr = new AA;
		ptr->_a1 = 1;

	}
}

