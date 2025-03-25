#define  _CRT_SECURE_NO_WARNINGS


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//    long pre = LONG_MIN; // ����ΪINT_MIN��������С����Ϊ���ڵ����ڵ�-2^31 -> -2147483648
//public:
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) return true;
//
//        // ���Ϊ��������������ô�������Ϊ����
//        bool left = isValidBST(root->left);
//        // ��֦
//        if (left == false) return false;
//
//        bool falg = true;
//        if (root->val <= pre) {
//            falg = false;
//        }
//        pre = root->val;
//        // ��֦
//        if (falg == false) return false;
//        bool right = isValidBST(root->right);
//
//        return left && right && falg;
//    }
//};


//class Solution {
//    int ret;
//    int cur = 0;
//public:
//    int subsetXORSum(vector<int>& nums) {
//        dfs(nums, 0);
//        return ret;
//    }
//    void dfs(vector<int>& nums, int pos) {
//        ret += cur;
//        for (int i = pos; i < nums.size(); i++) {
//            cur ^= nums[i];
//            dfs(nums, i + 1);
//            // �ָ� cur ��ֵ
//            cur ^= nums[i];
//        }
//    }
//};


//class Solution {
//    int ret;
//    int cur = 0;
//public:
//    int subsetXORSum(vector<int>& nums) {
//        dfs(nums, 0);
//        return ret;
//    }
//    void dfs(vector<int>& nums, int pos) {
//        if (pos == nums.size())
//        {
//            ret += cur;
//            return;
//        }
//
//        // ѡ
//        cur ^= nums[pos];
//        dfs(nums, pos + 1);
//        cur ^= nums[pos];
//
//        // ��ѡ
//        dfs(nums, pos + 1);
//    }
//};


//class Solution {
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[8];
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        dfs(nums);
//        return ret;
//    }
//    void dfs(vector<int>& nums) {
//        if (path.size() == nums.size()) {
//            if (find(ret.begin(), ret.end(), path) == ret.end())
//                ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (check[i] == false) {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs(nums);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//};


//class Solution {
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[8];
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        dfs(nums);
//        return ret;
//    }
//    void dfs(vector<int>& nums) {
//        if (path.size() == nums.size()) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true))
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs(nums);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//};


//class Solution {
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[8];
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        dfs1(nums);
//        return ret;
//    }
//    // ͬһ���ڵ�����з�֧�У���ͬ��Ԫ��ֻ��ѡһ��
//    // ͬһ����ֻ��ʹ��һ��
//    // ֻ���� �Ϸ� �ķ�֧
//    void dfs1(vector<int>& nums) {
//        if (path.size() == nums.size()) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true))
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs1(nums);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//
//    // ֻ���� ���Ϸ� �ķ�֧ 
//    void dfs2(vector<int>& nums) {
//        if (path.size() == nums.size()) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            // ���Ϸ�
//            if (check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == true)) {
//                continue;
//            }
//            else
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs1(nums);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//};


//class Solution {
//    unordered_map<char, string> ph{
//        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
//        {'7', "pqrs"}, {'8', "tuv"},{'9', "wxyz"}
//    };
//    vector<string> ret;
//    string path;
//public:
//    vector<string> letterCombinations(string digits) {
//        if (digits.empty()) return ret;
//        dfs(digits, 0);
//        return ret;
//    }
//    void dfs(string& digits, int pos) {
//        if (pos == digits.size()) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < ph[digits[pos]].size(); i++) {
//            path.push_back(ph[digits[pos]][i]);
//            dfs(digits, pos + 1);
//            path.pop_back();
//        }
//    }
//};


//class Solution {
//    vector<string> ret;
//    string path;
//public:
//    vector<string> generateParenthesis(int n) {
//        dfs(n, 0, 0);
//        return ret;
//    }
//    void dfs(int n, int open, int close) {
//        if (path.size() == n * 2) {
//            ret.push_back(path);
//            return;
//        }
//        if (n > open) {
//            path.push_back('(');
//            dfs(n, open + 1, close);
//            path.pop_back();
//        }
//        if (open > close) {
//            path.push_back(')');
//            dfs(n, open, close + 1);
//            path.pop_back();
//        }
//    }
//};


//class Solution {
//    vector<vector<int>> ret;
//    vector<int> path;
//public:
//    vector<vector<int>> combine(int n, int k) {
//        dfs(n, k, 1);
//        return ret;
//    }
//    void dfs(int n, int k, int pos) {
//        if (path.size() == k) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = pos; i <= n; i++) {
//            path.push_back(i);
//            dfs(n, k, i + 1);
//            path.pop_back();
//        }
//    }
//};


//class Solution {
//    int ret;
//    int sum;
//    int t;
//
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        t = target;
//        dfs(nums, 0);
//        return ret;
//    }
//    void dfs(vector<int>& nums, int pos) {
//        if (pos == nums.size()) {
//            if (sum == t)
//                ret++;
//            return;
//        }
//        // +
//        sum += nums[pos];
//        dfs(nums, pos + 1);
//        sum -= nums[pos];
//
//        // -
//        sum -= nums[pos];
//        dfs(nums, pos + 1);
//        sum += nums[pos];
//    }
//};


//class Solution {
//    vector<vector<int>> ret;
//    vector<int> path;
//    int sum;
//    int t;
//
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        t = target;
//        sort(candidates.begin(), candidates.end());
//        dfs(candidates, 0);
//        return ret;
//    }
//    void dfs(vector<int>& candidates, int pos) {
//        if (sum >= t) {
//            if (sum == t) {
//                ret.push_back(path);
//            }
//            return;
//        }
//        for (int i = pos; i < candidates.size(); i++) {
//            path.push_back(candidates[i]);
//            sum += candidates[i];
//            dfs(candidates, i);
//            sum -= candidates[i];
//            path.pop_back();
//        }
//    }
//};


//class Solution {
//    vector<vector<int>> ret;
//    vector<int> path;
//    int sum;
//    int t;
//
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        t = target;
//        //dfs1(candidates, 0);
//        dfs2(candidates, 0, 0);
//        return ret;
//    }
//    void dfs1(vector<int>& candidates, int pos) {
//        if (sum >= t) {
//            if (sum == t) {
//                ret.push_back(path);
//            }
//            return;
//        }
//        for (int i = pos; i < candidates.size(); i++) {
//            path.push_back(candidates[i]);
//            sum += candidates[i];
//            dfs1(candidates, i);
//            sum -= candidates[i];
//            path.pop_back();
//        }
//    }
//
//    // �ڶ���д�������Ե������ĸ�����д
//    void dfs2(vector<int>& candidates, int pos, int cursum) {
//
//        if (cursum == t) {
//            ret.push_back(path);
//            return;
//        }
//        if (cursum > t || pos == candidates.size()) return;
//
//        for (int k = 0; k * candidates[pos] <= t; k++) {
//            if (k != 0) path.push_back(candidates[pos]);
//            dfs2(candidates, pos + 1, cursum + k * candidates[pos]);
//        }
//
//        for (int k = 1; k * candidates[pos] <= t; k++) {
//            path.pop_back();
//        }
//    }
//};


//class Solution {
//    vector<string> ret;
//    string path;
//
//public:
//    vector<string> letterCasePermutation(string s) {
//        dfs(s, 0);
//        return ret;
//    }
//    char change(char ch) {
//        if (ch >= 'A' && ch <= 'Z') ch += 32;
//        else ch -= 32;
//        return ch;
//    }
//    void dfs(string& s, int pos) {
//        if (pos == s.size()) {
//            ret.push_back(path);
//            return;
//        }
//        char ch = s[pos];
//
//        // ���ı�
//        path.push_back(s[pos]);
//        dfs(s, pos + 1);
//        path.pop_back();
//
//        // �ı�
//        if (ch < '0' || ch > '9') {
//            char tmp = change(ch);
//            path.push_back(tmp);
//            dfs(s, pos + 1);
//            path.pop_back();
//        }
//    }
//};


//class Solution {
//    int ret;
//    bool check[16];
//public:
//    int countArrangement(int n) {
//        dfs(n, 1);
//        return ret;
//    }
//    void dfs(int n, int pos) {
//        if (pos == n + 1) {
//            ret++;
//            return;
//        }
//        for (int i = 1; i <= n; i++) {
//            if (check[i] == false && (pos % i == 0 || i % pos == 0)) {
//                check[i] = true;
//                dfs(n, pos + 1);
//                // ����
//                check[i] = false;
//            }
//        }
//    }
//};


//class Solution {
//    bool checkCol[10], checkDig1[20], checkDig2[20];
//    vector<vector<string>> ret;
//    vector<string> path;
//
//public:
//    vector<vector<string>> solveNQueens(int n) {
//        path.resize(n);
//        for (int i = 0; i < n; i++) {
//            // �Ƚ�����ȫ��Ϊ .
//            path[i].append(n, '.');
//        }
//        dfs(n, 0);
//        return ret;
//    }
//    void dfs(int n, int pos) {
//        if (pos == n) {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = 0; i < n; i++) {
//
//            // ������pos�е�i�з�һ���ʺ�
//            if (checkCol[i] == false
//                && checkDig1[pos - i + n] == false
//                && checkDig2[pos + i] == false)
//            {
//                checkCol[i] = true;
//                checkDig1[pos - i + n] = true;
//                checkDig2[pos + i] = true;
//                path[pos][i] = 'Q';
//                dfs(n, pos + 1);
//                path[pos][i] = '.';
//                checkCol[i] = false;
//                checkDig1[pos - i + n] = false;
//                checkDig2[pos + i] = false;
//            }
//
//            // ȫ���з���
//
//            // path[pos][i] = 'Q';
//            // dfs(n, pos + 1);
//            // path[pos][i] = '.';
//        }
//    }
//};


//class Solution {
//    vector<vector<string>> ret;
//    vector<string> path;
//    int n;
//public:
//    vector<vector<string>> solveNQueens(int _n) {
//        n = _n;
//        path.resize(n);
//        for (int i = 0; i < n; i++) {
//            // �Ƚ�����ȫ��Ϊ .
//            path[i].append(n, '.');
//        }
//        dfs(0);
//        return ret;
//    }
//    bool check(int row, int col) {
//        for (int i = 0; i < n; i++) {
//            if (path[i][col] == 'Q') {
//                return false;
//            }
//        }
//        // ���Խ���
//        // Сϸ�ڣ�ֻ��Ҫ���ǰ����о��У�������л�û�зŻʺ�
//        // ������Խ��ߣ����ϵ����£�
//        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//            if (path[i][j] == 'Q') {
//                return false;
//            }
//        }
//
//        // ��鸱�Խ��ߣ����ϵ����£�
//        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//            if (path[i][j] == 'Q') {
//                return false;
//            }
//        }
//        return true;
//    }
//    void dfs(int pos) {
//        if (pos == n) {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = 0; i < n; i++) {
//
//            // ������pos�е�i�з�һ���ʺ�
//            if (check(pos, i))
//            {
//                path[pos][i] = 'Q';
//                dfs(pos + 1);
//                path[pos][i] = '.';
//            }
//
//            // ȫ���з���
//
//            // path[pos][i] = 'Q';
//            // dfs(n, pos + 1);
//            // path[pos][i] = '.';
//        }
//    }
//};


//#include <iostream>
//bool Row[9][10];
//using namespace std;
//
//int main() 
//{
//	if (Row[1][1] == false) {
//		cout << "false" << endl;
//	}
//	return 0;
//}


//class Solution {
//    // ���ÿռ任ʱ��
//    // Ĭ�ϳ�ʼ��Ϊ0��Ҳ����false
//    bool Row[9][10]; // ���ô˼��ĳ���Ƿ����ظ���
//    bool Col[10][9]; // ���ô˼��ĳ���Ƿ����ظ���
//    bool grid[3][3][10]; // ���ô˼��ĳ���������е�С�����Ƿ����ظ���
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//        for (int i = 0; i < 9; i++) { // ��
//            for (int j = 0; j < 9; j++) { // ��
//                if (board[i][j] != '.') {
//                    int num = board[i][j] - '0';
//                    if (Row[i][num] || Col[num][j] || grid[i / 3][j / 3][num]) {
//                        return false;
//                    }
//                    Row[i][num] = true;
//                    Col[num][j] = true;
//                    grid[i / 3][j / 3][num] = true;
//                }
//            }
//        }
//        return true;
//    }
//};


//class Solution {
//    // ���ÿռ任ʱ��
//    // Ĭ�ϳ�ʼ��Ϊ0��Ҳ����false
//    bool Row[9][10];     // ���ô˼��ĳ���Ƿ����ظ���
//    bool Col[10][9];     // ���ô˼��ĳ���Ƿ����ظ���
//    bool grid[3][3][10]; // ���ô˼��ĳ���������е�С�����Ƿ����ظ���
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        for (int i = 0; i < 9; i++) {
//            for (int j = 0; j < 9; j++) {
//                if (board[i][j] != '.') {
//                    int num = board[i][j] - '0';
//                    Row[i][num] = true;
//                    Col[num][j] = true;
//                    grid[i / 3][j / 3][num] = true;
//                }
//            }
//        }
//        dfs(board, 0, 0);
//    }
//    bool dfs(vector<vector<char>>& board, int row, int col) {
//        if (row == 9) {
//            return true;
//        }
//        if (col == 9) {
//            return dfs(board, row + 1, 0);
//        }
//        // �����ǰ�����������֣�����
//        if (board[row][col] != '.') {
//            return dfs(board, row, col + 1);
//        }
//
//        for (int num = 1; num <= 9; num++)
//        {
//            if (!Row[row][num] && !Col[num][col] && !grid[row / 3][col / 3][num])
//            {
//                board[row][col] = '0' + num;
//                Row[row][num] = Col[num][col] = grid[row / 3][col / 3][num] = true;
//                if (dfs(board, row, col + 1) == true)
//                    return true;
//                // �ָ��ֳ�
//                board[row][col] = '.';
//                Row[row][num] = Col[num][col] = grid[row / 3][col / 3][num] = false;;
//            }
//        }
//        // 1-9ȫ�������ˣ�������
//        return false;
//    }
//};


//class Solution {
//    // ���ÿռ任ʱ��
//    // Ĭ�ϳ�ʼ��Ϊ0��Ҳ����false
//    bool Row[9][10];     // ���ô˼��ĳ���Ƿ����ظ���
//    bool Col[10][9];     // ���ô˼��ĳ���Ƿ����ظ���
//    bool grid[3][3][10]; // ���ô˼��ĳ���������е�С�����Ƿ����ظ���
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                if (board[i][j] != '.')
//                {
//                    int num = board[i][j] - '0';
//                    Row[i][num] = Col[num][j] = grid[i / 3][j / 3][num] = true;
//                }
//            }
//        }
//        dfs(board);
//    }
//    bool dfs(vector<vector<char>>& board) {
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                if (board[i][j] == '.')
//                {
//                    for (int num = 1; num <= 9; num++)
//                    {
//                        if (!Row[i][num] && !Col[num][j] && !grid[i / 3][j / 3][num])
//                        {
//                            board[i][j] = '0' + num;
//                            Row[i][num] = Col[num][j] = grid[i / 3][j / 3][num] = true;
//                            if (dfs(board) == true) return true;
//                            board[i][j] = '.';
//                            Row[i][num] = Col[num][j] = grid[i / 3][j / 3][num] = false;
//                        }
//                    }
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//};


//class Solution {
//    bool vis[7][7];
//    int m, n;
//public:
//    bool exist(vector<vector<char>>& board, string word) {
//        // m�� n��
//        m = board.size(), n = board[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (board[i][j] == word[0])
//                {
//                    vis[i][j] = true;
//                    if (dfs(board, i, j, word, 1)) return true;
//                    vis[i][j] = false;
//                }
//            }
//        }
//        return false;
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos) {
//        if (pos == word.size())
//        {
//            return true;
//        }
//        // �ĸ���λ
//        // i-1,j   i+1,j    i,j-1    i,j+1
//        // Сϸ�ڣ��������ô����������飬��������x��y
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == word[pos]) {
//                vis[x][y] = true;
//                if (dfs(board, x, y, word, pos + 1)) return true;
//                vis[x][y] = false;
//            }
//        }
//        return false;
//    }
//};


//class Solution {
//    int ret = 0;
//    int sum = 0;
//    int m, n;
//    bool vis[15][15];
//public:
//    int getMaximumGold(vector<vector<int>>& grid) {
//        // m�� n��
//        m = grid.size(), n = grid[0].size();
//        // ���û���������ô(0, 0) ��ʼ DFS�����grid[0][0] == 0��DFS ��ֱ�ӽ���
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] != 0)
//                { // �����з�����ӿ�ʼDFS
//                    vis[i][j] = true;
//                    sum += grid[i][j];
//                    dfs(grid, i, j);
//                    sum -= grid[i][j];
//                    vis[i][j] = false;
//                }
//            }
//        }
//        return ret;
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void dfs(vector<vector<int>>& grid, int i, int j) {
//        if (sum > ret) {
//            ret = sum;
//            // ���ֱ�ӷ��أ�����ֹ��ǰ·���ļ���̽�������ܴ�����Ž⡣
//        }
//
//        // �ĸ���λ
//        // i-1,j   i+1,j    i,j-1    i,j+1
//        // Сϸ�ڣ��������ô����������飬��������x��y
//        for (int k = 0; k < 4; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0 && !vis[x][y]) {
//                vis[x][y] = true;
//                sum += grid[x][y];
//                dfs(grid, x, y);
//                sum -= grid[x][y];
//                vis[x][y] = false;
//            }
//        }
//    }
//};