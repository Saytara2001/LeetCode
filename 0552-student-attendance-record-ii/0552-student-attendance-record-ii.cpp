class Solution {
public:
    int dp[100001][2][2][3];
    int sz;
    int const mod = 1e9 + 7;
    int rec(int i, int isLstL, int A, int L) {
        if(L >= 3 or A >= 2) 
            return 0;
        
        if(i == sz) 
            return 1;
        
        int &ret = dp[i][isLstL][A][L];
        if(~ret)
            return ret;
        
        ret = rec(i + 1, 0, A, L); //add P
        ret += rec(i + 1, 0, A + 1, L); //add A
        ret %= mod;
        if(isLstL) {
            ret += rec(i + 1, 1, A, L + 1); //add L
            ret %= mod;
        }else {
            ret += rec(i + 1, 1, A, 1); //add L
            ret %= mod;
        }
        return ret;
    }
    int checkRecord(int n) {
        sz = n;
        memset(dp, -1, sizeof dp);
        return rec(0, 0, 0, 0);
    }
};