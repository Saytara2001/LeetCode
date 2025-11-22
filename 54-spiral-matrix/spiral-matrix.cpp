class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool> > vis(n + 1, vector<bool>(m + 1));
        int state = 0, i = 0, j = 0;
        auto valid = [&](int x, int y) {
            return 0 <= x and x < n and 0 <= y and y < m and !vis[x][y];
        };
        vector<int> res;
        while (valid(i, j)) {
            res.push_back(matrix[i][j]);
            vis[i][j] = true;
            int ni = i + dx[state];
            int nj = j + dy[state];
            if (!valid(ni, nj)) {
                state = (state + 1) % 4;
            }
            i += dx[state];
            j += dy[state];
        }
        return res;
    }
};