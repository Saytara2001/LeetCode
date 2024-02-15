class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        long long mx = -1;
        int n = size(nums);
        vector<long long> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            if(i > 1 and nums[i] < pref[i - 1]) {
                mx = max(mx, pref[i]);
            }
        }
        return mx;
    }
};