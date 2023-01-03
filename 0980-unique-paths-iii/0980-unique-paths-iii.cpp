class Solution {
public:
    int freee = 0, n, ans = 0;
    int di[4] = {1, 0, -1, 0},
        dj[4] = {0, 1, 0, -1};
    void rec(int i, int j, int emty,vector<vector<int>> grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == -1)
            return;
        if(grid[i][j] == 2){
            if(freee == emty) ans++;
            return;
        }
        grid[i][j] = -1;
        for(int d = 0; d < 4; d++){
            int ni = i + di[d];
            int nj = j + dj[d];
            rec(ni, nj, emty+1, grid);
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i, j;
        for(int x = 0 ; x < grid.size() ; x++){
            for(int y = 0; y < grid[x].size(); y++){
                if(grid[x][y] == 0) freee++;
                if(grid[x][y] == 1) i = x, j = y;
            }
        }
        rec(i, j, -1, grid);
        return ans;
    }
};