class Solution {
public:
    int dijkstra(vector<vector<int>>& dis, vector<vector<int>>& grid) {

        priority_queue<array<int, 3>> pq;
        pq.push({0, 0, 0});
        dis[0][0] = 0;

        int n = size(grid), m = size(grid[0]);
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        auto valid = [&](int i, int j) {
            return (i >= 0 and i < n and j >= 0 and j < m);
        };

        while(pq.size()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(valid(nx, ny)) {
                    if(dis[nx][ny] != 2e9 and grid[nx][ny] == 0) continue;
                    int newCost = -cost + (grid[nx][ny] == 1);
                    if(dis[nx][ny] > newCost) {
                        dis[nx][ny] = newCost;
                        pq.push({-newCost, nx, ny});
                    }
                    if(make_pair(nx, ny) == make_pair(n - 1, m - 1))
                        return dis[n - 1][m - 1];
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