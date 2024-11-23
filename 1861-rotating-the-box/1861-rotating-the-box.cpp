class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = size(box), m = size(box[0]);
        vector<vector<char>> rotatedBox(m, vector<char>(n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rotatedBox[j][n - i - 1] = box[i][j];
            }
        }
        swap(n, m);
        
        for(int j = 0; j < m; j++) {
            int r = n - 1, l = n - 1;
            while(l >= 0) {
                char cl = rotatedBox[l][j];  
                char cr = rotatedBox[r][j];
                if(cl == '*' or (cl == cr and cl == '#')) {
                    r = --l;
                }else if(cl == '#' and cr == '.') {
                    swap(rotatedBox[l][j], rotatedBox[r][j]);
                    --l, --r;
                }else {
                    --l;
                }
            }
        }
        
        return rotatedBox;
    }
};