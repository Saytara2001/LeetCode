class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int k = 401;
        map<int, int> mp;
        for(auto it: requirements) {
            mp[it[0] + 1] = it[1];
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) { // permutation of length => i
            for (int j = 0; j <= k; ++j) { // inversion
                for (int l = 0; l < i; ++l) {
                    if (j - l >= 0) {
                        dp[i][j] += dp[i - 1][j - l];
                        dp[i][j] %= mod;
                    }
                }
            }
            //check if requirement is exist 
            if(mp.find(i) != mp.end()) {
                int inversion = mp[i];
                for(int j = 0; j < k; j++) {
                    if(inversion != j) {
                        //must reset this because it's not valid for anwser
                        dp[i][j] = 0; 
                    }
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < k; i++) {
            res += dp[n][i];
            res %= mod;
        }
        return res;
    }
};