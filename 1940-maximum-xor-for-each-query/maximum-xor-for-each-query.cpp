class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr = 0;
        for(auto x: nums) {
            xr ^= x;
        }
        int n = nums.size();
        vector<int> res;
        for(int i = n - 1; i >= 0; i--) {
            int k = 0;
            for(int bit = 0; bit < maximumBit; bit++) {
                if(!((1 << bit) & xr)) {
                    k |= (1 << bit);
                }
            }
            xr ^= nums[i];
            res.push_back(k);
        }
        return res;
    }
};