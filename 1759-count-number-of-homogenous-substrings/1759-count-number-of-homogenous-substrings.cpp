class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int mod = 1e9 + 7;
        int n = size(s);
        for(int i = 0; i < n; i++) {
            int cur = i, cnt = 0;;
            while(cur < n and s[cur] == s[i]) {
                cur++;
                cnt++;
            }
            i = cur - 1;
            ans += 1LL * cnt * (cnt + 1) / 2;
            ans %= mod;
        }
        return ans;
    }
};