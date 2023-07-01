class Solution {
public:
    int mn = 1e9, n, kk;
    vector<int> sum;
    int rec(int i, vector<int>& cookies) {
        if(i == n) {
            int mx = 0;
            for(auto vv: sum)
                mx = max(mx, vv);
            mn = min(mn, mx);;
            return mn;
        }
        
        for(int j = 0; j < kk; j++) {
            sum[j] += cookies[i];
            rec(i + 1, cookies);
            sum[j] -= cookies[i];
        }
        return mn;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = size(cookies);
        kk = k;
        sum = vector<int> (n);
        return rec(0, cookies);
    }
};