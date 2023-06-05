class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        double pre_mile = 0;
        for(int i = 1; i < v.size(); i++) {
            double y = v[i][1] - v[i-1][1];
            double x = v[i][0] - v[i-1][0];
            if(i != 1) {
                double new_mile = x == 0 ? 1e9 : y / x;;
                if(pre_mile != new_mile)
                    return false;
            }
            pre_mile = x == 0 ? 1e9 : y / x;
        }
        return true;
    }
};