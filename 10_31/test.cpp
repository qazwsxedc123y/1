#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

// ����ģ��
// STL��׼���п��ܴ��������㶨��ĺ�������ͬ�ĺ���
//int Add(int x, int y)
//{
//	return x + y;
//}
//double Add(double x, double y)
//{
//	return x + y;
//}
////����ʵ��һ��int��char���

// ��ô���ԣ�
// �Ȱ�F10
// ���뷴���

// F10 ��������
// F11 ����̵���

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
//    // ���徲̬���ݳ�Ա
//};
//int User::numbers = 0;
//// ��̬���ݳ�Ա�ĳ�ʼ��
//
//int  main()
//{
//    User  u1, u2, u3;
//    cout << "�û�����Ϊ��" << User::numbers << endl;    // �����̬���ݳ�Ա��ֵ
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
//    void visit(); //ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
//    void visit2();
//private:
//    Building* building;
//};
//class Building
//{
//    //1.���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
//    friend class goodGay;
//    //2.���߱�����  goodGayGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
//    friend void goodGayGay::visit();
//     //3.���߱����� printtȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������
//    friend void printt(Building* building);
//
//public:
//    Building()
//    {
//        this->m_SittingRoom = "����";
//        this->m_BedRoom = "����";
//    }
//    string m_SittingRoom; //����
//private:
//    string m_BedRoom; //����
//};
////����Ϊ���嶨�庯�� 
//goodGay::goodGay()
//{
//    building = new Building;
//}
//void goodGay::visit()
//{
//    cout << "��һ���û������ڷ���" << building->m_SittingRoom << endl;
//    cout << "��һ���û������ڷ���" << building->m_BedRoom << endl;
//}
//goodGayGay::goodGayGay()
//{
//    building = new Building;
//}
//void goodGayGay::visit()
//{
//    cout << "�ڶ����û������ڷ���" << building->m_SittingRoom << endl;
//    cout << "�ڶ����û������ڷ���" << building->m_BedRoom << endl;
//}
//void goodGayGay::visit2()
//{
//    cout << "�ڶ����û������ڵڶ��η���" << building->m_SittingRoom << endl;
//    //cout << "�ڶ����û������ڵڶ��η���" << building->m_BedRoom << endl;
//}
//void printt(Building* building)
//{
//    cout << "�������û������ڷ��ʣ� " << building->m_SittingRoom << endl;
//    cout << "�������û������ڷ��ʣ� " << building->m_BedRoom << endl;
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
//    test01();//friend���α����
//    test02();//friend���γ�Ա����
//    test03();//friend�������ⶨ��ĺ���
//    return 0;
//}

