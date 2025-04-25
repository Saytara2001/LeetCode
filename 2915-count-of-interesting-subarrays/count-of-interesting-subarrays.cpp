class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = size(nums);
        long long pref = 0, res = 0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            int x = (nums[i] % modulo) == k;
            pref = (pref + x) % modulo;
            res += mp[(pref - k + modulo) % modulo];
            mp[pref]++;
        }
        return res;
    }
};