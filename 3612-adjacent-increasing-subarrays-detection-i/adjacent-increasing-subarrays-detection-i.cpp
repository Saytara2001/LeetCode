class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, pre = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                pre = cnt;
                cnt = 1;
            }
            if(cnt >= 2 * k or (pre >= k and cnt >= k)) return  true;
        }
        return false;
    }
};