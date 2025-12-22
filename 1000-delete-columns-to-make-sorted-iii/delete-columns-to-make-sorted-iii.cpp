class Solution {
public:
    bool isGood(int col, int prevCol, vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++) {
            if(strs[i][prevCol] > strs[i][col])
                return false;
        }
        return true;
    }
    int rec (int col, int prevCol, vector<string>& strs, vector<vector<int>>& dp) {
        if(col == strs[0].size())
            return 0;
        
        int &ret = dp[col][prevCol];
        if(~ret)
            return ret;
        
        ret = INT_MAX;
        if(col == prevCol) {
            ret = min(ret, rec(col + 1, col + 1, strs, dp) + 1); // leave (delete)
            ret = min(ret, rec(col + 1, col, strs, dp)); // take
        } else {
            ret = min(ret, rec(col + 1, prevCol, strs, dp) + 1); // leave (delete)
            if(isGood(col, prevCol, strs)) {
                ret = min(ret, rec(col + 1, col, strs, dp)); // take
            }
        }
        return ret;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return rec(0, 0, strs, dp);
    }
};