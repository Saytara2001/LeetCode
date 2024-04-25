class Solution {
public:
    int dp[100000][28];
    int rec(int i, int prev, string& s, int k) {
        
        if(i == size(s)) return 0;
        
        int &ret = dp[i][prev];
        if(~ret)
            return ret;
        
        ret = max(ret, rec(i + 1, prev, s, k)); //leave
        if(prev == 27 or abs(prev - (s[i] - 'a')) <= k){
            ret = max(ret, rec(i + 1, s[i] - 'a', s, k) + 1); //take
        }
        
        return ret;
    }
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof dp);
        return rec(0, 27, s, k);
    }
};