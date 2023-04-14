class Solution {
public:
    int dp[1005][1005];
    int rec(int l, int r, string& s) {
        
        if(l == r)
            return 1;
        
        if(l > r)
            return 0;
        
        int &ret = dp[l][r];
        
        if(~ret)
            return ret;
        
        if(s[l] == s[r]) {
            ret = rec(l + 1, r - 1, s) + 2;
        }else {
            ret = max(rec(l + 1, r, s), rec(l, r - 1, s));
        }
        
        return ret;
    }
    int longestPalindromeSubseq(string s) {
        
        memset(dp, -1, sizeof dp);
        return rec(0, s.size() - 1, s);
    }
};