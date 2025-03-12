#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//class Solution {
//public:
//    int lastStoneWeight(vector<int>& stones) {
//        priority_queue<int> heap; // 创建大根堆
//        for (auto x : stones) heap.push(x);
//        while (heap.size() > 1)
//        {
//            int a = heap.top(); heap.pop();
//            int b = heap.top(); heap.pop();
//            if (a > b) heap.push(a - b);
//        }
//        return heap.size() ? heap.top() : 0;
//    }
//};


//class KthLargest {
//public:
//    // 创建一个大小为K的小根堆
//    // 然后返回头
//    priority_queue<int, vector<int>, greater<int>> q;
//    int k;
//    KthLargest(int k, vector<int>& nums) {
//        this->k = k;
//        for (auto x : nums)
//        {
//            add(x);
//        }
//    }
//
//    int add(int val) {
//        q.push(val);
//        if (q.size() > k)
//        {
//            q.pop();
//        }
//        return q.top();
//    }
//};
//
///**
// * Your KthLargest object will be instantiated and called as such:
// * KthLargest* obj = new KthLargest(k, nums);
// * int param_1 = obj->add(val);
// */


//class Solution {
//    // 小跟堆  
//    // 大根堆用的是less函数 其中用 < (小于号)
//    // 小根堆用的是greater函数，其中用 > (大于号)
//    typedef pair<string, int> PSI;
//    struct cmp
//    {
//        bool operator()(const PSI& a, const PSI& b)
//        {
//            if (a.second == b.second) // 相同按照大堆的方式
//            {
//                return a.first < b.first;
//            }
//            return a.second > b.second;
//        }
//    };
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        // 先用哈希表统计每个单词出现次数
//        unordered_map<string, int> hash;
//        for (auto& s : words) hash[s]++;
//
//        // 创建大跟堆
//        priority_queue<PSI, vector<PSI>, cmp> heap;
//        for (auto& psi : hash)
//        {
//            heap.push(psi);
//            if (heap.size() > k) heap.pop();
//        }
//        // 提取
//        vector<string> ret;
//        ret.resize(k);
//        for (int i = k - 1; i >= 0; i--)
//        {
//            ret[i] = heap.top().first;
//            heap.pop();
//        }
//        return ret;
//    }
//};


//class MedianFinder {
//public:
//    // 创建两个堆，left堆为大根堆  right堆为小根堆
//    priority_queue<int> left;
//    priority_queue<int, vector<int>, greater<int>> right;
//    MedianFinder() {
//
//    }
//
//    void addNum(int num) {
//        if (left.size() == right.size())
//        {
//            if (left.size() == 0 || num <= left.top())
//            {
//                left.push(num);
//            }
//            else
//            {
//                // 进右边，右边的头再去左边
//                right.push(num);
//                int tmp = right.top();
//                right.pop();
//            }
//        }
//        else
//        {
//            if (num <= left.top())
//            {
//                // 进左边，左边的头再去右边
//                left.push(num);
//                int tmp = left.top();
//                left.pop();
//                right.push(tmp);
//            }
//            else
//            {
//                // 进右边
//                right.push(num);
//            }
//        }
//    }
//
//    double findMedian() {
//        if (left.size() == right.size())
//        {
//            // 为偶数 中位数为二者的平均值
//            double tmp = left.top() + right.top();
//            return tmp / 2;
//        }
//        else {
//            return (double)left.top();
//        }
//    }
//};
//
///**
// * Your MedianFinder object will be instantiated and called as such:
// * MedianFinder* obj = new MedianFinder();
// * obj->addNum(num);
// * double param_2 = obj->findMedian();
// */
//
//
//class MedianFinder {
//public:
//    // 创建两个堆，left堆为大根堆  right堆为小根堆
//    priority_queue<int> left;  // 大小关系为 m == n 或 m = n+1
//    priority_queue<int, vector<int>, greater<int>> right;
//    MedianFinder() {
//
//    }
//
//    void addNum(int num) {
//        if (left.size() == right.size())
//        {
//            if (left.size() == 0 || num <= left.top())
//            {
//                left.push(num);
//            }
//            else
//            {
//                // 进右边，右边的头再去左边
//                right.push(num);
//                int tmp = right.top();
//                right.pop();
//                left.push(tmp);
//            }
//        }
//        else
//        {
//            if (num <= left.top())
//            {
//                // 进左边，左边的头再去右边
//                left.push(num);
//                int tmp = left.top();
//                left.pop();
//                right.push(tmp);
//            }
//            else
//            {
//                // 进右边
//                right.push(num);
//            }
//        }
//    }
//
//    double findMedian() {
//        if (left.size() == right.size())
//        {
//            // 为偶数 中位数为二者的平均值
//            return (left.top() + right.top()) / 2.0;
//        }
//        else {
//            return (double)left.top();
//        }
//    }
//};
//
///**
// * Your MedianFinder object will be instantiated and called as such:
// * MedianFinder* obj = new MedianFinder();
// * obj->addNum(num);
// * double param_2 = obj->findMedian();
// */

int main()
{
    Solution s;
    vector<string> s1 = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    s.topKFrequent(s1,4);
	return 0;
}