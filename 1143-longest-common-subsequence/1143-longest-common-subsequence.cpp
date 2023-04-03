class Solution {
public:
    int dp[1001][1001];
    int LCS(int i, int j, string& s, string& t) {
        
        if (i == s.size() or j == t.size())
            return 0;
        
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        
        int take = 0;
        if (s[i] == t[j])
            take = LCS(i + 1, j + 1, s, t) + 1;

        int leave1 = LCS(i + 1, j, s, t);
        int leave2 = LCS(i, j + 1, s, t);
        int leave3 = LCS(i + 1, j + 1, s, t);

        return ret = max({take, leave1, leave2, leave3});

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return LCS(0, 0, text1, text2);
    }
};