#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//struct Process {
//    int id;
//    int burst_time;
//    int waiting_time;
//    int turn_around_time;
//};
//
//void calculateTimes(Process processes[], int n) {
//    processes[0].waiting_time = 0;
//    processes[0].turn_around_time = processes[0].burst_time;
//
//    for (int i = 1; i < n; i++) {
//        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
//        processes[i].turn_around_time = processes[i].waiting_time + processes[i].burst_time;
//    }
//}
//
//void printResults(Process processes[], int n) {
//    cout << "Processes    Burst time   Waiting time   Turn around time\n\n";
//
//    for (int i = 0; i < n; i++) {
//        cout << processes[i].id << "    " << processes[i].burst_time << "    "
//            << processes[i].waiting_time << "    " << processes[i].turn_around_time << endl;
//    }
//
//    float total_waiting = 0, total_turnaround = 0;
//    for (int i = 0; i < n; i++) {
//        total_waiting += processes[i].waiting_time;
//        total_turnaround += processes[i].turn_around_time;
//    }
//
//    cout << fixed << setprecision(2);
//    cout << "\nAverage waiting time = " << total_waiting / n << endl;
//    cout << "Average turn around time = " << total_turnaround / n << endl;
//}
//
//int main() {
//    Process processes[] = {
//        {1, 21, 0, 0},
//        {2, 3, 0, 0},
//        {3, 6, 0, 0},
//        {4, 2, 0, 0}
//    };
//    int n = sizeof(processes) / sizeof(processes[0]);
//
//    calculateTimes(processes, n);
//    printResults(processes, n);
//
//    return 0;
//}

//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//int count_2(int t)
//{
//	int ret = 0;
//	while (t)
//	{
//		if (t % 10 == 2) ret++;
//		t /= 10;
//	}
//	return ret;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 2020; i++)
//	{
//		count += count_2(i);
//	}
//	cout << count << endl;
//	return 0;
//}



//#include <cmath>
//#include <iostream>
//#include <string> 
//#include <queue> 
//#include <string>
//using namespace std;
//
//int dx[4] = { -1, 1, 0, 0 }; // ×ó ÓÒ ÉÏ ÏÂ 
//int dy[4] = { 0, 0, -1, 1 };
//char dir[4] = { 'L', 'R', 'U', 'D' };
//string maza[30];
//bool vis[30][50]; // ÓÃÓÚ±ê¼ÇÊÇ·ñ×ß¹ý 
//vector<vector<char>> pathDir(30, vector<char>(50, ' '));  // ¼ÇÂ¼ÒÆ¶¯·½Ïò 
//int main()
//{
//	memset(vis, 0, sizeof(vis));
//	// 0¿É×ß 1²»ÄÜ 
//	int rows = 30, cols = 50;
//
//	queue<pair<int, int>> q;
//	q.push({ 0, 0 });
//	vis[0][0] = true;
//
//	for (int i = 0; i < 30; i++) cin>>maza[i];
//
//	while (!q.empty()) {
//		int sz = q.size();
//		for (int i = 0; i < sz; i++) {
//			int a = q.front().first;
//			int b = q.front().second;
//			q.pop();
//			if (a == rows - 1 && b == cols - 1) {
//				// »ØËÝÂ·¾¶
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


#include <cmath>
#include <iostream>
#include <string> 
#include <queue> 
#include <cstring>
#include <algorithm>
using namespace std;

// DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRUUURRRRDDDDRDRRRRRURRRDRRDDD
// RRRRUURUUUUUUUULLLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLL
// DDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR

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
