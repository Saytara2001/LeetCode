class Solution {
public:
    int dijkstra(vector<vector<int>>& dis, vector<vector<int>>& grid) {

        deque<array<int, 3>> dq;
        dq.push_back({0, 0, 0});
        dis[0][0] = 0;

        int n = size(grid), m = size(grid[0]);
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        auto valid = [&](int i, int j) {
            return (i >= 0 and i < n and j >= 0 and j < m);
        };

        while(dq.size()) {
            auto [cost, x, y] = dq.front();
            dq.pop_front();

            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(valid(nx, ny) and dis[nx][ny] == 2e9) {
                    int newCost = cost + (grid[nx][ny] == 1);
                    dis[nx][ny] = newCost;
                    if(grid[nx][ny] == 1) {
                        dq.push_back({newCost, nx, ny});
                    }else {
                        dq.push_front({newCost, nx, ny});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);
        vector<vector<int>> dis(n, vector<int>(m, 2e9)); //2e9 --> !visited
        return dijkstra(dis, grid);
    }
};