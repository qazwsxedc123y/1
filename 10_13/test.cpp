#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

//int main()
//{
//	unordered_multimap<int, string> umm;
//	//�����ֵ�ԣ������ֵ�ظ���
//	umm.insert(make_pair(2024, "year"));
//	umm.insert(make_pair(10, "month"));
//	umm.insert(make_pair(13, "day"));
//	umm.insert(make_pair(13, "dayy"));
//	for (auto e : umm)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //13->day 13->dayy 2024->year 10->month
//	return 0;
//}



//int main()
//{
//	unordered_map<int, string> um;
//	//�����ֵ�Է�ʽһ�����������������
//	um.insert(pair<int, string>(1, "one"));
//	um.insert(pair<int, string>(2, "two"));
//	um.insert(pair<int, string>(3, "three"));
//	//������ʽһ����Χfor
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //1->one 2->two 3->three
//	//�����ֵ�Է�ʽ��������make_pair����ģ�����
//	um.insert(make_pair(4, "four"));
//	um.insert(make_pair(5, "five"));
//	um.insert(make_pair(6, "six"));
//	//������ʽ��������������
//	unordered_map<int, string>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << "->" << it->second << " ";
//		it++;
//	}
//	cout << endl; //1->one 2->two 3->three 4->four 5->five 6->six
//	//�����ֵ�Է�ʽ��������[]��������غ������в��루���ã�
//	um[7] = "seven";
//	um[8] = "eight";
//	um[9] = "nine";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 5->five 6->six 7->seven 8->eight
//	//ɾ����ֵ�Է�ʽһ������keyֵɾ��
//	um.erase(5);
//	//ɾ����ֵ�Է�ʽ�������ݵ�����ɾ��
//	unordered_map<int, string>::iterator pos = um.find(7); //���Ҽ�ֵΪ7�ļ�ֵ��
//	if (pos != um.end())
//	{
//		um.erase(pos);
//	}
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 6->six 8->eight
//	//�޸ļ�ֵ�Է�ʽһ��ͨ��find��õ�������ͨ���������޸�
//	pos = um.find(1);
//	if (pos != um.end())
//	{
//		pos->second = "one/first";
//	}
//	//�޸ļ�ֵ�Է�ʽ��������[]��������غ��������޸ģ����ã�
//	um[2] = "two/second";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one/first 2->two/second 3->three 4->four 6->six 8->eight
//	//������keyֵΪ3�ļ�ֵ�Եĸ���
//	cout << um.count(3) << endl;
//	//�����Ĵ�С
//	cout << um.size() << endl;
//	//�������
//	um.clear();
//	//�����п�
//	cout << um.empty() << endl;
//	//������������������
//	unordered_map<int, string> tmp{ { 2024, "year" }, { 10, "month" }, {13, "day"} };
//	um.swap(tmp);
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //2024->year 10->month 13->day
//	return 0;
//}



//int main()
//{
//	unordered_multiset<int> ums;
//	//����Ԫ�أ������ظ���
//	ums.insert(1);
//	ums.insert(4);
//	ums.insert(3);
//	ums.insert(3);
//	ums.insert(2);
//	ums.insert(2);
//	ums.insert(2);
//	ums.insert(3);
//	ums.insert(5);
//	for (auto e : ums)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 4 3 3 3 2 2 2 5
//	return 0;
//}


//int main()
//{
//	unordered_set<int> us;
//	//����Ԫ�أ�ȥ�أ�
//	us.insert(1);
//	us.insert(5);
//	us.insert(3);
//	us.insert(5);
//	us.insert(4);
//	us.insert(3);
//	//����������ʽһ����Χfor��
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 5 3 4
//	//ɾ��Ԫ�ط�ʽһ
//	us.erase(5);
//	//ɾ��Ԫ�ط�ʽ��
//	unordered_set<int>::iterator pos = us.find(1);
//	if (pos != us.end())
//	{
//		us.erase(pos);
//	}
//	//����������ʽ����������������
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;//3 4
//	//������ֵΪ2��Ԫ�ظ���
//	cout << us.count(3) << endl;//1
//	//������С
//	cout << us.size();//2
//	//�������
//	us.clear();//��ʱ��ͱ�Ϊ�˿�
//	//�����п�
//	//�շ���true��1����Ϊ��Ϊfalse��0��
//	cout << us.empty() << endl;//1
//	//������������������
//	unordered_set<int> tmp{ 11, 12, 13, 14 };//c++11�Ĺ��췽��
//	us.swap(tmp);
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //11 12 13 14
//	return 0;
//}