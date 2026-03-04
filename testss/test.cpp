#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class BugTemplate {
public:
    virtual void FixTest() = 0;
};

//存在1个bug
class ClassBug :public BugTemplate
{
public:
    const std::string StringToUpper(const char* src)
    {
        std::string temp;
        temp = src;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        // 在栈/堆上申请一个临时的temp
        return temp;
    }

    const std::string StringToLower(const char* src)
    {
        std::string temp;
        temp = src;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        return temp;
    }

public:
    ClassBug() {}
    ~ClassBug() {}
    // 需要修复乱码问题
    // tip:考察对类的作用域理解
    virtual void FixTest()
    {
        std::cout << "请修复bug，使程序正确输出转大写转小写" << std::endl;
        const char* test = "ABCddasdasdaddaweqWADfFcddasdasdaddaweqewabcddasdasdaddaweWQD";
        // 栈或堆上传值返回，会被清除（本质覆盖）。string会调用析构。必定清除
        const string s1 = StringToUpper(test);
        const char* test1 = s1.c_str();
        
        const string s2 = StringToLower(test);
        const char* test2 = s2.c_str();

        std::cout << test << std::endl;
        std::cout << test1 << std::endl;
        std::cout << test2 << std::endl;

    }

};

struct buffertest {
    char strbuffer1[8];
    char strbuffer2[8];
    char strbuffer3[8];
};

//存在3个bug
class CopyBug :public BugTemplate
{
public:
    CopyBug() {}
    ~CopyBug() {}
    //需要修复乱码问题
    virtual void FixTest()
    {

        std::cout << "请让程序能够正常输出ABCDEFGHIJKLMNOP" << std::endl;
        buffertest* buffer = (buffertest*)malloc(sizeof(buffertest)); // 在堆上，地址从低到高
        // 缓冲区移除：strcpy会在后添加'\0'
        // 1. 空间是连续的，buffer->strbuffer2被赋值为IJKLMNOP，后面还会携带一个'\0'
        // buffer->strbuffer1被赋值为ABCDEFGH，后'\0'，
        // buffer->strbuffer2第一个被改为'\0'
        // 修改：交换顺序
        strcpy(buffer->strbuffer1, "ABCDEFGH");
        strcpy(buffer->strbuffer2, "IJKLMNOP");
        std::cout << buffer->strbuffer1;
        std::cout << buffer->strbuffer2 << std::endl;
        free(buffer);
    }
};

//存在一个bug
class VectorBug :public BugTemplate
{
public:
    VectorBug() {}
    ~VectorBug() {}
    virtual void FixTest()
    {
        std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
        std::cout << "正确使用迭代器删除程序前三个数值,使程序不崩溃" << std::endl;
        std::vector<int>::iterator it = vec.begin();
        for (int i = 0; i < 3; i++)
        {
            it = vec.erase(it);
            //it++;
        }
        for (it = vec.begin(); it != vec.end(); it++)
        {
            std::cout << *it << " ";
        }
        cout << endl;
    }
};
//修复bug 使程序正常运作
int main()
{

    {
        ClassBug bug;
        bug.FixTest();
    }
    {
        CopyBug bug;
        bug.FixTest();
    }
    {
        VectorBug bug;
        bug.FixTest();
    }
    system("pause");
    return 0;
}
