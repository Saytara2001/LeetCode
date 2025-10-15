class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxK = 0, pre = 1, cnt = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                pre = cnt;
                cnt = 1;
            }
            maxK = max(maxK, cnt / 2);
            maxK = max(maxK, min(cnt, pre));
        }
        return maxK;
    }
};