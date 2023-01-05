class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int i = 0, arrows = 0, n = points.size();
        while(i < n){
            int y = points[i][1];
            while(i < n and y >= points[i][0]){
                y = min(y, points[i][1]);
                i++;
            }
            arrows++;
        }
        return arrows;
    }
};