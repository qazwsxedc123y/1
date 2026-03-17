#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// bugTest.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Solution {
public:
    string decodeString(string s) {
        // 感觉可以用栈
        int n = s.size(), i = 0;
        stack<int> st1;
        stack<string> st2;
        st2.push(""); // 避免为空的情况，即全为普通串
        while (i < n)
        {
            cout << i << " ";
            if (s[i] == '[')
            {
                i++;
                string tmp;
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    tmp += s[i++];
                }
                st2.push(tmp);
            }
            else if (s[i] == ']')
            {
                // 统计，然后入栈
                int ans = st1.top();
                st1.pop();
                string tmp = st2.top();
                st2.pop();
                while (ans)
                {
                    st2.top() += tmp;
                    ans--;
                }
                i++;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                int ans = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    ans = ans * 10 + s[i] - '0';
                    i++;
                }
                st1.push(ans);
            }
            else
            {
                st2.top() += s[i++];
            }
        }
        return st2.top();
    }
};
int main()
{
	cout << (int)'6' << endl;
	return 0;
}