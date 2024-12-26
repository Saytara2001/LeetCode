class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = size(nums);
        int totalSum = accumulate(begin(nums), end(nums), 0);
        
        vector<int> dp(2 * totalSum + 1);
        dp[nums[0] + totalSum] = 1;
        dp[-nums[0] + totalSum] += 1;
        
        for(int i = 1; i < n; i++) {
            vector<int> next(2 * totalSum + 1);
            for(int sum = -totalSum; sum <= totalSum; sum++) {
                if(dp[sum + totalSum] > 0) {
                    next[sum + nums[i] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[i] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }
        
        return abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
};