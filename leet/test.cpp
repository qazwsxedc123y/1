#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


//class Solution {
//    const int N = 1e5 + 7;
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        // 只能向下 或 右
//        // 使用动态规划
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp[i][j] 表示到达[i-1,j-1]的最小路径和
//        // 初始化
//        dp[0][1] = dp[1][0] = 0;
//        for (int i = 2; i <= n; i++) dp[0][i] = N;
//        for (int i = 2; i <= m; i++) dp[i][0] = N;
//
//        for (int i = 1; i <= m; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//
//        return dp[m][n];
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