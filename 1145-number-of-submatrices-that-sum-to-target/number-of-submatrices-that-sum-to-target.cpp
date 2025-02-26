class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        
        int n = size(matrix), m = size(matrix[0]);
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));

        int sub = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + matrix[i][j];
            }
        }
        
        for(int r2 = 1; r2 <= n; r2++) {
            for(int r1 = 0; r1 < r2; r1++) {
                map<int, int> mp;
                mp[0] = 1;
                for(int c = 1; c <= m; c++) {
                    int val = pref[r2][c] - pref[r1][c];
                   sub += mp[val - target];
                   ++mp[val];
                }
            }
        }

        return sub;
    }
};