#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <queue>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        // 两边之和大于第三边，两边之差小于第三边
//        // 模拟
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                int left = j + 1, right = n - 1, k = j;
//                while (left <= right)
//                {
//                    int mid = (left + right) / 2;
//                    if (nums[mid] < nums[i] + nums[j])
//                    {
//                        // 在右边
//                        k = mid;
//                        left = mid + 1;
//                    }
//                    else
//                    {
//                        right = mid - 1;
//                    }
//                }
//                ans += k - j;
//            }
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        // 两边之和大于第三边，两边之差小于第三边
//        // 模拟
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int k = i;
//            for (int j = i + 1; j < n; j++)
//            {
//                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j])
//                {
//                    k++;
//                }
//                ans += max(k - j, 0);
//            }
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    string simplifyPath(string path) {
//        // 从左向右遍历
//        // 如果是 .. 上一路径
//        // . 不用管
//        // 最后不能以 / 收尾
//        int n = path.size();
//        string ret;
//        for (int i = 0; i < n; i++) {
//            if (path[i] == '/') {
//                // 合并/
//                while (i + 1 < n && path[i + 1] == '/')
//                    i++;
//                if (ret.empty() || ret.back() != '/') {
//                    ret += '/';
//                }
//            }
//
//            else if (path[i] == '.') {
//                // 开始查有几个 .
//                int count = 1;
//                int k = i + 1;
//                while (k < n && path[k] == '.') {
//                    count++;
//                    k++;
//                }
//                if ((k == n || path[k] == '/') && ret.back() == '/' && count <= 2)
//                {
//                    if (count == 1)
//                    {
//                        // 啥都不需要做
//                        if (i + 1 < n)
//                            i++;
//                    }
//                    else if (count == 2)
//                    {
//                        // 向前删 ..
//                        ///.../a/
//                        // 删除到两个 / 停止
//                        if (!ret.empty() && ret != "/")
//                        {
//                            // 删除当前目录
//                            if (ret.back() == '/')
//                                ret.pop_back();
//                            // 找到前一个斜杠
//                            while (!ret.empty() && ret.back() != '/')
//                            {
//                                ret.pop_back();
//                            }
//                            if (ret.empty())
//                                ret = "/";
//                        }
//                    }
//                }
//                else
//                {
//                    // 添加
//                    ret.append(count, '.');
//                }
//                i = k - 1;
//            }
//            else
//                ret += path[i];
//        }
//        while (ret.size() > 1 && ret.back() == '/')
//            ret.pop_back();
//        if (ret.size() == 0)
//            ret.push_back('/');
//        return ret;
//    }
//};


//class Solution {
//public:
//    double largestTriangleArea(vector<vector<int>>& points) {
//        // S = 1/2 * |(x2 - x1) * (y3-y1) - (y2 - y1) * (x3 - x1)|
//        // 暴力
//        int n = points.size();
//        double ret = 0;
//        for (int i = 0; i < n; i++) // 1
//        {
//            for (int j = i + 1; j < n; j++) // 2
//            {
//                for (int m = j + 1; m < n; m++) // 3
//                {
//                    double s = std::abs((points[j][0] - points[i][0]) * (points[m][1] - points[i][1])
//                        - (points[j][1] - points[i][1]) * (points[m][0] - points[i][0])) / 2.0;
//                    ret = max(ret, s);
//                }
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int largestPerimeter(vector<int>& nums) {
//        // 排序后，只需保证两边之和大于第三边即可
//        sort(nums.begin(), nums.end(), greater<int>());
//        int n = nums.size();
//        int ret = 0;
//        for (int i = 0; i < n; i++) // 最大
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                if (j != i + 1) break;
//                for (int m = j + 1; m < n; m++)
//                {
//                    if (nums[i] < nums[j] + nums[m])
//                    {
//                        return nums[i] + nums[j] + nums[m];
//                    }
//                    else break;
//                }
//            }
//        }
//        return 0;
//    }
//};


//class Solution {
//public:
//    int largestPerimeter(vector<int>& nums) {
//        // 排序后，只需保证两边之和大于第三边即可
//        sort(nums.begin(), nums.end(), greater<int>());
//        int n = nums.size();
//        int ret = 0;
//        for (int i = 0; i < n - 2; i++) // 最大
//        {
//            if (nums[i] < nums[i + 1] + nums[i + 2]) return nums[i] + nums[i + 1] + nums[i + 2];
//        }
//        return 0;
//    }
//};

int main()
{
    //Solution s;
    //string str = "/a/./b/../../c/";
    //s.simplifyPath(str);
	return 0;
}