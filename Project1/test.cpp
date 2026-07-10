#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int main() {
//    int q, a, b, c;
//    cin >> q;
//    for (int i = 0; i < q; i++)
//    {
//        cin >> a >> b >> c;
//        int ret = 0;
//        int ans = min(a, min(b, c));
//        ret += ans * 2;
//        b -= ans;
//        if (b != 0) ret += b - 1;
//        cout << ret << endl;
//    }
//}
//// 64 位输出请用 printf("%lld")


#include <queue>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int q, a, b, c;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        int ret = 0;
        int ans = min(a, min(b, c));
        ret += ans * 2;
        b -= ans;
        if (b != 0) ret += b - 1;
        cout << ret << endl;
    }
}
// 64 位输出请用 printf("%lld")






