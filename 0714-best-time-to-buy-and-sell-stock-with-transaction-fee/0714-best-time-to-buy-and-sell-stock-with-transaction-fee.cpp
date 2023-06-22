class Solution {
public:
    long long dp[50005][2];
    int fe;
    long long rec(int i, bool stock, vector<int>& prices) {
        if(i == size(prices))
            return 0;
        
        long long &ret = dp[i][stock];
        if(ret != -1e18)
            return ret;
        
        ret = 0;
        ret = max(ret, rec(i + 1, stock, prices)); //leave
        //buy
        if(!stock) {
            ret = max(ret, rec(i + 1, !stock, prices) - prices[i]);
        }else {
            ret = max(ret, rec(i + 1, !stock, prices) + prices[i] - fe);
        }
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        fe = fee;
        for(int i = 0; i < 5e4 + 5; i++) {
            dp[i][0] = dp[i][1] = -1e18;
        }
        // memset(dp, -1, sizeof dp);
        return rec(0, 0, prices);
    }
};