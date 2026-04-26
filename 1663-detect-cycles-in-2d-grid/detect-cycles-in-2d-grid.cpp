class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        auto valid = [&](int i, int j, int pi, int pj) {
            return i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == grid[pi][pj];
        };
        bool ans = false;
        function<void(int, int,int,int)> dfs = [&](int i, int j, int pi, int pj) {
            if(!valid(i, j, pi, pj)) return;
            if(vis[i][j]) {
                ans = true;
                return;
            }
            vis[i][j] = true;
            if(make_pair(i + 1, j) != make_pair(pi, pj))
                dfs(i + 1, j, i, j);
            if(make_pair(i - 1, j) != make_pair(pi, pj))
                dfs(i - 1, j, i, j);
            if(make_pair(i, j + 1) != make_pair(pi, pj))
                dfs(i, j + 1, i, j);
            if(make_pair(i, j - 1) != make_pair(pi, pj))    
                dfs(i, j - 1, i, j);
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    dfs(i, j, i, j);
                }
            }
        }
        return ans;
    }
};