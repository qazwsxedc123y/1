#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
using namespace std;

class Point_x_y
{
public:
	void Display()
	{
		cout << "x=" << x << " ";
		cout << "y=" << y << " ";
	}
	~Point_x_y()
	{
		cout << "~Point_x_y()" << endl;
	}
	int x;
	int y;
};
class Point_x_y_z : public Point_x_y
{
public:
	Point_x_y_z(int _z)
		:z(_z)
	{}
	void Display()
	{
		Point_x_y::Display();
		cout << "z=" << z << endl;
	}
protected:
	int z;
};
//int main()
//{
//	Point_x_y_z point_xyz(13);
//	point_xyz.x = 11;
//	point_xyz.y = 12;
//	return 0;
//}

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> f(m, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			f[0][i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			f[i][0] = 1;
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
		return f[m - 1][n - 1];
	}
};
int main()
{
	Solution s;
	cout<<s.uniquePaths(3, 7);
	return 0;
}




//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		long long ans = 1;
//		for (int x = n, y = 1; y < m; ++x, ++y)
//		{
//			ans = ans * x / y;
//		}
//		return ans;
//
//	}
//};

//class Node {
//public:
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//
//    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val, Node* _left, Node* _right, Node* _next)
//        : val(_val), left(_left), right(_right), next(_next) {}
//};
//class Solution {
//public:
//    Node* connect(Node* root) {
//        if (!root) {
//            return nullptr;
//        }
//        queue<Node*> q;
//        q.push(root);
//        while (!q.empty()) {
//            int n = q.size();
//            Node* last = nullptr;
//            for (int i = 1; i <= n; ++i) 
//            {
//                Node* f = q.front();
//                q.pop();
//                if (f->left) {
//                    q.push(f->left);
//                }
//                if (f->right) {
//                    q.push(f->right);
//                }
//                if (i != 1) {
//                    last->next = f;
//                }
//                last = f;
//            }
//        }
//        return root;
//    }
//};


//class Solution {
//public:
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		if (intervals.size() == 0) {
//			return {};
//		}
//		sort(intervals.begin(), intervals.end());
//		vector<vector<int>> ret;
//		for (int i = 0; i < intervals.size(); i++)
//		{
//			int L = intervals[i][0], R = intervals[i][1];
//			if (ret.empty() || ret.back()[1] < L)
//			{
//				ret.push_back({ L,R });
//			}
//			else
//			{
//				ret.back()[1] = max(ret.back()[1], R);
//			}
//		}
//		return ret;
//	}
//};
//class Solution {
//public:
//    vector<string> stringSequence(string target) {
//        vector<string> ret;
//        int n = target.size();
//        string tmp;
//        int j = 0;
//        for (int i = 0; i < n; i++)
//        {
//            char ch = 'a';
//            ret.push_back(tmp + ch);
//            while (target[j] != ch)
//            {
//                ch++;
//                ret.push_back(tmp + ch);
//            }
//            j++;
//            tmp = tmp + ch;
//        }
//        int m = ret.size();
//        for (int i = 0; i < m; i++)
//        {
//            cout << ret[i] << " ";
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    vector<string> stringSequence(string target) {
//        vector<string> ret;
//        int n = target.size();
//        string tmp;
//        int j = 0;
//        for (int i = 0; i < n; i++)
//        {
//            char ch = 'a';
//            ret.push_back(tmp + ch);
//            while (target[j] != ch)
//            {
//                ch++;
//                ret.push_back(tmp + ch);
//            }
//            j++;
//            tmp = tmp + ch;
//        }
//        int m = ret.size();
//        for (int i = 0; i < m; i++)
//        {
//            cout << ret[i] << " ";
//        }
//        return ret;
//    }
//};
//// 函数: 找到 n 的最大真因数  
//int max_proper_divisor(int n) {
//    for (int i = n - 1; i > 0; --i) {
//        if (n % i == 0) {
//            return i;
//        }
//    }
//    return -1;  // 返回 -1，表示没有真因数  
//}
//
//// 函数: 将 nums 数组转换为非递减所需的最少操作次数  
//int minOperations(vector<int>& nums) 
//{
//    int n = nums.size();
//    int operations = 0;
//
//    // 从倒数第二个元素开始处理到第一个  
//    for (int i = n - 2; i >= 0; --i) {
//        while (nums[i] > nums[i + 1]) {
//            int divisor = max_proper_divisor(nums[i]);
//            if (divisor == -1) {  // 如果没有真因数，无法继续操作  
//                return -1;
//            }
//
//            nums[i] /= divisor;
//            operations++;
//
//            if (nums[i] == 0) {  // 如果当前元素变为 0，停止操作  
//                return -1;
//            }
//        }
//    }
//
//    return operations;
//}
//class Solution {
//public:
//    string countAndSay(int n) {
//        string prev = "1";
//        for (int i = 2; i <= n; i++)
//        {
//            string cur = "";
//            int start = 0;
//            int pos = 0;
//            while (pos < prev.size())
//            {
//                while (pos < prev.size() && prev[pos] == prev[start])
//                {
//                    pos++;
//                }
//                cur += to_string(pos - start) + prev[start];
//                start = pos;
//            }
//            prev = cur;
//        }
//        return prev;
//    }
//};
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int mx = 0;
//        int n = nums.size();
//        int end = 0;
//        int ret = 0;
//        for (int i = 0; i < n - 1; i++) {
//            if (mx >= i) {
//                mx = max(mx, i + nums[i]);
//                if (i == end) {
//                    ret++;
//                    end = mx;
//                }
//            }
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    void dfs(vector<vector<int>>& ret, vector<int>& v, vector<int>& nums) {
//        if (v.size() == nums.size())
//        {
//            ret.push_back(v);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (find(v.begin(), v.end(), nums[i]) == v.end())
//            {
//                v.push_back(nums[i]);
//                dfs(ret, v, nums);
//                v.pop_back();
//            }
//        }
//    }
//
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> ret;
//        vector<int> v;
//        dfs(ret, v, nums);
//        return ret;
//    }
//};

//class Solution {
//public:
//    void dfs(vector<vector<int>>& ret, vector<int>& v, vector<int>& nums) {
//        if (nums.size() == v.size()) {
//            ret.push_back(v);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (i == 1)
//            {
//                int a;
//            }
//            if (find(v.begin(), v.end(), nums[i]) == v.end()) {
//                v.push_back(nums[i]);
//                dfs(ret, v, nums);
//                v.pop_back();
//            }
//        }
//    }
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> ret;
//        vector<int> v;
//        dfs(ret, v, nums);
//        return ret;
//    }
//};

//int main()
//{
//    //string s{ "abc" };
//    vector<int> v{ 1,2,3 };
//    Solution a;
//    a.permute(v);
//    return 0;
//}

//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//        {
//            return head;
//        }
//        ListNode* newhead = head->next;
//        head->next = swapPairs(newhead->next);
//        newhead->next = head;
//        return newhead;
//    }
//};


//class Solution {
//public:
//    void backtrack(vector<string>& ans, string& cur, int open, int close, int n)
//    {
//        if (cur.size() == n * 2)
//        {
//            ans.push_back(cur);
//            return;
//        }
//        if (n > open)
//        {
//            cur.push_back('(');
//            backtrack(ans, cur, open + 1, close, n);
//            cur.pop_back();
//        }
//        if (open > close)
//        {
//            cur.push_back(')');
//            backtrack(ans, cur, open, close + 1, n);
//            cur.pop_back();
//        }
//    }
//    vector<string> generateParenthesis(int n) {
//        //在原已经是的情况下，添加（），（一定在）左边
//        vector<string> result;
//        string current;
//        backtrack(result, current, 0, 0, n);
//        return result;
//    }
//};

//class Solution {
//    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
//        if (cur.size() == n * 2) {
//            ans.push_back(cur);
//            return;
//        }
//        if (open < n) {
//            cur.push_back('(');
//            backtrack(ans, cur, open + 1, close, n);
//            cur.pop_back();
//        }
//        if (close < open) {
//            cur.push_back(')');
//            backtrack(ans, cur, open, close + 1, n);
//            cur.pop_back();
//        }
//    }
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> result;
//        string current;
//        backtrack(result, current, 0, 0, n);
//        return result;
//    }
//};

//int main()
//{
//    Solution s;
//    s.generateParenthesis(3);
//    return 0;
//}


////**
// //* Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
// //*/
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        // 快慢指针
//        int tmp = n;
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while (tmp--)
//        {
//            fast = fast->next;
//        }
//        ListNode* pre = nullptr;
//        while (fast)
//        {
//            pre = slow;
//            slow = slow->next;
//            fast = fast->next;
//        }
//        ListNode* _next = slow->next;
//        // 删除slow
//        if (pre == nullptr)
//        {
//            head = head->next;
//        }
//        else
//        {
//            pre->next = _next;
//        }
//        return head;
//    }
//};