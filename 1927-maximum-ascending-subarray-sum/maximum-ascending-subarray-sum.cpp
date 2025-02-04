class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums.front(), curSum = maxSum;
        for(int i = 1; i < size(nums); i++) {
            if(nums[i] > nums[i - 1]) {
                curSum += nums[i];
            } else {
                curSum = nums[i];
            }
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};