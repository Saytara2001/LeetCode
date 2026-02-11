class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        for (int i = 0; i < n; i++) {
            int even = 0, odd = 0;
            map<int, bool> vis;
            for (int j = i; j < n; j++) {
                if (!vis.count(nums[j])) {
                    nums[j] & 1 ? ++odd : ++even;
                    vis[nums[j]] = true;
                }
                if (even == odd) {
                    longest = max(longest, j - i + 1);
                }
            }
        }
        return longest;
    }
};