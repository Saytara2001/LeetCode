class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int mx = -2e9, sum = 0, n = nums.size();
        int l = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(i >= k) {
                sum -= nums[l++];
            }
            if(i >= k - 1)
                mx = max(mx, sum);
        }
        return 1.0 * mx / k;
    }
};