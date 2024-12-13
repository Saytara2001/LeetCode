class Solution {
public:
    const int mod = 1e9 + 7;
    long long Mul(long long a, long long b) {
        return (a % mod) * (b % mod) % mod;
    }
    int sumOfPower(vector<int>& nums) {
        
        long long res = 0 ;
        int n = size(nums);
        sort(begin(nums), end(nums));
        
        /// 1  2  3  5
        for(auto x: nums) {
            res += Mul(1LL * x * x, x); // (x ^ 2) * x
            res %= mod;
        }
        
        long long pref = 0;
        for(int i = 1; i < n; i++) {
            pref = Mul(pref, 2) + nums[i - 1];
            res += Mul(1LL * nums[i] * nums[i], pref);
            res %= mod;
        }
        
        return res;
    }
};