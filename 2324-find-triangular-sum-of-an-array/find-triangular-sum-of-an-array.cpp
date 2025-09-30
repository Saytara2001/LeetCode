class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n > 1) {
            int prev = nums[0];
            for(int i = 1; i < n; i++) {
                nums[i - 1] = (prev + nums[i]) % 10;
                prev = nums[i];
            }
            --n;
        }
        return nums[0];
    }
};