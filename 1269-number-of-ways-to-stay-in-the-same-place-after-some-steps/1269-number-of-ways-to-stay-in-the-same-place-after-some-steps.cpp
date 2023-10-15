class Solution {
public:
    int mod = 1e9 + 7;
    int sz;
    long long dp[251][501];
    long long rec(int i, int steps) {
        
        if(i == 0 and steps == 0)
            return 1;
        
        //i have 500 steps then to return to zero index again need 500 / 2 steps so max is 250
        if(i < 0 or i >= sz or steps < 0 or i > 250)
            return 0;
            
        long long &ret = dp[i][steps];
        if(~ret)
            return ret;
        
        ret = rec(i, steps - 1);
        ret = (ret + rec(i + 1, steps - 1)) % mod;
        ret = (ret + rec(i - 1, steps - 1)) % mod;
        
        return ret;
    }
    int numWays(int steps, int arrLen) {
        sz = arrLen;
        memset(dp, -1, sizeof dp);
        return rec(0, steps);
    }
};