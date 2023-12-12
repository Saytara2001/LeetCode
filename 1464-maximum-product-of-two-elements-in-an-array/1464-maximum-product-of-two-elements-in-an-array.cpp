class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return --nums.back() * --nums[size(nums) - 2];
    }
};