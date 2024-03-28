class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = size(nums);
        int l = 0, r = 0;
        int len = 0;
        while(r < n) {
            while(r < n and mp[nums[r]] < k) mp[nums[r++]]++;
            len = max(len, r - l);
            mp[nums[l++]]--;
        }
        return len;
    }
};