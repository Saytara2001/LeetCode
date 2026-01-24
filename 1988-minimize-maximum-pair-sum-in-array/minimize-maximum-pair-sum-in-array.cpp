class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {
            int lst = (n - 1) - i;
            maxSum = max(maxSum, nums[i] + nums[lst]);
        }
        return maxSum;
    }
};