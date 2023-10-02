class Solution {
public:
    int dp[20001], freq[20001];
    int rec(int i) {
        
        if(i >= 20001)
            return 0;
        
        int &ret = dp[i];
        if(~ret)
            return ret;
        
        ret = max(freq[i] * i + rec(i + 2), ret); //take
        ret = max(rec(i + 1), ret); //leave
        
        return ret;
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        for(auto it: nums) {
            freq[it]++;
        }
        return rec(1);
    }
};