class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return idx >= 0 and nums[idx] == target ? idx : -1;
    }
};