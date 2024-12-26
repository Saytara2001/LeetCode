class Solution {
public:
    int rec(int i, int sum, int target, vector<int>& nums) {
        
        if(i == size(nums)) {
            return sum == target;
        }
        
        int ways = rec(i + 1, sum + nums[i], target, nums);
        ways += rec(i + 1, sum - nums[i], target, nums);
        
        return ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0, 0, target, nums);
    }
};