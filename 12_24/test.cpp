#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


// ������
class channel
{
private:
    channel(int cmdfd, int slaverid, const std::string& processname)
        :_cmdfd(cmdfd), _slaverid(slaverid), _processname(processname)
    {
    }
public:
    int _cmdfd;               // ����������ļ�������
    pid_t _slaverid;          // �ӽ��̵�PID
    string _processname; // �ӽ��̵����� -- �������Ǵ�ӡ��־
};

// ���룺const &
// �����*
// ���������&

int main()
{
    // ������������֯
    // ����Ϊ�����ܵ�
    // ����fork ������Ϊд�� �ӽ���Ϊ����
    // ����ͨ�������ܵ�ʹ�ú���pipe
}


//int n, m;
//string s1, s2;

//int main()
//{
//    cin >> n >> m; // �����ַ������ȣ�δ�ڴ�����ʹ�ã�
//    cin >> s1; // ԭʼ�ַ���
//    cin >> s2; // Ҫ������ַ���
//
//    unordered_map<char, int> hash;
//    for (auto x : s2)
//    {
//        hash[x]++; // ͳ��ÿ���ַ��ĳ��ִ���
//    }
//
//    // ���ַ����뵽�ַ��� s1 ��
//    for (auto [ch, num] : hash)
//    {
//        bool inserted = false; // ����Ƿ�ɹ�����
//        for (int i = 0; i < s1.size(); ++i)
//        {
//            if (ch < s1[i])
//            {
//                s1.insert(i, num, ch); // �ں���λ�ò��� num ���ַ� ch
//                inserted = true;
//                break; // ���������ѭ��
//            }
//        }
//        if (!inserted)
//        {
//            // ���û�к���λ�ã�ֱ��׷�ӵ�ĩβ
//            s1.append(num, ch);
//        }
//    }
//
//    cout << s1; // ��������ַ���
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