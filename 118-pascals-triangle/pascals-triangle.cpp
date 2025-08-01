class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas(numRows);
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0 or j == i)
                    pas[i].push_back(1);
                else
                    pas[i].push_back(pas[i-1][j] + pas[i-1][j-1]);
            }
        }
        return pas;
    }
};