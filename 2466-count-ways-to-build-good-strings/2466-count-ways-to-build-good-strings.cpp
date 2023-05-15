class Solution {
public:
    long long dp[100005];
    long long mod = 1000000007;
    long long rec(int rem, int zero, int one) {
        
        // if(rem <= 0) 
        //     return 1;
        
        long long &ret = dp[rem];
        
        if(~ret)
            return ret;
        
        long long count = 0;
        
        if(rem >= one) {
            count += rec(rem - one, zero, one);
        }
        
        if(rem >= zero) {
            count += rec(rem - zero, zero, one);
        }
        ret = count % mod;
        return ret;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof dp);
        dp[0] = 1;
        long long ans = 0;
        for(int i = low; i <= high; i++) {
            int res = rec(i, zero, one);;
            ans += res;
            cout<< res<<" "<< ans<< endl;
            ans %= mod;
        }
        return ans;
    }
};