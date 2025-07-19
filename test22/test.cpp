#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//#include <iostream>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    int n = s.size();
//    int pre = -1, now = 0, next = 1;
//    int t = 0;
//    string ret;
//    for (; now < n;)
//    {
//        if (pre != -1 && s[now] == s[pre]) // 与前消
//        {
//            pre--;
//            now = next;
//            next++;
//        }
//        else if (next != n && s[now] == s[next]) // 与后消
//        {
//            now = next + 1;
//            next = now + 1;
//        }
//        else // 什么也不消，拷贝已经完成的部分
//        {
//            ret += s.substr(t, pre + 1 - t); // 拷贝 [t,pre +1)  3，4  
//            // 
//            t = now;
//            pre = now;
//            now = next;
//            next = now + 1;
//        }
//    }
//    if (pre == -1 && now == n) {
//        cout << 0 << endl;
//        return 0;
//    }
//    else if (pre + 1 == now && pre < n) ret += s.substr(pre);
//    cout << ret;
//}
//// 64 位输出请用 printf("%lld")



//#include <string>
//#include <stack>
//using namespace std;
//
//string removeDuplicates(string s) {
//    stack<char> st;
//    for (char c : s) {
//        if (!st.empty() && st.top() == c) {
//            st.pop();
//        }
//        else {
//            st.push(c);
//        }
//    }
//    string result;
//    while (!st.empty()) {
//        result = st.top() + result;
//        st.pop();
//    }
//    return result.empty() ? "0" : result;
//}
//
//int main() {
//    string s;
//    cin >> s;
//    cout << removeDuplicates(s) << endl;
//    return 0;
//}


//int main()
//{
//	double n = 3.74;
//	int a = n;
//	if (n > a) cout << "1";
//	return 0;
//}
//
//int n;
//int cost[100001];
//int ret[1000002];
//int main() {
//    // 楼顶为n
//    // 数组的每个值为当前台阶费用
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        // 刚才手机断网了
//        cin >> cost[i];
//    }
//    ret[0] = ret[1] = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        ret[i] = min(ret[i - 1] + cost[i - 1], ret[i - 2] + cost[i - 2]);
//    }
//    cout << ret[n] << endl;
//}
// 64 位输出请用 printf("%lld")


//int n;
//string s1, s2;
//int a = -1, b = -1;
//int ret = -1;
//int main() {
//    cin >> n;
//    cin >> s1 >> s2;
//    for (int i = 0; i < n; i++)
//    {
//        string t;
//        cin >> t;
//        if (t == s1 || t == s2)
//        {
//            if (t == s1)
//            {
//                // 更新最短距离
//                a = i;
//                if (b != -1)
//                {
//                    int tmp = a - b;
//                    if (tmp < 0) tmp = -tmp;
//                    ret = min(ret, tmp);
//                }
//            }
//            else
//            {
//                b = i;
//                if (a != -1)
//                {
//                    int tmp = a - b;
//                    if (tmp < 0) tmp = -tmp;
//                    ret = min(ret, tmp);
//                }
//            }
//        }
//    }
//    cout << ret;
//}
//// 64 位输出请用 printf("%lld")


//class A
//{
//public:
//	A(int _a) {
//		a = _a;
//	}
//private:
//	int a;
//};
//
//int main()
//{
//	A a1(1);
//	A a2(2);
//	a2 = a1;
//	return 0;
//}

//string s, ret;
//int main() {
//    std::getline(std::cin, s);
//    int pos = -1;
//    int end = s.find(' ');
//    while (end != std::string::npos)
//    {
//        char c = s[pos + 1];
//        if (c >= 'a' && c <= 'z') c -= 32;
//        ret += c;
//        pos = s.find(' ', pos + 1);
//        if (pos == std::string::npos) break;
//    }
//
//    cout << ret;
//}
//// 64 位输出请用 printf("%lld")


//int n, x;
//int arr[10000001];
//int main() {
//    cin >> n >> x;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//    int sum = 0, l = 0, r = 0, start = 0, len = n;
//    for (; r < n; r++)
//    {
//        sum += arr[r];
//            while (sum >= x)
//        {
//            sum -= arr[l++];
//            if (len > r - l + 1)
//            {
//                start = l;
//                len = r - l + 1;
//            }
//        }
//    }
//    cout << l << " " << l + len << endl;
//}
// 64 位输出请用 printf("%lld")



//
//#include <algorithm>
//int n, k;
//int main()
//{
//    int sum = 0;
//    cin >> n >> k;
//    vector<int> v;
//    for (int i = 0; i < n; i++)
//    {
//        int t;
//        cin >> t;
//        if (t % 2 != 0) sum += t;
//        else v.push_back(t);
//    }
//    while (k--)
//    {
//        sort(v.begin(), v.end());
//        int t = v[v.size() - 1];
//        v.pop_back();
//        t /= 2;
//        if (t % 2 != 0) sum += t;
//        else v.push_back(t);
//    }
//    for (int i = 0; i < v.size(); i++)
//    {
//        sum += v[i];
//    }
//    cout << sum << endl;
//    return 0;
//}

// int main() {
//     // 大根堆
//     int n, k;
//     priority_queue<int> q;
//     int sum = 0;
//     cin >> n >> k;
//     for(int i = 0; i < n; i++)
//     {
//         int t;
//         cin >> t;
//         if(t % 2 != 0) sum += t;
//         else q.push(t);
//     }
//     while(!q.empty() && k)
//     {
//         int t = q.top();
//         q.pop();
//         t /= 2;
//         if(t % 2 != 0) sum += t;
//         else q.push(t);
//         k--;
//     }
//     while(!q.empty())
//     {
//         int t = q.top();
//         sum += t;
//         q.pop();
//     }
//     cout << sum << endl;
// }
// 64 位输出请用 printf("%lld")



//const int N = 1000000;
//int n, ret = 0;
//int main() {
//    n = 15;
//    int a = 0, b = 1, c = 1;
//    int a1, a2;
//    while (c >= n)
//    {
//        a = b;
//        b = c;
//        c = a + b;
//    }
//    a2 = c, a1 = b;
//    while (true)
//    {
//        if (a1 == n || a2 == n)
//        {
//            break;
//        }
//        a1++, a2--;
//        ret++;
//    }
//    cout << ret << endl;
//}
// 
// 
// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    int n, m;
//    int ret = 0;
//    queue<pair<int, int>> q;
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//    bool vis[1001][1001];
//    void bfs(vector<vector<int> >& grid)
//    {
//        while (!q.empty())
//        {
//            int sz = q.size();
//            for (int i = 0; i < sz; i++)
//            {
//                auto [a, b] = q.front();
//                q.pop();
//                for (int k = 0; k < 4; k++)
//                {
//                    int x = a + dx[k], y = b + dy[k];
//                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && vis[x][y] == false)
//                    {
//                        vis[x][y] = true;
//                        q.push({ x, y });
//                    }
//                }
//            }
//            ret++;
//        }
//    }
//    int rotApple(vector<vector<int> >& grid) {
//        // write code here
//        n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 2)// 蔓延
//                {
//                    q.push({ i, j });
//                    vis[i][j] = true;
//                }
//            }
//        }
//        if (q.size() == n * m) return 0;
//        bfs(grid);
//        cout << ret << endl;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 1 && vis[i][j] == false)// 蔓延
//                {
//                    return -1;
//                }
//            }
//        }
//        return ret - 1;
//    }
//}; class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    int n, m;
//    int ret = 0;
//    queue<pair<int, int>> q;
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//    bool vis[1001][1001];
//    void bfs(vector<vector<int> >& grid)
//    {
//        while (!q.empty())
//        {
//            int sz = q.size();
//            for (int i = 0; i < sz; i++)
//            {
//                auto [a, b] = q.front();
//                q.pop();
//                for (int k = 0; k < 4; k++)
//                {
//                    int x = a + dx[k], y = b + dy[k];
//                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && vis[x][y] == false)
//                    {
//                        vis[x][y] = true;
//                        q.push({ x, y });
//                    }
//                }
//            }
//            ret++;
//        }
//    }
//    int rotApple(vector<vector<int> >& grid) {
//        // write code here
//        n = grid.size(), m = grid[0].size();
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 2)// 蔓延
//                {
//                    q.push({ i, j });
//                    vis[i][j] = true;
//                }
//            }
//        }
//        if (q.size() == n * m) return 0;
//        bfs(grid);
//        cout << ret << endl;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == 1 && vis[i][j] == false)// 蔓延
//                {
//                    return -1;
//                }
//            }
//        }
//        return ret - 1;
//    }
//};


//class Solution {
//public:
//    int iceBreakingGame(int n, int m) {
//        int ans = 0;
//        for (int i = 2; i <= n; i++)
//        {
//            ans = (ans + m) % i;
//        }
//        return ans;
//    }
//};

//class Solution {
//    struct Node
//    {
//        Node* next;
//        int val;
//        Node(int v) : val(v), next(nullptr) {}
//    };
//public:
//    int iceBreakingGame(int n, int m) {
//        // 环形链表
//        if (n == 1) return 0;
//        Node* head = new Node(0);
//        Node* cur = head;
//        for (int i = 1; i < n; i++)
//        {
//            cur->next = new Node(i);
//            cur = cur->next;
//        }
//        cur->next = head;
//        // 模拟
//        Node* prev = cur;  // 前驱节点
//        cur = head;        // 当前节点
//        while (cur->next != cur) {
//            // 找到第m个节点
//            for (int i = 1; i < m; i++) {
//                prev = cur;
//                cur = cur->next;
//            }
//            // 删除当前节点
//            prev->next = cur->next;
//            cur = prev->next; // 从下一个继续
//        }
//        return cur->val;
//    }
//};



//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 计算两个数之和
//     * @param s string字符串 表示第一个整数
//     * @param t string字符串 表示第二个整数
//     * @return string字符串
//     */
//    string solve(string s, string t) {
//        // write code here
//        // 不转为数字，直接用字符串计算，添加一个进位
//        int array = 0;
//        int n = s.size() - 1, m = t.size() - 1;
//        string ret;
//        int a, b;
//        while (n >= 0 || m >= 0)
//        {
//            a = b = 0;
//            if (n >= 0) a = s[n] - '0';
//            if (m >= 0) b = t[m] - '0';
//            int sum = a + b + array;
//            array = sum / 10;
//            sum %= 10;
//            ret.push_back(sum + '0');
//            n--, m--;
//        }
//        if (array != 0) ret.push_back(array + '0');
//        ret.reserve();
//        int sz = ret.size();
//        for (int i = 0; i < sz / 2; i++)
//        {
//            char tmp = ret[i];
//            ret[i] = ret[sz - i - 1];
//            ret[sz - i - 1] = tmp;
//        }
//        return ret;
//    }
//};
//

//
//struct ListNode {
// 	int val;
// 	struct ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
// 
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param head1 ListNode类
//     * @param head2 ListNode类
//     * @return ListNode类
//     */    ListNode* addInList(int a, int b) {
//        // write code here
//
//        int sum = a + b;
//        ListNode* head = nullptr;
//        while (sum)
//        {
//            int t = sum % 10;
//            sum /= 10;
//            ListNode* cur = new ListNode(t);
//            if (head == nullptr) head = cur;
//            else
//            {
//                cur->next = head->next;
//                head->next = cur;
//                head = cur;
//            }
//        }
//        return head;
//};
//int main()
//{
//    Solution s;
//    s.addInList(937, 63);
//    return 0;
//}


//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        int m = num1.size(), n = num2.size();
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//
//        // 先计算无进位相乘
//        vector<int> tmp(n + m - 1);
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                tmp[i + j] += ((num1[i] - '0') * (num2[j] - '0'));
//            }
//        }
//
//        // 处理进位
//        int cur = 0, array = 0;
//        string ret;
//        while (cur < n + m - 1 || array)
//        {
//            if (cur < n + m - 1) array += tmp[cur++];
//            ret.push_back(array % 10 + '0');
//            array /= 10;
//        }
//
//        // 处理前导0
//        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
//        // 逆置
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};


//#include <iostream>
//using namespace std;
//
//int main() {
//    string s, ret;
//    s = "abcd1230587890ed125ss123058789";
//    int sz = s.size();
//    int begin, len = 0, ans = 0;
//    for (int i = 0; i < sz;)
//    {
//        if (s[i] >= '0' && s[i] <= '9')
//        {
//            int t = i;
//            len = 0;
//            while (i < sz && s[i] >= '0' && s[i] <= '9')
//            {
//                len++;
//                i++;
//            }
//            if (ans < len)
//            {
//                ans = len;
//                begin = t;
//            }
//        }
//        else i++;
//    }
//    cout << s.substr(begin, ans) << endl;
//
//}
//// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 判断岛屿数量
//     * @param grid char字符型vector<vector<>>
//     * @return int整型
//     */
//     // 1 -> 陆地
//    vector<vector<bool>> vis;
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//    int n, m;
//    void dfs(vector<vector<char> >& grid, int i, int j)
//    {
//        vis[i][j] = true;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = dx[k] + i, y = dy[k] + j;
//            if (x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == false && grid[x][y] == '1')
//            {
//                dfs(grid, x, y);
//            }
//        }
//    }
//    int solve(vector<vector<char> >& grid) {
//        // write code here
//        n = grid.size(), m = grid[0].size();
//        vis = vector<vector<bool>>(n, vector<bool>(m));
//        int ret = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (grid[i][j] == '1' && vis[i][j] == false)
//                {
//                    dfs(grid, i, j);
//                    ret++;
//                }
//            }
//        }
//        return ret;
//    }
//};


//int main()
//{
//	int arr[3] = { 1,2,3 };
//	arr.fin
//	return 0;
//}




//#include <iostream>
//#include <vector>
//#include <cstdlib>  // 添加abs函数需要的头文件
//using namespace std;
//
//int arr[6];
//bool flag = false;  // 修正拼写错误：falg -> flag
//
//bool isTriangle(int a, int b, int c) {
//    return (a + b > c) && (a + c > b) && (b + c > a);
//}
//
//void is_true(vector<int>& arr1) {
//    int a = arr[arr1[0]], b = arr[arr1[1]], c = arr[arr1[2]];
//
//    if (isTriangle(a, b, c)) {
//        vector<int> other;
//        for (int k = 0; k < 6; k++) {
//            if (k != arr1[0] && k != arr1[1] && k != arr1[2]) {
//                other.push_back(arr[k]);
//            }
//        }
//
//        int x = other[0], y = other[1], z = other[2];
//        if (isTriangle(x, y, z)) {
//            flag = true;
//        }
//    }
//}
//
//void dfs(vector<int>& arr1, vector<bool>& visited) {
//    if (flag) return;
//    if (arr1.size() == 3) {
//        is_true(arr1);
//        return;  // 添加return，避免不必要的递归
//    }
//    for (int j = 0; j < 6; j++) {
//        if (!visited[j]) {
//            visited[j] = true;
//            arr1.push_back(j);
//            dfs(arr1, visited);
//            arr1.pop_back();
//            visited[j] = false;
//        }
//    }
//}
//
//int main() {
//    int t;
//    cin >> t;
//    for (int i = 0; i < t; i++) {
//        flag = false;  // 每次测试用例前重置flag
//        vector<bool> visited(6, false);
//        for (int j = 0; j < 6; j++) {
//            cin >> arr[j];
//        }
//        vector<int> arr1;
//        dfs(arr1, visited);
//        cout << (flag ? "Yes" : "No") << endl;
//    }
//    return 0;
//}





//using namespace std;
//int arr[6];
//bool flag = false;
//vector<bool> visited(6, false);
//bool isTriangle(int a, int b, int c) {
//    return (a + b > c) && (a + c > b) && (b + c > a);
//}
//void is_true(vector<int>& arr1)
//{
//    // 如何获取另外的三个数字组合？
//
//    int a = arr[arr1[0]], b = arr[arr1[1]], c = arr[arr1[2]];
//    int _a = arr1[0], _b = arr1[1], _c = arr1[2];
//
//    if (isTriangle(a, b, c))
//    {
//        // 获取另外的三个的组合
//        // 全为 1 怎么处理？
//        // 全排列为下标
//        int tmp[3];
//        int i = 0;
//        for (int k = 0; k < 6; k++)
//        {
//            if (k != _a && k != _b && k != _c)
//            {
//                tmp[i++] = k;
//            }
//        }
//        a = arr[tmp[0]], b = arr[tmp[1]], c = arr[tmp[2]];
//        if (isTriangle(a, b, c))
//        {
//            flag = true;
//        }
//    }
//}
//void dfs(vector<int>& arr1, vector<bool>& visited)
//{
//    if (arr1.size() > 3) return;
//    if (arr1.size() == 3)
//    {
//        // 判断是否为三角形
//        if (flag == true) return;
//        is_true(arr1);
//        if (flag == true) return;
//    }
//    for (int j = 0; j < 6; j++)
//    {
//        if (!visited[j])
//        { // 避免重复选择同一个元素
//            visited[j] = true;
//            arr1.push_back(j);
//            dfs(arr1, visited);
//            arr1.pop_back();
//            visited[j] = false;
//        }
//    }
//}
//
//int main() {
//    // 全排列
//    // 后判断是否为三角形
//    int t;
//
//    cin >> t;
//    for (int i = 0; i < t; i++)
//    {
//        flag = false;
//        for (int j = 0; j < 6; j++)
//        {
//            cin >> arr[j];
//        }
//        // 进行全排列
//        vector<int> arr1;
//        dfs(arr1, visited);
//        if (flag == true) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")修改正确


//#include <queue>
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * max increasing subsequence
//     * @param arr int整型vector the array
//     * @return int整型
//     */
//    int MLS(vector<int>& arr) {
//        // write code here
//        priority_queue<int> q;
//        int ret = 0, len = 1;
//        for (int i = 0; i < arr.size(); i++)
//        {
//            q.push(arr[i]);
//        }
//        int a = q.top();
//        q.pop();
//        while (!q.empty())
//        {
//            // 手机掉网了wifi不好
//            int t = q.top();
//            q.pop();
//            if (a == t + 1)
//            {
//                len++;
//            }
//            else if (a == t)
//            {
//
//            }
//            else
//            {
//                ret = max(ret, len);
//                len = 1;
//            }
//            a = t;
//        }
//        ret = max(ret, len);
//        return ret;
//    }
//};
//
//int n, m;
//int dp[502][502];
//char ch[502][502];
//int is_love(char c)
//{
//    if (c == 'l') return 4;
//    else if (c == 'o') return 3;
//    else if (c == 'v') return 2;
//    else if (c == 'e') return 1;
//    else return 0;
//}
//int main() {
//    // 不使用dfs，使用dp
//    // 其只可以向右或向下走
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> ch[i][j];
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            dp[i][j] = max(dp[i][j - 1] + is_love(ch[i - 1][j - 1]), dp[i - 1][j] + is_love(ch[i - 1][j - 1]));
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}
//// 64 位输出请用 printf("%lld")
//
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N;
//string ret;
//int i = 0;
//int main() {
//    cin >> N;
//    while (N)
//    {
//        i++;
//        int t = N % 10;
//        ret.push_back(t + '0');
//        if (i % 3 == 0) ret.push_back(',');
//        N /= 10;
//    }
//    if (ret[ret.size() - 1] == ',') ret.pop_back();
//    reverse(ret.begin(), ret.end());
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")


//#include <iostream>
//using namespace std;
//int n;
//int dp[41];
//int main() {
//    // 使用dp
//    // 从0台阶开始跳
//    cin >> n;
//    // dp[i] 表示到达第 i 台阶的方式有多少种
//    // dp[i] = dp[i-1] + dp[i-2]
//    dp[0] = 0, dp[1] = 1, dp[2] = 2;
//    for (int i = 3; i <= n; i++)
//    {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    cout << dp[n] << endl;
//}
//// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param A string字符串
//     * @return int整型
//     */
//    int is_Palindromic(string s)
//    {
//        int sz = s.size();
//        int l = 0, r = sz - 1;
//        while (l < r)
//        {
//            if (s[l] != s[r]) return 0;
//            l++, r--;
//        }
//        return sz;
//    }
//    int getLongestPalindrome(string A) {
//        // write code here
//        int n = A.size();
//        int ret = 1;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                // 计算当前字串是否为回文子串
//                ret = max(ret, is_Palindromic(A.substr(i, j - i + 1)));
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    s.getLongestPalindrome("ababc");
//    return 0;
//}


#include <iostream>
#include <unordered_map>
using namespace std;
int n, m, x, y;
int dp[21][21];
unordered_map<int, int> myhash;
void func(int x, int y)
{
    int x1 = x + 2, y1 = y + 1;
    if (x1 <= n && y1 <= m)
    {
        myhash.insert({ x1,y1 });
    }
}
//int main() {
//    cin >> n >> m >> x >> y;
//    func(x, y);
//}
// 64 位输出请用 printf("%lld")


//#include <iostream>
//#include <unordered_map>
//using namespace std;
//int n, m, x, y;
//bool vis[21][21] = { false };  // 记录是否可达
//int dp[22][22]; // 到达 i j下标的总路径数 dp[i-1][j] + dp[i][j]
//void func(int x, int y) {
//    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//
//    for (int i = 0; i < 8; i++) {
//        int x1 = x + dx[i];
//        int y1 = y + dy[i];
//        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m) {
//            vis[x1][y1] = true;  // 标记为可达
//        }
//    }
//}
//int main() {
//    cin >> n >> m >> x >> y;
//    func(x, y);
//    for (int i = 0; i < n; i++)
//    {
//        if (vis[i][0] != true) dp[i][0] = 1;
//    }
//    for (int j = 0; j < m; j++)
//    {
//        if (vis[0][j] != true) dp[0][j] = 1;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (vis[i - 1][j - 1] == true) dp[i][j] = 0;
//            else
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j-1];
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//}
//// 64 位输出请用 printf("%lld")


//#include <iostream>
//#include <unordered_map>
//using namespace std;
//int n, m, x, y;
//bool vis[21][21] = { false };  // 记录是否可达
//int dp[22][22]; // 到达 i j下标的总路径数 dp[i-1][j] + dp[i][j]
//void func(int x, int y) {
//    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//
//    for (int i = 0; i < 8; i++) {
//        int x1 = x + dx[i];
//        int y1 = y + dy[i];
//        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m) {
//            vis[x1][y1] = true;  // 标记为可达
//        }
//    }
//}
//int main() {
//    cin >> n >> m >> x >> y;
//    func(x, y);
//    dp[0][0] = vis[0][0] ? 0 : 1;  // 起点
//    for (int i = 0; i < n; i++)
//    {
//        if (!vis[i][0]) {
//            dp[i][0] = dp[i - 1][0];
//        }
//    }
//    for (int j = 0; j < m; j++)
//    {
//        if (!vis[0][j]) {
//            dp[0][j] = dp[0][j - 1];
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (vis[i - 1][j - 1] == true || (i == x - 1 && j == y - 1)) dp[i][j] = 0;
//            else
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//}
//// 64 位输出请用 printf("%lld")
//
//#include <iostream>
//#include <unordered_map>
//
//int main() {
//    std::unordered_map<int, int> myMap;  // 建议不要用 hash 作为变量名
//
//    int a = 1, b = 100;
//    myMap.insert({ a, b });  // C++11 及以上支持这种方式
//
//    // 或者更简单的方式：
//    myMap[a] = b;
//
//    // 验证是否插入成功
//    std::cout << myMap[a] << std::endl;  // 输出 100
//
//    return 0;
//}


//int main() {
//    // 当天的状态
//    // 有   f[i] = max(f[i-1], g[i-1] - price[i]);            有   没有 
//    // 没有  g[i] = max(f[i-1] + prices[i], g[i-1]);      有   没有
//    // f[i]表示第i天买入后的最大收入
//    // g[i]表示第i天卖出后的最大收入
//
//    // 初始化
//    // f[0] = -prices[0], g[0] = 0;
//        
//
//    int n = 7;
//    int prices[7];
//    for (int i = 0; i < n; i++) cin >> prices[i];
//    int f[7], g[7];    
//    f[0] = -prices[0], g[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        f[i] = max(f[i - 1], g[i - 1] - prices[i]);
//        g[i] = max(f[i - 1] + prices[i], g[i - 1]);
//        cout << f[i] << " " << g[i] << endl;
//    }
//    cout << f[n - 1] << endl;
//    cout << g[n - 1] << endl;
//}
//// 64 位输出请用 printf("%lld")


//#include <iostream>
//using namespace std;
//
//int main() {
//    string s;
//    getline(std::cin, s);
//    s = ' ' + s;
//    int sz = s.size() - 1;
//    string ret;
//    int t = sz;
//    while (sz >= 0)
//    {
//        if (s[sz] == ' ')
//        {
//            int len = t - sz;
//            ret += s.substr(sz + 1, len);
//            ret += ' ';
//            t = sz - 1;
//        }
//        sz--;
//    }
//    ret.pop_back();
//    cout << ret << endl;
//}
//// 64 位输出请用 printf("%lld")

///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == nullptr || pHead2 == nullptr) {
//			return nullptr;
//		}
//		ListNode* head1 = pHead1, * head2 = pHead2;
//		int n1 = 0, n2 = 0;
//		while (head1 != nullptr)
//		{
//			n1++;
//			head1 = head1->next;
//		}
//		while (head2 != nullptr)
//		{
//			n2++;
//			head2 = head2->next;
//		}
//		head1 = pHead1, head2 = pHead2;
//		if (n1 < n2)
//		{
//			head1 = pHead2;
//			head2 = pHead1;
//			swap(n2, n1);
//		}
//		int t = n1 - n2;
//		while (t)
//		{
//			head1 = head1->next;
//			t--;
//		}
//		while (head1 != nullptr && head2 != nullptr && head1 != head2)
//		{
//			head1 = head1->next;
//			head2 = head2->next;
//		}
//		return head1;
//	}
//};

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
//class Solution {
//public:
//    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//        if (pHead1 == nullptr || pHead2 == nullptr) {
//            return nullptr;
//        }
//
//        ListNode* head1 = pHead1, * head2 = pHead2;
//        while (head1 != head2)
//        {
//            if (head1 == nullptr) head1 = pHead2;
//            else head1 = head1->next;
//            if (head2 == nullptr) head2 = pHead1;
//            else head2 = head2->next;
//        }
//        return head1;
//    }
//};


///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) :
//            val(x), next(NULL) {
//    }
//};*/
//class Solution {
//public:
//    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//        if (pHead1 == nullptr || pHead2 == nullptr) {
//            return nullptr;
//        }
//
//        ListNode* head1 = pHead1, * head2 = pHead2;
//        while (head1 != head2)
//        {
//            head1 = head1 != nullptr ? head1->next : pHead2;
//            head2 = head2 != nullptr ? head2->next : pHead1;
//        }
//        return head1;
//    }
//};


//#include <iostream>
//#include <string>
//using namespace std;
//int n;
//string str;
//long long s[300001], sh[300001], shy[300001];
//int main()
//{
//    cin >> n >> str;
//    // s[i]表示[0,i]区间内有多少个s
//    // sh[i]表示[0,i]区间内有多少个sh
//    // shy[i]表示[0,i]区间内有多少个shy
//
//    // 初始化
//    s[0] = str[0] == 's' ? 1 : 0;
//    sh[0] = shy[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (str[i] == 's') s[i] = s[i - 1] + 1;
//        else s[i] = s[i - 1];
//
//        if (str[i] == 'h') sh[i] = s[i - 1] + sh[i - 1];
//        else sh[i] = sh[i - 1];
//
//        if (str[i] == 'y') shy[i] = sh[i - 1] + shy[i - 1];
//        else shy[i] = shy[i - 1];
//    }
//    cout << shy[n - 1] << endl;
//    return 0;
//}


#include <iostream>
#include <string>
using namespace std;
int n;
string str;
int main()
{
    cin >> n >> str;
    long long s, h, y;
    // 初始化
    s = str[0] == 's' ? 1 : 0;
    h = y = 0;
    for (int i = 1; i < n; i++)
    {
        char ch = str[i];

        if (ch == 's') s += 1;
        else if (ch == 'h') h += s;
        else if (ch == 'y') y += h;
    }
    cout << y << endl;
    return 0;
}