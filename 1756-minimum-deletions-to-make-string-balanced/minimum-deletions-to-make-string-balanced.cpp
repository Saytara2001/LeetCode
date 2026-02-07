class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        vector<int> pref(n + 1), suff(n + 2);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == 'b');
        }
        for (int i = n - 1; i >= 0; i--) {
            suff[i + 1] = suff[i + 2] + (s[i] == 'a');
        }
        int res = n;
        for (int i = 1; i <= n; i++) {
            int mx = pref[i - 1] + suff[i + 1];
            res = min(res, mx);
        }
        return res;
    }
};