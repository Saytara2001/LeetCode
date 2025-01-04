class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int n = size(points);
        int seconds = 0;

        for(int i = 1; i < n; i++) {
            int x = points[i - 1][0], y = points[i - 1][1];
            int x2 = points[i][0], y2 = points[i][1];
            int diagonal = min(abs(x - x2), abs(y - y2));
            int straight = abs(x - x2)  + abs(y - y2) - 2 * diagonal;
            seconds += diagonal + straight;
        }

        return seconds;
    }
};