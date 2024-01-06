class Solution {
public:
    int dp[50001];
    vector<array<int, 3>> vp; //start, end, profit
    vector<int> start, last, bonus;
    int rec(int i) {
        
        if(i >= size(start))
            return 0;
        
        int &ret = dp[i];
        if(~ret)
            return ret;
        
        ret = rec(i + 1); //leave
        
        //try to take
        int idx = lower_bound(begin(start), end(start), last[i]) - begin(start);
        
        ret = max(ret, rec(idx) + bonus[i]);
        
        return ret;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < size(startTime); i++) {
            vp.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(begin(vp), end(vp));
        for(int i = 0; i < size(startTime); i++) {
            start.push_back(vp[i][0]);
            last.push_back(vp[i][1]);
            bonus.push_back(vp[i][2]);
        }
        return rec(0);
    }
};