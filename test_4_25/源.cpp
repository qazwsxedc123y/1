#define  _CRT_SECURE_NO_WARNINGS
#include"test.h"
using namespace std;
int main()
{
	date d1;
	d1.print();

	date d2(d1);
	d1.print();
	cout << (d1 < d2) << endl;//d1为主,等价于
	cout << d1.operator<(d2) << endl;
	cout << d1.operator==(d2) << endl;
	cout << d1.operator!=(d2) << endl;
	cout << d1.operator<=(d2) << endl;
	//cout << (operator<(d1, d2)) << endl;

	//date ret1 = d2 += 50;
	//ret1.print();

	//+

	//date ret2 = d2 + 50;
	//ret2.print();

	//+=

	//d2 += 50;
	//d2.print();

	//-

	//date ret3 = d2 - 50;
	//ret3.print();

	//-=
	//d2.print();
	//d2 -= -50;
	//d2 -= 50;
 //   d2.print();

	//-

	//date ret4 = d2 - (-50);
	//ret4.print();

	//++i   与   ++i
	//d2.print();
	//date tmp = d2++;
	////d2.operator++(100);
	//d2.print();
	//d2.operator++();
	//d2.print();

	//赋值

	//date ret;
	//ret = d2;
	//ret.print();

	//--i与i--

	//date tmp = d2--;
	//--d2;
	//d2.print();

	//日期-日期

	//d1++;
	//cout << d1 - d2 << endl;;

	//stack st1;
	//st1.push(1);
	//st1.push(2);
	//stack st2(st1);
	//while (!st1.StackEmpty())
	//{
	//	cout << st1.StackTop() << " ";
	//	st1.StackPop();
	//}
	//cout << endl;
	////stack st2(st1);
	//while (!st2.StackEmpty())
	//{
	//	cout << st2.StackTop() << " ";
	//	st2.StackPop();
	//}

	return 0;
}