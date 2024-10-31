#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

// 函数模板
// STL标准库中可能存在着与你定义的函数名相同的函数
//int Add(int x, int y)
//{
//	return x + y;
//}
//double Add(double x, double y)
//{
//	return x + y;
//}
////帮我实现一个int与char相加

// 怎么调试：
// 先按F10
// 进入反汇编

// F10 逐语句调试
// F11 逐过程调试

//template<class T1,class T2>
//T1 Add(T1 x, T2 y)
//{
//	y -= 'a';
//	return x + y;
//}
//int main()
//{
//	cout << Add('a', 'b') << endl;
//	return 0;
//}

//template<class T>
//class A
//{
//public:
//	A(T _a)
//	    :a(_a)
//	{}
//private:
//	T a;
//};
//
////class A
////{
////public:
////	A(double _a)
////		:a(_a)
////	{}
////private:
////	double a;
////};
//
//int main()
//{
//	A<double> a(3.3);
//	return 0;
//}


//class  User
//{
//public:
//    User()
//    {
//        numbers++;
//    }
//    int  getNumbers()
//    {
//        return  numbers;
//    }
//
//    static int numbers;
//    // 定义静态数据成员
//};
//int User::numbers = 0;
//// 静态数据成员的初始化
//
//int  main()
//{
//    User  u1, u2, u3;
//    cout << "用户数量为：" << User::numbers << endl;    // 输出静态数据成员的值
//    return 0;
//}


//class Building;
//class goodGay
//{
//public:
//    goodGay();
//    void visit();
//private:
//    Building* building;
//};
//class goodGayGay
//{
//public:
//    goodGayGay();
//    void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
//    void visit2();
//private:
//    Building* building;
//};
//class Building
//{
//    //1.告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
//    friend class goodGay;
//    //2.告诉编译器  goodGayGay类中的visit成员函数 是Building好朋友，可以访问私有内容
//    friend void goodGayGay::visit();
//     //3.告诉编译器 printt全局函数 是 Building类的好朋友，可以访问类中的私有内容
//    friend void printt(Building* building);
//
//public:
//    Building()
//    {
//        this->m_SittingRoom = "客厅";
//        this->m_BedRoom = "卧室";
//    }
//    string m_SittingRoom; //客厅
//private:
//    string m_BedRoom; //卧室
//};
////以下为具体定义函数 
//goodGay::goodGay()
//{
//    building = new Building;
//}
//void goodGay::visit()
//{
//    cout << "第一个好基友正在访问" << building->m_SittingRoom << endl;
//    cout << "第一个好基友正在访问" << building->m_BedRoom << endl;
//}
//goodGayGay::goodGayGay()
//{
//    building = new Building;
//}
//void goodGayGay::visit()
//{
//    cout << "第二个好基友正在访问" << building->m_SittingRoom << endl;
//    cout << "第二个好基友正在访问" << building->m_BedRoom << endl;
//}
//void goodGayGay::visit2()
//{
//    cout << "第二个好基友正在第二次访问" << building->m_SittingRoom << endl;
//    //cout << "第二个好基友正在第二次访问" << building->m_BedRoom << endl;
//}
//void printt(Building* building)
//{
//    cout << "第三个好基友正在访问： " << building->m_SittingRoom << endl;
//    cout << "第三个好基友正在访问： " << building->m_BedRoom << endl;
//}
//void test01()
//{
//    goodGay gg;
//    gg.visit();
//}
//void test02()
//{
//    goodGayGay gg;
//    gg.visit();
//}
//void test03()
//{
//    Building b;
//    printt(&b);
//}
//
//int main() {
//    test01();//friend修饰别的类
//    test02();//friend修饰成员函数
//    test03();//friend修饰类外定义的函数
//    return 0;
//}

