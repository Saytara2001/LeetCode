class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pref(n, vector<int>(n));
        for(auto query: queries) {
            int x1 = query[0], y1 = query[1];
            int x2 = query[2], y2 = query[3];
            ++pref[x1][y1];
            if(x2 + 1 < n and y2 + 1 < n)
                ++pref[x2 + 1][y2 + 1];
            if(y2 + 1 < n)
                --pref[x1][y2 + 1];
            if(x2 + 1 < n)
                --pref[x2 + 1][y1];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                pref[i][j] += i > 0 ? pref[i - 1][j] : 0;
                pref[i][j] += j > 0 ? pref[i][j - 1] : 0;
                pref[i][j] -= (i > 0 and j > 0 ? pref[i - 1][j - 1] : 0);
            }
        }
        return pref;
    }
};