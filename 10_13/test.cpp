#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

//int main()
//{
//	unordered_multimap<int, string> umm;
//	//插入键值对（允许键值重复）
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
//	//插入键值对方式一：构造匿名对象插入
//	um.insert(pair<int, string>(1, "one"));
//	um.insert(pair<int, string>(2, "two"));
//	um.insert(pair<int, string>(3, "three"));
//	//遍历方式一：范围for
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //1->one 2->two 3->three
//	//插入键值对方式二：调用make_pair函数模板插入
//	um.insert(make_pair(4, "four"));
//	um.insert(make_pair(5, "five"));
//	um.insert(make_pair(6, "six"));
//	//遍历方式二：迭代器遍历
//	unordered_map<int, string>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << "->" << it->second << " ";
//		it++;
//	}
//	cout << endl; //1->one 2->two 3->three 4->four 5->five 6->six
//	//插入键值对方式三：利用[]运算符重载函数进行插入（常用）
//	um[7] = "seven";
//	um[8] = "eight";
//	um[9] = "nine";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 5->five 6->six 7->seven 8->eight
//	//删除键值对方式一：根据key值删除
//	um.erase(5);
//	//删除键值对方式二：根据迭代器删除
//	unordered_map<int, string>::iterator pos = um.find(7); //查找键值为7的键值对
//	if (pos != um.end())
//	{
//		um.erase(pos);
//	}
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 6->six 8->eight
//	//修改键值对方式一：通过find获得迭代器，通过迭代器修改
//	pos = um.find(1);
//	if (pos != um.end())
//	{
//		pos->second = "one/first";
//	}
//	//修改键值对方式二：利用[]运算符重载函数进行修改（常用）
//	um[2] = "two/second";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one/first 2->two/second 3->three 4->four 6->six 8->eight
//	//容器中key值为3的键值对的个数
//	cout << um.count(3) << endl;
//	//容器的大小
//	cout << um.size() << endl;
//	//清空容器
//	um.clear();
//	//容器判空
//	cout << um.empty() << endl;
//	//交换两个容器的数据
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
//	//插入元素（允许重复）
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
//	//插入元素（去重）
//	us.insert(1);
//	us.insert(5);
//	us.insert(3);
//	us.insert(5);
//	us.insert(4);
//	us.insert(3);
//	//遍历容器方式一（范围for）
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 5 3 4
//	//删除元素方式一
//	us.erase(5);
//	//删除元素方式二
//	unordered_set<int>::iterator pos = us.find(1);
//	if (pos != us.end())
//	{
//		us.erase(pos);
//	}
//	//遍历容器方式二（迭代器遍历）
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;//3 4
//	//容器中值为2的元素个数
//	cout << us.count(3) << endl;//1
//	//容器大小
//	cout << us.size();//2
//	//清空容器
//	us.clear();//这时候就变为了空
//	//容器判空
//	//空返回true（1）不为空为false（0）
//	cout << us.empty() << endl;//1
//	//交换两个容器的数据
//	unordered_set<int> tmp{ 11, 12, 13, 14 };//c++11的构造方法
//	us.swap(tmp);
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //11 12 13 14
//	return 0;
//}