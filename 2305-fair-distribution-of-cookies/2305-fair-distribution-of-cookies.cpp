class Solution {
public:
    int mn = INT_MAX, n, kk;
    vector<int> sum;
    int rec(int i, vector<int>& cookies, int rem) {
        if(n - i < rem)
            return INT_MAX;
        if(i == n) {
            int mx = 0;
            for(auto vv: sum)
                mx = max(mx, vv);
            mn = min(mn, mx);;
            return mn;
        }
        
        for(int j = 0; j < kk; j++) {
            
            rem -= sum[j] == 0 ? 1 : 0;
            sum[j] += cookies[i];
            
            rec(i + 1, cookies, rem);
            
            
            sum[j] -= cookies[i];
            rem += sum[j] == 0 ? 1 : 0;
        }
        return mn;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = size(cookies);
        kk = k;
        sum = vector<int> (n);
        return rec(0, cookies, k);
    }
};