class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = size(nums);
        int res = 0;
        for(int msk = 0; msk < (1 << n); msk++) {
            int xr = 0;
            for(int i = 0; i < n; i++) {
                if(msk & (1 << i)) {
                    xr ^= nums[i]; 
                }
            }
            res += xr;
        }
        return res;
    }
};