class Solution {
public:
    int dp[505][505];
    string s, t;
    int rec(int i, int j) {
        
        if(i == s.size()) // base case 1
            return t.size() - j;
        
        if(j == t.size()) // base case 2
            return s.size() - i;
        
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        
        if(s[i] == t[j])
            return ret = rec(i + 1, j + 1);
        
        int replace = rec(i + 1, j + 1) + 1;
        int insert = rec(i + 1, j) + 1;
        int del = rec(i, j + 1) + 1;
        
        return ret = min({replace, insert, del});
    }
    int minDistance(string word1, string word2) {
        s = word1; t = word2;
        
        memset(dp, -1, sizeof dp);
        
        return rec(0, 0);
    }
};