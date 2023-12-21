class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        int maxVerticalArea = 0;
        for(int i = 1; i < size(points); i++) {
            maxVerticalArea = max(maxVerticalArea, points[i][0] - points[i - 1][0]);
        }
        return maxVerticalArea;
    }
};