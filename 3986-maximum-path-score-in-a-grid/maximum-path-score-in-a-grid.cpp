class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));

        auto calc = [&](int x) {
            if (x <= 1)
                return make_pair(x, x);
            return make_pair(x, 1);
        };
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c <= k; c++) {
                    if (i + 1 < n) {
                        auto [score, cost] = calc(grid[i + 1][j]);
                        int val = dp[i][j][c] + score;
                        int nwc = c + cost;
                        if (nwc <= k)
                            dp[i + 1][j][nwc] = max(dp[i + 1][j][nwc], val);
                    }
                    if (j + 1 < m) {
                        auto [score, cost] = calc(grid[i][j + 1]);
                        int val = dp[i][j][c] + score;
                        int nwc = c + cost;
                        if (nwc <= k)
                            dp[i][j + 1][nwc] = max(dp[i][j + 1][nwc], val);
                    }
                }
            }
        }
        int maxScore = INT_MIN;
        for (int c = 0; c <= k; c++) {
            maxScore = max(maxScore, dp[n - 1][m - 1][c]);
        }
        return maxScore < 0 ? -1 : maxScore;
    }
};