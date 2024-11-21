class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        // 0 => unvisited, 1 => visited, 2 => wall or guard
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        queue<pair<int, int>> q, q2;
        for(int i = 0; i < size(guards); i++) {
            vis[guards[i][0]][guards[i][1]] = 2; 
            q.push({guards[i][0], guards[i][1]});
        }
        for(int i = 0; i < size(walls); i++) {
            vis[walls[i][0]][walls[i][1]] = 2; 
        }
        
        int dx[4] = {0 , 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        auto valid = [&](int i, int j) {
            return i >= 0 and i < m and j >= 0 and j < n and vis[i][j] != 2;
        };
        
        q2 = q;
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int d = 0; d < 2; d++) {
                int ni = x + dx[d];
                int nj = y + dy[d];
                if(valid(ni, nj) and vis[ni][nj] != 1) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        
        while(q2.size()) {
            auto [x, y] = q2.front();
            q2.pop();
            
            for(int d = 2; d < 4; d++) {
                int ni = x + dx[d];
                int nj = y + dy[d];
                if(valid(ni, nj) and vis[ni][nj] != 3) {
                    vis[ni][nj] = 3;
                    q2.push({ni, nj});
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cnt += !vis[i][j];
        
        return cnt;
    }
};