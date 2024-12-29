class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[1000][1000];
    int add(int x, int y) {
        return (x % mod + y % mod) % mod;
    }
    int count_ways(int i, int k, vector<string>& words, string& target, vector<vector<int>>& freq) {
        if(i == size(target))
            return 1;

        if(k == size(words[0]))
            return 0;

        int &ret = dp[i][k];
        if(~ret)
            return ret;
        
        ret = 0;
        ret = add(ret, count_ways(i, k + 1, words, target, freq)) % mod;

        int count = freq[k][target[i] - 'a'];
        ret = add(ret, 1LL * count * count_ways(i + 1, k + 1, words, target, freq) % mod) % mod;

        return ret;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof dp);
        int m = size(words[0]);
        vector<vector<int>> freq(m, vector<int> (26));
        for(int i = 0; i < size(words); i++) {
            for(int j = 0; j < m; j++) {
                ++freq[j][words[i][j] - 'a'];
            }
        }
        return count_ways(0, 0, words, target, freq);
    }
};