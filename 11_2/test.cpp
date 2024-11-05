#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

// 运算符重载
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = { 0 };
        int m = p.size();
        for (auto& e : p) hash1[e - 'a']++;
        int hash2[26] = { 0 };
        int n = s.size();
        vector<int> ret;
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            char in = s[right];
            //进窗口
            hash2[in - 'a']++;
            if (hash2[in - 'a'] <= hash1[in - 'a']) count++;
            //出窗口
            char ou = s[left];
            if (right - left + 1 > m)
            {
                if (hash2[ou - 'a']-- <= hash1[ou - 'a']) count--;
                left++;
            }
            //更新结果
            if (count == m)
            {
                cout << "a" << endl;
                ret.push_back(left);
            }
        }
        return ret;
    }
};
class Date
{
public:
	Date(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	//void add(int _day)
	//{
	//	this->day += _day;
	//}
	Date operator+(int _day)
	{
		this->day += _day;
	}
private:
	int year;
	int month;
	int day;
};
int main()
{
	Date d1(2024, 11, 03);
	//d1.add(3);
	d1 = d1 + 3;// 按F11 进入该函数
	return 0;
}






















//// 写代码的步骤
//// 实现一个二维坐标点类模板
//// template<class T>
//// 这是要实现一个类
//// 要实现这个类的类成员：private x，y
//// 要实现这个类的类成员：public 
//// 构造函数  显示函数（返回x或者y）
//// 析构函数  伪拷贝函数
//
//template<class T>
//class PointTemplate
//{
//public:
//	PointTemplate()
//	{
//		x = 0;
//		y = 0;
//	}
//	PointTemplate(T _x,T _y)
//	{
//		x = _x;
//		y = _y;
//	}
//	T Getx()
//	{
//		return x;
//	}
//	T Gety()
//	{
//		return y;
//	}
//	PointTemplate<T> tranlate(T xd, T yd)// 实现传x，y返回一个类类型的变量
//	{
//		// 我们先创建一个类类型，然后进行操作
//		PointTemplate<T> temp;
//		temp.x = xd;
//		temp.y = yd;
//		return temp;
//		//对当前类的操作
//		//this->x += xd;
//		//this->y += xd;
//	}
//private:
//	T x;
//	T y;
//};
//
//int main()
//{
//	PointTemplate<int> p1(22, 22);
//	// 参考移动构造与移动赋值
//	PointTemplate<int> newpor = p1.tranlate(21, 22);
//                                 
//	return 0;
//}




















////class Solution {
////public:
////    int minSubArrayLen(int target, vector<int>& nums) {
////        int left = 0, right = 0;
////        int n = nums.size();
////        if (n == 0)
////        {
////            return 0;
////        }
////        int sum = 0;
////        int ret = n;
////        while (right < n)
////        {
////            while (right < n && sum < target)
////            {
////                sum += nums[right];
////                right++;
////            }
////            while (left < right && sum >= target)
////            {
////                ret = min(ret, right - left + 1);
////                sum -= nums[left];
////                left++;
////            }
////        }
////        return ret == n ? 0 : ret;
////    }
////};
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int left = 0, right = 0;
//        int n = nums.size();
//        if (n == 0)
//        {
//            return 0;
//        }
//        int sum = 0;
//        int ret = INT_MAX;
//        while (right < n)
//        {
//            while (right < n && sum < target)
//            {
//                sum += nums[right];
//                right++;
//            }
//            while (left < right && sum >= target)
//            {
//                ret = min(ret, right - left);
//                sum -= nums[left];
//                left++;
//            }
//        }
//        return ret == INT_MAX ? 0 : ret;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v{ 1,2,3,4,5 };
//    s.minSubArrayLen(15, v);
//    return 0;
//}