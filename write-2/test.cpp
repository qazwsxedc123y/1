#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
using namespace std;
//class Solution {
//public:
//    int myAtoi(string str) {
//        int res = 0, bndry = INT_MAX / 10;
//        int i = 0, sign = 1, length = str.size();
//        if (length == 0) return 0;
//        while (str[i] == ' ')
//            if (++i == length) return 0;
//        if (str[i] == '-') sign = -1;
//        if (str[i] == '-' || str[i] == '+') i++;
//        for (int j = i; j < length; j++) {
//            if (str[j] < '0' || str[j] > '9') break;
//            if (res > bndry || res == bndry && str[j] > '7')
//                return sign == 1 ? INT_MAX : INT_MIN;
//            res = res * 10 + (str[j] - '0');
//        }
//        return sign * res;
//    }
//};
//class Solution {
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0")
//            return "0";
//        string ret;
//        int count = 0;
//        int n = num1.size(), m = num2.size();
//        for (int i = m - 1; i >= 0; i--)
//        {
//            string curr;
//            int tmp = num2[i]-'0';
//            int carry = 0;
//            for (int j = n - 1; j >= 0; j--)
//            {
//                int a = num1[j]-'0';
//                int sum = tmp * a + carry;
//                carry = sum / 10;
//                curr.push_back(sum % 10+'0');
//            }
//            if (carry != 0)
//            {
//                curr.push_back(carry+'0');
//                carry = 0;
//            }
//            //反转字符串
//            int right = curr.size() - 1;
//            int left = 0;
//            while (right > left)
//            {
//                char cr = curr[right];
//                char cl = curr[left];
//                curr[right] = cl;
//                curr[left] = cr;
//                --right;
//                ++left;
//            }
//            for (int x = 0; x < count; x++)
//            {
//                curr.push_back('0');
//            }
//            count++;
//            ret = addStrings(curr, ret);
//        }
//        return ret;
//    }
//    string addStrings(string num1, string num2) {
//        string s;
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int carry = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int x1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int x2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int sum = x1 + x2 + carry;
//            carry = sum / 10;
//            sum %= 10;
//            s += ('0' + sum);
//            --end1, --end2;
//        }
//        if (carry == 1)
//        {
//            s += '1';
//        }
//        reverse(s.begin(), s.end());
//        return s;
//    }
//};
//class Solution {
//public:
//    string reverseWords(string s) {
//        int sz = s.size();
//        int i = 0;
//        int end_sz = 0;
//        int a = sz - 1;
//        while (s[a] != ' ')
//        {
//            end_sz++;
//            a--;
//        }
//        while (1)
//        {
//            if (i == sz - end_sz - 1) {
//                int right = sz - 1;
//                int left = i;
//                while (right > left) {
//                    char cr = s[right];
//                    char cl = s[left];
//                    s[right] = cl;
//                    s[left] = cr;
//                    --right;
//                    ++left;
//                }
//                break;
//            }
//            int tmp = i;
//            i = s.find(" ", i+1);
//            
//            int right = i - 1;
//            int left = tmp == 0 ? 0 : tmp + 1;
//            while (right > left) {
//                char cr = s[right];
//                char cl = s[left];
//                s[right] = cl;
//                s[left] = cr;
//                --right;
//                ++left;
//            }
//        }
//
//        return s;
//    }
//};
class Solution {
public:
    string reverseWords(string s) {
        stack<char> s1;
        int sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == ' ')
            {
                i++;
            }
            int j = i;
            int count = 0;
            while (s[i] != ' ' && i != sz)//进栈
            {
                count++;
                s1.push(s[i]);
                i++;
            }
            //入栈完毕开始出栈
            while (count--)
            {
                char ch = s1.top();
                s1.pop();
                s[j] = ch;
                j++;
            }
 
        }
        return s;
    }
};

int main()

{

    int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };

    int n = sizeof(array) / sizeof(int);

    list<int> mylist(array, array + n);

    auto it = mylist.begin();

    while (it != mylist.end())

    {

        if (*it != 0)

            cout << *it << " ";

        else

            it = mylist.erase(it);

        ++it;

    }

    return 0;

}

