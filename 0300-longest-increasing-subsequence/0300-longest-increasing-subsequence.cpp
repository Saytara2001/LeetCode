class Solution {
public:
    // int dp[2501][2501];
    int rec(int i, int prev, vector<int>& v, vector<vector<int>>& dp) {
        if (i == v.size())
            return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        int take = 0;
        int leave = rec(i + 1, prev, v, dp);
        
        if(i == prev) {
            take = rec(i + 1, i , v, dp) + 1;
            leave = rec(i + 1, i + 1, v, dp);
        }else if (v[i] > v[prev]) {
            take = rec(i + 1, i , v, dp) + 1;
        }
        return dp[i][prev] = max(take, leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        // memset(dp, -1, sizeof(dp));
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return rec(0, 0, nums, dp);
    }
};