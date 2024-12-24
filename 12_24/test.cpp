#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


// 先描述
class channel
{
private:
    channel(int cmdfd, int slaverid, const std::string& processname)
        :_cmdfd(cmdfd), _slaverid(slaverid), _processname(processname)
    {
    }
public:
    int _cmdfd;               // 发送任务的文件描述符
    pid_t _slaverid;          // 子进程的PID
    string _processname; // 子进程的名字 -- 方便我们打印日志
};

// 输入：const &
// 输出：*
// 输入输出：&

int main()
{
    // 先描述，在组织
    // 描述为创建管道
    // 利用fork 父进程为写端 子进程为读端
    // 建立通信匿名管道使用函数pipe
}


//int n, m;
//string s1, s2;

//int main()
//{
//    cin >> n >> m; // 读入字符串长度（未在代码中使用）
//    cin >> s1; // 原始字符串
//    cin >> s2; // 要插入的字符串
//
//    unordered_map<char, int> hash;
//    for (auto x : s2)
//    {
//        hash[x]++; // 统计每个字符的出现次数
//    }
//
//    // 将字符插入到字符串 s1 中
//    for (auto [ch, num] : hash)
//    {
//        bool inserted = false; // 标记是否成功插入
//        for (int i = 0; i < s1.size(); ++i)
//        {
//            if (ch < s1[i])
//            {
//                s1.insert(i, num, ch); // 在合适位置插入 num 个字符 ch
//                inserted = true;
//                break; // 插入后跳出循环
//            }
//        }
//        if (!inserted)
//        {
//            // 如果没有合适位置，直接追加到末尾
//            s1.append(num, ch);
//        }
//    }
//
//    cout << s1; // 输出最终字符串
//    return 0;
//}



//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//const int N = 100001;
//int n, ans = N;
//int arr[N], fid[N];
//void Create(int n)
//{
//    fid[0] = 1;
//    fid[1] = 1;
//    for (int i = 2; i < n; i++) fid[i] = fid[i - 1] + fid[i - 2];
//}
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//    Create(n);
//    for (int i = 1; i < 1e6; i++)
//    {
//        int count = 0;
//        for (int j = 0; j < min(n, 30); j++)count += (arr[j] != i * fid[j]);
//        ans = min(count, ans);
//    }
//    cout << ans + max(0, n - 30);
//    return 0;
//}