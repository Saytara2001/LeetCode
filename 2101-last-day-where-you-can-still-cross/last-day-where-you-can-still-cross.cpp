class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int> > &cells) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        auto valid = [&](int i, int j) {
            return i >= 1 and i <= row and j >= 1 and j <= col;
        };
        auto can = [&](int mid) -> bool {
            vector<vector<bool> > vis(row + 1, vector<bool>(col + 1, false));
            for (int i = 0; i <= mid; ++i) {
                vis[cells[i][0]][cells[i][1]] = true;
            }
            queue<pair<int, int> > q;
            for (int i = 1; i <= col; ++i) {
                if (!vis[0][i]) {
                    q.emplace(0, i);
                    vis[0][i] = true;
                }
            }
            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (valid(ni, nj) and !vis[ni][nj]) {
                        if (ni == row) return true;
                        vis[ni][nj] = true;
                        q.emplace(ni, nj);
                    }
                }
            }
            return false;
        };
        int l = 0, r = cells.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (can(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l + 1;
    }
};