class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = size(nums);
        int l = 0, r = 0;
        int product = 1, ans = 0;
        while(r < n) {
            product *= nums[r++];
            while(l < r and product >= k) {
                product /= nums[l++];
            }
            ans += r - l;
        }
        return ans;
    }
};