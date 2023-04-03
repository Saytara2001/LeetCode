class Solution {
public:
    int target = 0, sum = 0;
    int dp[205][20005];
    bool can(int i, int have, vector<int>& v) {
        
        if(have != 0 and sum % have == 0 and sum / have == 2) {
            return 1;
        }
        
        if(i == v.size())
            return 0;
        
        int &ret = dp[i][have];
        
        if(~ret)
            return ret;
       
        int take = can(i+1, have + v[i], v);
        int leave = can(i+1, have, v);
        
        return ret = max(take, leave);

    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        for(auto vv:nums) {
            sum += vv;
        }
        return can(0, 0, nums);
    }
};