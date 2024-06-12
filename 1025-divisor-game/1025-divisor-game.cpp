class Solution {
public:
    int dp[1001][2];
    int rec(int n, bool turn) {
        
        if(n == 1) return (turn == 0);
        
        int &ret = dp[n][turn];
        if(~ret)
            return ret;
        
        bool win = 0;
        ret = 0;
        for(int x = 1; x * x < n; x++) {
            if(n % x == 0) {
                if(turn == rec(n - x, !turn)) {
                    win = 1;
                    ret |= rec(n - x, !turn);
                }
                
            }
        }
        if(!win) {
            return ret = (turn == 0);
        }
        return ret;
    }
    bool divisorGame(int n) {
        memset(dp, -1, sizeof dp);
        return rec(n, 1);
    }
};