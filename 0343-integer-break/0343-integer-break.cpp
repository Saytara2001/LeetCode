class Solution {
public:
    long long dp[60];
    long long rec(int n) {
        
        if(n == 1)
            return 1;
        
        long long &ret = dp[n];
        
        if(~ret)
            return ret;
        
        ret = n;
        for(int i = 1 ; i <= n; i++) {
            ret = max(ret, i * rec(n - i));
        }
        return ret;
    }
    int integerBreak(int n) {
        if(n == 2 or n == 3)
            return n - 1;
        memset(dp, -1, sizeof dp);
        return rec(n);
    }
};