#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ret;
    vector<int> v;
    void print_Pre(TreeNode* root)
    {
        if (root == nullptr) return;
        v.push_back(root->val);
        print_Pre(root->left);
        print_Pre(root->right);
    }
    void print_In(TreeNode* root)
    {
        if (root == nullptr) return;
        print_In(root->left);
        v.push_back(root->val);
        print_In(root->right);
    }
    void print_Post(TreeNode* root)
    {
        if (root == nullptr) return;
        print_Post(root->left);
        print_Post(root->right);
        v.push_back(root->val);
    }
    vector<vector<int>> threeOrders(TreeNode* root) {
        // write code here
        print_Pre(root);
        ret.push_back(v);
        v.clear();
        print_In(root);
        ret.push_back(v);
        v.clear();
        print_Post(root);
        ret.push_back(v);
        v.clear();
        return ret;
    }
};

//struct ListNode {
//    int val;
// 	struct ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//  };
// 
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// *	ListNode(int x) : val(x), next(nullptr) {}
// * };
// */
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param head ListNode类
//     * @return ListNode类
//     */
//    ListNode* head1 = nullptr, * head2 = nullptr, * ret_head = nullptr;
//    void split_node(ListNode* head)
//    {
//        ListNode* cur1 = head1, * cur2 = head2;
//        int i = 1;
//        while (head)
//        {
//            if (i % 2 == 1) // 奇数位
//            {
//                if (head1 == nullptr)
//                {
//                    head1 = head;
//                    cur1 = head;
//                    head = head->next;
//                }
//                else
//                {
//                    cur1->next = head;
//                    head = head->next;
//                    cur1 = cur1->next;
//                }
//            }
//            else // 偶数位 
//            {
//                if (head2 == nullptr)
//                {
//                    head2 = head;
//                    cur2 = head;
//                    head = head->next;
//                }
//                else
//                {
//                    cur2->next = head;
//                    head = head->next;
//                    cur2 = cur2->next;
//                }
//            }
//            i++;
//        }
//        cur1->next = nullptr;
//        cur2->next = nullptr;
//    }
//    ListNode* reverse_node(ListNode* head)
//    {
//        // 将其翻转
//        if (head == nullptr || head->next == nullptr) return head;
//        ListNode* ret = reverse_node(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//        return ret;
//    }
//    void print(ListNode* head)
//    {
//        while (head)
//        {
//            cout << head->val << " ";
//            head = head->next;
//        }
//        cout << endl;
//    }
//    void sort_node()
//    {
//        // 将head1,head2进行排序
//        ListNode* cur1 = head1, * cur2 = head2,
//            * cur = new ListNode(0), * t = cur;;
//        while (cur1 && cur2)
//        {
//            if (cur1->val <= cur2->val)
//            {
//                cur->next = cur1;
//                cur = cur1;
//                cur1 = cur1->next;
//            }
//            else
//            {
//                cur->next = cur2;
//                cur = cur2;
//                cur2 = cur2->next;
//            }
//        }
//        if (cur1) cur->next = cur1;
//        if (cur2) cur->next = cur2;
//
//        ret_head = t->next;
//    }
//    ListNode* sortLinkedList(ListNode* head) {
//        // write code here
//        // 先将链表拆为俩链表
//        split_node(head);
//        // print(head1);
//
//        head2 = reverse_node(head2);
//        // print(head2);
//        sort_node();
//        return ret_head;
//    }
//};
//
//int main()
//{
//    // 创建各个节点
//    ListNode* head = new ListNode(1);
//    ListNode* node2 = new ListNode(3);
//    ListNode* node3 = new ListNode(2);
//    ListNode* node4 = new ListNode(2);
//    ListNode* node5 = new ListNode(3);
//    ListNode* node6 = new ListNode(1);
//
//    // 连接节点
//    head->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = nullptr;
//    Solution s;
//    s.sortLinkedList(head);
//	return 0;
//}


//class BugTemplate {
//public:
//    virtual void FixTest() = 0;
//};
//
////存在1个bug
//class ClassBug :public BugTemplate
//{
//public:
//    const std::string StringToUpper(const char* src)
//    {
//        std::string temp;
//        temp = src;
//        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
//        // 在栈/堆上申请一个临时的temp
//        // 临时变量temp的类型为string，作为STL的容器
//        // 在本函数结束时会自动调用析构函数。
//        // 函数最后为传值返回，最后会调用析构
//        return temp;
//    }
//
//    const std::string StringToLower(const char* src)
//    {
//        std::string temp;
//        temp = src;
//        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
//        return temp;
//    }
//
//public:
//    ClassBug() {}
//    ~ClassBug() {}
//    // 需要修复乱码问题
//    // tip:考察对类的作用域理解
//    virtual void FixTest()
//    {
//        std::cout << "请修复bug，使程序正确输出转大写转小写" << std::endl;
//        const char* test = "ABCddasdasdaddaweqWADfFcddasdasdaddaweqewabcddasdasdaddaweWQD";
//        // 分析修改原因：
//        // 源代码是将返回值，进行转化为字符串，然后用指针指向。 const char* test1 = StringToUpper(test).c_str();
//        // 传值返回虽可以正常将其修改为字符串，但由于其类型必定会自动调用自己的析构函数。导致原有内存上的数据被清空变为0
//        // 所以不能正常进行转化输出
//
//
//        // 修改方式：
//        // 将传值返回先保存，尽管原有内存被覆盖也不影响
//        // 后在转字符串，用指针保存其地址
//        const string s1 = StringToUpper(test);
//        const char* test1 = s1.c_str();
//        
//        const string s2 = StringToLower(test);
//        const char* test2 = s2.c_str();
//
//        std::cout << test << std::endl;
//        std::cout << test1 << std::endl;
//        std::cout << test2 << std::endl;
//
//    }
//
//};
//
//struct buffertest {
//    char strbuffer1[8];
//    char strbuffer2[8];
//    char strbuffer3[8];
//};
//
////存在3个bug
//class CopyBug :public BugTemplate
//{
//public:
//    CopyBug() {}
//    ~CopyBug() {}
//    //需要修复乱码问题
//    virtual void FixTest()
//    {
//
//        std::cout << "请让程序能够正常输出ABCDEFGHIJKLMNOP" << std::endl;
//        buffertest* buffer = (buffertest*)malloc(sizeof(buffertest)); 
//        // 分析修改原因：
//        // 对于申请的结构体对象，是保存在堆上的，堆上的存储方式是：从低地址到高地址
//        // 在源代码运行上，是先对strbuffer2进行赋值，后对strbuffer1赋值
//        // 如果仅仅修改8位，则无影响，但strcpy函数会在后面默认添加'\0'标志结束位
//        // 故而对strbuffer1赋值时，会导致strbuffer2的第一位变为'\0'。
//        // 如果是在栈上申请的内存，则源代码从运行角度来看是没有问题的。
//        
//        // bug1：空间是连续的，buffer->strbuffer1被赋值为ABCDEFGH，后面还会携带一个'\0'会将buffer->strbuffer2的第一位修改为'\0'
//        // bug2：代码最后没有进行堆上的内存释放
//        // bug3：越界
//        // 修改：交换顺序
//        strcpy(buffer->strbuffer1, "ABCDEFGH");
//        strcpy(buffer->strbuffer2, "IJKLMNOP");
//        std::cout << buffer->strbuffer1;
//        std::cout << buffer->strbuffer2 << std::endl;
//        free(buffer);
//    }
//};
//
////存在一个bug
//class VectorBug :public BugTemplate
//{
//public:
//    VectorBug() {}
//    ~VectorBug() {}
//    virtual void FixTest()
//    {
//        std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
//        std::cout << "正确使用迭代器删除程序前三个数值,使程序不崩溃" << std::endl;
//        std::vector<int>::iterator it = vec.begin();
//        for (int i = 0; i < 3; i++)
//        {
//            it = vec.erase(it);
//            //it++;
//            // 源代码：
//            // vec.erase(it);
//            // it++
//
//            // 分析修改原因：
//            // 对于迭代器，最开始指向的是第一位1
//            // 进行erase后，如果不it++，此时it迭代器还是会第一位
//            // 这是因为vector的删除，是删除后，将后面的数据往前移动对应位置。
//            // 这是理应可以删除前三位，但是代码还是会崩溃，这是因为迭代器失效的问题
//            // 对于erase的返回值是迭代器类型，所以还需要将it重新赋值，代码便可运行
//            
//
//        }
//        for (it = vec.begin(); it != vec.end(); it++)
//        {
//            std::cout << *it << " ";
//        }
//        cout << endl;
//    }
//};
////修复bug 使程序正常运作
//int main()
//{
//
//    {
//        ClassBug bug;
//        bug.FixTest();
//    }
//    {
//        CopyBug bug;
//        bug.FixTest();
//    }
//    {
//        VectorBug bug;
//        bug.FixTest();
//    }
//    system("pause");
//    return 0;
//}
