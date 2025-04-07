class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int tot = accumulate(begin(nums), end(nums), 0);
        if(tot & 1)
            return false;

        int n = size(nums);
        vector<int> dp(2 * tot + 1);

        dp[tot / 2] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int sum = 0; sum <= tot / 2; sum++) {
                int &ret = dp[sum];
                ret |= dp[sum];
                ret |= dp[sum + nums[i]];
            }
        }
        return dp[0];
    }
};