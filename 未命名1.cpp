#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;



//long long a[10010];
//int main()
//{
//	long long n = 2021041820210418, sum = 0, now = 0;
//	for(int i = 1; i < sqrt(n); i++)
//	{
//		if(n%i == 0){
//			a[now++] = i;
//			// 存另一个因子
//			if(i*i != n) a[now++] = n / i; 
//		}
//	}
//	for(int i = 0; i < now; i++)
//		for(int j = 0; j < now; j++)
//			for(int m = 0; m < now; m++)
//				if(a[i]*a[j]*a[m] == n) sum++;
//				
//	cout << sum << endl;
//	return 0;
//}


//int a[10];
//bool func(int t)
//{
//	while(t)
//	{
//		int m = t % 10;
//		if(a[m]-- <= 0) return false;
//		t /= 10;
//	}
//	return true;
//}
//int main()
//{
//	for(int i = 0; i < 10; i++) a[i] = 2021;
//	int i = 1;
//	for(i; ;i++)
//	{
//		// 查看是否可以凑齐，凑不齐返回false 
//		if(!func(i)) break;
//	}
//	cout << i - 1 << endl;
//	return 0;
//}


//int main()
//{
//	int sum = 0;
//	for(int i = 1; i <= 25; i++){
//		if(25 % i == 0) sum++;
//	}
//	cout << sum << endl;
//	return 0;
//}
  


//int a[1000][1000];
//int main()
//{
//	a[1][1] = 1;
//	int m = 1;
//	for(int i = 1, j = 1; i <= 40 && j <= 40;)
//	{
//		// 向右
//		a[i][++j] = ++m;
//		
//		// 左下 
//		while(j > 1)
//		{
//			a[++i][--j] = ++m;
//		}
//		
//		// 向下 
//		a[++i][j] = ++m;
//		
//		// 右上
//		while(i > 1)
//		{
//			a[--i][++j] = ++m;
//		} 
//	}
//	cout << a[20][20] << endl;
//	return 0;
//}



//bool com(int i, int j)
//{
//	while(i % j){
//		int t = i % j;
//		i = j;
//		j = t;
//	}
//	return j == 1; 
//}
//int main()
//{
//	int count = 0;
//	for(int i = 1; i <= 5; i++){
//		for(int j = 1; j <= 5; j++){
//			// 判断最大公约数是否为1，为1返回true 
//			if(com(i, j)) count++;
//		}
//	}  
//	cout << count << endl; 
//	return 0;
//}


//int count_2(int t)
//{
//	int ret = 0;
//	while(t)
//	{
//		if(t % 10 == 2) ret++;
//		t /= 10;
//	}
//	return ret;
//}
//int main()
//{
//	int count = 0;
//	for(int i = 1; i <= 22; i++)
//	{
//		count += count_2(i);
//	}
//	cout << count << endl;
//	return 0;
//}
