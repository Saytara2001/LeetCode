class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = size(nums);
        int l = 0, r = 0;
        while(l <= r and r < n) {
            if(nums[l] != 0 and nums[r] != 0) {
                l++, r++;
                continue;
            }
            if(nums[r] == 0) r++;
            if(nums[l] != 0) l++;
            if(l < r and r < n and nums[l] == 0 and nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++, r++;
            }
        }
    }
};