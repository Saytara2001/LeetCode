class Solution {
public:
     bool vis[51][51];
     int dx[4] = {-1, 0, 1, 0},
         dy[4] = {0, 1, 0, -1};
    void dfs(int i, int j, char color, char prev_color, vector<vector<int>>& image){
        
        if(i < 0 or i >= image.size() or j < 0 or j >= image[i].size()
                 or image[i][j] != prev_color or vis[i][j]) return;
        vis[i][j] = 1;
        image[i][j] = color;
        for(int d = 0; d < 4 ;d++){
            int ni = i + dx[d]; 
            int nj = j + dy[d];
            dfs(ni, nj, color, prev_color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev_color = image[sr][sc] ;
        dfs(sr, sc, color, prev_color, image);
        return image;
    }
};