class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n = size(grid), m = size(grid[0]);
        vector<vector<bool>> vis(n, vector<bool> (m));
        int fish = 0;
        function<void(int, int)> dfs = [&](int i, int j) {
            
            if(i < 0 or j < 0 or i >= n or j >= m) return;
            if(vis[i][j] or grid[i][j] == 0) return;
            fish += grid[i][j];
            vis[i][j] = true;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        int maxFishes = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] and grid[i][j]) {
                    fish = 0;
                    dfs(i, j);
                    cout << endl;
                    maxFishes = max(maxFishes, fish);
                }
            }
        }

        return maxFishes;
    }
};