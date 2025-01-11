class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = size(nums);
        int sum = 0, maxSum = -2e9, minSum = 0;
        // using prefix Sum
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            minSum = min(minSum, sum);
        }
        return maxSum;
    }
};