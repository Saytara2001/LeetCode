class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        long long ans = 1;
        int n = size(nums);
        int l = 0;
        const int mod = 1e9 + 7;
        
        while(n > 0 and nums[n - 1] == 0) 
            --n;
        
        if(n == 0)
            return 0;
        
        while(nums[l] == 0) 
            ++l;
        
        int cntZeros = 0;
        for(int i = l; i < n; i++) {
            if(nums[i] == 0) 
                cntZeros++;
            else {
                ans = ans * (cntZeros + 1) % mod;
                cntZeros = 0;
            }
        }
        
        return ans;
    }
};