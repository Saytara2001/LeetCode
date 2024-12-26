class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = size(nums);
        int totalSum = accumulate(begin(nums), end(nums), 0);
        
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1));
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;
        
        for(int i = 1; i < n; i++) {
            for(int sum = -totalSum; sum <= totalSum; sum++) {
                if(dp[i - 1][sum + totalSum] > 0) {
                    dp[i][sum + nums[i] + totalSum] += dp[i - 1][sum + totalSum];
                    dp[i][sum - nums[i] + totalSum] += dp[i - 1][sum + totalSum];
                }
            }
        }
        
        return abs(target) > totalSum ? 0 : dp[n - 1][target + totalSum];
    }
};