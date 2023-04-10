class Solution {
public:
    int dp[1005];
    vector<int> v;
    int rec(int i) {
        
        if(i >= v.size())
            return 0;
        
        int &ret = dp[i];
        
        if(~ret)
            return ret;
        
        ret = 1e9;
        ret = min({ret, rec(i+1) + v[i], rec(i + 2) + v[i]});
        
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        for(auto vv:cost) {
            v.push_back(vv);
        }
        memset(dp, -1, sizeof dp);
        return min(rec(0), rec(1));
    }
};