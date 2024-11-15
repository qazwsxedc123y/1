#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <assert.h>
#include <bitset>
using namespace std;

int main()
{
	//�˴�Ӧ�ô��ļ��ж�ȡ100�ڸ�����������Ϊ�˷�����ʾ���ͼ����Ѿ���ȡ��
	vector<int> v{ -12, 33, 4, 2, 7, 3, 32, 3, 3, 12, 21 };// ����v������100�ڸ���������
	//�ڶ�������ռ�
	bitset<INT_MAX>* bs1 = new bitset<INT_MAX>;
	bitset<INT_MAX>* bs2 = new bitset<INT_MAX>;
	for (auto e : v)
	{
		if (!bs1->test(e) && !bs2->test(e)) //00->01
		{
			bs2->set(e);
		}
		else if (!bs1->test(e) && bs2->test(e)) //01->10
		{
			bs1->set(e);
			bs2->reset(e);
		}
		else if (bs1->test(e) && !bs2->test(e)) //10->10
		{
			//��������
		}
		else //11������������֣���Ϊ�����趨�Ͼ������Ϊ10��
		{
			assert(false);
		}
	}
	// ͳ���Ǹ�����������һ��
	for (size_t i = 0; i < 4294967295; i++)
	{
		if ((!bs1->test(i) && bs2->test(i)) || (bs1->test(i) && !bs2->test(i))) //01��10
			cout << i << endl;
	}
	return 0;
}
