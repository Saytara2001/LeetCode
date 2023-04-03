class Solution {
public:
    int dp[105];
    vector<int> v;
    int rec(int i) {

        if (i >= v.size())
            return 0;

        int &ret = dp[i];
        
        if (~ret)
            return ret;

        int leave = rec(i + 1);
        int take = rec(i + 2) + v[i];

        return ret = max(take, leave);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        for(auto vv:nums) {
            v.push_back(vv);
        }
        return rec(0);
    }
};