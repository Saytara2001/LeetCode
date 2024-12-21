class Solution {
public:
    int dp[300][300][40];
    int n, m;
    int mod = 1e9 + 7;
    int add(int a, int b) {
        return (a % mod + b % mod) % mod;
    }
    int rec(int i, int j, int xr, int k, vector<vector<int>>& grid) {
        if(i == n - 1 and j == m - 1) {
            return k == xr;
        }
        int &ret = dp[i][j][xr];
        if(~ret)
            return ret;

        ret = 0;
        if(i + 1 < n)
            ret = add(ret, rec(i + 1, j, xr ^ grid[i + 1][j], k, grid));
        if(j + 1 < m)
            ret = add(ret, rec(i, j + 1, xr ^ grid[i][j + 1], k, grid));

        return ret;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        n = size(grid), m = size(grid[0]);
        memset(dp, -1, sizeof dp);
        return rec(0, 0, grid[0][0], k, grid);
    }
};