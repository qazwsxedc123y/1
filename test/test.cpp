#define  _CRT_SECURE_NO_WARNINGS
////
//
////
////class Solution {
////public:
////    string toHex(int num) {
////        if (num == 0)
////        {
////            return "0";
////        }
////        string s;
////        for (int i = 7; i >= 0; i--)
////        {
////            int val = (num >> (i * 4)) & 0xf;
////            char digit;
////            if (s.size() != 0 || val > 0)
////            {
////                digit = val < 10 ? (char)'0' + val : (char)'a' + val - 10;
////                s.push_back(digit);
////            }
////        }
////        return s;
////    }
////};
////
////int main()
////{
////    int val = (-1 >> (7 * 4)) & 0xf;
////    cout << ( - 1 >> (7 * 4)) << endl;
////    cout << val << endl;
////    memmove()
////}
//
//
//
////#include<iostream>
////#include<vector>
////#include <algorithm>
////using namespace std;
////
////class A
////{
////protected:
////	int _a;
////};
////
////class B : virtual public A
////{
////protected:
////	int _b;
////};
////
////class C : virtual public A
////{
////protected:
////	int _c;
////};
////
////class D :public B, public C
//////class D 
////{
////protected:
////	int _d;
////};
////int main()
////{
////	cout << sizeof(D) << endl;
////	return 0;
////}
//
//
//#include<iostream>
//using namespace std;
//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//
////class B :virtual public A
//class B : public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C : public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D : public C, public B
//{
//public:
//	//D(const char* s1, const char* s2, const char* s3, const char* s4) 
//	//	:B(s1, s2)
//	//	, C(s1, s3)
//	//	, A(s1)
//	//{
//	//	cout << s4 << endl;
//	//}
//
//	D(const char* s1, const char* s2, const char* s3, const char* s4)
//		:B(s1, s2)
//		, C(s1, s3)
//	{
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
    }
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k)
    {
        //舍弃k/2个
        //结束条件k==1
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        //让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
        if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        //还存在一种情况，就是k不为1的情况下，但len1已经等于0
        if (len1 == 0)
        {
            return nums2[start2 + k - 1];
        }
        if (k == 1)
            return min(nums1[start1], nums2[start2]);
        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;
        if (nums1[i] > nums2[j])
        {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
        else
        {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};



//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//	{
//		size_t n = nums1.size();
//		size_t m = nums2.size();
//		if (m == 0)
//		{
//			if (n % 2 == 0)
//				return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
//			else
//				return nums1[n / 2];
//		}
//		if (n == 0)
//		{
//			if (m % 2 == 0)
//				return (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
//			else
//				return nums2[m / 2];
//		}
//		size_t sum = m + n;
//		int* nums = new int[m + n];
//		int count = 0, i = 0, j = 0;
//		while (count != sum)
//		{
//			if (i == n)
//			{
//				while (j != m)
//					nums[count++] = nums2[j++];
//				break;
//			}
//			if (j == m)
//			{
//				while (i != n)
//					nums[count++] = nums1[i++];
//				break;
//			}
//			if (nums1[i] > nums2[j])
//				nums[count++] = nums2[j++];
//			else
//				nums[count++] = nums1[i++];
//		}
//		if (count % 2 == 0)
//			return (nums[count / 2 - 1] + nums[count / 2]) / 2.0;
//		else
//			return nums[count / 2];
//	}
//};

//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int m = nums1.size();
//        int n = nums2.size();
//        int len = m + n;
//        int left = -1, right = -1;
//        int aStart = 0, bStart = 0;
//        for (int i = 0; i <= len / 2; i++) {
//            left = right;
//            //调整right
//            if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
//                right = nums1[aStart++];
//            }
//            else {
//                right = nums2[bStart++];
//            }
//        }
//        if ((len % 2) == 0)
//            return (left + right) / 2.0;
//        else
//            return right;
//    }
//};

int main()
{
	vector<int> s1;
	vector<int> s2;
	s1.push_back(1);
	s1.push_back(2);

    s2.push_back(3);
    s2.push_back(4);
    s2.push_back(5);
	s2.push_back(6);
	Solution s;
	cout << s.findMedianSortedArrays(s1, s2) << endl;
	return 0;
}