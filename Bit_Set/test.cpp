#define  _CRT_SECURE_NO_WARNINGS

#include"bit_set.h"

//int main()
//{
//	//��40�ڸ��޷��ŵ������������Ǹ����ڣ��Ǹ�����
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
//	//size_t ��Χ��0-4290000000����
//	// int  ������Χ-1~...  0~...-1   һ����4290000000����
//	// 0~127
//    // -1~-128
//	//_bitset::bitset<100> bs;//�����100��Ĭ��ʶ��Ϊint����
//	//���Ҫ�봴��һ������ȫ�����������飬��Ҫ����
//	//_bitset::bitset<-1> bs;//��ʽ���͵�int��-1��ת��Ϊsize_t(max)ֵ
//	//_bitset::bitset<0xffffffff> bigbs1;
//
//	return 0;
//}

//int main()
//{
//	//��100�ڸ��޷��ŵ������������Ǹ���ֻ������һ��
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
	//��100�ڸ��޷��ŵ����������ҳ��ִ���������2�ε�

	int a[] = { 1,4,7,9,44,88,1,4,88,99,78,5,7 ,7,7,7 };
	_bitset::twobitset_2<100> twobs;
	for (auto& e : a)
	{
		twobs.set(e);
	}
	twobs.PrintUnderTwo();
	return 0;
}