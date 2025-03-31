#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int halveArray(vector<int>& nums) {
//        // 贪心，每次都去将最大的值去减半
//        // 利用大根堆去写
//        priority_queue<double> pq(nums.begin(), nums.end());
//        int ret = 0;
//        double sum = accumulate(nums.begin(), nums.end(), 0.0);
//        sum /= 2.0;
//        while (sum > 0)
//        {
//            double x = pq.top();
//            pq.pop();
//            sum -= x / 2.0;
//            pq.push(x / 2.0);
//            ret++;
//        }
//        return ret;
//    }
//};