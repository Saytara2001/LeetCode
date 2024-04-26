class Solution {
public:
    int dp[201][201];
    int n;
    int rec(int i, int j, vector<vector<int>>& v) {
        
        if(i == n - 1) return v[i][j]; //last row
        
        int &ret = dp[i][j];
        if(~ret) 
            return ret;
        
        ret = 1e9;
        for(int c = 0; c < n; c++) {
            if(c != j) {
                ret = min(ret, rec(i + 1, c, v) + v[i][j]);
            }
        }
        return ret;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        n = size(grid);
        int mn = INT_MAX;
        for(int c = 0; c < size(grid); c++) {
            int res = rec(0, c, grid);
            mn = min(res, mn);
        }
        return mn;
    }
};