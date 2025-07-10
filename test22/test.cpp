#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
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



const int N = 1000000;
int n, ret = 0;
int main() {
    n = 15;
    int a = 0, b = 1, c = 1;
    int a1, a2;
    while (c >= n)
    {
        a = b;
        b = c;
        c = a + b;
    }
    a2 = c, a1 = b;
    while (true)
    {
        if (a1 == n || a2 == n)
        {
            break;
        }
        a1++, a2--;
        ret++;
    }
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")