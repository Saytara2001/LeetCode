class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = size(nums);
        vector<int> pos(n);
        for(int i = 0; i < n; i++) {
            pos[i] = nums[nums[i]];
        }
        return pos;
    }
};