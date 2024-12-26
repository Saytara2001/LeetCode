class Solution {
public:
    int dp[20][40005];
    int rec(int i, int sum, int target, vector<int>& nums) {
        
        if(i == size(nums)) {
            return sum == target;
        }
        
        int fixSum = sum < 0 ? 20000 + -sum : sum;
        int &ret = dp[i][fixSum];
        if(~ret)
            return ret;
        
        ret = rec(i + 1, sum + nums[i], target, nums);
        ret += rec(i + 1, sum - nums[i], target, nums);
        
        return ret;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, target, nums);
    }
};