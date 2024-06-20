//#define  _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    string toHex(int num) {
//        if (num == 0)
//        {
//            return "0";
//        }
//        string s;
//        for (int i = 7; i >= 0; i--)
//        {
//            int val = (num >> (i * 4)) & 0xf;
//            char digit;
//            if (s.size() != 0 || val > 0)
//            {
//                digit = val < 10 ? (char)'0' + val : (char)'a' + val - 10;
//                s.push_back(digit);
//            }
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    int val = (-1 >> (7 * 4)) & 0xf;
//    cout << ( - 1 >> (7 * 4)) << endl;
//    cout << val << endl;
//    memmove()
//}