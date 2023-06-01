class Solution {
public:
    int dx[8] = {0, 1, 1,  1,  0, -1, -1, -1},
        dy[8] = {1, 1, 0, -1, -1, -1,  0,  1};
    int n;
    vector<vector<int>> arr;
    vector<vector<int>> dis;
    bool valid(int i, int j) {
        return (i >= 0 and i < n and j >= 0 and j < n and arr[i][j] == 0);
    }
    void bfs() {
        
        queue<pair<int ,int>> q;
        q.push({0, 0});
        dis[0][0] = 1;
        while(!q.empty()) {
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int d = 0; d < 8; d++) {
                
                int ni = x + dx[d]; 
                int nj = y + dy[d];
                
                if(valid(ni, nj) and dis[ni][nj] > dis[x][y] + 1) {
                    dis[ni][nj] = dis[x][y] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        dis.resize(n, vector<int> (n, 1e9));
        arr.resize(n);
        for(int i = 0; i < n; i++) {
            arr[i].resize(n);
            for(int j = 0; j < n; j++) {
                arr[i][j] = grid[i][j];
            }
        }
        bfs();
        
        if(dis[n-1][n-1] == 1e9 or arr[0][0] == 1)
            return -1;
        
        return dis[n-1][n-1];
    }
};