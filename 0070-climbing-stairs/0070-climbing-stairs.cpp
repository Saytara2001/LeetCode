class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1; // one choice (1 step) first stair
        dp[1] = 2; // two choice (2 step) second stair (1 + 1, 2)
        for(int i = 2 ;i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};