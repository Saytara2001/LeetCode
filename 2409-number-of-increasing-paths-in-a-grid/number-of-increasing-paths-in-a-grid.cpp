class Solution {
public:
    int n, m;
    const int mod = 1e9 + 7;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int add(int a, int b) {
        return (a % mod + b % mod) % mod;
    }
    bool valid(int& i, int& j, int& n, int& m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

            int &ret = dp[i][j];
            if(~ret)
                return ret;

            ret = 1;
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(valid(ni, nj, n, m) and grid[i][j] < grid[ni][nj]) {
                    ret = add(ret, rec(ni, nj, grid, dp));
                }
            }

            return ret;
    };
    int countPaths(vector<vector<int>>& grid) {

        n = size(grid), m = size(grid[0]);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int paths = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                paths = add(paths, rec(i, j, grid, dp));
            }
        }
        return paths;
    }
};