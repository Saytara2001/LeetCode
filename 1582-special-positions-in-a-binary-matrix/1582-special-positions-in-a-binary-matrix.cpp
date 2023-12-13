class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = size(mat), m = size(mat[0]);
        vector<int> prefRow(n), prefCol(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prefRow[i] += (mat[i][j] == 1);
                prefCol[j] += (mat[i][j] == 1);
            }
        }
        int special = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if(mat[i][j] and prefCol[j] == 1 and prefRow[i] == 1)
                    special++;
            }
        }
        return special;
    }
};