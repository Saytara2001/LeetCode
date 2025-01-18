class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);

        int dx[4] = {0,  0, 1, -1};
        int dy[4] = {1, -1, 0,  0};
        auto valid = [&](auto& i, auto& j) -> bool{
            return (i >= 0 and i < n and j >= 0 and j < m);
        };

        vector<vector<int>> cost(n, vector<int>(m, 1e5));
        priority_queue<array<int, 3>> pq;

        pq.push({0, 0, 0}); //-mincost, i, j 
        cost[0][0] = 0;

        while(pq.size()) {

            auto [c, i, j] = pq.top();
            pq.pop();
            
            int di = i + dx[grid[i][j] - 1];
            int dj = j + dy[grid[i][j] - 1];

            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                int newCost = -c + (make_pair(ni, nj) != make_pair(di, dj));
                if(valid(ni, nj) and newCost < cost[ni][nj]) {
                    cost[ni][nj] = newCost;
                    pq.push({-newCost, ni, nj});
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};