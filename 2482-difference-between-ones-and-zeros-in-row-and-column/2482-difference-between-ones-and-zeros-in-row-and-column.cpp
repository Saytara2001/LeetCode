class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);
        vector<int> row(n), col(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        vector<vector<int>> diff(n, vector<int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diff[i][j] = row[i] + col[j] - (n - row[i]) - (m - col[j]);
            }
        }
        return diff;
    }
};