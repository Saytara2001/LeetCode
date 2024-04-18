class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, -1, 0},
        dy[4] = {1, 0, 0, -1};
    bool valid(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    bool vis[100][100];
    int dfs(int i, int j, vector<vector<int>>& grid) {
        
        
        if(!valid(i, j) or !grid[i][j]) 
            return 1;
        
        if(vis[i][j]) 
            return 0;
        
        vis[i][j] = true;
        int val = 0;
        for(int d = 0; d < 4 ; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            val += dfs(ni, nj, grid);
        }
        return val;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = size(grid), m = size(grid[0]);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j])
                    return dfs(i, j, grid);
            }
        }
        return 0;
    }
};