class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = size(nums);
        long long res = 0;
        int mx = 0;
        for(auto it: nums) mx = max(mx, it);
        int l = 0, r = 0, cnt = 0;
        while(l < n or r < n) {
            while(r < n and cnt < k) {
                cnt += (nums[r++] == mx);
            }
            if(cnt == k)
                res += n - r + 1;
            cnt -= (nums[l++] == mx);
        }
        return res;
    }
};