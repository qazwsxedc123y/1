#include <cmath>
#include <iostream>
#include <string> 
#include <queue> 
#include <cstring>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 1, 0, 0 }; 
int dy[4] = { 0, 0, -1, 1 };
char dir[4] = { 'U', 'D', 'L', 'R' };
string maza[30];
bool vis[30][50]; 
vector<vector<char>> pathDir(30, vector<char>(50, ' '));
int main()
{
	memset(vis, 0, sizeof(vis));
	int rows = 30, cols = 50;

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	vis[0][0] = true;

	for (int i = 0; i < 30; i++) cin >> maza[i];

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			if (a == rows - 1 && b == cols - 1) {
				// ???Y?·??
				string path;
				int i = rows - 1, j = cols - 1;
				while (i != 0 || j != 0) {
					path += pathDir[i][j];
					if (pathDir[i][j] == 'D') i--;
					else if (pathDir[i][j] == 'L') j++;
					else if (pathDir[i][j] == 'R') j--;
					else if (pathDir[i][j] == 'U') i++;
				}
				reverse(path.begin(), path.end());
				cout << path << endl;
				return 0;
			}
			for (int k = 0; k < 4; k++) {
				int x = a + dx[k], y = b + dy[k];
				if (x >= 0 && x < rows && y >= 0 && y < cols && maza[x][y] == '0' && !vis[x][y]) {
					q.push({ x, y });
					vis[x][y] = true;
					pathDir[x][y] = dir[k];
				}
			}
		}
	}

	return 0;
}



//// 4659
//
//int a[20190350];
//
//int main()
//{
//	int n = 20190324;
//	a[1] = a[2] = a[3] = 1;
//	for(int i = 4; i <= n; i++){
//		a[i] = ((a[i-1] + a[i-2]) % 10000+ a[i-3]) % 10000;
//	}
//	cout << a[12];
//	return 0;
//} 



//// 2658417853
//
//bool check(int i){
//	while(i){
//		int t = i % 10;
//		i /= 10;
//		if(t == 2 || t == 0 || t == 1 || t == 9) return true;
//	}
//	return false;
//}
//
//int main()
//{
//	long long sum = 0, ans = 0;
//	for(int i = 1; i <= 2019; i++){
//		if(check(i)){
//			ans = i * i;
//			sum += ans; 
//		}
//	}
//	cout << sum << endl; 
//	return 0;
//}


//// AAAEEEEEEHHHIIILLRRRSSTTWWWY
//int main()
//{
//	string s;
//	cin >> s;
//	int ch[32] = {0};
//	int n = s.size();
//	for(int i = 0; i < n; i++){
//		ch[s[i] - 'A']++;
//	}
//	for(int i = 0; i < 26; i++){
//		int sz = ch[i];
//		for(int j = 0; j < sz; j++){
//			char t = 'A' + i;
//			cout << t;
//		}
//	}
//	return 0;
//} 

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
