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


//class Solution {
//    int ret;
//    int step;
//    int m, n;
//    int x1, y1;
//    bool vis[21][21];
//public:
//    int uniquePathsIII(vector<vector<int>>& grid) {
//        m = grid.size(), n = grid[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] == 0) step++;
//                else if (grid[i][j] == 1)
//                {
//                    x1 = i;
//                    y1 = j;
//                }
//            }
//        }
//        step += 2;
//        vis[x1][y1] = true;
//        dfs(grid, x1, y1, 1);
//        return ret;
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void dfs(vector<vector<int>>& grid, int i, int j, int count) {
//        if (grid[i][j] == 2) {
//            if (count == step) {
//                ret++;
//                return;
//            }
//        }
        //for (int k = 0; k < 4; k++) {
        //    int x = i + dx[k], y = j + dy[k];
        //    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != -1 && !vis[x][y]) {
        //        vis[x][y] = true;
        //        dfs(grid, x, y, count + 1);
        //        vis[x][y] = false;
        //    }
        //}
//    }
//};


//class Solution {
//    int n, m;
//    int color;
//    int ans;
//public:
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int _color) {
//        m = image.size();
//        if (m == 0) return image;
//        n = image[0].size();
//        color = _color;
//
//        ans = image[sr][sc];
//        image[sr][sc] = color;
//
//        if (ans == color) return image; // �ؼ��������������
//        dfs(image, sr, sc);
//        return image;
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void dfs(vector<vector<int>>& image, int i, int j) {
//        for (int k = 0; k < 4; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == ans) {
//                image[x][y] = color;
//                dfs(image, x, y);
//            }
//        }
//    }
//};


//class Solution {
//    int n, m;
//    // ��Ŀ����n�� m��Χ���Ϊ300����������飬���е��˷ѿռ�
//    // ���Կ�����vector
//    vector<vector<bool>> vis;
//    int ret;
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        m = grid.size(), n = grid[0].size();
//        vis = vector<vector<bool>>(m, vector<bool>(n));
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (!vis[i][j] && grid[i][j] == '1')
//                {
//                    ret++;
//                    dfs(grid, i, j);
//                }
//            }
//        }
//        return ret;
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void dfs(vector<vector<char>>& grid, int i, int j)
//    {
//        vis[i][j] = true;
//        for (int k = 0; k < 4; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y]) {
//                dfs(grid, x, y);
//            }
//        }
//    }
//};

//
//class Solution {
//    int m, n;
//
//public:
//    // ������
//    // �ȴ���߽����⣬Ȼ��ʣ�µ�oȫ��Ϊx�����
//    // Ȼ���ٻ�ԭ�߽�
//    void solve(vector<vector<char>>& board) {
//        m = board.size(), n = board[0].size();
//
//        // 1. �ѱ߽����ͨ�飬ȫ���� o ��Ϊ .
//        for (int j = 0; j < n; j++) {
//            if (board[0][j] == 'O')
//                dfs(board, 0, j);
//            if (board[m - 1][j] == 'O')
//                dfs(board, m - 1, j);
//        }
//        for (int i = 0; i < m; i++) {
//            if (board[i][0] == 'O')
//                dfs(board, i, 0);
//            if (board[i][n - 1] == 'O')
//                dfs(board, i, n - 1);
//        }
//
//        // �ٱ����������е� o ��Ϊ x ���ٸ�ԭ�߽缴���
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (board[i][j] == 'O')
//                    board[i][j] = 'X';
//                else if (board[i][j] == '.')
//                    board[i][j] = 'O';
//            }
//        }
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void dfs(vector<vector<char>>& board, int i, int j)
//    {
//        // ֻ���Ǵ�� 'O' ������Żᱻ����dfs��
//        board[i][j] = '.';
//        for (int k = 0; k < 4; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
//                dfs(board, x, y);
//            }
//        }
//    }
//};
// 

//
// class Solution {
//    int m, n;
//public:
//    // ������
//    // �ȴ���߽����⣬Ȼ��ʣ�µ�oȫ��Ϊx�����
//    // Ȼ���ٻ�ԭ�߽�
//    void solve(vector<vector<char>>& board) {
//        m = board.size(), n = board[0].size();
//
//        // 1. �ѱ߽����ͨ�飬ȫ���� o ��Ϊ .
//        for (int j = 0; j < n; j++) {
//            if (board[0][j] == 'O')
//                dfs(board, 0, j);
//            if (board[m - 1][j] == 'O')
//                dfs(board, m - 1, j);
//        }
//        for (int i = 0; i < m; i++) {
//            if (board[i][0] == 'O')
//                dfs(board, i, 0);
//            if (board[i][n - 1] == 'O')
//                dfs(board, i, n - 1);
//        }
//
//        // �ٱ����������е� o ��Ϊ x ���ٸ�ԭ�߽缴���
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (board[i][j] == 'O')
//                    board[i][j] = 'X';
//                else if (board[i][j] == '.')
//                    board[i][j] = 'O';
//            }
//        }
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void dfs(vector<vector<char>>& board, int i, int j)
//    {
//        // ֻ���Ǵ�� 'O' ������Żᱻ����dfs��
//        board[i][j] = '.';
//        for (int k = 0; k < 4; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
//                dfs(board, x, y);
//            }
//        }
//    }
//};


//class Solution {
//    int m, n;
    //int dx[4] = { 0, 0, -1, 1 };
    //int dy[4] = { -1, 1, 0, 0 };
//    vector<vector<int>> ret;
//    // ����
//    // �ֱ�ͳ���Ǹ�λ�ÿ������� ʲôʲô ��
//public:
//    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//        m = heights.size(), n = heights[0].size();
//
//        vector<vector<bool>> pac(m, vector<bool>(n));
//        vector<vector<bool>> atc(m, vector<bool>(n));
//
//        // �ȴ���̫ƽ��
//        for (int i = 0; i < m; i++) dfs(heights, i, 0, pac);
//        for (int j = 0; j < n; j++) dfs(heights, 0, j, pac);
//
//        // �ٴ��������
//        for (int i = 0; i < m; i++) dfs(heights, i, n - 1, atc);
//        for (int j = 0; j < n; j++) dfs(heights, m - 1, j, atc);
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (pac[i][j] && atc[i][j])
//                {
//                    ret.push_back({ i, j });
//                }
//            }
//        }
//        return ret;
//    }
//    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis) {
//        vis[i][j] = true;
//        for (int k = 0; k < 4; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j] && !vis[x][y]) {
//                dfs(heights, x, y, vis);
//            }
//        }
//    }
//};


//class Solution {
//    int m, n;
//    int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//    int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//public:
//    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//        m = board.size(), n = board[0].size();
//        int x = click[0], y = click[1];
//        if (board[x][y] == 'M') // �ȵ��ף���Ϸ����
//        {
//            board[x][y] = 'X';
//            return board;
//        }
//        // ����
//        dfs(board, x, y);
//        return board;
//    }
//    void dfs(vector<vector<char>>& board, int i, int j) {
//        int count = 0;
//        for (int k = 0; k < 8; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
//                count++;
//            }
//        }
//        if (count != 0) {
//            board[i][j] = '0' + count;
//        }
//        else
//        {
//            board[i][j] = 'B';
//            for (int k = 0; k < 8; k++)
//            {
//                int x = i + dx[k], y = j + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
//                    dfs(board, x, y);
//            }
//        }
//    }
//};


//bool digit(int x, int y) {
//    int sum1 = 0;
//    while (x /= 10) {
//        sum1 = sum1 + x % 10;
//    }
//    int sum2 = 0;
//    while (y /= 10) {
//        sum2 = sum2 + y % 10;
//    }
//    return sum1 + sum2 <= 1;
//}
//int main()
//{
//    digit(1, 2);
//    return 0;
//}


//class Solution {
//    int m, n, cnt;
//    int ret;
//    int dx[2] = { 1, 0 };
//    int dy[2] = { 0, 1 };
//    vector<vector<bool>> vis;
//public:
//    int wardrobeFinishing(int _m, int _n, int _cnt) {
//        m = _m, n = _n, cnt = _cnt;
//        vis = vector<vector<bool>>(m, vector<bool>(n));
//        //if(cnt == 0) return 1;
//        vis[0][0] = true;
//        dfs(0, 0);
//        return ret;
//    }
//    bool digit(int x, int y) {
//        int sum1 = 0;
//        while (x) {
//            sum1 = sum1 + x % 10;
//            x /= 10;
//        }
//        int sum2 = 0;
//        while (y) {
//            sum2 = sum2 + y % 10;
//            y /= 10;
//        }
//        return sum1 + sum2 <= cnt;
//    }
//    void dfs(int i, int j) {
//        ret++;
//        for (int k = 0; k < 2; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && digit(x, y) && !vis[x][y]) {
//                vis[x][y] = true;
//                dfs(x, y);
//            }
//        }
//    }
//};


//class Solution {
//    int m, n, cnt;
//    int ret;
//    int dx[2] = { 1, 0 };
//    int dy[2] = { 0, 1 };
//    vector<vector<bool>> vis;
//public:
//    int wardrobeFinishing(int _m, int _n, int _cnt) {
//        m = _m, n = _n, cnt = _cnt;
//        vis = vector<vector<bool>>(m, vector<bool>(n));
//        //if(cnt == 0) return 1;
//        vis[0][0] = true;
//        dfs(0, 0);
//        return ret;
//    }
//    bool digit(int x, int y) {
//        int sum1 = 0;
//        while (x) {
//            sum1 = sum1 + x % 10;
//            x /= 10;
//        }
//        int sum2 = 0;
//        while (y) {
//            sum2 = sum2 + y % 10;
//            y /= 10;
//        }
//        return sum1 + sum2 <= cnt;
//    }
//    void dfs(int i, int j) {
//        ret++;
//        cout << "(" << i << "," << j << ").";
//        for (int k = 0; k < 2; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && digit(x, y) && !vis[x][y]) {
//                vis[x][y] = true;
//                dfs(x, y);
//            }
//        }
//    }
//};


//class Solution {
//    int m, n, cnt;
//    int ret;
//    int dx[2] = { 1, 0 };
//    int dy[2] = { 0, 1 };
//    bool vis[101][101];
//public:
//    int wardrobeFinishing(int _m, int _n, int _cnt) {
//        m = _m, n = _n, cnt = _cnt;
//        dfs(0, 0);
//        return ret;
//    }
//    bool digit(int x, int y) {
//        int sum1 = 0;
//        while (x) {
//            sum1 = sum1 + x % 10;
//            x /= 10;
//        }
//        int sum2 = 0;
//        while (y) {
//            sum2 = sum2 + y % 10;
//            y /= 10;
//        }
//        return sum1 + sum2 <= cnt;
//    }
//    void dfs(int i, int j) {
//        ret++;
//        vis[i][j] = true;
//        for (int k = 0; k < 2; k++) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && digit(x, y) && !vis[x][y]) {
//                dfs(x, y);
//            }
//        }
//    }
//};


//class Solution {
//    // ��������
//    // �����ظ�������ݹ�
//    // �������һ������¼
//    // 1. ���һ������¼
//    // 2. �ݹ�ÿ�η��ص�ʱ�򣬽�����ŵ�����¼���汣��
//    // 3. ��ÿ�ν���ݹ��ʱ��������¼�����һ��
//    int memo[31]; // memeory -> ����
//public:
//    int fib(int n) {
//        for (int i = 0; i <= 30; i++) {
//            memo[i] = -1;
//        }
//        return dfs(n);
//    }
//    int dfs(int n) {
//        if (memo[n] != -1) return memo[n];
//
//        if (n == 0 || n == 1) {
//            memo[n] = n;
//            return n;
//        }
//        memo[n] = dfs(n - 1) + dfs(n - 2);
//
//        return memo[n];
//    }
//};


//class Solution {
//    int memo[101][101];
//public:
//    int uniquePaths(int m, int n) {
//        for (int i = 0; i < 101; i++)
//            for (int j = 0; j < 101; j++)
//                memo[i][j] = -1;
//
//        return dfs(m, n);
//    }
//    int dfs(int i, int j) {
//        if (memo[i][j] != -1) return memo[i][j];
//
//        if (i == 1 && j == 1) return 1; // �����1����Ч·��
//        if (i == 1 || j == 1) return 1; // ����߽�ֻ��1��·��
//
//        memo[i][j] = dfs(i - 1, j) + dfs(i, j - 1);
//        return memo[i][j];
//    }
//};


//class Solution {
//    int dp[101][101];
//public:
//    int uniquePaths(int m, int n) {
//
//        dp[1][1] = 1;
//
//        for (int i = 1; i <= m; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (i == 1 && j == 1) continue;
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m][n];
//    }
//};


//class Solution {
//    int n;
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        int ret = 0;
//        n = nums.size();
//        vector<int> dp(n, 1); // dp[i] ��ʾ�Ե� i ��λ��Ϊ��㣬Ȼ��ͳ����ĵ��������г���
//        // ��Ϊ���������е�״̬���̣�ǰ���ֵҪ���������ֵ������dpӦ�ôӺ���ǰ����
//        for (int i = n - 1; i >= 0; i--) {
//            for (int j = i + 1; j < n; j++) {
//                if (nums[i] < nums[j]) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//            ret = max(ret, dp[i]);
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int getMoneyAmount(int n) {
//        // ����Ҫ�������еĽڵ�
//        return dfs(1, n);
//    }
//    int dfs(int left, int right) {
//        if (left >= right) {
//            return 0;
//        }
//        int ret = INT_MAX;
//        for (int head = left; head <= right; head++) {
//            int x = dfs(left, head - 1);
//            int y = dfs(head + 1, right);
//            ret = min(ret, head + max(x, y));
//        }
//        return ret;
//    }
//};


//class Solution {
//    int memo[201][201];
//public:
//    int getMoneyAmount(int n) {
//        // ����Ҫ�������еĽڵ�
//        return dfs(1, n);
//    }
//    int dfs(int left, int right) {
//        if (left >= right) return 0;
//
//        if (memo[left][right]) return memo[left][right];
//
//        int ret = INT_MAX;
//        for (int head = left; head <= right; head++) {
//            int x = dfs(left, head - 1);
//            int y = dfs(head + 1, right);
//            ret = min(ret, head + max(x, y));
//        }
//        memo[left][right] = ret;
//        return ret;
//    }
//};


//class Solution {
//    int m, n; 
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//public:
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        int ret;
//        m = matrix.size(), n = matrix[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                ret = max(ret, dfs(matrix, i, j));
//            }
//        }
//        return ret;
//    }
//    int dfs(vector<vector<int>>& matrix, int i, int j) {
//        int ret = 1;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
//                ret = max(ret, dfs(matrix, x, y) + 1);
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//    int m, n;
    //int dx[4] = { 0, 0, -1, 1 };
    //int dy[4] = { -1, 1, 0, 0 };
//    int memo[201][201];
//public:
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        int ret = 0;
//        m = matrix.size(), n = matrix[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                ret = max(ret, dfs(matrix, i, j));
//            }
//        }
//        return ret;
//    }
//    int dfs(vector<vector<int>>& matrix, int i, int j) {
//        if (memo[i][j] != 0) return memo[i][j];
//        int ret = 1;
//        for (int k = 0; k < 4; k++)
//        {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
//                ret = max(ret, dfs(matrix, x, y) + 1);
//            }
//        }
//        memo[i][j] = ret;
//        return ret;
//    }
//};


//class Solution {
//    typedef pair<int, int> PII;
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//public:
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//        int prev = image[sr][sc]; // �ȱ��һ����Ҫ�޸ĵ�����ֵ
//        if (prev == color) return image; // �����������
//
//        int m = image.size(), n = image[0].size();
//
//        queue<PII> q;
//        q.push({ sr, sc });
//
//        while (!q.empty()) {
//            auto [a, b] = q.front();
//            q.pop();
//            image[a][b] = color;
//            for (int k = 0; k < 4; k++) {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev) {
//                    q.push({ x, y });
//                }
//            }
//        }
//        return image;
//    }
//};


//class Solution {
//    int n, m;
//    int ret;
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    typedef pair<int, int> PII;
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        m = grid.size(), n = grid[0].size();
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] == '1') {
//                    ret++;
//                    bfs(grid, i, j);
//                }
//            }
//        }
//        return ret;
//    }
//    void bfs(vector<vector<char>>& grid, int i, int j) {
//        queue<PII> q;
//        q.push({ i, j });
//        while (!q.empty()) {
//            auto [a, b] = q.front();
//            q.pop();
//            grid[a][b] = '0';
//            for (int k = 0; k < 4; k++) {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
//                    q.push({ x, y });
//                }
//            }
//        }
//    }
//};


//class Solution {
//    int n, m;
//    int ret;
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    typedef pair<int, int> PII;
//    bool vis[301][301];
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        m = grid.size(), n = grid[0].size();
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] == '1' && !vis[i][j]) {
//                    ret++;
//                    bfs(grid, i, j);
//                }
//            }
//        }
//        return ret;
//    }
//    void bfs(vector<vector<char>>& grid, int i, int j) {
//        queue<PII> q;
//        q.push({ i, j });
//        vis[i][j] = true;
//
//        while (!q.empty()) {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++) {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y]) {
//                    q.push({ x, y });
//                    vis[x][y] = true;
//                }
//            }
//        }
//    }
//};


//class Solution {
//    int n, m;
//    int max_area = 0;
//    int count;
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    typedef pair<int, int> PII;
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        if (grid.empty() || grid[0].empty())
//            return 0;
//
//        m = grid.size(), n = grid[0].size();
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 1) {
//                    count = 1;
//                    bfs(grid, i, j);
//                    max_area = max(max_area, count);
//                }
//            }
//        }
//        return max_area;
//    }
//
//    void bfs(vector<vector<int>>& grid, int i, int j) {
//
//        queue<PII> q;
//        q.push({ i, j });
//        grid[i][j] = 0;
//
//        while (!q.empty()) {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++) {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
//                    count++;
//                    q.push({ x, y });
//                    grid[x][y] = 0;
//                }
//            }
//        }
//    }
//}
//;


//class Solution {
//    int n, m;
//    int max_area = 0;
//    int count;
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    typedef pair<int, int> PII;
//    bool vis[51][51];
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        if (grid.empty() || grid[0].empty())
//            return 0;
//
//        m = grid.size(), n = grid[0].size();
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 1 && !vis[i][j]) {
//                    count = 1;
//                    bfs(grid, i, j);
//                    max_area = max(max_area, count);
//                }
//            }
//        }
//        return max_area;
//    }
//
//    void bfs(vector<vector<int>>& grid, int i, int j) {
//
//        queue<PII> q;
//        q.push({ i, j });
//        vis[i][j] = true;
//
//        while (!q.empty()) {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++) {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !vis[x][y]) {
//                    count++;
//                    q.push({ x, y });
//                    vis[x][y] = true;
//                }
//            }
//        }
//    }
//}
//;


//class Solution {
//    int m, n;
//    typedef pair<int, int> PII;
//public:
//    // ������
//    // �ȴ���߽����⣬Ȼ��ʣ�µ�oȫ��Ϊx�����
//    // Ȼ���ٻ�ԭ�߽�
//    void solve(vector<vector<char>>& board) {
//        m = board.size(), n = board[0].size();
//
//        // 1. �ѱ߽����ͨ�飬ȫ���� o ��Ϊ .
//        for (int j = 0; j < n; j++) {
//            if (board[0][j] == 'O')
//                bfs(board, 0, j);
//            if (board[m - 1][j] == 'O')
//                bfs(board, m - 1, j);
//        }
//        for (int i = 0; i < m; i++) {
//            if (board[i][0] == 'O')
//                bfs(board, i, 0);
//            if (board[i][n - 1] == 'O')
//                bfs(board, i, n - 1);
//        }
//
//        // �ٱ����������е� o ��Ϊ x ���ٸ�ԭ�߽缴���
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (board[i][j] == 'O')
//                    board[i][j] = 'X';
//                else if (board[i][j] == '.')
//                    board[i][j] = 'O';
//            }
//        }
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { -1, 1, 0, 0 };
//    void bfs(vector<vector<char>>& board, int i, int j)
//    {
//        // ֻ���Ǵ�� 'O' ������Żᱻ����bfs��
//        queue<PII> q;
//        q.push({ i, j });
//        board[i][j] = '.';
//
//        while (!q.empty()) {
//            auto [a, b] = q.front();
//            q.pop();
//            for (int k = 0; k < 4; k++) {
//                int x = a + dx[k], y = b + dy[k];
//                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
//                    q.push({ x, y });
//                    board[x][y] = '.';
//                }
//            }
//        }
//    }
//};



