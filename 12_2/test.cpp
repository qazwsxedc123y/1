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
//����ѧ���������ͣ������ܴ洢ѧ��,����,�Ա�,�����רҵ����Ϣ������ʹ��Ӣ�Ĳ���
typedef struct student {
    //��������Ĵ���
    string id;
    string name;
    string sex;
    string home;
    string major;


    //�������
} Student;
//����ѧ���б��������ͣ�����ѧ�������ѧ������
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
    // ��ʼ�� myList �б�
    myList.item = new Student[MaxSize];
    myList.length = 0;
    try
    {
        // ������������ѧ������Ϣ
        //���磺20210001 ��˹ �� ���պϷ� ����ռ䰲ȫ
        int index;
        for (index = 0; index < 3; index++)
        {
            cin >> id >> Name >> Sex >> Home >> Major;
            //��������Ĵ���
            //������ѧԱ��Ϣ�洢��myList
            myList.item[myList.length].id = id;
            myList.item[myList.length].name = Name;
            myList.item[myList.length].sex = Sex;
            myList.item[myList.length].home = Home;
            myList.item[myList.length].major = Major;
            myList.length++;
            //�������

        }
        //��ӡѧ���б���Ϣ

        for (index = 0; index < myList.length; index++)
        {
            //��������Ĵ���
            //��ӡѧ���б�ע�ⰴ�� ���� �Ա� ���� רҵ ѧ�� ��˳��
            cout << myList.item[index].name << " "
                << myList.item[index].sex << " "
                << myList.item[index].home << " "
                << myList.item[index].major << " "
                << myList.item[index].id << endl;
            //�������
        }
    }

    catch (const std::exception& e)
    {
        cout << "�����쳣����: " << e.what() << endl;
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