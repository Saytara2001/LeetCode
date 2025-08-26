class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        double longestDiagonal = 0;
        int maximumArea = 0;
        for(auto it: dimensions) {
            int a = it[0], b = it[1];
            double diag = sqrt(a * a + b * b);
            if(diag > longestDiagonal) {
                longestDiagonal = diag;
                maximumArea = a * b;
            } else if(diag == longestDiagonal){
                maximumArea = max(maximumArea, a * b);
            }
        }
        return maximumArea;
    }
};