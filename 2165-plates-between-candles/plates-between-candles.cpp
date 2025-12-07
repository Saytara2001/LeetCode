class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int> > &queries) {
        int n = s.size();
        s = "#" + s;
        int sum = 0;
        vector<int> pref(n + 1), nxt(n + 2, n);
        for (int i = 1; i <= n; i++) {
            sum += s[i] == '*';
            pref[i] = (s[i] == '|' ? sum : pref[i - 1]);
        }
        sum = 0;
        for (int i = n; i >= 1; --i) {
            nxt[i] = nxt[i + 1];
            if (s[i] == '|') nxt[i] = i;
        }
        vector<int> res;
        for (auto query: queries) {
            int l = nxt[query[0] + 1], r = query[1] + 1;
            int plates = max(pref[r] - pref[l], 0);
            res.push_back(plates);
        }
        return res;
    }
};