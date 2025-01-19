class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx = abs(nums[0] - nums.back());
        for(int i = 0; i + 1 < size(nums); i++) {
            mx = max(mx, abs(nums[i] - nums[i + 1]));
        }
        return mx;
    }
};