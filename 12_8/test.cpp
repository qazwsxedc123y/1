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

using namespace std;

//class Solution {
//public:
//    vector<int> constructTransformedArray(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> result(n);
//        for (int i = 0; i < n; i++) {
//            if (nums[i] == 0) result[i] = 0;
//            else if (nums[i] > 0) {
//                // 向右移动nums[i] 步
//                long long x = i + nums[i];
//                int t = nums[x % n];
//                result[i] = t;
//            }
//            else {
//                long long x = i + nums[i] + n;
//                int t = nums[x % n];
//                result[i] = t;
//            }
//        }
//        return result;
//    }
//};
//
//class Solution {
//public:
//    long long maxSubarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<long long> dp(n + 1, 0);
//        for (int i = 0; i < n; i++) {
//            dp[i + 1] = dp[i] + nums[i];
//        }
//        long long max_sum = LLONG_MIN;
//        unordered_map<int, int> hash;
//        hash[0] = 0;
//        long long ret;
//        for (int i = 1; i <= n; i++) {
//            int t = dp[i] % k;
//            if (t < 0) {
//                t += k;
//            }
//            if (hash.find(t) != hash.end()) {
//                int prev_index = hash[t];
//                int length = i - prev_index;
//
//                if (length % k == 0) {
//                    long long subarray_sum = dp[i] - dp[prev_index];
//                    max_sum = max(max_sum, subarray_sum);
//                }
//            }
//
//            // 将当前前缀和余数和其索引存入哈希表
//            hash[t] = i;
//        }
//        return max_sum;
//    }
//}; 
//
//class Solution {
//public:
//    long long maxSubarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//        const long long INF = 1e18;
//        // mn[x] 表示 mod k = x 的下标出现过的最小前缀和
//
//        long long mn[k];
//        for (int i = 0; i < k; i++) mn[i] = INF;
//        mn[k - 1] = 0;//因为 0 % K 的前缀和应该从 0 开始。
//        long long ans = -INF, sm = 0;
//        for (int i = 0; i < n; i++)
//        {
//            sm += nums[i];
//            ans = max(ans, sm - mn[i % k]);
//            mn[i % k] = min(mn[i % K], sm);
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    long long maxSubarraySum(vector<int>& nums, int K) {
//        int n = nums.size();
//
//        const long long INF = 1e18;
//        // mn[x] 表示 mod k = x 的下标出现过的最小前缀和
//        long long mn[K];
//        for (int i = 0; i < K; i++) mn[i] = INF;
//        mn[K - 1] = 0;
//
//        long long ans = -INF, sm = 0;
//        // 枚举子数组右端点
//        for (int i = 0; i < n; i++) {
//            sm += nums[i];
//            ans = max(ans, sm - mn[i % K]);
//            mn[i % K] = min(mn[i % K], sm);
//        }
//        return ans;
//    }
//};

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int K) {
        int n = nums.size();
        const long long INF = 1e18;
        // mn[x] 表示 mod k = x 的下标出现过的最小前缀和

        vector<long long> mn(K);
        for (int i = 0; i < K; i++) mn[i] = INF;
        mn[K - 1] = 0;//因为 0 % K 的前缀和应该从 0 开始。
        long long ans = -INF, sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += nums[i];
            ans = max(ans, sm - mn[i % K]);
            mn[i % K] = min(mn[i % K], sm);
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> v{ 1,2};
    s.maxSubarraySum(v, 1);
    return 0;
}