class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<long double>> dp(102, vector<long double>(102));
        dp[0][0] = (long double) poured;
        for (int row = 0; row <= query_row; row++) {
            for(int glass = 0; glass <= row; glass++) {
                long double nxt = (dp[row][glass] - 1.0) / 2.0;
                if(nxt > 0) {
                    dp[row + 1][glass] += nxt;
                    dp[row + 1][glass + 1] += nxt;
                }
            }
        }
        return min(1.0, (double)dp[query_row][query_glass]);
    }
};