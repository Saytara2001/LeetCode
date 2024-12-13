class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = size(nums);
        vector<long long> suff(n + 1);
        
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] | nums[i];
        }
        
        long long pref = 0, res = 0;
        for(int i = 0; i < n; i++) {
            long long mul = (1LL << k) * nums[i]; // best is to add all k to one element
            res = max(res, mul | pref | suff[i + 1]);
            pref |= nums[i];
        }
        
        return res;
    }
};