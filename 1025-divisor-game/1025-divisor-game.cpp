class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false); // 1 => win, 0 => lose
        for(int i = 2; i <= n; i++) {
            for(int x = 1; x * x < i; x++) {
                if(i % x == 0) {
                    if(dp[i - x] == false) { //lose
                        dp[i] = true; //then can win here
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};