class Solution {
public:
    int dp[501][501];
    int rec(int i, int rem, vector<int>& cost, vector<int>& time) {
        
        if(rem <= 0)
            return 0;
        
        if(i == size(time))
            return 1e9;
            
        int &ret = dp[i][rem];
        if(~ret)
            return ret;
        
        ret = 1e9;
        ret = min(ret, rec(i + 1, rem, cost, time));
        ret = min(ret, rec(i + 1, rem - time[i] - 1, cost, time) + cost[i]);
        
        return ret;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof dp);        
        return rec(0, size(time), cost, time);
    }
};