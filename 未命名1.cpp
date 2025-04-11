#include <cmath>
#include <iostream>
#include <string> 
#include <queue> 
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long a[100001];
int Rnum(long long num) {
    while (num / 10) {
        num /= 10;
    }
    return num;
}
int Lnum(long long num) {
    return num % 10;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, 1); //表示以i为结尾，符合要求的最长长度
    int ret = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int right = Rnum(a[i]);
            int left = Lnum(a[j]);
            if (left == right) dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }
    cout << n - ret << endl;

    return 0;
}


//int a[10001], b[10001];
//int main()
//{
//  // 请在此输入您的代码
//  int n;
//  cin >> n;
//  for(int i = 0; i < n; i++){
//    cin >> a[i] >> b[i];
//  }
//  // 最大是当前的a正好够练b个，然后每组取min
//  // a/(b+1) < ret <= a/b
//  int Max = INT_MAX, Min = 0;
//  for(int i = 0; i < n; i++){
//    int t = a[i] / b[i];
//    int q = a[i] / (b[i] + 1) + 1;
//    Max = min(Max, t);
//    Min = max(Min, q);
//  }
//  cout << Min << " " << Max << endl;
//  return 0;
//}



//const int n = 23333333;
//const double target = 11625907.5798;
//const double eps = 1e-6;  // 允许的误差范围
//
//int main(){
//	int ret = 0;
//	for(int i = 1; i <= n; i++){
//		// 1个1， 
//		double p1 = (double)i / n;
//		double p0 = 1.0 - p1;
//		double H = -(n - i) * p0 * log2(p0) - (i) * p1 * log2(p1);
//		if (abs(H - target) < eps){
//			ret = n - i;
//			break;
//		}
//	} 
//	cout << ret << endl;
//	return 0;
//}


//// 2023
//
//5 6 8 6 9 1 6 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2
//7 0 5 8 8 5 7 0 9 9 1 9 4 4 6 8 6 3
//
//3 8 5 1 6 3 4 6 7 0 7 8 2/7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3

//int ans = 0;
//
//void dfs(int k, int sum)
//{
//  if(sum == 100 || k >= 31) //100分的时候停止答题
//    return ;
//  
//  if(sum == 70) //只要70分就记录答案，小明可能会中途放弃...可能家里有事了吧，注意中途放弃，这个很关键嗷，要不会少情况
//    ans++;
//    
//  dfs(k + 1, sum + 10);
//  dfs(k + 1, 0); //答错归0
//}
//
////总共30到题目，答对10分，打错归0分
//int main()
//{
//  // dfs(0, 0);
//
//  cout << 8335366 << endl;
//  return 0;
//}


//// 4430091
//
//bool check(int i){
//	int sum = 0;
//	int t = i;
//	while(t){
//		sum++;
//		t/=10;
//	}
//	if(sum%2 != 0) return false;
//	
//	int a = sum / 2;
//	int c1 = 0, c2 = 0;
//	
//	t = i;
//	while(a--){
//		int p = t % 10;
//		c1 += p;
//		t /= 10;
//	}
//	while(t){
//		int p = t % 10;
//		c2 += p;
//		t /= 10;
//	}
//	
//	return c1 == c2;
//}
//
//int main()
//{
//	int ret = 0;
//	for(int i = 1; i <= 100000000; i++){
//		if(check(i)) ret++;
//	}
//	cout << ret;
//	return 0;
//}
