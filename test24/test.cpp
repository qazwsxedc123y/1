#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
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