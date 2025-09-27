class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double area = 0;
        auto getDistance = [&](int i, int j) -> double {
            int diff_X = points[i][0] - points[j][0];
            int diff_Y = points[i][1] - points[j][1];
            return sqrt(diff_X * diff_X + diff_Y * diff_Y);
        };
        auto getArea = [&](int i, int j, int k) -> double {
            double a = getDistance(i, j);
            double b = getDistance(i, k);
            double c = getDistance(j, k);
            double s = (a + b + c) / 2.0;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        };
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    area = max(area, getArea(i, j, k));
                }
            }
        }
        return area;
    }
};