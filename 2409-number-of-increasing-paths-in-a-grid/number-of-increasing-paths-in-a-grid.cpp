class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {

        int n = size(grid), m = size(grid[0]);
        vector<vector<int>> dp(n, vector<int>(m, -1));

        const int mod = 1e9 + 7;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        auto add = [&](int a, int b) {
            return (a % mod + b % mod) % mod;
        };
        auto valid = [&](int i, int j) {
            return (i >= 0 and i < n and j >= 0 and j < m);
        };

        function<int(int, int)> rec = [&](int i, int j) {

            int &ret = dp[i][j];
            if(~ret)
                return ret;

            ret = 0;
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(valid(ni, nj) and grid[i][j] < grid[ni][nj]) {
                    ret = add(ret, rec(ni, nj) + 1);
                }
            }

            return ret;
        };
        
        int paths = n * m; // path with one length (one cell)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                paths = add(paths, rec(i, j));
            }
        }
        return paths;
    }
};