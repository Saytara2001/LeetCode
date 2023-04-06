class Solution {
public:
    
    int dx[4] = {0, 1, 0, -1},
        dy[4] = {1, 0, -1, 0};
    
    int n, m;
    vector<vector<int>> v;
    bool valid(int i, int j) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    int ok = 1;
    void dfs(int i, int j) {
        v[i][j] = 1;
        if(i == 0 or i == n - 1 or j == 0 or j == m - 1) {
            ok = 0;
        }
        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(valid(ni, nj) and v[ni][nj] != 1) {
                dfs(ni, nj);
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        n = grid.size(), m = grid[0].size();
        v = vector<vector<int>> (n, vector<int> (m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                v[i][j] = grid[i][j];
            }
        }
        
        int islands = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if(v[i][j] == 0) {
                    ok = 1;
                    dfs(i, j);
                    cout<<endl;
                    islands += ok;
                }
            }
        }
        return islands;
    }
};