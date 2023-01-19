class Solution {
public:
    bool vis[301][301];
    int dx[4] = {-1, 0, 1, 0},
        dy[4] = {0, 1, 0, -1};
    bool dfs(int i,int j, vector<vector<char>> & grid){
        
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[i].size()
                 or grid[i][j] == '0' or vis[i][j]) return false;
        
        vis[i][j] = 1;
        for(int d = 0; d < 4 ;d++){
            int ni = i + dx[d]; 
            int nj = j + dy[d];
            dfs(ni, nj, grid);
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j <grid[i].size(); j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    islands += dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};