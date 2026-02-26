#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        // 先乘，然后再考虑进位
//        int n = num1.size(), m = num2.size();
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//        vector<int> tmp(n + m);
//        // 最多n + m位
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                tmp[i + j] += ((num1[i] - '0') * (num2[j] - '0'));
//            }
//        }
//
//        //for(int i = 0; i < n+m; i++) cout << tmp[i] << " ";
//
//        // 调整进位
//        int array = 0;
//        string ret;
//        for (int i = 0; i < n + m; i++)
//        {
//            tmp[i] += array;
//            ret.push_back(tmp[i] % 10 + '0');
//            array = tmp[i] / 10;
//        }
//        // 处理前导0
//        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
//
//        reverse(ret.begin(), ret.end());
//
//        return ret;
//
//    }
//};


int main()
{
    //vector<vector<int>> v;
    //v.push_back({ 1,1,1 });
    //v.push_back({ 1,0,1 });
    //v.push_back({ 1,1,1 });
    // [1,1,1],[1,0,1],[1,1,1]
    Solution s;
    int x = 100;
    // s.setZeroes(v);
    return 0;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


//void checkEndianness() {
//    int num = 1;  // 二进制：0x00000001
//
//    // 将int指针转为char指针，只取第一个字节
//    char* ptr = (char*)&num;
//
//    if (*ptr == 1) {
//        cout << "小端模式 (Little Endian)" << endl;
//        cout << "说明：低位字节(0x01)存储在低地址" << endl;
//    }
//    else {
//        cout << "大端模式 (Big Endian)" << endl;
//        cout << "说明：高位字节(0x00)存储在低地址" << endl;
//    }
//
//    // 打印内存布局
//    cout << "\n内存中的字节顺序：" << endl;
//    for (int i = 0; i < sizeof(int); i++) {
//        printf("地址 %p : 0x%02x\n", ptr + i, (unsigned char)ptr[i]);
//    }
//}
//
//int main() {
//    cout << "=== 检测系统大小端 ===" << endl;
//    checkEndianness();
//    return 0;
//}