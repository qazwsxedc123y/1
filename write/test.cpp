#define  _CRT_SECURE_NO_WARNINGS
//#include<string>
#include<iostream>
#include<string.h>
#include<vector>
#include<assert.h>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

int main()

{

    priority_queue<int> a;

    priority_queue<int, vector<int>, greater<int> > c;

    priority_queue<string> b;

    for (int i = 0; i < 5; i++)

    {

        a.push(i);

        c.push(i);

    }

    while (!a.empty())

    {

        cout << a.top() << ' ';

        a.pop();

    }

    cout << endl;

    while (!c.empty())

    {

        cout << c.top() << ' ';

        c.pop();

    }

    cout << endl;

    b.push("abc");

    b.push("abcd");

    b.push("cbd");

    while (!b.empty())

    {

        cout << b.top() << ' ';

        b.pop();

    }

    cout << endl;

    return 0;

}




namespace st
{
    template<class T>
    struct stack_node
    {
        stack_node(const T& _val)
            :next(nullptr)
            , val(_val)
        {}
        stack_node* next;
        T val;
    };
    /* 基于链表实现的栈 */
    template<class T>
    class stack
    {
    public:
        stack()
        {
            stackTop = nullptr;
            stkSize = 0;
        }

        ~stack()
        {
            delete[]stackTop;
            stackTop = nullptr;
            stkSize = 0;
        }

        /* 获取栈的长度 */
        int size()
        {
            return stkSize;
        }

        /* 判断栈是否为空 */
        bool isMmpty()
        {
            return size() == 0;
        }

        /* 入栈 */
        void push(int num)
        {
            stack_node<T>* node = new stack_node<T>(num);
            node->next = stackTop;
            stackTop = node;
            stkSize++;
        }

        /* 出栈 */
        int pop()
        {
            assert(!isMmpty());
            int num = top();
            stack_node<T>* tmp = stackTop;
            stackTop = stackTop->next;
            // 释放内存
            delete tmp;
            stkSize--;
            return num;
        }

        /* 访问栈顶元素 */
        int top()
        {
            assert(!isMmpty());
            return stackTop->val;
        }

    private:
        stack_node<T>* stackTop; // 将头节点作为栈顶
        int stkSize;        // 栈的长度
    };
    void test_1()
    {
        stack<int> st;

        // 元素入栈
        st.push(1);
        st.push(3);
        st.push(2);
        st.push(5);
        st.push(4);

        //访问栈顶元素 
        int top = st.top();

        // 元素出栈 
        st.pop(); // 无返回值

        // 获取栈的长度 
        cout << st.size() << endl;

        // 判断是否为空 
        cout << st.isMmpty() << endl;
                                   
    }
}
    template<class T, class Con = deque<T>>

    class queue
    {
    public:
        queue()
        {

        }

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_front();
        }

        T& back()
        {
            return _c.back();
        }

        const T& back()const
        {
            return _c.back();
        }

        T& front()
        {
            return _c.front();
        }

        const T& front()const
        {
            return _c.front();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:
        Con _c;

    };





//namespace bit
//{
//    template<class T, class Con = deque<T>>
//    class stack
//    {
//    public:
//        stack()
//        {}
//
//        void push(const T& x)
//        {
//            _c.push_back(x);
//        }
//        void pop()
//        {
//            _c.pop_back();
//        }
//
//        T& top()
//        {
//            return _c.back();
//        }
//
//        const T& top()const
//        {
//            return _c.back();
//        }
//
//        size_t size()const
//        {
//            return _c.size();
//        }
//
//        bool empty()const
//        {
//            return _c.empty();
//        }
//
//    private:
//        Con _c;
//
//    };
//    void test_stack_1()
//    {
//        stack<int> st;
//
//        // 元素入栈
//        st.push(1);
//        st.push(3);
//        st.push(2);
//        st.push(5);
//        st.push(4);
//
//        //访问栈顶元素 
//        int top = st.top();
//
//        // 元素出栈 
//        st.pop(); // 无返回值
//
//        // 获取栈的长度 
//        cout << st.size() << endl;
//
//        // 判断是否为空 
//        cout << st.empty() << endl;
//    }
//    template<class T, class Con = deque<T>>
//
//    class queue
//    {
//    public:
//        queue()
//        {
//
//        }
//
//        void push(const T& x)
//        {
//            _c.push_back(x);
//        }
//
//        void pop()
//        {
//            _c.pop_front();
//        }
//
//        T& back()
//        {
//            return _c.back();
//        }
//
//        const T& back()const
//        {
//            return _c.back();
//        }
//
//        T& front()
//        {
//            return _c.front();
//        }
//
//        const T& front()const
//        {
//            return _c.front();
//        }
//
//        size_t size()const
//        {
//            return _c.size();
//        }
//
//        bool empty()const
//        {
//            return _c.empty();
//        }
//
//    private:
//        Con _c;
//
//    };
//    void test_queue_1()
//    {
//        stack<int> q;
//
//        // 元素入栈
//        q.push(1);
//        q.push(3);
//        q.push(2);
//        q.push(5);
//        q.push(4);
//
//        //访问栈顶元素 
//        int top = q.top();
//
//        // 元素出栈 
//        q.pop(); // 无返回值
//
//        // 获取队列的长度 
//        cout << q.size() << endl;
//
//        // 判断是否为空 
//        cout << q.empty() << endl;
//    }
//}
//int main()
//{
//    bit::test_stack_1();
//    bit::test_queue_1();
//    return 0;
//}



//int main()
//{
//    queue<char> Q;
//
//    char x, y;
//
//    x = 'n'; y = 'g';
//
//    Q.push(x); Q.push('i'); Q.push(y);
//
//    Q.pop(); Q.push('r'); Q.push('t'); Q.push(x);
//
//    Q.pop(); Q.push('s');
//
//    while (!Q.empty())
//
//    {
//
//        x = Q.front();
//
//        Q.pop();
//
//        cout << x;
//
//    };
//
//    cout << y;
//}
namespace bit
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator cbegin()
        {
            return _finish;
        }

        const_iterator cend() const
        {
            return _start;
        }



            // construct and destroy

        vector()
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr)
        {}

        vector(int n, const T& value = T())
            : _start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
            reserve(n);
            for (int i = 0; i < n; i++)
            {
                push_back(value);
            }
        }

        template<class InputIterator>

        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(const vector<T>& v)
            :_start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
            reserve(v.capacity());
            for (auto& e : v)
            {
                push_back(e);
            }
        }
        vector<T>& operator= (vector<T> v)
        {
            delete[]_start;
            _start = _finish = _endOfStorage = nullptr;
            reserve(v.capacity());
            for (auto& e : v)
            {
                push_back(e);
            }
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }

            // capacity

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endOfStorage - _start;
        }

        void reserve(size_t n)
        {
            size_t cp = capacity();
            if (n > cp)
            {
                T* tmp = new T[n];
                size_t sz = size();
                if (_start)
                {
                    for (size_t i = 0; i < sz; i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[]_start;
                }
                _start = tmp;
                _finish = _start + sz;
                _endOfStorage = _start + n;
            }
        }

        void resize(size_t n, const T& value = T())
        {
            size_t sz = size();
            if (n <= sz)
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                while (_finish < _start + n)
                {
                    *(_finish) = value;
                    ++_finish;
                }
            }
        }



            ///////////////access///////////////////////////////

        T& operator[](size_t pos)
        {
            return *(_start + pos);
        }

        const T& operator[](size_t pos)const
        {
            return *(_start + pos);
        }



            ///////////////modify/////////////////////////////

        void push_back(const T& x)
        {
            insert(end(), x);
        }
        void pop_back()
        {
            erase(end());
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }

        iterator insert(iterator pos, const T& x)
        {
            if (_finish == _endOfStorage)
            {
                size_t len = pos - _start;
                size_t cp = capacity() == 0 ? 4 : capacity() * 2;
                reserve(cp);
                pos = _start + len;
            }
            T* end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }
            *pos = x;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos)
        {
            iterator it = pos;
            while (it < _finish)
            {
                *it = *(it + 1);
                ++it;
            }
            --_finish;
            return pos;
        }

    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾
    };
    void test_1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);

        for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        vector<int>::iterator it = v.begin();
        while (it != v.end())
        {
            *it *= 10;
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
        v.insert(v.begin(), 0);
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
        v.erase(v.end());
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
//int main()
//{
//    bit::test_1();
//    return 0;
//}


//namespace bit
//{
//    class string
//    {
//        friend ostream& operator<<(ostream& _cout, const bit::string& s);
//        friend istream& operator>>(istream& _cin, bit::string& s);
//    public:
//        typedef char* iterator;
//    public:
//        string(const char* str = "")
//            :_size(strlen(str))
//            ,_capacity(_size)
//        {
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }       
//
//        string(const string& s)
//            :_size(s._size)
//            ,_capacity(s._capacity)
//        {
//            string tmp(s._str);
//            swap(tmp);
//        }
//        string& operator=(const string& s)
//        {
//            _size = s._size;
//            _capacity = s._capacity;
//            _str = new char[_capacity + 1];
//            strcpy(_str, s._str);
//        }
//        ~string()
//        {
//            if (_str)
//            {
//                delete[] _str;
//                _str = nullptr;
//            }
//        }
//
//            //////////////////////////////////////////////////////////////
//
//            // iterator
//
//        iterator begin()
//        {
//            return _str;
//        }
//
//        iterator end()
//        {
//            return _str + _size;
//        }
//
//
//
//            /////////////////////////////////////////////////////////////
//
//            // modify
//
//        void push_back(char c)
//        {
//            if (_size == _capacity)
//            {
//                reserve(_capacity == 0 ? 4 : _capacity * 2);
//            }
//            _str[_size] = c;
//            ++_size;
//            _str[_size] = '\0';
//        }
//
//        string& operator+=(char c)
//        {
//            push_back(c);
//            return *this;
//        }
//
//        void append(const char* str)
//        {
//            size_t len = strlen(str);
//            if (_size + len > _capacity)
//            {
//                reserve(_size + len);
//            }
//            strcpy(_str + _size, str);
//            _size += len;
//        }
//
//        string& operator+=(const char* str)
//        {
//            append(str);
//            return *this;
//        }
//
//        void clear()
//        {
//            _size = 0;
//            _str[0] = '\0';
//        }
//
//        void swap(string& s)
//        {
//            std::swap(_str, s._str);
//            std::swap(_size, s._size);
//            std::swap(_capacity, s._capacity);
//        }
//
//        const char* c_str()const
//        {
//            return _str;
//        }
//
//
//
//        /////////////////////////////////////////////////////////////
//
//        // capacity
//
//        size_t size()const
//        {
//            return _size;
//        }
//
//        size_t capacity()const
//        {
//            return _capacity;
//        }
//
//        bool empty()const
//        {
//            return _size == 0;
//        }
//
//        void resize(size_t n, char c = '\0')
//        {
//            if (n > _size)
//            {
//                reserve(n);
//                for (size_t i = _size; i < n; i++)
//                {
//                    _str[i] = c;
//                }
//                _str[n] = '\0';
//                _size = n;
//            }
//            else
//            {
//                _str[n] = '\0';
//                _size = n;
//            }
//        }
//
//        void reserve(size_t n)
//        {
//            if (n > _capacity)
//            {
//                char* tmp = new char[n + 1];//第n+1个位置存的是'/0'
//
//                strcpy(tmp, _str);
//                _capacity = n;
//            }
//        }
//
//
//
//        /////////////////////////////////////////////////////////////
//
//        // access
//
//        char& operator[](size_t index)
//        {
//            return _str[index];
//        }
//
//        const char& operator[](size_t index)const
//        {
//            return _str[index];
//        }
//
//
//
//        /////////////////////////////////////////////////////////////
//
//        //relational operators
//
//        bool operator<(const string& s)
//        {
//            return strcmp(_str, s._str) < 0;
//        }
//
//        bool operator<=(const string& s)
//        {
//            return *this < s || *this == s;
//        }
//
//        bool operator>(const string& s)
//        {
//            return !(*this <= s);
//        }
//
//        bool operator>=(const string& s)
//        {
//            return !(*this < s);
//        }
//
//        bool operator==(const string& s)
//        {
//            return strcmp(_str, s._str) == 0;
//        }
//
//        bool operator!=(const string& s)
//        {
//            return !(*this == s);
//        }
//
//
//
//        // 返回c在string中第一次出现的位置
//
//        size_t find(char c, size_t pos = 0) const
//        {
//            for (size_t i = pos; i < _size; i++)
//            {
//                if (_str[i] == c)
//                {
//                    return i;
//                }
//            }
//            return -1;
//        }
//
//        // 返回子串s在string中第一次出现的位置
//
//        size_t find(const char* s, size_t pos = 0) const
//        {
//            const char* p = strstr(_str + pos, s);
//            if (p)
//            {
//                return p - _str;
//            }
//            else
//            {
//                return -1;
//            }
//        }
//
//        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
//
//        string& insert(size_t pos, char c)
//        {
//            if (_size == _capacity)
//            {
//                reserve(_capacity == 0 ? 4 : _capacity * 2);
//            }
//            size_t end = _size + 1;
//            while (end > pos)
//            {
//                _str[end] = _str[end - 1];
//                --end;
//            }
//            _str[pos] = c;
//            _size++;
//            return *this;
//        }
//
//        string& insert(size_t pos, const char* str)
//        {
//            size_t len = strlen(str);
//            if (_size+len > _capacity)
//            {
//                reserve(_size + len);
//            }
//            size_t end1 = _size + 1;
//            size_t end2 = _size + len + 1;
//            while (end1 > pos)
//            {
//                _str[end2 - 1] = _str[end1 - 1];
//                end2--;
//                end1--;
//            }
//            _str[_size + len] = '\0';
//            strncpy(_str + pos, str, len);
//            _size += len;
//            return *this;
//        }
//
//
//
//        // 删除pos位置上的元素，并返回该元素的下一个位置
//
//        string& erase(size_t pos, size_t len)
//        {
//            if (len == _size || len + pos >= _size)
//            {
//                _str[pos] = '\0';
//                _size = pos;
//                return *this;
//            }
//            size_t begin = pos + len;
//            while (begin <= _size)
//            {
//                _str[begin - len] = _str[begin];
//                begin++;
//            }
//            _size -= len;
//            return *this;
//        }
//    private:
//        char* _str;
//        size_t _capacity;
//        size_t _size;
//    };
//    void test_1()
//    {
//        string s1("hello world");
//        cout << s1.c_str() << endl;
//        s1.push_back(' ');
//        s1.append("hello bit hello bit");
//
//        cout << s1.c_str() << endl;
//
//        s1 += '#';
//        s1 += "*********************";
//        cout << s1.c_str() << endl;
//
//        string s2;
//        s2 += '#';
//        s2 += "*********************";
//        cout << s2.c_str() << endl;
//    }
//    void test_2()
//    {
//        string s1("hello world");
//        cout << s1.c_str() << endl;
//
//        s1.insert(5, '%');
//        cout << s1.c_str() << endl;
//
//        s1.insert(s1.size(), '%');
//        cout << s1.c_str() << endl;
//
//        s1.insert(0, '%');
//        cout << s1.c_str() << endl;
//    }
//}
//int main()
//{
//    bit::test_1();
//    bit::test_2();
//	return 0;
//}


//template<class T>
//void Swap(T& x,T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//template<class T>
//T Add(const T& x, const T& y)
//{
//
//	return x + y;
//}
//template<class T>
//class A
//{
//public:
//	A(T val) 
//		:a(val)
//	{}
//	void print();
//private:
//	T a;
//};
//template<class T>
//void A<T>::print()
//{
//	cout << a << endl;
//}
////int main()
////{
////	A<int> a(2);
////	a.print();
////	return 0;
////}