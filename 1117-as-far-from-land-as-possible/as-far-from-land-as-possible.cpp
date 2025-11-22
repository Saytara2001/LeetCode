class Solution {
public:
    int maxDistance(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > dis(n, vector<int>(m, INT_MAX));
        queue<pair<int, int> > q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        auto valid = [&](int i, int j) {
            return i >= 0 and i < n and j >= 0 and j < m and !grid[i][j];
        };
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int max_dis = -1;
        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (valid(ni, nj) and dis[ni][nj] > dis[i][j] + 1) {
                    dis[ni][nj] = dis[i][j] + 1;
                    q.push({ni, nj});
                    max_dis = max(max_dis, dis[ni][nj]);
                }
            }
        }
        return max_dis;
    }
};