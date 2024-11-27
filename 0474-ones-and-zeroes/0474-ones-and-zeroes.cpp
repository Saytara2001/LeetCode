class Solution {
public:
    int dp[600][101][101];
    int rec(int i, int ones, int zeros, vector<string>& strs) {
        if(zeros < 0 or ones < 0) 
            return -1e6;
        if(i == size(strs)) 
            return 0;
        
        int &ret = dp[i][ones][zeros];
        if(~ret)
            return ret;
        
        ret = max(ret, rec(i + 1, ones, zeros, strs));
        
        int cntOnes = count(begin(strs[i]), end(strs[i]), '1');  
        int cntZeros = count(begin(strs[i]), end(strs[i]), '0');
        ret = max(ret, rec(i + 1, ones - cntOnes, zeros - cntZeros, strs) + 1);
        
        return ret;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof dp);
        return rec(0, n, m, strs);
    }
};