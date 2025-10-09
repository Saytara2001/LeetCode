class Solution {
public:
    int rec(int i, int lstOp, int &fee, vector<int>& prices, vector<vector<int>> &dp) {
        if (i == size(prices)) return 0;

        int &ret = dp[i][lstOp];
        if (ret != -2e9)
            return ret;

        ret = max(ret, rec(i + 1, lstOp, fee, prices, dp));

        if (lstOp == 0) {
            ret = max(ret, rec(i + 1, 1, fee, prices, dp) - prices[i] - fee);
        } else if (lstOp == 1){
            ret = max(ret, rec(i + 1, 0, fee, prices, dp) + prices[i] );
        }
        
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -2e9));
        return rec(0, 0, fee, prices, dp);
    }
};