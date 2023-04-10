class Solution {
public:
    int dp[100000];
    int rec(int n) {
        
        if(n == 0)
            return 0;
        
        int &ret = dp[n];
        
        if(~ret)
            return ret;
        
        ret = 1e9;
        for(int i = 1 ; i <= n; i++) {
            if(n - (1LL * i * i) >= 0) {
                ret = min(ret, rec(n - (1LL * i * i)) + 1);
            }
        }
        return ret;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof dp);
        return rec(n);
    }
};