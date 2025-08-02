class Solution {
public:
    int nearestExit(vector<vector<char> > &maze, vector<int> &entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        auto valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m and maze[i][j] == '.';
        };
        vector<vector<int> > dist(n, vector<int>(m, 1e4));
        queue<pair<int, int> > q;
        q.push({entrance[0], entrance[1]});
        dist[entrance[0]][entrance[1]] = 0;
        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if ((ni < 0 or nj < 0 or ni >= n or nj >= m) and dist[i][j] > 0) // exit
                    return dist[i][j];
                if (valid(ni, nj) and dist[ni][nj] > dist[i][j] + 1) {
                    q.push({ni, nj});
                    maze[ni][nj] = '+'; // visited
                    dist[ni][nj] = dist[i][j] + 1;
                }
            }
        }
        return -1;
    }
};