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

using namespace std;

//class Solution {
//public:
//    int numSubarraysWithSum(vector<int>& nums, int goal) {
//        int n = nums.size();
//        int ret = 0;
//        int sum1 = 0, sum2 = 0;
//        for (int left1 = 0, left2 = 0, right = 0; right < n; right++)
//        {
//            // ������
//            sum1 += nums[right];
//            sum2 += nums[right];
//            while (left1 <= right && sum1 >= goal) // ����������
//            {
//                sum1 -= nums[left1++];
//            }
//            while (left2 <= right && sum2 >= goal + 1) // ����������
//            {
//                sum2 -= nums[left2++];
//            }
//            ret += (left1 - left2);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int numberOfSubarrays(vector<int>& nums, int k) {
//        int n = nums.size(), count1 = 0, count2 = 0;
//        int ret = 0;
//        for (int left1 = 0, left2 = 0, right = 0; right < n; right++)
//        {
//            // ������
//            if (nums[right] % 2 == 1)
//            {
//                count1++;
//                count2++;
//            }
//            while (left1 <= right && count1 >= k)// �������ڵ���k��ʱ
//            {
//                if (nums[left1++] % 2 == 1) count1--;
//            }
//            while (left2 <= right && count2 >= k + 1)// �������ڵ���k+1��ʱ
//            {
//                if (nums[left2++] % 2 == 1) count2--;
//            }
//            ret += (left1 - left2);
//        }
//        return ret;
//    }
//};

//class Solution {
//    const string VOWEL = "aeiou";
//
//    long long f(string& word, int k)
//    {
//        long long ans = 0;
//        // �����ù�ϣ��ʵ�֣��滻����������
//        unordered_map<char, int> cnt1; // ÿ��Ԫ���ĸ���
//        int cnt2 = 0; // ��������
//        int left = 0;
//        for (char b : word)
//        {
//            if (VOWEL.find(b) != string::npos)
//            {
//                cnt1[b]++;
//            }
//            else
//            {
//                cnt2++;
//            }
//            while (cnt1.size() == 5 && cnt2 >= k)
//            {
//                char out = word[left];
//                if (VOWEL.find(out) != string::npos)
//                {
//                    if (--cnt1[out] == 0)
//                    {
//                        cnt1.erase(out);
//                    }
//                }
//                else
//                {
//                    cnt2--;
//                }
//                left++;
//            }
//            ans += left;
//        }
//        return ans;
//    }
//
//public:
//    long long countOfSubstrings(string word, int k) {
//        return f(word, k) - f(word, k + 1);
//    }
//};

int main()
{
    int count1 = 0, count2 = 0;
    if (1) count1++, count2++;
    cout << count1 << "   " << count2 << endl;
    return 0;
}