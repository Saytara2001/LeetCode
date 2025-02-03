class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = size(nums);
        int cnt = 1, mx = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) mx = max(mx, ++cnt);
            else cnt = 1;
        }
        cnt = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i]) mx = max(mx, ++cnt);
            else cnt = 1;
        }
        return mx;
    }
};