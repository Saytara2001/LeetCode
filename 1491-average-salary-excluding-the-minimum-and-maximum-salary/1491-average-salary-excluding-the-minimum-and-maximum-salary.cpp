class Solution {
public:
    double average(vector<int>& salary) {
        int mn = 1e9, mx = -1e9;
        int sum = 0;
        for(auto vv:salary) {
            sum += vv;
            mn = min(mn, vv);
            mx = max(mx, vv);
        }
        sum -= mn + mx;
        return 1.0 * sum / (salary.size() - 2);
    }
};