class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        
        int n = size(matrix), m = size(matrix[0]);
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + matrix[i][j];
            }
        }

        int sub = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                for(int x = 1; x <= i; x++) {
                    for(int y = 1; y <= j; y++) {

                        int val = pref[i][j];
                        val -= pref[x - 1][j] + pref[i][y - 1];
                        val += pref[x - 1][y - 1];
                        if(val == target) {
                            ++sub;
                        }

                    }
                }
            }
        }

        return sub;
    }
};