class Solution {
public:
    int orangesRotting(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size(); // 2 rotten (not vis), 0 (visited)
        queue<pair<int, int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        auto valid = [&](int i, int j) {
            return i >= 0 and i < n and j >= 0 and j < m;
        };
        int dx[4] = { 1, 0, -1, 0};
        int dy[4] = { 0, 1, 0, -1};
        int mintues = -1;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (valid(ni,nj) and grid[ni][nj] == 1) {
                        q.push({ni,nj});
                        grid[ni][nj] = 0;
                    }
                }
            }
            ++mintues;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return max(mintues, 0);
    }
};