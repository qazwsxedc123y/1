#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include<iostream>
#include<cmath>  // ����ͷ�ļ�
#include<algorithm >  // ���� sort ����

using namespace std;


//class Solution {
//public:
//    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
//        int n = s.size();
//        string ret;
//        int h = 0;   // �Ӵ���ϣֵ
//        long long p = 1;  // power^right % modulo
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            // ������
//            h = (h + (s[right] - 'a' + 1) * p) % modulo;
//            if (right - left + 1 >= k)
//            {
//                if (h == hashValue)
//                {
//                    ret = s.substr(left, k);
//                }
//                // ��
//                if (h == 0) h = modulo;
//                h = (h - (s[left++] - 'a' + 1) + modulo) % modulo;
//                p = (p * power) % modulo;  // ���� power^right % modulo
//            }
//            p = (p * power) % modulo;  // Update p for next iteration
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int divisorSubstrings(int num, int k) {
//        vector<int> v; //���num�������ÿ��λ��ֵ
//        int n;  //��������ÿ��λ����ֵ
//        int num1 = num; //��num����num1
//        int res = 0;//����ֵ-���صĽ��
//        while (num1 != 0) {//�Ӹ�λ ʮλ ��λ...����ѹ��v������
//            n = num1 % 10;//����
//            num1 = num1 / 10;//�Գ�����num1
//            v.push_back(n);
//        }
//        reverse(v.begin(), v.end());//����v������Ԫ��
//        int left = 0;//��߽�
//        int right = k - 1;//�ұ߽� //0��k-1����k����
//        for (left, right; right < v.size(); right++, left++) {//�������ڷ�ʽģ����֤
//            int tmp = v[left];//��ʼ��tmp  ����������߽���� ���������������λ
//            for (int i = left + 1; i <= right; i++) {
//                tmp = tmp * 10 + v[i]; //ģ�⻬��������Ԫ�����һ����
//            }
//            if (tmp == 0)//���Ϊ0��ֱ����һ��ѭ��
//                continue;
//            if (num % tmp == 0) {//���������������ֵ���+1
//                res++;
//            }
//        }
//        return res;//���ؽ��
//    }
//};

//class Solution {
//public:
//    int minimumDifference(vector<int>& nums, int k) {
//        int ret = INT_MAX;
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            if (right - left + 1 == k)
//            {
//                ret = min(ret, (nums[right] - nums[left++]));
//            }
//        }
//        return ret;
//    }
//};

int main()
{
    Solution s;
    string s1{ "leetcode" };
    s.divisorSubstrings(240, 2);
    return 0;
}