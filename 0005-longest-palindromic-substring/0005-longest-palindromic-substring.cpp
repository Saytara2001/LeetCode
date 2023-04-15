class Solution {
public:
    int dp[1005][1005];
    bool isPlaindrome(int l, int r, string& s) {
        
        if(l >= r)
            return 1;
        
        
        int &ret = dp[l][r];
        
        if(~ret)
            return ret;
        
        ret = 0;
        if(s[l] == s[r])
            return ret = max(ret, (int)isPlaindrome(l + 1,  r - 1, s));
        
        return ret;
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof dp);
        int idx = -1, len = 0, mxLen = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i ; j < s.size(); j++) {
                len = j - i + 1;
                if(isPlaindrome(i, j, s) and len > mxLen)
                    idx = i, mxLen = len;
            }
        }
        return s.substr(idx, mxLen);
    }
};