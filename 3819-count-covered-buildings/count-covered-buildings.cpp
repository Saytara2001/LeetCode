class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<array<int, 2>> x(n + 1, {INT_MAX, INT_MIN}); // min, max
        vector<array<int, 2>> y(n + 1, {INT_MAX, INT_MIN}); // min, max
        for (auto building : buildings) {
            int a = building[0];
            int b = building[1];
            // for each x and put b
            x[b][0] = min(x[b][0], a);
            x[b][1] = max(x[b][1], a);
            // for each b and put a
            y[a][0] = min(y[a][0], b);
            y[a][1] = max(y[a][1], b);
        }
        int covered = 0;
        for (auto building : buildings) {
            int a = building[0];
            int b = building[1];

            if(a > x[b][0] and a < x[b][1] and b > y[a][0] and b < y[a][1]) {
                ++covered;
            }
                
        }
        return covered;
    }
};