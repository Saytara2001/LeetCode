class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = 1, dec = 1;
        for(int i = 0; i + 1 < nums.size(); i++) {
            inc &= nums[i + 1] >= nums[i];
            dec &= nums[i + 1] <= nums[i];
        }
        return (inc | dec);
    }
};