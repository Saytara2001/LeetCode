class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res(size(matrix[0]));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < size(matrix[i]); j++) {
                res[j].push_back(matrix[i][j]);
            }
        }
        return res;
    }
};