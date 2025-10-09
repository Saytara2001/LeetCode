class Solution {
public:
    long long rec(int i, int lstOp, int &fee, vector<int>& prices, vector<vector<long long>> &dp) {
        if (i == size(prices)) return 0;

        long long &ret = dp[i][lstOp];
        if (ret != -1e18)
            return ret;

        ret = max(ret, rec(i + 1, lstOp, fee, prices, dp));

        if (lstOp == 0) {
            ret = max(ret, rec(i + 1, 1, fee, prices, dp) - prices[i]);
        } else if (lstOp == 1){
            ret = max(ret, rec(i + 1, 0, fee, prices, dp) + prices[i] - fee);
        }
        
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1e18));
        return rec(0, 0, fee, prices, dp);
    }
};