class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = size(matrix), m = size(matrix[0]);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int mn = matrix[i - 1][j];
                if(i - 1 >= 0 and j - 1 >= 0)
                    mn = min(mn, matrix[i - 1][j - 1]);
                if(i - 1 >= 0 and j + 1 < m)
                    mn = min(mn, matrix[i - 1][j + 1]);
                matrix[i][j] += mn;
            }
        }
        int minPath = 1e9;
        for(int j = 0; j < m; j++) {
            minPath = min(minPath, matrix[n - 1][j]);
        }
        return minPath;
    }
};