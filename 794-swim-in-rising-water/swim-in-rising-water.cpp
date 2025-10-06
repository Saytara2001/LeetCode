class Solution {
public:
    int swimInWater(vector<vector<int> > &grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<array<int, 3> > pq;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<vector<int> > cost(n, vector<int>(m, INT_MAX));
        auto valid = [&](int i, int j) {
            return 0 <= i && i < n && 0 <= j && j < m;
        };
        pq.push({-grid[0][0], 0, 0});
        cost[0][0] = grid[0][0];
        while (pq.size()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(!valid(ni, nj)) continue;
                int mx = max(grid[ni][nj], cost[i][j]);
                if (cost[ni][nj] > mx) {
                    pq.push({-mx, ni, nj});
                    cost[ni][nj] = mx;
                    if (make_pair(ni, nj) == make_pair(n - 1, n - 1))
                        return mx;
                }
            }
        }
        return 0;
    }
};