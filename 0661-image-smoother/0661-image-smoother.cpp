class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = size(img), m = size(img[0]);
        vector<vector<int>> res(n, vector<int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int sum = img[i][j], cnt = 1;
                if(i - 1 >= 0 and j - 1 >= 0) cnt++, sum += img[i - 1][j - 1];
                if(i + 1 < n and j + 1 < m) cnt++, sum += img[i + 1][j + 1];
                if(i + 1 < n and j - 1 >= 0) cnt++, sum += img[i + 1][j - 1];
                if(i - 1 >= 0 and j + 1 < m) cnt++, sum += img[i - 1][j + 1];
                if(i - 1 >= 0) cnt++, sum += img[i - 1][j];
                if(j - 1 >= 0) cnt++, sum += img[i][j - 1];
                if(i + 1 < n) cnt++, sum += img[i + 1][j];
                if(j + 1 < m) cnt++, sum += img[i][j + 1];
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};