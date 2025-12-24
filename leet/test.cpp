#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Ë®Æ½ + ×ªÖÃ
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
