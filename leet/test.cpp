#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        //
//        int sz = nums.size(); // 范围 1 ~ sz-1
//        // 只有一个数是重复的
//        // 按位与
//        int ret = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            int x = 0, y = 0;
//            for (int j = 0; j < sz; j++)
//            {
//                // 计算当前为是什么
//                if ((1 << i) & nums[j]) x++;
//
//                if (j >= 1 && (j & (1 << i))) y++;
//            }
//            if (x > y)
//            {
//                // 那么重复的那个数该位为1
//                ret |= (1 << i);
//            }
//        }
//
//        return ret;
//    }
//};


//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        int slow = 0, fast = 0;
//        do {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        } while (slow != fast);
//        slow = 0;
//        while (slow != fast) {
//            slow = nums[slow];
//            fast = nums[fast];
//        }
//        return slow;
//    }
//};


class Solution {
public:
    string longestPalindrome(string s) {
        // 动态规划
        int n = s.size();
        if (n < 2) return s;

        vector<vector<bool>> dp(n, vector<bool>(n)); // dp[i][j]表示下标[i,j]区间是否为回文
        // 首先长度为1的肯定是回文
        for (int i = 0; i < n; i++) dp[i][i] = true;

        int begin = 0, max_len = 1;

        // 查看长度大于等于2的
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i < n; i++) // 左
            {
                int j = i + len - 1; // 右
                if (j < n && s[i] == s[j])
                {
                    // 特殊处理2，因为如果长度为2，那么dp[i+1][j-1]就会变为dp[j][i]
                    if (len == 2) dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                    if (dp[i][j] && len > max_len)
                    {
                        max_len = len;
                        begin = i;
                    }
                }
            }
        }

        return s.substr(begin, max_len);
    }
};


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