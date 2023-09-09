class Solution {
public:
    int dp[1005];
    int rec(int target, vector<int>& nums) {
        
        if(target == 0)
            return 1;
        
        int &ret = dp[target];
        if(~ret)
            return ret;
        
        ret = 0;
        for(int i = 0; i < size(nums); i++) {
            if(target - nums[i] >= 0) {
                ret += rec(target - nums[i], nums);
            }
        }
        return ret;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        return rec(target, nums);
    }
};