class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxRows = 1, maxCols = 1;
        int cntRows = 1, cntCols = 1;
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        for (int i = 1; i < hBars.size(); i++) {
            if(hBars[i] == hBars[i - 1] + 1) {
                maxRows = max(maxRows, ++cntRows);
            } else {
                cntRows = 1;
            }
        }
        for (int i = 1; i < vBars.size(); i++) {
            if(vBars[i] == vBars[i - 1] + 1) {
                maxCols = max(maxCols, ++cntCols);
            } else {
                cntCols = 1;
            }
        }
        int len = min(maxRows, maxCols) + 1;
        return 1LL * len * len;
    }
};