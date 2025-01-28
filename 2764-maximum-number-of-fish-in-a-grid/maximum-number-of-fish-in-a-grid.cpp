class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n = size(grid), m = size(grid[0]);
        vector<vector<bool>> vis(n, vector<bool> (m));
        int fish = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        auto valid = [&](int i, int j) {
            return (i >= 0 and i < n and j >= 0 and j < m);
        };
        function<void(int, int)> dfs = [&](int i, int j) {
            
            fish += grid[i][j];
            vis[i][j] = true;

            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(valid(ni, nj) and !vis[ni][nj] and grid[ni][nj]) {
                    dfs(ni, nj);
                }
            }
        };

        int maxFishes = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] and grid[i][j]) {
                    fish = 0;
                    dfs(i, j);
                    maxFishes = max(maxFishes, fish);
                }
            }
        }

        return maxFishes;
    }
};