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


//int main() {
//    int n, q;
//    cin >> n >> q;
//    vector<int> v(n + 1);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> v[i];
//    }
//    vector<long long> dp(n + 1);
//    for (int i = 1; i <= n; i++)
//    {
//        dp[i] = dp[i - 1] + v[i];
//    }
//    int l = 0, r = 0;
//    while (q--)// ��ѯq��
//    {
//        cin >> l >> r;
//        // ��ѯ
//        // �����
//        long long ret = dp[r] - dp[l - 1];
//        cout << ret << endl;
//    }
//    return 0;
//}
// 64 λ������� printf("%lld")

//int main() {
//    int n, m, q;
//    cin >> n >> m >> q;
//    vector<vector<int>> v(n + 1, vector<int>(m + 1));
//    // ����
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> v[i][j];
//        }
//    }
//    int x1, x2, y1, y2;
//    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            dp[i][j] = v[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//    while (q--)// ��ѯq��
//    {
//        // ��������
//        cin >> x1 >> y1 >> x2 >> y2;
//        // ��ǰ׺��
//        // �����
//        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
//    }
//    return 0;
//}
//// 64 λ������� printf("%lld")

//class Solution {
//public:
//    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        int n = arr.size();
//        int t = 0;// tΪ���һ��С��x�������±�
//        for (auto& e : arr)
//        {
//            if (e < x)
//            {
//                t++;
//            }
//            else break;
//        }
//        int left = t - 1, right = t;
//        while (k--)
//        {
//            if (left < 0) right++;
//            else if (right >= n) left--;
//            else if (x - arr[left] <= arr[right] - x) left--;
//            else right++;
//        }
//        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
//    }
//};

//class Solution {
//public:
//    vector<int> getStrongest(vector<int>& arr, int k) {
//        int n = arr.size();
//        sort(arr.begin(), arr.end());
//        int mid = arr[(n - 1) / 2];
//        vector<int> ret;
//        int left = 0, right = n - 1;
//        while (k--)
//        {
//            if (mid - arr[left] <= arr[right] - mid)
//            {
//                ret[k] = arr[right--];
//            }
//            else
//            {
//                ret[k] = arr[left++];
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<int> getStrongest(vector<int>& arr, int k) {
//        int n = arr.size();
//        sort(arr.begin(), arr.end());
//        int mid = arr[(n - 1) / 2];
//        vector<int> ret(k);
//        int left = 0, right = n - 1;
//        while (k--)
//        {
//            if (mid - arr[left] <= arr[right] - mid)
//            {
//                ret[k] = arr[right--];
//            }
//            else
//            {
//                ret[k] = arr[left++];
//            }
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int pivotIndex(vector<int>& nums) {
//        // ʹ��ǰ׺�����׺�� f  g
//        // �ֱ�������
//        // f[i] ��ʾ[0,i-1]�ĺ�
//        // g[i] ��ʾ[i+1,n-1] �ĺ�
//        int n = nums.size();
//        vector<int> f(n), g(n);
//        for (int i = 1; i < n; i++)
//            f[i] = f[i - 1] + nums[i - 1];
//        for (int i = n - 2; i >= 0; i--)
//            g[i] = g[i + 1] + nums[i + 1];
//        for (int i = 0; i < n; i++)
//        {
//            if (f[i] == g[i])
//                return i;
//        }
//        return -1;
//    }
//};

//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int n = nums.size();
//        // ����������һ��ǰ׺f��һ����׺g
//        // f[i] ��ʾ[0,i-1] �Ļ�
//        // g[i] ��ʾ[i+1,n-1] �Ļ�
//        vector<int> f(n), g(n);
//        f[0] = 1, g[n - 1] = 1;
//        for (int i = 1; i < n; i++)
//            f[i] = f[i - 1] * nums[i - 1];
//        for (int i = n - 2; i >= 0; i--)
//            g[i] = g[i + 1] * nums[i + 1];
//        vector<int> ret(n);
//        for (int i = 0; i < n; i++)
//            ret[i] = f[i] * g[i];
//        return ret;
//    }
//};

//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//        // ���ù�ϣ��
//        // ��һ����ֵ��Ϊ�� ���ڶ���Ϊ����
//        unordered_map<int, int> hash;
//        // �����Ϊsum�ķ�Ϊ��������
//        // ǰ����Ϊsum-k   ��Ϊk
//        int sum = 0;
//        int ret = 0;
//        hash[0] = 1;
//        for (int i = 0; i < n; i++)
//        {
//            sum += nums[i];
//            if (hash.count(sum - k)) ret += hash[sum - k];
//            hash[sum]++;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int subarraysDivByK(vector<int>& nums, int k) {
//        // ͬ�ඨ��
//        // (a-b)/p=k...0  <=>  a%p=b%p
//        // (a+p*k)%p=a%p
//        // ���� % ���� = ����  ->��������Ϊ����  ������ % ���� + ������% ���� = ����
//        int sum = 0;
//        unordered_map<int, int> hash;
//        hash[0 % k] = 1; // 0 ����������� ���⴦������Ϊ0��һ��Ҳ����ʱ
//        // Ӧ�������������������֮��Ҳ����Ҫ��ʱ
//        // ��ֵ�� ��һ��Ϊ�ϳ���k���ֵ  �ڶ���Ϊ����
//        int ret = 0;
//        for (auto num : nums)
//        {
//            sum += num;
//            // sum%k = tmp%p
//            int t = (sum % k + k) % k;
//            if (hash.count(t)) ret += hash[t];
//            hash[t]++;
//        }
//        return ret;
//    }
//};

int main()
{
    Solution s;
    vector<int> v{ 1,2,3,4,5 };
    // s.findClosestElements(v, 4, 3);
    s.getStrongest(v, 2);
    return 0;
}