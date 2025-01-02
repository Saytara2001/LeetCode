class Solution {
public:
    int n, m;
    int dp[1000][1000];
    int minSteps(int i, int j, string& s1, string& s2) {

        if(i == n)
            return m - j;
        
        if(j == m)
            return n - i;

        int &ret = dp[i][j];
        if(~ret)
            return ret;

        ret = 2e9;
        if(s1[i] == s2[j]) {
            ret = min(ret, minSteps(i + 1, j + 1, s1, s2));
        }else {
            ret = min(ret, minSteps(i + 1, j + 1, s1, s2) + 2);
            ret = min(ret, minSteps(i + 1, j, s1, s2) + 1);
            ret = min(ret, minSteps(i, j + 1, s1, s2) + 1);
        }

        return ret;
    }
    int minDistance(string word1, string word2) {
        n = size(word1), m = size(word2);
        memset(dp, -1, sizeof dp);
        return minSteps(0, 0, word1, word2);
    }
};