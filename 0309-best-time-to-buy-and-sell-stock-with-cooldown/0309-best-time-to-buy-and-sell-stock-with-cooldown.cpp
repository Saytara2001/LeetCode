class Solution {
public:
    enum {
        NOTHING = 0,
        SELL = 1,
        BUY = 2
    };
    int dp[5005][2][3];
    vector<int> v;
    int rec(int i, bool haveStock, int lstOperation) {
        
        if(i == v.size())
            return 0;
        
        int &ret = dp[i][haveStock][lstOperation];
        
        if(~ret)
            return ret;
        
        int cooldown = rec(i + 1, haveStock, NOTHING);
        int buy = 0, sell = 0;
        
        if(haveStock)
            sell = rec(i + 1, 0, SELL) + v[i];
        
        if(lstOperation != SELL) 
            buy = rec(i + 1, 1, BUY) - v[i];
            
        
        return ret = max({cooldown, buy, sell});
    }
    int maxProfit(vector<int>& prices) {
        
        memset(dp, -1, sizeof dp);
        
        for(auto vv:prices) {
            v.push_back(vv);
        }
        
        return rec(0, 0, NOTHING);
    }
};