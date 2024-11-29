class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        
        int n = size(grid), m = size(grid[0]);
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
    
        
        
        vector<vector<bool>> vis(n, vector<bool> (m));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
        
        q.push({0, 0, 0});
        vis[0][0] = true;
        
        auto valid = [&](int i, int j) {
            return (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j]);
        };
        
        while(q.size()) {
            auto [t, x, y] = q.top();
            q.pop();
            
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(valid(nx, ny)) {
                    
                    vis[nx][ny] = true;
                    
                    int waiting = (grid[nx][ny] - t) & 1 ? 0 : 1;
                    int nextTime = max(grid[nx][ny] + waiting, t + 1);
                    
                    if(make_pair(nx, ny) == make_pair(n - 1, m - 1))
                        return nextTime;
                    
                    q.push({nextTime, nx, ny});
                }
            }
            
        }
        
        return -1;
    }
};