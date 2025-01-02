class Solution {
public:
    int n, m;
    int dp[1000][1000];
    int pref1[1002], pref2[1002];
    int lowestSum(int i, int j, string& s1, string& s2) {

        if(i == n)
            return pref2[m] - pref2[j];
        
        if(j == m)
            return pref1[n] - pref1[i];

        int &ret = dp[i][j];
        if(~ret)
            return ret;

        ret = 2e9;
        if(s1[i] == s2[j]) {
            ret = min(ret, lowestSum(i + 1, j + 1, s1, s2));
        }else {
            ret = min(ret, lowestSum(i + 1, j + 1, s1, s2) + s1[i] + s2[j]);
            ret = min(ret, lowestSum(i + 1, j, s1, s2) + s1[i]);
            ret = min(ret, lowestSum(i, j + 1, s1, s2) + s2[j]);
        }

        return ret;
    }
    int minimumDeleteSum(string s1, string s2) {

        n = size(s1), m = size(s2);
        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++) {
            pref1[i + 1] = pref1[i] + s1[i];
        }

        for(int i = 0; i < m; i++) {
            pref2[i + 1] = pref2[i] + s2[i];
        }

        return lowestSum(0, 0, s1, s2);
    }
};