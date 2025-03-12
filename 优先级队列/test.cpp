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
//        priority_queue<int> heap; // ���������
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
//    // ����һ����СΪK��С����
//    // Ȼ�󷵻�ͷ
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
//    // С����  
//    // ������õ���less���� ������ < (С�ں�)
//    // С�����õ���greater������������ > (���ں�)
//    typedef pair<string, int> PSI;
//    struct cmp
//    {
//        bool operator()(const PSI& a, const PSI& b)
//        {
//            if (a.second == b.second) // ��ͬ���մ�ѵķ�ʽ
//            {
//                return a.first < b.first;
//            }
//            return a.second > b.second;
//        }
//    };
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        // ���ù�ϣ��ͳ��ÿ�����ʳ��ִ���
//        unordered_map<string, int> hash;
//        for (auto& s : words) hash[s]++;
//
//        // ���������
//        priority_queue<PSI, vector<PSI>, cmp> heap;
//        for (auto& psi : hash)
//        {
//            heap.push(psi);
//            if (heap.size() > k) heap.pop();
//        }
//        // ��ȡ
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
//    // ���������ѣ�left��Ϊ�����  right��ΪС����
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
//                // ���ұߣ��ұߵ�ͷ��ȥ���
//                right.push(num);
//                int tmp = right.top();
//                right.pop();
//            }
//        }
//        else
//        {
//            if (num <= left.top())
//            {
//                // ����ߣ���ߵ�ͷ��ȥ�ұ�
//                left.push(num);
//                int tmp = left.top();
//                left.pop();
//                right.push(tmp);
//            }
//            else
//            {
//                // ���ұ�
//                right.push(num);
//            }
//        }
//    }
//
//    double findMedian() {
//        if (left.size() == right.size())
//        {
//            // Ϊż�� ��λ��Ϊ���ߵ�ƽ��ֵ
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
//    // ���������ѣ�left��Ϊ�����  right��ΪС����
//    priority_queue<int> left;  // ��С��ϵΪ m == n �� m = n+1
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
//                // ���ұߣ��ұߵ�ͷ��ȥ���
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
//                // ����ߣ���ߵ�ͷ��ȥ�ұ�
//                left.push(num);
//                int tmp = left.top();
//                left.pop();
//                right.push(tmp);
//            }
//            else
//            {
//                // ���ұ�
//                right.push(num);
//            }
//        }
//    }
//
//    double findMedian() {
//        if (left.size() == right.size())
//        {
//            // Ϊż�� ��λ��Ϊ���ߵ�ƽ��ֵ
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