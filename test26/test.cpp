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
////     // 检查位置是否合法
////     // 先检查行
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
////     // 检查45度，先检查上面
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
////     // 135度
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
//// 利用截距处理斜线？
//bool dpx[N], dpy[N], dp1[N], dp2[N];
//bool dfs(int x, int y, int pos)
//{
//    for (int i = 1; i < pos; i++)
//    {
//        int a = ans[i][0], b = ans[i][1];
//        // 查看x,y 与 a,b 是否互相攻击
//        if (x == a || y == b) return false;
//
//        // 对角线
//        if (x - a == y - b) return false;
//        if (x - a == -(y - b)) return false;
//    }
//    return true;
//}
//
//int main() {
//    // 重点是放置第i个皇后后，不是整体
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
//// 64 位输出请用 printf("%lld")
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
////     // 检查位置是否合法
////     // 先检查行
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
////     // 检查45度，先检查上面
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
////     // 135度
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
//        // 查看x,y 与 a,b 是否互相攻击
//        if (x == a || y == b) return false;
//
//        // 对角线
//        if (x - a == y - b) return false;
//        if (x - a == -(y - b)) return false;
//    }
//    return true;
//}
//
//int main() {
//    // 重点是放置第i个皇后后，不是整体
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
//// 64 位输出请用 printf("%lld")




//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param coins int整型vector
//     * @return int整型
//     */
//    int getCoins(vector<int>& coins) {
//        // write code here
//        // 优先取小的，最后再取边界
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
//        // 剩余俩边界
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
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param coins int整型vector
//     * @return int整型
//     */
//    int getCoins(vector<int>& coins) {
//        // write code here
//        // 优先取小的，最后再取边界
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
//        // 剩余俩边界
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
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param coins int整型vector
//     * @return int整型
//     */
//    int getCoins(vector<int>& coins) {
//        // write code here
//        int n = coins.size();
//        int dp[n + 2][n + 2]; // dp[i][j] 表示选取区间[i,j]得到的最大积分
//        for (int i = 0; i < n + 2; i++)
//            for (int j = 0; j < n + 2; j++)
//                dp[i][j] = 0;
//
//        coins.insert(coins.begin(), 1);
//        coins.push_back(1);
//        // 填表从下往上，从左往右
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
//    // 用于跟踪已放置皇后的信息
//    unordered_set<int> usedRows, usedCols, usedDiag1, usedDiag2;
//
//    for (int i = 1; i <= k; i++) {
//        int x, y;
//        cin >> x >> y;
//        if (ret != 1e5 + 10) continue;
//        // 检查当前皇后是否与之前皇后冲突
//        if (usedRows.count(x) || usedCols.count(y) ||
//            usedDiag1.count(x - y) || usedDiag2.count(x + y)) {
//            ret = i;
//        }
//
//        // 将当前皇后的信息加入集合（无论是否有冲突都要加入）
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


//
//int na, nb, nc, nd, m;
//int func(int n, int k) // 计算Cnk
//{
//    int t = k;
//    int sum = 1;
//    while (t--)
//    {
//        sum *= n;
//        n--;
//    }
//
//    while (k--)
//    {
//        cout << k << endl;
//        sum /= k;
//    }
//    cout << sum << endl;
//    return sum;
//}
//int main() {
//    //cin >> na >> nb >> nc >> nd >> m;
//
//    // 如果m为0，那么就是排列组合
//
//    int ret = func(3, 1);
//    cout << ret << endl;
//
//}
//// 64 位输出请用 printf("%lld")



//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * max water
//     * @param arr int整型vector the array
//     * @return long长整型
//     */
//    long long maxWater(vector<int>& arr) {
//        // write code here
//        int n = arr.size();
//        arr.push_back(0);
//        long long ret = 0;
//
//        int l = 1, r = 1;
//        for (; r < n;)
//        {
//            if (arr[r] <= arr[l - 1] && arr[r] <= arr[r + 1])
//            {
//                r++;
//            }
//            else
//            {
//                int ans = min(arr[l - 1], arr[r]);
//                for (int j = l; j < r; j++)
//                {
//                    ret += ans - arr[j];
//                }
//                l = r + 1;
//                r = l;
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<vector<int>> result;
//        vector<int> current;
//        sort(candidates.begin(), candidates.end());
//        backtrack(candidates, target, 0, current, result);
//        return result;
//    }
//    void backtrack(vector<int>& candidates, int target, int start,
//        vector<int>& current, vector<vector<int>>& result)
//    {
//        if (target == 0)
//        {
//            result.push_back(current);
//            return;
//        }
//
//        for (int i = start; i < candidates.size(); i++)
//        {
//            if (i > start && candidates[i - 1] == candidates[i])
//            {
//                continue;
//            }
//            if (candidates[i] > target)
//            {
//                break;
//            }
//            current.push_back(candidates[i]);
//            backtrack(candidates, target - candidates[i], i + 1, current, result);
//            current.pop_back();
//        }
//    }
//};



//class Solution {
//public:
//    vector<vector<int>> combinationSum3(int k, int n) {
//        // 和为n  个数为k
//        vector<vector<int>> result;
//        vector<int> current;
//        backtrack(0, n, 1, current, result, k);
//        return result;
//    }
//    void backtrack(int sz, int target, int start,
//        vector<int>& current, vector<vector<int>>& result, int k)
//    {
//        if (sz == k)
//        {
//            if (target == 0) result.push_back(current);
//            return;
//        }
//
//        for (int i = start; i <= 9; i++)
//        {
//            if (i > target)
//            {
//                break;
//            }
//            current.push_back(i);
//            backtrack(sz + 1, target - i, i + 1, current, result, k);
//            current.pop_back();
//        }
//    }
//}; 



//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        // 组合个数为k
//        vector<vector<int>> result;
//        vector<int> current;
//        backtrack(n, 1, k, 0, current, result);
//        return result;
//    }
//    void backtrack(int n, int start, int k, int sz,
//        vector<int>& current, vector<vector<int>>& result)
//    {
//        if (sz == k)
//        {
//            result.push_back(current);
//            return;
//        }
//
//        for (int i = start; i <= n; i++)
//        {
//            current.push_back(i);
//            backtrack(n, i + 1, k, sz + 1, current, result);
//            current.pop_back();
//        }
//    }
//};



//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> result;
//        vector<int> current;
//        sort(candidates.begin(), candidates.end());
//        backtrack(candidates, target, 0, current, result);
//        return result;
//    }
//    void backtrack(vector<int>& candidates, int target, int start,
//        vector<int>& current, vector<vector<int>>& result)
//    {
//        if (target == 0)
//        {
//            result.push_back(current);
//            return;
//        }
//        for (int i = start; i < candidates.size(); i++)
//        {
//            if (candidates[i] > target)
//            {
//                break;
//            }
//            current.push_back(candidates[i]);
//            backtrack(candidates, target - candidates[i], i, current, result);
//            current.pop_back();
//        }
//    }
//};


//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        vector<unsigned> f(target + 1);
//        f[0] = 1;
//        for (int i = 1; i <= target; i++) {
//            for (int x : nums) {
//                if (x <= i) {
//                    f[i] += f[i - x];
//                }
//            }
//        }
//        return f[target];
//    }
//};