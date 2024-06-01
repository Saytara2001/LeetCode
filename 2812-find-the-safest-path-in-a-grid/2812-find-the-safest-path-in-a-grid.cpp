class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = size(grid);
        vector<vector<int>> safeness(n, vector<int>(n, 1e7));
        queue<pair<int, int>> q;
        
        function<void()> bfs = [&]() {
            int dis = 1;
            
            while(q.size()) {
                int sz = q.size();
                while(sz--) {
                    auto [x, y] = q.front();
                    q.pop();

                    for(int d = 0; d < 4; d++) {
                        int ni = x + dx[d];
                        int nj = y + dy[d];
                        if(ni < 0 or nj < 0 or ni >= n or nj >= n) continue;
                        if(safeness[ni][nj] != 1e7) continue;
                        safeness[ni][nj] = dis;
                        q.push({ni, nj});
                    }
                }
                ++dis;
            }
        };
        
        function<bool(int, int, int)> canReach = [&](int i, int j, int safe) {
            
            queue<pair<int, int>> que;
            vector<vector<bool>> vis(n, vector<bool>(n));
            que.push({i, j});
            if(safeness[i][j] < safe) return false;
            vis[i][j] = 1;
            
            while(que.size()) {
                int sz = que.size();
                while(sz--) {
                    auto [x, y] = que.front();
                    que.pop();
                    
                    for(int d = 0; d < 4; d++) {
                        int ni = x + dx[d];
                        int nj = y + dy[d];
                        if(ni < 0 or nj < 0 or ni >= n or nj >= n) continue;
                        if(safeness[ni][nj] < safe or vis[ni][nj]) continue;
                        que.push({ni, nj});
                        vis[ni][nj] = 1;
                        if(ni == n - 1 and nj == n - 1)
                            return true;
                    }
                }
            }
            return false;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }
        
        //preprocessing for safeness
        bfs();
        //search for max safeness
        int L = 0, R = 1e5;
        while(L < R) {
            int mid = L + ((R - L + 1) >> 1);
            if(canReach(0, 0, mid)) {
                L = mid;
            }else {
                R = --mid;
            }
        }
        
        return L;
    }
};