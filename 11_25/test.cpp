#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>


using namespace std;

//class Solution {
//public:
//    int maximumLengthSubstring(string s) {
//        int n = s.size();
//        int cnt[26] = { 0 };
//        int ret = 0;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            int in = s[right] - 'a';
//            cnt[in]++;
//            while (cnt[in] > 2)
//            {
//                int ou = s[left++] - 'a';
//                cnt[ou]--;
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int longestSubarray(vector<int>& nums) {
//        int n = nums.size();
//        int zero = 0;
//        int ret = 0;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            int in = nums[right];
//            if (in == 0) zero++;
//            while (zero > 1)
//            {
//                int ou = nums[left++];
//                if (ou == 0)
//                {
//                    zero--;
//                }
//            }
//            ret = max(ret, right - left);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int equalSubstring(string s, string t, int maxCost) {
//        int n = s.size();
//        int ans = 0;
//        vector<int> diff(n, 0);
//        for (int i = 0; i < n; i++) diff[i] = abs(s[i] - t[i]);
//        int ret = 0;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            ans += diff[right];
//            while (ans > maxCost)
//            {
//                ans -= diff[left++];
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int maximumUniqueSubarray(vector<int>& nums) {
//        int n = nums.size();
//        int ret = 0;  // �洢����
//        int sum = 0;  // ��ǰ������ĺ�
//        unordered_map<int, int> hash;  // ��ϣ�����ڼ�¼ÿ��Ԫ�ص�Ƶ��
//
//        int left = 0;  // �������ڵ���ָ��
//        for (int right = 0; right < n; ++right) {
//            int in = nums[right];  // ��ǰ��ָ����ָ��Ԫ��
//            hash[in]++;  // ���Ӹ�Ԫ�ص�Ƶ��
//            sum += in;  // ����ǰԪ����ӵ���ǰ������ĺ�
//
//            // ��������ظ�Ԫ�أ��ƶ���ָ���Ա���Ψһ������
//            while (hash[in] > 1) {
//                int ou = nums[left];  // ��ָ����ָ��Ԫ��
//                hash[ou]--;  // ������ָ��Ԫ�ص�Ƶ��
//                sum -= ou;  // �ӵ�ǰ��������м�ȥ��ָ��Ԫ�ص�ֵ
//                left++;  // �ƶ���ָ��
//            }
//
//            // ��������������
//            ret = max(ret, sum);
//        }
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    int maxSubarrayLength(vector<int>& nums, int k) {
//        int ans = 0, left = 0;
//        unordered_map<int, int> cnt;
//        for (int right = 0; right < nums.size(); right++) {
//            cnt[nums[right]]++;
//            while (cnt[nums[right]] > k) {
//                cnt[nums[left++]]--;
//            }
//            ans = max(ans, right - left + 1);
//        }
//        return ans;
//    }
//};


int main()
{
    Solution s;
    string s1{ "eebadadbfa" };
    s.maximumLengthSubstring(s1);
    return 0;
}