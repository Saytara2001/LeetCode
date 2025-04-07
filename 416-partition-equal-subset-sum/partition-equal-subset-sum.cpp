class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int tot = accumulate(begin(nums), end(nums), 0);
        if(tot & 1)
            return false;

        int n = size(nums);
        vector<vector<int>> dp(n + 1, vector<int>(2 * tot + 1));

        dp[n][tot / 2] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int sum = 0; sum <= tot; sum++) {
                int &ret = dp[i][sum];
                ret |= dp[i + 1][sum];
                ret |= dp[i + 1][sum + nums[i]];
            }
        }
        return dp[0][0];
    }
};