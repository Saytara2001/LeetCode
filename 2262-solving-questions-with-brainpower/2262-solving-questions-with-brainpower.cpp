class Solution {
public:
    long long dp[100002];
    long long rec(int i, vector<vector<int>>& questions) {
        
        if(i >= questions.size())
            return 0;
        
        long long &ret = dp[i];
        if(~ret)
            return ret;
        
        long long take = questions[i][0] + rec(i + questions[i][1] + 1, questions);
        long long leave = rec(i + 1, questions);
        
        return ret = max(take, leave);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof dp);
        return rec(0, questions);
    }
};