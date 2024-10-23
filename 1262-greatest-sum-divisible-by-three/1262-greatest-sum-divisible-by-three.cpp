class Solution {
public:
    int dp[40001][3];
    int rec(int i, int sum, vector<int>& v) {
        if(i == size(v))
            return sum == 0 ? 0 : -1e9;
        
        int &ret = dp[i][sum];
        if(~ret)
            return ret;
        
        ret = -1e9;
        ret = max(ret, rec(i + 1, sum, v)); // leave
        ret = max(ret, v[i] + rec(i + 1, (sum + v[i]) % 3, v)); // take
        
        
        return ret;
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, nums);
    }
};