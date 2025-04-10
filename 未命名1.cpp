#include <cmath>
#include <iostream>
#include <string> 
#include <queue> 
#include <cstring>
#include <algorithm>
using namespace std;



//// 125
//
//int m[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30,  31, 30, 31};
//int main()
//{
//	// 2000 1 1
//	// 2000 5 4
//	// 计算中间差几天 
//	int count = 0;
//	int bm = 1, bd = 1; 
//	while(1){
//		if(bm == 5 && bd == 4) break; 
//		int t = m[bm];
//		bd++;
//		if(bd > t){
//			bm++;
//			bd = 1;
//		}
//		count++;
//	} 
//	cout << count + 1;
//	return 0;
//}


//long long ans, num = 59084709587505;
//int main()
//{
//    for(int i = 0; pow(3, i) <= num; ++i)
//        for(int j = 0; pow(5, j) <= num; ++j)
//            for(int k = 0; pow(7, k) <= num; ++k)
//                if(pow(3, i) * pow(5, j) * pow(7, k) <= num)
//                    ans++;
//    //初始有个1 == 3^0 * 5^0 * 7^0 == 1
//    cout<<ans - 1; //减去初始的1
//    return 0;
//}


////5650 4542 3554 473 946 4114 3871 9073 90 4329 
////2758 7949 6113 5659 5245 7432 3051 4434 6704 3594 
////9937 1173 6866 3397 4759 7557 3070 2287 1453 9899 
////1486 5722 3135 1170 4014 5510 5120 729 2880 9019 
////2049 698 4582 4346 4427 646 9742 7340 1230 7683 
////5693 7015 6887 7381 4172 4341 2909 2027 7355 5649 
////6701 6645 1671 5978 2704 9926 295 3125 3878 6785 
////2066 4247 4800 1578 6652 4616 1113 6205 3264 2915 
////3966 5291 2904 1285 2193 1428 2265 8730 9436 7074 
////689 5510 8243 6114 337 4096 8199 7313 3685 211 
//
//// 31
//
//int a[20][20], num_2, num_5;
//void pro(int x)
//{
//    while(1) { //先统计5的因子数
//        if(x % 5 == 0) {
//            x /= 5;
//            num_5 += 1;
//        }
//        else break;
//    }
//    while(1) { //再统计2的因子数
//        if(x % 2 == 0) {
//            x /= 2;
//            num_2 += 1;
//        }
//        else break;
//    }
//}
//int main()
//{
//	for(int i = 0; i < 10; ++i){
//        for(int j = 0; j < 10; ++j){
//        	cin >> a[i][j];
//		}	
//	}
//
//	for(int i = 0; i < 10; ++i){
//        for(int j = 0; j < 10; ++j){
//            pro(a[i][j]);      	
//		}	
//	}
//	cout<<min(num_2, num_5);
//	return 0;
//} 



//// 2000年12月31号是星期日
//// 1901/1/1
//int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,  31, 30, 31};
//bool check(int year){
//	// 是闰年返回true 
//	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
//	
//	return false;
//} 
//
//int main()
//{
//	int by = 1901, bm = 1, bd = 1;
//	int ey = 2000, em = 12, ed = 31;
//	int count = 0;
//	for(;by < ey; by++){
//		count += check(by) ? 366 : 365;
//	}
//	cout << count << endl;
//	while(1){
//		if(by == ey && bm == em && bd == ed) break; 
//		int t = m[bm];
//		if(check(by) && bm == 2) t++;
//		bd++;
//		if(bd > t){
//			bm++;
//			bd = 1;
//			if(bm > 12){
//				by++;
//				bm = 1;
//			}
//		}
//		count++;
//	}
//	cout << endl;
//	cout << count << endl;
//	// 36524天
//	// 分为 5217周 + 5天
//	// 5217 + 0
//	cout << "5217"; 
//	return 0;
//}


// 效率低，换 
 
//int main()
//{
//	// 统计多少个星期一 
//	int by = 1901, bm = 1, bd = 1;
//	int ey = 2000, em = 12, ed = 31;
//	int count = 0;
//	while(1){
//		if(by == ey && bm == em && bd == ed) break; 
//		int t = m[bm];
//		if(check(by) && bm == 2) t++;
//		bd++;
//		if(bd > t){
//			bm++;
//			bd = 1;
//			if(bm > 12){
//				by++;
//				bm = 1;
//			}
//		}
//		count++;
//	} 
//	cout << count;
//	return 0;
//}


//// 1048575/524288
//
//int main()
//{
//	int n = 20;
//	n--; 
//	int b = pow(2, n); // 分母 
//	int a = 0;
//	for(int i = n; i >= 0; i--){
//		// 先通分
//		// 再累加
//		int t = pow(2, i);
//		a += t;
//	}
//	cout << a << "/" << b;
//	return 0;
//}


//// 490
//
//int book[30], ans; //book[]的大小要大于20
//int c[20][5] = {
//{97, 90, 0 ,0, 0},
//{92, 85, 96, 0, 0},
//{0, 0, 0, 0, 93},
//{0, 0, 0, 80, 86},
//{89, 83, 97, 0, 0},
//{82, 86, 0, 0, 0},
//{0, 0, 0, 87, 90},
//{0, 97, 96, 0, 0},
//{0, 0, 89, 0, 0},
//{95, 99, 0, 0, 0},
//{0, 0, 96, 97, 0},
//{0, 0, 0, 93, 98},
//{94, 91, 0, 0, 0},
//{0, 83, 87, 0, 0},
//{0, 0, 98, 97, 98},
//{0, 0, 0, 93, 86},
//{98, 83, 99, 98, 81},
//{93, 87, 92, 96, 98},
//{0, 0, 0, 89, 92},
//{0, 99, 96, 95, 81}
//};
//
//void dfs(int step, int now){
//	if(step == 5){
//		ans = max(ans, now);
//		return ;
//	}
//	
//	// 遍历
//	for(int i = 0; i < 20; i++){
//		if(book[i] == false){
//			book[i] = true;
//			dfs(step+1, now + c[i][step]);
//			// 回溯
//			book[i] = false; 
//		}
//	} 
//}
//
//int main()
//{
//	// 第一个参数是个数，第二个是现在的总分数 
//	dfs(0, 0);
//	cout << ans;
//	return 0;
//} 



//int dx[4] = { -1, 1, 0, 0 }; 
//int dy[4] = { 0, 0, -1, 1 };
//char dir[4] = { 'U', 'D', 'L', 'R' };
//string maza[30];
//bool vis[30][50]; 
//vector<vector<char>> pathDir(30, vector<char>(50, ' '));
//int main()
//{
//	memset(vis, 0, sizeof(vis));
//	int rows = 30, cols = 50;
//
//	queue<pair<int, int>> q;
//	q.push({ 0, 0 });
//	vis[0][0] = true;
//
//	for (int i = 0; i < 30; i++) cin >> maza[i];
//
//	while (!q.empty()) {
//		int sz = q.size();
//		for (int i = 0; i < sz; i++) {
//			int a = q.front().first;
//			int b = q.front().second;
//			q.pop();
//			if (a == rows - 1 && b == cols - 1) {
//				// ???Y?·??
//				string path;
//				int i = rows - 1, j = cols - 1;
//				while (i != 0 || j != 0) {
//					path += pathDir[i][j];
//					if (pathDir[i][j] == 'D') i--;
//					else if (pathDir[i][j] == 'L') j++;
//					else if (pathDir[i][j] == 'R') j--;
//					else if (pathDir[i][j] == 'U') i++;
//				}
//				reverse(path.begin(), path.end());
//				cout << path << endl;
//				return 0;
//			}
//			for (int k = 0; k < 4; k++) {
//				int x = a + dx[k], y = b + dy[k];
//				if (x >= 0 && x < rows && y >= 0 && y < cols && maza[x][y] == '0' && !vis[x][y]) {
//					q.push({ x, y });
//					vis[x][y] = true;
//					pathDir[x][y] = dir[k];
//				}
//			}
//		}
//	}
//
//	return 0;
//}



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
