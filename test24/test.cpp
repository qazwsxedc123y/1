#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;




// 8.5

//string s;
//int n;
//int func()
//{
//    for (int len = 2; len <= n; len++)
//    {
//        for (int i = 0; i < n - len + 1; i++)
//        {
//            bool flag = true;
//            int l = i, r = i + len - 1;
//
//            // �жϸ������Ƿ�Ϊ���Ĵ�
//            while (l < r)
//            {
//                if (s[l] != s[r])
//                {
//                    flag = false;
//                    break;
//                }
//                l++, r--;
//            }
//            if (flag == true) return len;
//        }
//    }
//    return -1;
//}
//int main() {
//    cin >> s;
//    // ���Ȳ��������Կ��ǲ���ȫ�����ȱ���
//    // 2 �� n
//    n = s.size();
//
//    int ret = func();
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")
//
//
//
//const int N = 1e6 + 100;
//int n, arr[N];
//long long func(int pos)
//{
//    // ���ö�̬�滮
//    long long f[N] = { 0 }; // ��ʾ��iλ�ò�ѡʱ��ֵ����ѡ��
//    long long g[N] = { 0 }; // ��ʾ��iλ��ѡʱ��ֵ����ѡ��
//    // ���ڵ�iλ��
//    // ѡ��g[i] = max(f[i-1] + arr[i],arr[i] + g[i-2])
//    // ��ѡf[i] = max(g[i-1], f[i-1]);
//    // ��ʼ��
//    g[pos] = arr[pos];
//
//    for (int i = pos + 1; i <= n; i++)
//    {
//        g[i] = max(f[i - 1] + arr[i], arr[i] + g[i - 2]);
//        f[i] = max(g[i - 1], f[i - 1]);
//    }
//    return max(g[n], f[n]);
//}
//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> arr[i];
//
//    // ��ҽ���
//    cout << max(func(1), func(2)) << endl;
//}
//// 64 λ������� printf("%lld")
//
//
//
//const int N = 1e6 + 100;
//int n, p, a[N] = { 0 };
//int main() {
//    cin >> n >> p;
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    // ���Բ��û�������
//    sort(a, a + n);
//    // [K-p, K+p]
//
//    int ret = 0;
//    for (int l = 0, r = 0; r < n; r++)
//    {
//        while (a[r] - a[l] > 2 * p)
//        {
//            l++;
//        }
//        ret = max(r - l + 1, ret);
//    }
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")


//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ����ɹ��ٰ���Ҫ������������
//     * @param n int���� ��n���
//     * @param startEnd int����vector<vector<>> startEnd[i][0]���ڱ�ʾ��i����Ŀ�ʼʱ�䣬startEnd[i][1]��ʾ��i����Ľ���ʱ��
//     * @return int����
//     */
//    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
//        // write code here
//        sort(startEnd.begin(), startEnd.end());
//        priority_queue<int, vector<int>, greater<int>> heap;
//
//        heap.push(startEnd[0][1]);
//
//        for (int i = 1; i < n; i++)
//        {
//            int a = startEnd[i][0];
//            if (a >= heap.top())
//            {
//                heap.pop();
//                heap.push(startEnd[i][1]);
//            }
//            else
//            {
//                heap.push(startEnd[i][1]);
//            }
//        }
//
//        return heap.size();
//    }
//};


///**
// * struct TreeNode {
// *  int val;
// *  struct TreeNode *left;
// *  struct TreeNode *right;
// *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// * };
// */
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param root TreeNode��
//     * @return int����
//     */
//    int maxSum = INT_MIN;
//    int maxGain(TreeNode* root) {
//        if (root == nullptr) return 0;
//
//        int leftGain = max(maxGain(root->left), 0);
//        int rightGain = max(maxGain(root->right), 0);
//
//        int priceNewpath = root->val + leftGain + rightGain;
//
//        maxSum = max(maxSum, priceNewpath);
//
//        return root->val + max(leftGain, rightGain);
//    }
//    int maxPathSum(TreeNode* root) {
//        maxGain(root);
//        return maxSum;
//        // write code here
//    }
//};



//const long long N = 1e4 + 10;
//long long T, arr[N];
//int main() {
//    // ��û�й��ɣ�
//    cin >> T;
//    // 2^n - 1
//    for (long long i = 1; i <= 7; i++)
//    {
//        long long j = 1;
//        long long cnt = 0;
//        while (true)
//        {
//            long long ans = pow(2, j) - 1;
//            if (ans >= i)
//            {
//                if (ans == i)
//                {
//                    arr[i] = j;
//                }
//                else
//                {
//                    cnt = j - 1;
//                    long long t = i - pow(2, cnt) + 1;
//                    arr[i] = cnt + arr[t];
//                }
//                break;
//            }
//            j++;
//        }
//    }
//    for (int i = 0; i < T; i++)
//    {
//        int t;
//        cin >> t;
//        cout << arr[t] << endl;
//    }
//}
//// 64 λ������� printf("%lld")



//const int N = 15;
//int n, a[N], ret = 0;
//bool vis[N];
//void dfs(int pos)
//{
//    if (pos == n + 1)
//    {
//        ret++;
//        return;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        if (vis[i]) continue;
//        if (vis[a[i]]) return;
//        vis[i] = true;
//        dfs(pos + 1);
//        vis[i] = false;
//    }
//}
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//
//    dfs(1);
//    cout << ret << endl;
//    return 0;
//}



//const int N = 1e5 + 10;
//int n, arr[N];
//int ret = 0;
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//
//    for (int i = 0; i < n; i++)
//    {
//        if (i == n - 1)
//        {
//            ret++;
//            break;
//        }
//
//        if (arr[i] > arr[i + 1])
//        {
//            while (i + 1 < n && arr[i] >= arr[i + 1]) i++;
//            ret++;
//        }
//        else if (arr[i] < arr[i + 1])
//        {
//            while (i + 1 < n && arr[i] <= arr[i + 1]) i++;
//            ret++;
//        }
//    }
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")



//int t, h;
//void func()
//{
//    int ret = 0, a = 1;
//    while (h)
//    {
//        h -= a;
//        if (h % (a * 2) == 0)
//        {
//            a *= 2;
//        }
//        ret++;
//    }
//    cout << ret << endl;
//}
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        cin >> h;
//        func();
//    }
//    return 0;
//}



//int T;
//long long a, b;
//int main() {
//    cin >> T;
//    for (int i = 0; i < T; i++)
//    {
//        cin >> a >> b;
//        if (a == 1 || b == 1)
//        {
//            if (b == 1 && a == 1)
//            {
//                cout << "NO" << endl;
//            }
//            else
//            {
//                // ��鲻Ϊ1���ǲ�������
//                long long t = (a == 1 ? b : a);
//                bool flag = true;
//                for (long long j = 2; j <= pow(t, 0.5); j++)
//                {
//                    if (t % j == 0)
//                    {
//                        cout << "NO" << endl;
//                        flag = false;
//                        break;
//                    }
//                }
//                if (flag)
//                    cout << "YES" << endl;
//            }
//        }
//        else cout << "NO" << endl;
//    }
//}
//// 64 λ������� printf("%lld")
//



//const int N = 2e5 + 10;
//int n, k, a[N];
//int main() {
//    cin >> n >> k;
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    sort(a, a + n);
//
//    int ret = 0, ans = 0;
//    // ��������
//    for (int l = 0, r = 0; r < n; r++)
//    {
//        ans = a[r] - a[l];
//        while (ans > k)
//        {
//            ans = a[r] - a[++l];
//        }
//        ret = max(ret, r - l + 1);
//    }
//    cout << ret << endl;
//}
//// 64 λ������� printf("%lld")