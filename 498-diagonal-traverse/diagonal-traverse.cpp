class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int x = 0, y = 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n + m + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        for(int i = 0; i <= n + m; i++) {
            if(i & 1) {
                for(int j = 0; j < v[i].size(); j++) {
                    res.push_back(v[i][j]);
                }
            } else {
                for(int j = v[i].size() - 1; j >= 0; j--) {
                    res.push_back(v[i][j]);
                }
            }
        }
        return res;
    }
};