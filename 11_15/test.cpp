#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <assert.h>
#include <bitset>
using namespace std;

int main()
{
	//此处应该从文件中读取100亿个整数，但是为了方便演示，就假设已经读取了
	vector<int> v{ -12, 33, 4, 2, 7, 3, 32, 3, 3, 12, 21 };// 假设v里面有100亿个整形数据
	//在堆上申请空间
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
			//不做处理
		}
		else //11（不会出现这种，因为我们设定上就是最大为10）
		{
			assert(false);
		}
	}
	// 统计那个整数出现了一次
	for (size_t i = 0; i < 4294967295; i++)
	{
		if ((!bs1->test(i) && bs2->test(i)) || (bs1->test(i) && !bs2->test(i))) //01或10
			cout << i << endl;
	}
	return 0;
}
