class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sr = 0, sc = 0, er = n-1,ec = n-1, i;
        vector<vector<int>> v(n, vector<int> (n));
        int cur = 1;
        while(sr<=er && sc <= ec){
            for(i = sc; i <= ec && sr<=er; i++){
                v[sr][i] = cur++;
            }
            sr++;
            for(i = sr; i <= er &&  sc<=ec; i++){
                v[i][ec] = cur++;
            }
            ec--;
            for(i = ec; i >= sc &&  sr<=er; i--){
                v[er][i] = cur++;
            }
            er--;
            for(i = er; i >= sr && sc<=ec; i--){
                v[i][sc] = cur++;
            }
            sc++;
        }
        return v;
    }
};