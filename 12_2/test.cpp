//#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include <algorithm> 
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <ranges>

using namespace std;

////class Solution {
////public:
////    int findMaxLength(vector<int>& nums) {
////        for (auto& num : nums) num == 0 ? num = -1 : 1;
////        int sum = 0;
////        int ret = 0;
////        unordered_map<int, int> hash;
////        hash[0] = -1;
////        for (int i = 0; i < nums.size(); i++)
////        {
////            sum += nums[i];
////            if (hash.count(sum))
////            {
////                ret = max(ret, i + 1 - hash[sum]);
////            }
////            else hash[sum] = i + 1;
////        }
////        return ret;
////    }
////};
//
////int main()
////{
////    Solution s;
////    vector<int> v{ 0,1,0 };
////    s.findMaxLength(v);
////	return 0;
////}



//TypeStudent.cpp

#include <iostream>
#include <string>
#include <exception>
using namespace std;

#define MaxSize 100
//定义学生数据类型，至少能存储学号,姓名,性别,籍贯和专业等信息，建议使用英文参数
typedef struct student {
    //请输入你的代码
    string id;
    string name;
    string sex;
    string home;
    string major;


    //代码结束
} Student;
//定义学生列表数据类型，包含学生对象和学生数量
typedef struct StuList {
    Student* item;
    int length;
}StudentList;


int main()
{
    string id;
    string Name;
    string Sex;
    string Home;
    string Major;

    StudentList myList;
    // 初始化 myList 列表
    myList.item = new Student[MaxSize];
    myList.length = 0;
    try
    {
        // 连续插入三个学生的信息
        //形如：20210001 李斯 男 安徽合肥 网络空间安全
        int index;
        for (index = 0; index < 3; index++)
        {
            cin >> id >> Name >> Sex >> Home >> Major;
            //请输入你的代码
            //将输入学员信息存储进myList
            myList.item[myList.length].id = id;
            myList.item[myList.length].name = Name;
            myList.item[myList.length].sex = Sex;
            myList.item[myList.length].home = Home;
            myList.item[myList.length].major = Major;
            myList.length++;
            //代码结束

        }
        //打印学生列表信息

        for (index = 0; index < myList.length; index++)
        {
            //请输入你的代码
            //打印学生列表，注意按照 姓名 性别 籍贯 专业 学号 的顺序
            cout << myList.item[index].name << " "
                << myList.item[index].sex << " "
                << myList.item[index].home << " "
                << myList.item[index].major << " "
                << myList.item[index].id << endl;
            //代码结束
        }
    }

    catch (const std::exception& e)
    {
        cout << "出现异常输入: " << e.what() << endl;
    }
    delete[] myList.item;
    return 0;
}


//int main()
//{
//	string tmp;
//	cin >> tmp;
//	cout << tmp;
//	return 0;
//}