class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& v, int k) {
        int n = size(v);
        vector<pair<double, pair<int, int>>> res;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                res.push_back({1.0 * v[i] / v[j], {v[i], v[j]}});
            }
        }
        sort(begin(res), end(res));
        return {res[k - 1].second.first, res[k - 1].second.second};
    }
};