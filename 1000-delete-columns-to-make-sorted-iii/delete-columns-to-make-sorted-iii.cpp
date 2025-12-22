class Solution {
public:
    bool isGood(int col, int prevCol, vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++) {
            if(strs[i][prevCol] > strs[i][col])
                return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int maxKeep = 1;
        vector<int> dp(m, 1);
        for (int col = 1; col < m; col++) {
            for(int prev = 0; prev < col; prev++) {
                if(isGood(col, prev, strs)) {
                    dp[col] = max(dp[col], dp[prev] + 1);
                    maxKeep = max(maxKeep, dp[col]);
                }
            }
        }
        return m - maxKeep;
    }
};