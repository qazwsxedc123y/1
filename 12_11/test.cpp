#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include <algorithm> 
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <ranges>
#include <algorithm>
#include <queue>       // ���� priority_queue
#include <functional>  // ���� greater less �Ƚ���

using namespace std;

//#include <stdio.h>                                                                                                                         
//#include <string.h>
//int main(int argc, char* argv[])
//{
//	if (argc > 1)
//	{
//		if (strcmp(argv[1], "-a") == 0)
//		{
//			printf("you used -a option...\n");
//		}
//		else if (strcmp(argv[1], "-b") == 0)
//		{
//			printf("you used -b option...\n");
//		}
//		else
//		{
//			printf("you used unrecognizable option...\n");
//		}
//	}
//	else
//	{
//		printf("you did not use any option...\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int g_unval;  // δ��ʼ����ȫ�ֱ���
//int g_val = 100;  // �ѳ�ʼ����ȫ�ֱ���
//
//int main(int argc, char* argv[], char* envp[]) {
//    int i;
//
//    // ��ӡ����ε�ַ
//    printf("code addr: %p\n", main);  // main�����ĵ�ַ
//
//    // ��ӡֻ����������ַ
//    char* str = "hello world";  // �ַ������������洢��ֻ��������
//    printf("read only addr: %p\n", str);  // �ַ��������ĵ�ַ
//
//    // ��ӡ�ѳ�ʼ�����ݶεĵ�ַ
//    printf("init addr: %p\n", &g_val);  // �ѳ�ʼ��ȫ�ֱ���g_val�ĵ�ַ
//
//    // ��ӡδ��ʼ�����ݶεĵ�ַ
//    printf("uninit addr: %p\n", &g_unval);  // δ��ʼ��ȫ�ֱ���g_unval�ĵ�ַ
//
//    // ��ӡ������ַ
//    int* p = (int*)malloc(10 * sizeof(int));  // ��̬����10��int���͵��ڴ�
//    if (p == NULL) {
//        printf("Memory allocation failed!\n");
//        return 1;  // ����ڴ����ʧ�ܣ����˳�
//    }
//    printf("heap addr: %p\n", p);  // �����ĵ�ַ
//
//    // ��ӡջ����ַ
//    printf("stack addr: %p\n", &str);  // ջ�Ͼֲ�����str�ĵ�ַ
//    printf("stack addr: %p\n", &p);    // ջ�Ͼֲ�����p�ĵ�ַ
//
//    // ��ӡ�����в����ĵ�ַ
//    for (i = 0; i < argc; i++) {
//        printf("args addr: %p\n", argv[i]);  // ��ӡÿ�������в����ĵ�ַ
//    }
//
//    // ��ӡ���������ĵ�ַ
//    i = 0;
//    while (envp[i]) {
//        printf("env addr: %p\n", envp[i]);  // ��ӡÿ�����������ĵ�ַ
//        i++;
//    }
//
//    // �ͷŶ�̬������ڴ�
//    free(p);
//
//    return 0;
//}

//   g_val = 200;  // �ӽ����޸�ȫ�ֱ���
//         sleep(3);  // ��������ͣ3�룬�ȴ��ӽ������

//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <unistd.h>
//
//int g_val = 100;
//
//int main() {
//    pid_t id = fork();  // ����һ���µĽ���
//
//    if (id == 0) {  // �ӽ���
//        printf("child: PID: %d, PPID: %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
//    }
//    else if (id > 0) {  // ������
//        printf("father: PID: %d, PPID: %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
//    }
//    else {  // forkʧ��
//        perror("fork failed");
//        exit(1);
//    }
//    return 0;
//}

//class Solution {
//public:
//    bool isletter(char ch)
//    {
//        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
//    }
//    bool isPalindrome(string s) {
//        int n = s.size();
//        int r = n - 1, l = 0;
//        while (l < r)
//        {
//            while (l < r && !isletter(s[l])) l++;
//            while (l < r && !isletter(s[r])) r--;
//            if (tolower(s[l]) != tolower(s[r])) return false;
//            l++, r--;
//        }
//        return true;
//    }
//};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
        {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 2; i <= n; i++)//����
        {
            for (int l = 0; l < n; l++)//��ʼλ��
            {
                int r = l + i - 1;
                if (r >= n)
                {
                    break;
                }
                if (s[l] != s[r])
                {
                    dp[l][r] = false;
                }
                else
                {
                    if (r - l < 3)
                        dp[l][r] = true;
                    else
                        dp[l][r] = dp[l + 1][r - 1];
                }
                if (dp[l][r] && i > maxLen)
                {
                    maxLen = i;
                    begin = l;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main()
{
    Solution s;
    string s1{ "0P" };
    s.isPalindrome(s1);
	return 0;
}