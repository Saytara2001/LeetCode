class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        int mx = 0, n = v.size();
        sort(v.rbegin(), v.rend());
        for(int i = 0; i + 2 < n; i++) {
            if(v[i + 1] + v[i + 2] > v[i]) {
                mx = max(mx, v[i] + v[i + 1] + v[i + 2]);
            }
        }
        return mx;
    }
};