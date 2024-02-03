class Solution {
public:
    long long dp[501];
    long long rec(int i, int k, vector<int>& arr) {
        
        if(i >= size(arr))
            return 0;
        
        long long &ret = dp[i];
        if(~ret)
            return ret;
        
        int end = min((int)size(arr), i + k);
        int mx = 0;
        for(int j = i; j < end; j++) {
            mx = max(mx, arr[j]);
            ret = max(ret, 1LL * mx * (j - i + 1) + rec(j + 1, k, arr));
        }
        
        return ret;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof dp);
        return rec(0, k, arr);
    }
};