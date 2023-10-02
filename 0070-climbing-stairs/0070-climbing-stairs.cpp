class Solution {
public:
    int dp[46];
    int rec(int i, int n) {
        //not valid
        if(i > n)
            return 0;
        
        if(i == n)
            return 1;
        
        int &ret = dp[i];
        if(~ret)
            return ret;
        
        ret = rec(i + 1, n);
        ret += rec(i + 2, n);
        
        return ret;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof dp);
        return rec(0, n);
    }
};