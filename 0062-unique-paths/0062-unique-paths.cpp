class Solution {
public:
    int nn, mm, dp[101][101];
    int rec(int i, int j) {
        if(i >= nn or j >= mm)
            return 0;
        if(i == nn-1 or j == mm-1)
            return 1;
        
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        
        ret = rec(i + 1, j);
        ret += rec(i, j + 1);
        
        return ret;
    }
    int uniquePaths(int m, int n) {
        nn = n;
        mm = m;
        memset(dp, -1, sizeof dp);
        return rec(0, 0);
    }
};