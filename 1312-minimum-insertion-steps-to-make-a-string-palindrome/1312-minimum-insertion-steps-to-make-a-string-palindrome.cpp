class Solution {
public:
    int dp[505][505];
    int rec(int i, int j, string& s) {
        
        if(i >= j)
            return 0;
        
        int &ret = dp[i][j];
        
        if(~ret)
            return ret;
        
        ret = 1e9;
        if(s[i] == s[j])
            ret = min(ret, rec(i + 1, j - 1, s));
        else {
            ret = min(ret, rec(i, j - 1, s) + 1);
            ret = min(ret, rec(i + 1, j, s) + 1);
        }
        return ret;
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof dp);
        return rec(0, s.size()-1, s);
    }
};