class Solution {
public:
    int n, m;
    int dp[500][500][3];
    int rec(int i, int j, int k, vector<vector<int>>& coins) {
        if (i == n - 1 and j == m - 1)
            return k > 0 and coins[n - 1][m - 1] < 0 ? 0 : coins[n - 1][m - 1];

        int& ret = dp[i][j][k];
        if (ret != -1e9)
            return ret;

        if (i + 1 < n) {
            ret = max(ret, rec(i + 1, j, k, coins) + coins[i][j]);
            if (k > 0 and coins[i][j] < 0)
                ret = max(ret, rec(i + 1, j, k - 1, coins));
        }
        if (j + 1 < m) {
            ret = max(ret, rec(i, j + 1, k, coins) + coins[i][j]);
            if (k > 0 and coins[i][j] < 0)
                ret = max(ret, rec(i, j + 1, k - 1, coins));
        }

        return ret;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1e9;
                }
            }
        }
        return rec(0, 0, 2, coins);
    }
};