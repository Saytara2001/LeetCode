class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = size(grid);
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; i++) {
            vector<int> v;
            for(int j = 0; j < n - 2; j++) {
                int mx = 0;
                for(int x = i; x < i + 3; x++) {
                    for(int y = j; y < j + 3; y++) {
                        mx = max(mx, grid[x][y]);
                    }
                }
                v.push_back(mx);
            }
            res.push_back(v);
        }
        return res;
    }
};