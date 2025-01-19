class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int n = size(heightMap), m = size(heightMap[0]);
        vector<vector<bool>> vis(n, vector<bool>(m, 0)); 

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        auto valid = [&](int i, int j) {
            return  (i >= 0 and i < n and j >= 0 and j < m);
        };
        
        priority_queue<array<int, 3>> pq;
        // traverse from borders first
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    if(!vis[i][j]) {
                        vis[i][j] = true;
                        pq.push({-heightMap[i][j], i, j});
                    }
                }
            }
        }

        int water = 0;
        while(pq.size()) {
            auto [v, i, j] = pq.top();
            pq.pop();

            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(valid(ni, nj) and !vis[ni][nj]) {
                    vis[ni][nj] = true;
                    if(heightMap[ni][nj] < heightMap[i][j]) {
                        water += heightMap[i][j] - heightMap[ni][nj];
                        heightMap[ni][nj] = heightMap[i][j];
                        pq.push({-heightMap[ni][nj], ni, nj});
                        continue;
                    }
                    pq.push({-heightMap[ni][nj], ni, nj});
                }
            }
        }
        
        return water;
    }
};