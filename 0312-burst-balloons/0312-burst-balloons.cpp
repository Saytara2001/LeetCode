class Solution {
public:
    int n;
    long long dp[305][305];
    long long rec(int l, int r, vector<int>& nums) {
        
        if(l > r)  // [8] => 1 * 8 * 1
            return 0;
        
        long long &ret = dp[l][r];
        if(~ret)
            return ret;
        
        ret = 0;
        
        for(int k = l; k <= r; k++) {
            ret = max(ret, rec(l, k - 1, nums) + rec(k + 1, r, nums) + (nums[l - 1] * nums[k] * nums[r + 1]));
        }
        
        return ret;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(begin(nums), 1);
        nums.push_back(1);
        
        n = size(nums);
        
        memset(dp, -1, sizeof dp);
        return rec(1, n - 2, nums);
    }
};