class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> pref(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] += mat[i][j];
                pref[i][j] += i - 1 >= 0 ? pref[i - 1][j] : 0;
                pref[i][j] += j - 1 >= 0 ? pref[i][j - 1] : 0;
                pref[i][j] -=
                    (i - 1 >= 0 and j - 1 >= 0 ? pref[i - 1][j - 1] : 0);
            }
        }
        auto valid = [&](int mid) {
            for (int i = 0; i + mid - 1 < n; i++) {
                for (int j = 0; j + mid - 1 < m; j++) {
                    int x2 = i + mid - 1, y2 = j + mid - 1;
                    long long sum = pref[x2][y2];
                    sum -= i - 1 >= 0 ? pref[i - 1][y2] : 0;
                    sum -= j - 1 >= 0 ? pref[x2][j - 1] : 0;
                    sum += (i - 1 >= 0 and j - 1 >= 0 ? pref[i - 1][j - 1] : 0);
                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };
        int ans = 0;
        int l = 1, r = min(n, m);
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (valid(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};