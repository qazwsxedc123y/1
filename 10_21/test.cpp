#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

// 从二维坐标点派生出三维坐标点
//    父类（基类）     子类（派生类）

//class Point_x_y
//{
//public:
//    Point_x_y(int _x, int _y)
//        : x(_x)
//        , y(_y)
//    {}
//    Point_x_y()
//    {}
//    void Display()
//    {
//        cout << "x=" << x << " ";
//        cout << "y=" << y << " ";
//    }
//    ~Point_x_y()
//    {
//        cout << "~Point_x_y()" << endl;
//    }
//protected:
//    int x;
//    int y;
//};            
//// public  protected  private
//
//class Point_x_y_z : public Point_x_y
//{
//public:
//    Point_x_y_z(int _x, int _y, int _z)
//        : Point_x_y(_x, _y)
//        , z(_z)
//    {}
//    Point_x_y_z()
//    {}
//    void Display()
//    {
//        Point_x_y::Display();
//        cout << "z=" << z << endl;
//    }
//protected:
//    int z;
//};
//
//int main()
//{
//	Point_x_y_z point_xyz(2,2,2);
//	return 0;
//}



class point_x_y
{
public:
	//point_x_y(int _x,int _y)
	//{
	//	x = _x;
	//	y = _y;
	//}
	point_x_y(int _x, int _y)
		:x(_x)
		,y(_y)
	{}
	point_x_y()
	{}
	void Display()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
	~point_x_y()
	{
		cout << "~point_x_y()" << endl;
	}
protected:
	int x;
	int y;
};
class point_x_y_z : public point_x_y
{
public:
	point_x_y_z(int _x, int _y, int _z)
		: point_x_y(_x, _y)
	    ,z(_z)
	{}
	point_x_y_z()
		:point_x_y(0, 0)
		,z(0)
	{}
	~point_x_y_z()
	{
		cout << "~point_x_y_z()" << endl;
	}
	void Display()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl;
	}
protected:
	int z;
};
int main()
{
	point_x_y_z point1(1, 2, 3);
	return 0;
}