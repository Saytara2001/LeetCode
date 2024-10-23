class Solution {
public:
    int dp[40001][3];
    int rec(int i, int sum, vector<int>& v) {
        if(i == size(v))
            return sum == 0 ? 0 : -1e9;
        
        int &ret = dp[i][sum];
        if(~ret)
            return ret;
        
        ret = max(rec(i + 1, sum, v), v[i] + rec(i + 1, (sum + v[i]) % 3, v));
        
        return ret;
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, nums);
    }
};