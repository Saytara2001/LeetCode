class Solution {
public:
    #define mod 1000000007
    int kInversePairs(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 2));
        dp[1][0] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][min(j + i + 1, k + 1)] -= dp[i][j];
            }
            for(int j = 1; j <= k; ++j)
            {
                dp[i + 1][j] += dp[i + 1][j - 1];
                dp[i + 1][j] += mod;
                dp[i + 1][j] %= mod;
            }
        }
        return dp[n][k];
    }
};