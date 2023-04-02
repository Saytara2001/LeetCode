class Solution {
public:
    int dp[2501][2501];
    int rec(int i, int prev, vector<int>& v) {
        if (i == v.size())
            return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        int leave = 0, take = INT_MIN;
        leave = rec(i + 1, prev, v);
        
        if(i == prev) {
            take = rec(i + 1, i , v) + 1;
            leave = rec(i + 1, i + 1, v);
        }else if (v[i] > v[prev]) {
            take = rec(i + 1, i , v) + 1;
        }
        return dp[i][prev] = max(take, leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        
        return rec(0, 0, nums);
    }
};