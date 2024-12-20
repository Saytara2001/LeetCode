class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = size(coins);
        vector<int> dp(amount + 1, 1e9);
        
        dp[0] = 0;
        for(int i = 0; i <= amount; i++) {
            for(int j = 0; j < n; j++) {
                if(i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};