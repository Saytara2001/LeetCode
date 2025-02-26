class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = size(nums);
        int maxSum = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(cur < 0) {
                cur = 0;
            }
            maxSum = max(maxSum, cur);
            nums[i] = -nums[i];
        }
        cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(cur < 0) {
                cur = 0;
            }
            maxSum = max(maxSum, cur);
        }
        return maxSum;
    }
};