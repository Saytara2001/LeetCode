class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);
        
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                //flip row to get max value
                for(int j = 0; j < m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += grid[i][j];
            }
            if(sum < n - sum) {
                //flip column
                 for(int i = 0; i < n; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    res += (1LL << (m - j - 1));
                }
            }
        }
        return res;
    }
};