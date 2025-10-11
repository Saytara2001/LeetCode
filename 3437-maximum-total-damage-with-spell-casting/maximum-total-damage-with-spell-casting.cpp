class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> freq;
        for(auto x: power) {
            ++freq[x];
        }
        vector<pair<int, int>> v;
        for(auto [x, f] : freq) {
            v.push_back({x, f});
        }
        int n = v.size();
        long long res = 0;
        vector<long long> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i] = 1LL * v[i].first * v[i].second;
            long long cur = dp[i];
            for(int j = i - 1; j >= max(i - 6, 0); j--) {
                if(v[i].first - 2 > v[j].first)
                    cur = max(cur, dp[i] + dp[j]);
            }
            dp[i] = cur;
            res = max(res, dp[i]);
        }
        return res;
    }
};