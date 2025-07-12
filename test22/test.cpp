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


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // 先计算无进位相乘
        vector<int> tmp(n + m - 1);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp[i + j] += ((num1[i] - '0') * (num2[j] - '0'));
            }
        }

        // 处理进位
        int cur = 0, array = 0;
        string ret;
        while (cur < n + m - 1 || array)
        {
            if (cur < n + m - 1) array += tmp[cur++];
            ret.push_back(array % 10 + '0');
            array /= 10;
        }

        // 处理前导0
        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
        // 逆置
        reverse(ret.begin(), ret.end());
        return ret;
    }
};