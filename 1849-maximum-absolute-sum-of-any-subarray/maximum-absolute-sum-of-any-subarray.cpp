class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = size(nums);
        int maxSum = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            cur = max(cur + nums[i], nums[i]);
            maxSum = max(maxSum, cur);
            nums[i] = -nums[i];
        }
        cur = 0;
        for(int i = 0; i < n; i++) {
            cur = max(cur + nums[i], nums[i]);
            maxSum = max(maxSum, cur);
        }
        return maxSum;
    }
};