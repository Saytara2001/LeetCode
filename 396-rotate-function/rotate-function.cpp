class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int cur = 0, sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            cur += i * nums[i];
            sum += nums[i];
        }
        int max_ans = cur;
        for(int i = n - 1; i >= 0; i--) {
            cur += (sum - n * nums[i]);
            max_ans = max(max_ans, cur);
        }
        return max_ans;
    }
};