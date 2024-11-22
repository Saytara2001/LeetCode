class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> mp;
        int n = size(matrix), m = size(matrix[0]);
        for(int i = 0; i < n; i++) {
            
            string s = "";
            for(int j = 0; j < m; j++)
                s += matrix[i][j] + '0';
            
            mp[s]++;
        }
        
        int mx = 0;
        
        for(auto it: mp) {
            string t = it.first;
            for(int i = 0; i < m; i++) {
                t[i] = '1' - t[i] + '0';
            }
            mx = max(mx, mp[t] + it.second);
        }
        
        return mx;
    }
};