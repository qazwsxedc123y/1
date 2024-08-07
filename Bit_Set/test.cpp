#define  _CRT_SECURE_NO_WARNINGS

#include"bit_set.h"

//int main()
//{
//	//给40亿个无符号的整数，查找那个数在，那个不在
//	_bitset::bitset<100> bs;
//	bs.set(40);
//	bs.set(39);
//
//	cout << bs.test(38) << endl;
//	cout << bs.test(39) << endl;
//	cout << bs.test(40) << endl;
//	cout << bs.test(41) << endl;
//	cout << bs.test(42) << endl << endl;
//
//
//	bs.reset(40);
//
//	cout << bs.test(38) << endl;
//	cout << bs.test(39) << endl;
//	cout << bs.test(40) << endl;
//	cout << bs.test(41) << endl;
//	cout << bs.test(42) << endl << endl;
//
//
//	//size_t 范围是0-4290000000左右
//	// int  负数范围-1~...  0~...-1   一共是4290000000左右
//	// 0~127
//    // -1~-128
//	//_bitset::bitset<100> bs;//这里的100会默认识别为int类型
//	//如果要想创建一个包含全部正数的数组，则要这样
//	//_bitset::bitset<-1> bs;//隐式类型的int（-1）转化为size_t(max)值
//	//_bitset::bitset<0xffffffff> bigbs1;
//
//	return 0;
//}

//int main()
//{
//	//给100亿个无符号的整数，查找那个数只出现了一次
//	int a[] = { 1,4,7,9,44,88,1,4,88,99,78,5,7 ,7,7,7 };
//	_bitset::twobitset_1<100> twobs;
//	for (auto& e : a)
//	{
//		twobs.set(e);
//	}
//	twobs.PrintOnce();
//	return 0;
//}


int main()
{
	//给100亿个无符号的整数，查找出现次数不超过2次的

	int a[] = { 1,4,7,9,44,88,1,4,88,99,78,5,7 ,7,7,7 };
	_bitset::twobitset_2<100> twobs;
	for (auto& e : a)
	{
		twobs.set(e);
	}
	twobs.PrintUnderTwo();
	return 0;
}