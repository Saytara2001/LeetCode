class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0, mnLen = 1e9;
        int n = size(nums);
        while(r < n) {
            sum += nums[r++];
            while(l < r and l < n and sum >= target) {
                mnLen = min(mnLen, r - l);
                sum -= nums[l++];
            }
        }
        return mnLen == 1e9 ? 0 : mnLen;
    }
};