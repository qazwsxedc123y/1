#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ret = n;
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            if (blocks[right] == 'W') count++;
            while (right - left + 1 >= k)
            {
                ret = min(ret, count);
                if (blocks[left++] == 'W') count--;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        int k1 = 2 * k + 1;
        vector<int> ret(n, -1);
        if (k1 > n) return ret;
        for (int i = 0; i < k1 && i < n; i++) {
            sum += nums[i];
        }
        for (int i = k; i < n - k; i++) {
            // ���㴰�ڵ�ƽ��ֵ
            ret[i] = sum / k1;

            // �������ڣ�ȥ����������ߵ�Ԫ�أ��������ұߵ���Ԫ��
            if (i + k <= n) {
                sum -= nums[i - k];  // ȥ����ߵ�Ԫ��
                if (i + 1 < n - k)sum += nums[i + k + 1];  // �����ұߵ�Ԫ��
            }
        }
        return ret;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int ret = 0;
        double avg = 0, sum = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            // ������
            sum += arr[right];
            // �ж� ����ƽ��ֵ
            if (right - left + 1 >= k)
            {
                avg = sum / k;
                if (avg >= threshold) ret++;
                sum -= arr[left++];
            }
        }
        return ret;
    }
};
class Solution {
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int ret = 0;
    int maxVowels(string s, int k) {
        int n = s.size();
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            // ������
            if (isVowel(s[right])) count++;
            // �жϳ�
            if (right - left + 1 >= k)
            {
                ret = max(ret, count);
                if (isVowel(s[left++])) count--;
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++)
        {
            q.emplace(make_pair(nums[i], i));
        }
        vector<int> ans{ q.top().first };
        for (int i = k; i < n; i++)
        {
            q.emplace(make_pair(nums[i], i));
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
int main()
{
    int a = 10;
    cout << a << endl;
    return 0;
}