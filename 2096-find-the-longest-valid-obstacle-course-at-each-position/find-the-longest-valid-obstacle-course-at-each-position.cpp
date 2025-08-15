class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        int n = obstacles.size();
        vector<int> dp, res(n);
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(begin(dp), end(dp), obstacles[i]);
            if (it == end(dp)) {
                dp.push_back(obstacles[i]);
                res[i] = dp.size();
            } else {
                *it = obstacles[i];
                res[i] = it - begin(dp) + 1;
            }
        }
        return res;
    }
};