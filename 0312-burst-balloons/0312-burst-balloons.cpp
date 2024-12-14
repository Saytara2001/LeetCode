class Solution {
public:
    int n;
    long long dp[305][305];
    long long rec(int l, int r, vector<int>& nums) {
        
        if(r - l == 0)  // [8] => 1 * 8 * 1
            return nums[r];
        
        long long &ret = dp[l][r];
        if(~ret)
            return ret;
        
        ret = 0;
        
        for(int k = l + 1; k < r; k++) {
            ret = max(ret, rec(l, k, nums) + rec(k, r, nums) + (nums[l] * nums[k] * nums[r]));
        }
        
        return ret;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(begin(nums), 1);
        nums.push_back(1);
        
        n = size(nums);
        
        memset(dp, -1, sizeof dp);
        return rec(0, n - 1, nums);
    }
};