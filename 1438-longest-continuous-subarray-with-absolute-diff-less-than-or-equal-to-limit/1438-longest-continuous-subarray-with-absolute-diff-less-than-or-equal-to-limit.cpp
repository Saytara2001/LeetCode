class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0;
        int n = size(nums);
        multiset<int> ms;
        int mx = 0;
        while(r < n) {
            ms.insert(nums[r++]);
            while(*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[l]));
                l++;
            }
            mx = max(mx, r - l);
        }
        return mx;
    }
};