class Solution {
public:
    string convert(string s, int numRows) {
        int n = numRows, sz = s.size();
        vector<vector<char>> v(n, vector<char> (sz, '?'));
        int idx = 0;
        for(int col = 0; col < sz and idx < sz; col++) {
            //fill_row
            for(int row = 0; row < n and idx < sz; row++){
                v[row][col] = s[idx++];
            }
            //fill diagonal
            for(int row = n - 2; row > 0 and idx < sz; row--) {
                col++;
                v[row][col] = s[idx++];
            }
        }
        string res = "";
        for(auto vv:v){
            for(auto v2:vv) {
                if(v2 != '?') res += v2;
            }
        }
        return res;
    }
};