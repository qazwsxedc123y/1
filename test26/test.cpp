#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <queue>
#include <unordered_set>
using namespace std;




//const int N = 1e5 + 10;
////vector<vector<int>> v(N, vector<int>(N, -1));
//int k, t;
//vector<vector<int>> ans(N, vector<int>(2));
//// bool dfs(int x, int y, int pos)
//// {
////     // ���λ���Ƿ�Ϸ�
////     // �ȼ����
////     // [x, y]
////     for(int i = 1; i < N; i++)
////     {
////         if(v[x][i] < pos) return false;
////     }
//
////     for(int i = 1; i < N; i++)
////     {
////         if(v[i][y] < pos) return false;
////     }
//
////     // ���45�ȣ��ȼ������
////     for(int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     for(int i = x + 1, j = y + 1; i < N && j < N; i++, j++)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     // 135��
////     for(int i = x + 1, j = y - 1; i < 1 && j >= 1; i--, j++)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     for(int i = x - 1, j = y + 1; i >= 1 && j < N; i++, j--)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     return true;
//// }
//
//// ���ýؾദ��б�ߣ�
//bool dpx[N], dpy[N], dp1[N], dp2[N];
//bool dfs(int x, int y, int pos)
//{
//    for (int i = 1; i < pos; i++)
//    {
//        int a = ans[i][0], b = ans[i][1];
//        // �鿴x,y �� a,b �Ƿ��๥��
//        if (x == a || y == b) return false;
//
//        // �Խ���
//        if (x - a == y - b) return false;
//        if (x - a == -(y - b)) return false;
//    }
//    return true;
//}
//
//int main() {
//    // �ص��Ƿ��õ�i���ʺ�󣬲�������
//    cin >> k;
//    //v.resize(N);
//
//
//    for (int i = 1; i <= k; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        //v[a][b] = i;
//        ans[i][0] = a, ans[i][1] = b;
//        //dpx[a] = true, dpy[b] = true;
//
//    }
//
//    cin >> t;
//    while (t--)
//    {
//        int a;
//        cin >> a;
//        int x = ans[a][0], y = ans[a][1];
//        if (!dfs(x, y, a)) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}
//// 64 λ������� printf("%lld")
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstring>
//using namespace std;
//const int N = 1e5 + 10;
////vector<vector<int>> v(N, vector<int>(N, -1));
//int k, t;
//vector<vector<int>> ans(N, vector<int>(2));
//// bool dfs(int x, int y, int pos)
//// {
////     // ���λ���Ƿ�Ϸ�
////     // �ȼ����
////     // [x, y]
////     for(int i = 1; i < N; i++)
////     {
////         if(v[x][i] < pos) return false;
////     }
//
////     for(int i = 1; i < N; i++)
////     {
////         if(v[i][y] < pos) return false;
////     }
//
////     // ���45�ȣ��ȼ������
////     for(int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     for(int i = x + 1, j = y + 1; i < N && j < N; i++, j++)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     // 135��
////     for(int i = x + 1, j = y - 1; i < 1 && j >= 1; i--, j++)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     for(int i = x - 1, j = y + 1; i >= 1 && j < N; i++, j--)
////     {
////         if(v[i][j] < pos) return false;
////     }
//
////     return true;
//// }
//
//vector<bool> mem(N);
//bool dfs(int x, int y, int pos)
//{
//    for (int i = 1; i < pos; i++)
//    {
//        int a = ans[i][0], b = ans[i][1];
//        // �鿴x,y �� a,b �Ƿ��๥��
//        if (x == a || y == b) return false;
//
//        // �Խ���
//        if (x - a == y - b) return false;
//        if (x - a == -(y - b)) return false;
//    }
//    return true;
//}
//
//int main() {
//    // �ص��Ƿ��õ�i���ʺ�󣬲�������
//    cin >> k;
//    //v.resize(N);
//    mem.resize(false);
//
//    for (int i = 1; i <= k; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        //v[a][b] = i;
//        ans[i][0] = a, ans[i][1] = b;
//    }
//
//    for (int i = 1; i <= k; i++)
//    {
//        int x = ans[i][0], y = ans[i][1];
//        if (!dfs(x, y, i))
//        {
//            mem[i] = true;
//            while (i <= k)
//            {
//                i++;
//                mem[i] = true;
//            }
//        }
//    }
//
//    cin >> t;
//    while (t--)
//    {
//        int a;
//        cin >> a;
//        if (mem[a]) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}
//// 64 λ������� printf("%lld")




//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param coins int����vector
//     * @return int����
//     */
//    int getCoins(vector<int>& coins) {
//        // write code here
//        // ����ȡС�ģ������ȡ�߽�
//        int n = coins.size();
//        priority_queue<int, vector<int>, greater<int>> q;
//        for (int i = 1; i < n - 1; i++) q.push(coins[i]);
//        int ret = 0;
//        while (!q.size())
//        {
//            int a = q.top();
//            q.pop();
//            int sum = 1;
//            for (int i = 0; i < n; i++)
//            {
//                if (coins[i] == a) coins[i] = -1;
//                else if (coins[i] != -1) sum *= coins[i];
//            }
//            sum *= a;
//            ret += sum;
//            cout << sum << endl;
//        }
//        // ʣ�����߽�
//        int t = coins[0] * coins[n - 1];
//        ret += t;
//        if (coins[0] < coins[n - 1]) coins[0] = coins[n - 1];
//        ret += coins[0];
//
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> v = { 5,6,4,8 };
//    Solution s;
//    s.getCoins(v);
//    return 0;
//}


//
//
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param coins int����vector
//     * @return int����
//     */
//    int getCoins(vector<int>& coins) {
//        // write code here
//        // ����ȡС�ģ������ȡ�߽�
//        int n = coins.size();
//        priority_queue<int, vector<int>, greater<int>> q;
//        for (int i = 1; i < n - 1; i++) q.push(coins[i]);
//        int ret = 0;
//        while (!q.empty())
//        {
//            int a = q.top();
//            q.pop();
//            int sum = 1;
//            for (int i = 0; i < n; i++)
//            {
//                if (coins[i] == a)
//                {
//                    sum = a;
//                    coins[i] = -1;
//                    int t = i - 1;
//                    while (t >= 0)
//                    {
//                        if (coins[t] != -1)
//                        {
//                            sum *= coins[t];
//                            //cout << coins[t] << " ";
//                            break;
//                        }
//                        t--;
//                    }
//                    t = i + 1;
//                    while (t < n)
//                    {
//                        if (coins[t] != -1)
//                        {
//                            sum *= coins[t];
//                            //cout << coins[t] << " ";
//                            break;
//                        }
//                        t++;
//                    }
//                }
//            }
//            ret += sum;
//            cout << sum << endl;
//        }
//        // ʣ�����߽�
//        int t = coins[0] * coins[n - 1];
//        ret += t;
//        if (coins[0] < coins[n - 1]) coins[0] = coins[n - 1];
//        ret += coins[0];
//
//        return ret;
//    }
//};



//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param coins int����vector
//     * @return int����
//     */
//    int getCoins(vector<int>& coins) {
//        // write code here
//        int n = coins.size();
//        int dp[n + 2][n + 2]; // dp[i][j] ��ʾѡȡ����[i,j]�õ���������
//        for (int i = 0; i < n + 2; i++)
//            for (int j = 0; j < n + 2; j++)
//                dp[i][j] = 0;
//
//        coins.insert(coins.begin(), 1);
//        coins.push_back(1);
//        // ���������ϣ���������
//        for (int i = n; i >= 1; i--)
//        {
//            for (int j = i; j <= n; j++)
//            {
//                for (int k = i; k <= j; k++)
//                {
//                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + coins[k] * coins[i - 1] * coins[j + 1]);
//                }
//            }
//        }
//        return dp[1][n];
//    }
//};




//using namespace std;
//
//
//int main() {
//    int k, t;
//    cin >> k;
//    int ret = 1e5 + 10;
//
//    // ���ڸ����ѷ��ûʺ����Ϣ
//    unordered_set<int> usedRows, usedCols, usedDiag1, usedDiag2;
//
//    for (int i = 1; i <= k; i++) {
//        int x, y;
//        cin >> x >> y;
//        if (ret != 1e5 + 10) continue;
//        // ��鵱ǰ�ʺ��Ƿ���֮ǰ�ʺ��ͻ
//        if (usedRows.count(x) || usedCols.count(y) ||
//            usedDiag1.count(x - y) || usedDiag2.count(x + y)) {
//            ret = i;
//        }
//
//        // ����ǰ�ʺ����Ϣ���뼯�ϣ������Ƿ��г�ͻ��Ҫ���룩
//        usedRows.insert(x);
//        usedCols.insert(y);
//        usedDiag1.insert(x - y);
//        usedDiag2.insert(x + y);
//    }
//
//    cin >> t;
//    while (t--)
//    {
//        int a;
//        cin >> a;
//        if (a < ret) cout << "No" << endl;
//        else cout << "Yes" << endl;
//    }
//
//    return 0;
//}