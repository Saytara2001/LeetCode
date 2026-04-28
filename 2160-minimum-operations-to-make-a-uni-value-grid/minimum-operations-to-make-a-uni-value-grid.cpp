class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int prev = -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> all;
        for(int i = 0; i < n; i++) {
            for(int j = 0;  j< m; j++) {
                if(prev == -1) {
                    prev = grid[i][j] % x;
                } else {
                    if(prev != grid[i][j] % x)
                        return -1;
                }
                all.push_back(grid[i][j]);
            }
        }
        sort(all.begin(), all.end());
        int a = all[all.size() / 2];
        int diff = 0;
        for(int i = 0; i < all.size(); i++) {
            diff += abs(all[i] - a) / x;
        }
        return diff;
    }
};