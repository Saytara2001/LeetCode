class Solution {
public:
    int dp[102];
    int rec(int i, string& s) {
        
        if(i == s.size())
            return 1;
        
        int &ret = dp[i];
        if(~ret)
            return ret;
        
        ret = 0;
        if(s[i] >= '1' and s[i] <= '9') {
            ret += rec(i + 1, s);
        }
        if(i + 1 < s.size()) {
            string tmp = s.substr(i, 2);
            if(stoi(tmp) > 9 and stoi(tmp) <= 26) {
                ret += rec(i + 2, s);
            }
        }
        return ret;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        int res = rec(0, s);
        return res;
    }
};