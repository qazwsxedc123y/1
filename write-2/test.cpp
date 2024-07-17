#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
using namespace std;

int main()
{
    int ar[] = { 1,2,3,4,5,6,7,8,9,10 };

    int n = sizeof(ar) / sizeof(int);

    vector<int> v(ar, ar + n);

    cout << v.size() << ":" << v.capacity() << endl;

    v.reserve(100);

    v.resize(20);

    cout << v.size() << ":" << v.capacity() << endl;

    v.reserve(50);

    v.resize(5);

    cout << v.size() << ":" << v.capacity() << endl;
}






namespace bite
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
            , _pNext(nullptr)
            ,_val(val)
        {}
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}
        ListIterator(const Self& l);
        T& operator*()
        {
            return  &_pNode->_val;
        }
        T* operator->()
        {
            return _pNode->_val;
        }
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self& operator--(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return !(_pNode == Self._pNode);
        }
        bool operator==(const Self& l)
        {
            return _pNode == Self._pNode;
        }
    private:
        PNode _pNode;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
        }
        list(int n, const T& value = T())
        {
            int count = 0;
            PNode cur = _pHead;
            while (count--)
            {
                PNode tmp = new Node(value);
                tmp->_pPre = cur;

            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last);
        list(const list<T>& l)
        {
            list<T> tmp = l;
            swap(*this, tmp);
        }

        list<T>& operator=(const list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }
        iterator end()
        {
            return _pHead;
        }
        const_iterator begin()
        {
            return const_iterator(_pHead->_pNext);
        }
        const_iterator end()
        {
            return const_iterator(_pHead);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            size_t sz = 0;
            PNode _head = _pHead;
            PNode cur = _pHead->_pNext;
            while (cur != _head)
            {
                ++sz;
            }
            return sz;
        }
        bool empty()const
        {
            return _pHead == _pHead->_pPre;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front();
        const T& front()const;
        T& back();
        const T& back()const;


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            PNode cur = pos.PNode;
            PNode newNode = new Node(val);
            PNode prev = cur->_pPre;//_pNext
            cur->_pPre = newNode;
            prev->_pNext = newNode;

            newNode->_pNext = cur;
            newNode->_pPre = prev;
            return iterator(newNode);
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            PNode cur = pos.PNode;
            PNode prev = cur->_pPre;
            PNode next = cur->_pNext;//_pNext

            delete cur;
            prev->_pNext = next;
            next->_pPre = prev;

            return iterator(next);
        }
        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }
        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
        }
    private:
        void CreateHead()
        {
            _pHead = new Node;//data初始化为0
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }
        PNode _pHead;
    };
};
void test_list1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

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

    list<int>::iterator r = s.begin();
    s.erase(r);
    list<int>::iterator q = s.begin();
    while (q!=s.end())
    {

        cout << *q << " ";
        ++q;
    }
    cout << endl;
}
//int main()
//{
//    test_list1();
//    return 0;
//}


//class Solution {
//public:
//    int myAtoi(string str) {
//        int res = 0, bndry = INT_MAX / 10;
//        int i = 0, sign = 1, length = str.size();
//        if (length == 0) return 0;
//        while (str[i] == ' ')
//            if (++i == length) return 0;
//        if (str[i] == '-') sign = -1;
//        if (str[i] == '-' || str[i] == '+') i++;
//        for (int j = i; j < length; j++) {
//            if (str[j] < '0' || str[j] > '9') break;
//            if (res > bndry || res == bndry && str[j] > '7')
//                return sign == 1 ? INT_MAX : INT_MIN;
//            res = res * 10 + (str[j] - '0');
//        }
//        return sign * res;
//    }
//};
//class Solution {
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0")
//            return "0";
//        string ret;
//        int count = 0;
//        int n = num1.size(), m = num2.size();
//        for (int i = m - 1; i >= 0; i--)
//        {
//            string curr;
//            int tmp = num2[i]-'0';
//            int carry = 0;
//            for (int j = n - 1; j >= 0; j--)
//            {
//                int a = num1[j]-'0';
//                int sum = tmp * a + carry;
//                carry = sum / 10;
//                curr.push_back(sum % 10+'0');
//            }
//            if (carry != 0)
//            {
//                curr.push_back(carry+'0');
//                carry = 0;
//            }
//            //反转字符串
//            int right = curr.size() - 1;
//            int left = 0;
//            while (right > left)
//            {
//                char cr = curr[right];
//                char cl = curr[left];
//                curr[right] = cl;
//                curr[left] = cr;
//                --right;
//                ++left;
//            }
//            for (int x = 0; x < count; x++)
//            {
//                curr.push_back('0');
//            }
//            count++;
//            ret = addStrings(curr, ret);
//        }
//        return ret;
//    }
//    string addStrings(string num1, string num2) {
//        string s;
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int carry = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int x1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int x2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int sum = x1 + x2 + carry;
//            carry = sum / 10;
//            sum %= 10;
//            s += ('0' + sum);
//            --end1, --end2;
//        }
//        if (carry == 1)
//        {
//            s += '1';
//        }
//        reverse(s.begin(), s.end());
//        return s;
//    }
//};
//class Solution {
//public:
//    string reverseWords(string s) {
//        int sz = s.size();
//        int i = 0;
//        int end_sz = 0;
//        int a = sz - 1;
//        while (s[a] != ' ')
//        {
//            end_sz++;
//            a--;
//        }
//        while (1)
//        {
//            if (i == sz - end_sz - 1) {
//                int right = sz - 1;
//                int left = i;
//                while (right > left) {
//                    char cr = s[right];
//                    char cl = s[left];
//                    s[right] = cl;
//                    s[left] = cr;
//                    --right;
//                    ++left;
//                }
//                break;
//            }
//            int tmp = i;
//            i = s.find(" ", i+1);
//            
//            int right = i - 1;
//            int left = tmp == 0 ? 0 : tmp + 1;
//            while (right > left) {
//                char cr = s[right];
//                char cl = s[left];
//                s[right] = cl;
//                s[left] = cr;
//                --right;
//                ++left;
//            }
//        }
//
//        return s;
//    }
//};
//class Solution {
//public:
//    string reverseWords(string s) {
//        stack<char> s1;
//        int sz = s.size();
//        for (int i = 0; i < sz; i++)
//        {
//            if (s[i] == ' ')
//            {
//                i++;
//            }
//            int j = i;
//            int count = 0;
//            while (s[i] != ' ' && i != sz)//进栈
//            {
//                count++;
//                s1.push(s[i]);
//                i++;
//            }
//            //入栈完毕开始出栈
//            while (count--)
//            {
//                char ch = s1.top();
//                s1.pop();
//                s[j] = ch;
//                j++;
//            }
// 
//        }
//        return s;
//    }
//};
//
//int main()
//
//{
//
//    int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
//
//    int n = sizeof(array) / sizeof(int);
//
//    list<int> mylist(array, array + n);
//
//    auto it = mylist.begin();
//
//    while (it != mylist.end())
//
//    {
//
//        if (*it != 0)
//
//            cout << *it << " ";
//
//        else
//
//            it = mylist.erase(it);
//
//        ++it;
//
//    }
//
//    return 0;
//
//}

