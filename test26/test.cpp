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


//
//int na, nb, nc, nd, m;
//int func(int n, int k) // ����Cnk
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
//    // ���mΪ0����ô�����������
//
//    int ret = func(3, 1);
//    cout << ret << endl;
//
//}
//// 64 λ������� printf("%lld")



//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * max water
//     * @param arr int����vector the array
//     * @return long������
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
//        // ��Ϊn  ����Ϊk
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
//        // ��ϸ���Ϊk
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


//class Solution {
//public:
//    int canBeTypedWords(string text, string brokenLetters) {
//        unordered_set<char> hash;
//        for (auto e : brokenLetters)
//            hash.insert(e);
//
//        int ret = 0;
//        bool flag = true;
//        for (auto ch : text)
//        {
//            if (ch == ' ')
//            {
//                if (flag) ret++;
//                flag = true;
//            }
//
//            else if (hash.find(ch) != hash.end())
//            {
//                flag = false;
//            }
//        }
//
//        // ����ĩβ����
//        if (flag) ret++;
//
//        return ret;
//    }
//};


//class Solution {
//public:
//    int binary_l(vector<int>& nums, int target) // ��һ�����ڵ��� target ��λ��
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//        return left;
//    }
//
//    int binary_r(vector<int>& nums, int target) // ��һ������ target ��λ��
//    {
//        int left = 0, right = nums.size();
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] <= target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//        return left;
//    }
//
//    vector<int> searchRange(vector<int>& nums, int target) {
//        if (nums.empty()) return { -1, -1 };
//
//        int left_idx = binary_l(nums, target);
//        // ����Ƿ��ҵ�target
//        if (nums[left_idx] != target) {
//            return { -1, -1 };
//        }
//
//        int right_idx = binary_r(nums, target) - 1;
//        return { left_idx, right_idx };
//    }
//};



//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        // ����ģ��
//        vector<vector<int>> v(n, vector<int>(n));
//        // �ȳ�ʼ��Ϊ0��Ȼ��߽��ж�������Ϊ0����ֵ�߽�
//        int maxNum = n * n;
//        int curNum = 1;
//        int dx[4] = { 0, 1, 0, -1 }; int dy[4] = { 1, 0, -1, 0 }; // ��������
//        int x = 0, y = 0;
//        int dir = 0;
//        while (curNum <= maxNum)
//        {
//            v[x][y] = curNum++;
//            int next_x = dx[dir] + x, next_y = dy[dir] + y;
//            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || v[next_x][next_y] != 0)
//            {
//                dir = (dir + 1) % 4;
//            }
//            x += dx[dir], y += dy[dir];
//        }
//        return v;
//    }
//};



//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int maxstep = 0;
//        // ����һ��һ���ߣ�Ȼ��ʵ��������Ƿ���Ը���nums�ߵ�����߲�����false
//        // ����һ��һ�����꣬��ô��true
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i > maxstep) return false;
//            maxstep = max(maxstep, i + nums[i]);
//        }
//        return true;
//    }
//};



//class NumberContainers {
//public:
//    // �����д洢������ȫΪ������
//
//    // ����Ҳ��������Ϊһ����ϣ
//    // find�������һ����ϣ
//    unordered_map<int, int> hash1; // �±� - ��ֵ
//    unordered_map<int, set<int>> hash2; // ��ֵ - �±�
//    NumberContainers() {
//    }
//
//    void change(int index, int number) {
//        auto it = hash1.find(index);
//
//        // �滻
//        if (it != hash1.end())
//        {
//            hash2[it->second].erase(index);
//        }
//
//        // ����
//        hash1[index] = number;
//        hash2[number].insert(index);
//    }
//
//    int find(int number) {
//        auto it = hash2.find(number);
//
//        if (it == hash2.end() || it->second.empty()) return -1;
//
//        else
//        {
//            return *it->second.begin();
//        }
//    }
//};
//
///**
// * Your NumberContainers object will be instantiated and called as such:
// * NumberContainers* obj = new NumberContainers();
// * obj->change(index,number);
// * int param_2 = obj->find(number);
// */


//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        vector<int> left(n);
//        vector<int> right(n);
//
//        left[0] = height[0];
//        right[n - 1] = height[n - 1];
//
//        for (int i = 1; i < n; i++) left[i] = max(left[i - 1], height[i]);
//
//        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i + 1], height[i]);
//
//        int ret = 0;
//
//        for (int i = 0; i < n; i++)
//        {
//            ret += min(left[i], right[i]) - height[i];
//        }
//
//        return ret;
//    }
//};


//class TaskManager
//{
//    unordered_map<int, pair<int, int>> taskInfo;
//    priority_queue<pair<int, int>> heap;
//public:
//    // ��ϣ + ��
//    TaskManager(vector<vector<int>>& tasks) {
//        for (auto& task : tasks)
//        {
//            int userId = task[0], taskId = task[1], priority = task[2];
//            // �� userId ���һ�����ȼ�Ϊ priority ������ taskId
//            taskInfo[taskId] = { priority, userId };
//            heap.push({ priority, taskId });
//        }
//    }
//
//    void add(int userId, int taskId, int priority) {
//        taskInfo[taskId] = { priority, userId };
//        heap.push({ priority, taskId });
//    }
//
//    void edit(int taskId, int newPriority) {
//        taskInfo[taskId].first = newPriority;
//        heap.push({ newPriority, taskId });
//    }
//
//    void rmv(int taskId) {
//        taskInfo.erase(taskId);
//    }
//
//    int execTop()
//    {
//        // ֻɾ��һ��
//        while (!heap.empty())
//        {
//            auto [priority, taskId] = heap.top();
//            heap.pop();
//
//            if (taskInfo.find(taskId) != taskInfo.end() &&
//                taskInfo[taskId].first == priority)
//            {
//                int userId = taskInfo[taskId].second;
//                taskInfo.erase(taskId);
//                return userId;
//            }
//        }
//        return -1;
//    }
//};
//
///**
// * Your TaskManager object will be instantiated and called as such:
// * TaskManager* obj = new TaskManager(tasks);
// * obj->add(userId,taskId,priority);
// * obj->edit(taskId,newPriority);
// * obj->rmv(taskId);
// * int param_4 = obj->execTop();
// */



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp
        // i-1 i
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        // ���ϵ��� ���ҵ���
        for (int i = 1; i < n; i++)
        {
            // �������һλ
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--)
            {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            // �����һλ
            dp[0] += triangle[i][0];
        }


        int ret = INT_MAX;
        for (int i = 0; i < n; i++) ret = min(ret, dp[i]);

        return ret;
    }
};