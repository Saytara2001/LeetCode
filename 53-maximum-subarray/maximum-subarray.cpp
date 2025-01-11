class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = size(nums);
        int sum = 0, maxSum = -2e9;
        // using kadane algorthim
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};