#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int ret = 0;
//        int n = fruits.size();
//        unordered_map<int, int> mp;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            //������
//            mp[fruits[right]]++;
//            count++;
//            //�ж� ������
//            while (mp.size() > 2)
//            {
//                mp[fruits[left]]--;
//                if (mp[fruits[left]] == 0)
//                {
//                    mp.erase(fruits[left]);
//                }
//                count--;
//            }
//            ret = max(ret, count);
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> v;
//        int len = words[0].size();
//        int n = s.size();
//        int m = words.size();
//
//        if (n < len * m) return v; // ���Ȳ��������
//
//        unordered_map<string, int> hash1; // ��¼ÿ�����ʳ��ֵĴ���
//        for (const auto& word : words) hash1[word]++;
//
//        // ���ѭ������ 0 �� len-1��ÿ�δӲ�ͬλ�ÿ�ʼ
//        for (int i = 0; i < len; i++)
//        {
//            unordered_map<string, int> hash2; // ��¼��ǰ�����е��ʳ��ֵĴ���
//            int left = i, right = i, count = 0;
//
//            while (right + len <= n)
//            {
//                // ������
//                string in = s.substr(right, len);
//                right += len;
//
//                if (hash1.find(in) != hash1.end())
//                {
//                    hash2[in]++;
//                    if (hash2[in] <= hash1[in])
//                    {
//                        count++;
//                    }
//                }
//
//                // �жϳ����ڣ���������
//                while (right - left > len * m)
//                {
//                    string out = s.substr(left, len);
//                    left += len;
//
//                    if (hash1.find(out) != hash1.end())
//                    {
//                        if (hash2[out] <= hash1[out])
//                        {
//                            count--;
//                        }
//                        hash2[out]--; // ֱ�Ӽ��٣������� erase
//                    }
//                }
//
//                // ��������ڰ��������е���
//                if (count == m)
//                {
//                    v.push_back(left);
//                }
//            }
//        }
//        return v;
//    }
//};

//
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> v;
//        int len = words[0].size();
//        int n = s.size();
//        int m = words.size();
//        unordered_map<string, int> hash1;
//        for (auto& word : words) hash1[word]++;
//        for (int i = 0; i < len; i++)
//        {
//            unordered_map<string, int> hash2;
//            for (int left = i, right = i, count = 0; right < n; right += len)
//            {
//                // ������
//                string in = s.substr(right, len);
//                hash2[in]++;
//                if (hash2[in] <= hash1[in]) count++;
//                //�жϳ�
//                if (right - left + 1 > len * m)
//                {
//                    string out = s.substr(left, len);
//                    if (hash2[out] <= hash1[out]) count--;
//                    hash2[out]--;
//                    if (hash2[out] == 0)
//                    {
//                        hash2.erase(out);
//                    }
//                    left += len;
//                }
//                if (count == m)
//                {
//                    v.push_back(left);
//                }
//            }
//        }
//        return v;
//    }
//};

int main()
{
    Solution s;
    vector<int> v{ 3,3,3,1,2,1,1,2,3,3,4 };
    string s1{ "barfoothefoobarman" };
    vector<string> s2{ "foo","bar" };
    s.findSubstring(s1, s2);
    return 0;
}