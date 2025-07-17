class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int maxLen = 0;
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for(auto num: nums) {
            int cur = num % k;
            for(int prev = 0; prev < k; prev++) {
                dp[cur][prev] = dp[prev][cur] + 1;
                maxLen = max(maxLen,  dp[cur][prev]);
            }
        }
        return maxLen;
    }
};