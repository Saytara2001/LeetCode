class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = 1000, minY = 1000;
        int maxX = 0, maxY = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        int x = maxX - minX + 1;
        int y = maxY - minY + 1;
        long long area = 1LL * x * y;
        return area;
    }
};