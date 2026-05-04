class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, r = n - 1;
        while (l < r) {
            for (int i = 0; i < r - l; i++) {
                int top = l, bottom = r;
                int temp = matrix[top][l + i];
                // move bottom left to top left
                matrix[top][l + i] = matrix[bottom - i][l];
                // move bottom right to bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];
                // move top right to bottom right
                matrix[bottom][r - i] = matrix[top + i][r];
                // move top left to top right
                matrix[top + i][r] = temp;
            }
            ++l, --r;
        }
    }
};