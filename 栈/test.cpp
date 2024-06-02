#define  _CRT_SECURE_NO_WARNINGS


#include"stack.h"
#include"queue.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //bit::stack<int, vector<int>> st;
        //bit::stack<int, list<int>> st;
        test1::stack<int> st;

        for (auto& str : tokens)
        {
            if (str == "+"
                || str == "-"
                || str == "*"
                || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
}; 
void test_stack()
{
    test1::stack<int, vector<int>> s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(7);
    s.push(5);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void test_queue()
{
    //test2::queue<int, list<int>> q;
    test2::queue<int> q;
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(7);
    q.push(5);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    test_stack();
    test_queue();
    //vector<string> v = { "4","13","5","/","+" };
    //cout << Solution().evalRPN(v) << endl;
    return 0;
}