class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mx = 0, n = size(nums);
        vector<int> bit(31);
        auto valid = [&]() {
            for(int i = 0; i < 31; i++) {
                if(bit[i] > 1) return false;
            }
            return true;
        };
        int l = 0;
        for(int r = 0; r < n; r++) {
            // add right 
            for(int msk = 0; msk < 30; msk++) {
                if((1 << msk) & nums[r]) {
                    bit[msk]++;
                }
            }
            while(!valid() and l < r) {
                // remove left 
                for(int msk = 0; msk < 30; msk++) {
                    if((1 << msk) & nums[l]) {
                        bit[msk]--;
                    }
                }
                ++l;
            }
            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};